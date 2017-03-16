#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int tmp[22];

bool isPalindrome(long long a) {
	int cnt=0;
	while(a) {
		tmp[cnt++]=a%10; a/=10;
	}
	int l=0,r=cnt-1;
	while(l<r) {
		if (tmp[l]!=tmp[r]) return false;
		++l; --r;
	}
	return true;
}

long long dp[55][11][2];
char str[202];

long long find(int n) {
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	int tot=(n+1)/2;
	for(int len=0;len<tot;++len)
		for(int sum=0;sum<10;++sum)
			for(int less=0;less<2;++less) {
				if (dp[len][sum][less])
					for(int j=(len==0);j<=(less ? 9 : (str[len]-'0'));++j) {
						if (sum+(2-(len==(tot-1)&&(n&1)))*j*j<10)
							dp[len+1][sum+(2-(len==(tot-1)&&(n&1)))*j*j][less||(j<(str[len]-'0'))]+=dp[len][sum][less];
					}
			}
	bool ok=true; int sum=0;
	for(int i=0;i<tot;++i) {
		sum+=(str[i]-'0')*(str[i]-'0');
		if (str[i]>str[n-1-i]) ok=false;
	}
	long long ans=0;
	if (ok&&sum<10) ++ans;
	for(int sum=0;sum<10;++sum)
		ans+=dp[tot][sum][1];
	return ans;
}

int base=10000;

struct Long {
	Long() : len(0) {
		memset(a,0,sizeof(a));
	};
	int & operator [] (int i) {
		return a[i];
	}
	int a[60],len;
	int read() {
		char str[102];
		scanf("%s",str);
		int l=strlen(str);
		len=-1;
		for(int i=l-1;i>=0;i-=4) {
			int r=max(0,i-3),val=0;
			for(;r<=i;++r) {
				val=val*10+str[r]-'0';
			}
			a[++len]=val;
		}
		return l;
	}
	void output(char * str) {
		sprintf(str,"%d",a[len]);
		int ln=strlen(str);
		for(int i=len-1;i>=0;--i) {
			sprintf(str+ln,"%04d",a[i]);
			ln+=4;
		}
		str[ln]='\0';
	}
};

Long operator + (Long & a,Long & b) {
	Long ret; int p=0;
	for(int i=0;i<=a.len||i<=b.len;++i) {
		int r=p;
		if (i<=a.len) r+=a[i];
		if (i<=b.len) r+=b[i];
		if (r>=base) p=r/base,r%=base;
		else p=0;
		ret[i]=r;
	}
	ret.len=max(a.len,b.len);
	if (p) ret[++ret.len]=p;
	return ret;
}

Long operator - (Long & a,int b) {
	Long ret=a; ret[0]-=b;
	for(int i=0;i<=ret.len;++i) {
		if (ret[i]<0) ret[i]+=base,ret[i+1]--;
	}
	while(ret.len&&ret[ret.len]==0) --ret.len;
	return ret;
}

Long operator * (Long & a,Long & b) {
	Long ret; ret.len=a.len+b.len+1;
	for(int i=0;i<=a.len;++i)
		for(int j=0;j<=b.len;++j) {
			ret[i+j]+=a[i]*b[j];
			if (ret[i+j]>=base) {
				ret[i+j+1]+=ret[i+j]/base;
				ret[i+j]%=base;
			}
		}
	for(int i=0;i<ret.len;++i)
		if (ret[i]>=base) {
			ret[i+1]+=ret[i]/base;
			ret[i]%=base;
		}
	while(ret.len&&ret[ret.len]==0) --ret.len;
	return ret;
}

Long operator / (Long & a,int b) {
	Long ret=a;
	for(int i=ret.len;i>=0;--i) {
		if (ret[i]%b) {
			if (i) ret[i-1]+=(ret[i]%b)*base;
		}
		ret[i]/=b;
	}
	while(ret.len&&ret[ret.len]==0) --ret.len;
	return ret;
}

bool operator < (Long & a,Long & b) {
	if (a.len<b.len) return true;
	if (a.len>b.len) return false;
	for(int i=a.len;i>=0;--i) {
		if (a[i]<b[i]) return true;
		if (a[i]>b[i]) return false;
	}
	return false;
}

bool operator <= (Long & a,Long & b) {
	if (a.len<b.len) return true;
	if (a.len>b.len) return false;
	for(int i=a.len;i>=0;--i) {
		if (a[i]<b[i]) return true;
		if (a[i]>b[i]) return false;
	}
	return true;
}

bool operator == (Long & a,Long & b) {
	if (a.len<b.len) return false;
	if (a.len>b.len) return false;
	for(int i=a.len;i>=0;--i) {
		if (a[i]<b[i]) return false;
		if (a[i]>b[i]) return false;
	}
	return true;
}

Long one;

Long sqrt(Long & a) {
	Long l,r=a+one;
	while(one+l<r) {
		Long m=(l+r)/2;
		if (m*m<=a) l=m;
		else r=m;
	}
	return l;
}

long long mem[102];

long long solve() {
	Long a,b;
	int l1=a.read(),l2=b.read();
	Long s1=sqrt(a-1),s2=sqrt(b);
	long long ret=0;
	s2.output(str); ret=find(strlen(str));
//	cout << str << endl;
	for(int i=strlen(str)-1;i>=0;--i)
		ret+=mem[i];
	s1.output(str);
	if (strlen(str)!=1||str[0]!='0') {
		ret-=find(strlen(str));
		for(int i=strlen(str)-1;i>=0;--i)
			ret-=mem[i];
	}
//	cout << str << endl;
	return ret;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
/*	for(int i=1;i<=10000000;++i)
		if (isPalindrome(i)&&isPalindrome(1LL*i*i)) {
			if (i!=1) cout << 1 << "	" << 1LL*i*i-1 << endl;
			cout << 1 << "	" << 1LL*i*i << endl;
		}*/
	for(int i=0;i<=100;++i)
		str[i]='9';
	for(int i=1;i<=100;++i)
		mem[i]=find(i);
	one[0]=1;
/*	Long a;
	for(int it=0;it<1000;++it) {
		Long b=sqrt(a);
		b.output(str);
		cout << it << "	" << str << endl;
		a=a+one;
	}*/
	int T; scanf("%d",&T);
	for(int test=1;test<=T;++test) {
		printf("Case #%d: %I64d\n",test,solve());
	}
	return 0;
}