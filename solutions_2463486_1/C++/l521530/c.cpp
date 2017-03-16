
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define N 120
typedef long long int LL;

using namespace std;

struct INT{
	int s[N];
	INT(){
		memset(s,0,sizeof(s));
	}
	int digit(){
		int t=0;
		for(int i=0; i<N; i++){
			if(1<=s[i] && s[i]<=9)t=i+1;
		}
		return t;
	}

	void input(){
		char c[N];
		scanf("%s",c);
		int l=strlen(c);
		reverse(c,c+l);
		for(int i=0; i<l; i++)s[i]=c[i]-'0';
	}
	void print(){
		int l=digit();
		if(l==0) printf("0\n");
		else{
			for(int i=l-1; i>=0; i--){
				printf("%d",s[i]);
			}
			printf("\n");
		}
	}
	
	void adjust(){
		int r=0;
		for(int i=0;i<N;i++){
			s[i] += r;
			if(s[i]>=10){
				r = s[i]/10;
			}
			else if(s[i]<0){
				r = -(-s[i]+9)/10;
			}
			else{
				r = 0;
			}
			s[i] -= r*10;
		}
	}
	bool operator==(const INT& b)const{
		for(int i=0;i<N;i++)if(s[i]!=b.s[i])return false;
		return true;
	}
	bool operator<(const INT& b)const{
		for(int i=N-1;i>=0;i--){
			if(s[i]<b.s[i])return true;
			if(s[i]>b.s[i])return false;
		}
		return false;
	}
	bool operator<=(const INT& b)const{
		return *this<b || *this==b;
	}
	INT operator+(const INT& b)const{
		INT ans;
		for(int i=0; i<N; i++)
			ans.s[i] = s[i] + b.s[i];
		ans.adjust();
		return ans;
	}
	INT operator-(const INT& b)const{
		INT ans;
		for(int i=0; i<N; i++)
			ans.s[i] = s[i] - b.s[i];
		ans.adjust();
		return ans;
	}
	INT square()const{
		INT ans;
		for(int i=0;i<N;i++){
			for(int j=0;j<=i;j++){
				ans.s[i] += s[j]*s[i-j];
			}
		}
		ans.adjust();
		return ans;
	}
	INT sqrt()const{
		INT ans;
		for(int i=N/2-5; i>=0; i--){
			for(int j=1;j<=9;j++){
				ans.s[i]=j;
				if(ans.square()<=*this) continue;
				ans.s[i]=j-1;
				break;
			}
		}
		ans.adjust();
		return ans;
	}
};

LL C(LL n,LL k){
	LL ans=1;
	for(int i=0;i<k;i++){
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}

LL Csum(int l,int k){//C(l,0)+..C(l,k)
	LL ans=0;
	k=min(l,k);
	for(int i=0; i<=k; i++){
		ans+=C(l,i);
	}
	return ans;
}

LL partial(INT com, INT b, int st,int ed, int l, int k){
	//printf("partial (%d,%d) l=%d,k=%d ",st,ed,l,k);
	//com.print(); b.print();puts("");
	if(!(com<=b)) return 0;
	if(k==0){
		return 1;
	}
	
	int th=l-1;
	LL ans=1;
	for(int i=st; i<=ed; i++){
		com.s[i] = com.s[th-i] = 2;
		if(com<=b){
			ans+=Csum(ed-i, k-1);	
		}
		else{
			com.s[i] = com.s[th-i] = 1;
			ans += partial(com, b, i+1, ed, l, k-1);
			break;
		}
		com.s[i] = com.s[th-i] = 0;
	}
	return ans;
}

LL sum22(INT b){
	int l = b.digit();
	LL ans=0;
	for(int i=2; i<l; i++){
		ans+=1;
		if(i&1)ans+=1;
	}
	INT com;
	int th = l-1;
	com.s[0] = com.s[th] = 2;
	
	if(com<=b) ans++;
	if(l&1){
		com.s[th/2] = 1; //2...1...2
		if(com<=b) ans++;
	}
	//printf("sum22 = %lld\n",ans);
	return ans;
}

LL sum2(INT b){
	int l = b.digit();
	LL ans=1;//2
	for(int i=3; i<l; i+=2){
		ans+= i/2;
	}
	if(l&1){
		INT com;
		int th=l-1;
		com.s[0] = com.s[th] = 1;//1...2...1
		com.s[th/2] = 2;
		if(com<=b) ans++;
		for(int i=1; i<th/2; i++){
			com.s[i] = com.s[th-i] = 1;
			if(com<=b) ans++;
			com.s[i] = com.s[th-i] = 0;
		}
	}
	//printf("sum2 = %lld\n", ans);
	return ans;
}


LL sum11(INT b){
	int l = b.digit();
	LL ans=0;
	for(int i=2; i<l; i++){
		ans+=Csum((i-2)/2,3);
		//cout << "add " << Csum((i-2)/2,3) << endl;
	}
	INT com;
	int th = l-1;
	com.s[0] = com.s[th] = 1;
	ans+=partial(com, b, 1, l/2-1, l, 3);
	//printf("sum11 = %lld\n", ans);
	return ans;
}

LL sum1(INT b){
	int l = b.digit();
	LL ans=1;//1
	for(int i=3; i<l; i+=2){
		ans+=Csum((i-3)/2,3);
		//cout << "add " << Csum((i-3)/2,3) << endl;
	}
	if(l&1){
		INT com;
		int th = l-1;
		com.s[0] = com.s[th] = 1;
		com.s[th/2] = 1;
		ans+=partial(com, b, 1, th/2-1, l, 3);
	}
	//printf("sum1 = %lld\n",ans);
	return ans;
}

LL sum(INT a){
	INT b=a.sqrt();
	int l = b.digit();
	//printf("sqrt = "); b.print();

	if(l<=1){
		return min(b.s[0],3);
	}
	return sum22(b) + sum2(b) + sum11(b) + sum1(b) + 1;
}

void go(){
	INT a,b;
	a.input();
	b.input();
	INT n1;
	n1.s[0]=1;
	a = a-n1;
	//printf("%lld , %lld\n",sum(b), sum(a));
	static int i=0;
	printf("Case #%d: %lld\n",++i, sum(b)-sum(a));

}

int main(){

	int zn;
	scanf("%d",&zn);
	while(zn--){
		go();
	}

	return 0;
}
