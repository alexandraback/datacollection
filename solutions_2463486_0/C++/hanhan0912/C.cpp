/* hanhanw v1.1 */
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
// for Online Judge or Contests
#define MSET(x,y) memset(x,y,sizeof(x))
#define REP(x,y,z) for(int x=y; x<=z; x++)
#define FORD(x,y,z) for(int x=y; x>=z; x--)
#define FLST(x,y,z) for(int x=y; x; x=z[x])
#define SZ size
#define PB push_back

using namespace std;
//
typedef long long LL;
typedef unsigned long long uLL;
typedef long double LD;
// start here OAO~

const int size = 10000;
const int BN_AZ=300;
struct BigNum{
	int len, x[BN_AZ];
	
	void print(){
		printf("%d", x[len-1]);
		FORD(i,len-2,0)
			printf("%04d", x[i]);
	}
	
	void reset(){
		len = 1;
		MSET(x,0);
	}
	
	void clear_trash(){
		while (len>1 && !x[len-1])
			len--;
	}
	string str(){
		string s = "";
		REP(i,0,len-1){
			int tmp=x[i];
			char s2[2];
			s2[1]=0;
			REP(j,1,4){
				s2[0]= (tmp%10+'0');
				s = s + string(s2);
				tmp /= 10;
				if (!tmp && i == len-1)
					break;
			}
		}
		reverse(s.begin(), s.end());
		return s;
	}
	void str_change(char s[]){
		reset();
		len = strlen(s) / 4;
		int remain = strlen(s)%4, j=0;
		if (remain) len++;
		else remain = 4;
		REP(i,0,remain-1)
			x[len-1] = x[len-1]*10 + s[i]-'0';
		FORD(i,len-2,0){
			sscanf(s+remain+j, "%04d", &x[i]);
			j+=4;
		}
		clear_trash();
	}
	void int_change(long long num){
		reset();
		if (num==0) return;
		len = 0;
		while (num){
			x[len++] = num%size;
			num /= size;
		}
	}
	
	bool operator > (BigNum ag){
		if (len != ag.len) return len > ag.len;
		FORD(i,len-1,0)
			if (x[i] != ag.x[i])
				return x[i] > ag.x[i];
		return false;
	}
	bool operator < (BigNum ag){
		if (len != ag.len) return len < ag.len;
		FORD(i,len-1,0)
			if (x[i] != ag.x[i])
				return x[i] < ag.x[i];
		return false;
	}
	bool operator == (BigNum ag){
		if (len != ag.len) return false;
		REP(i,0,len-1)
			if (x[i] != ag.x[i])
				return false;
		return true;
	}
	bool operator != (BigNum ag){
		return !(*this==ag);
	}
	bool operator >= (BigNum ag){
		return !(*this<ag);
	}
	bool operator <= (BigNum ag){
		return !(*this>ag);
	}
	
	BigNum (){ reset(); }
	BigNum (int num){ int_change(num); }
	BigNum (char s[]){ str_change(s); }
	
	BigNum operator + (BigNum ag){
		BigNum ans;
		ans.reset();
		int l = std::max(ag.len,len);
		REP(i,0,l-1){
			ans.x[i] += x[i] + ag.x[i];
			if (ans.x[i] >= size){
				ans.x[i+1]++;
				ans.x[i] -= size;
			}
		}
		if (ans.x[l]) l++;
		ans.len = l;
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator - (BigNum ag){
		BigNum ans;
		ans.reset();
		int l = std::max(ag.len, len);
		REP(i,0,l-1){
			ans.x[i] += x[i] - ag.x[i];
			if (ans.x[i] < 0){
				ans.x[i] += size;
				ans.x[i+1]--;
			}
		}
		ans.len = l;
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator * (BigNum ag){
		BigNum ans;
		ans.reset();
		REP(i,0,len-1){
			REP(j,0,ag.len-1){
				int l = i+j;
				ans.x[l] += x[i] * ag.x[j];
				while (ans.x[l] >= size){
					ans.x[l+1] += ans.x[l] / size;
					ans.x[l++] %= size;
				}
			}
		}
		ans.len = len+ag.len+1;
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator / (BigNum ag2){
		int l,r,m;
		BigNum ag1=*this, ans, tmp, minus;
		ans.len = ag1.len;
		FORD(i,ag1.len-1,0){
			l = 0;
			r = size;
			while (l < r){
				m = (l + r) / 2;
				tmp=ag2*BigNum(m);
				minus.reset();
				REP(j,0,tmp.len-1)
					minus.x[i+j] = tmp.x[j];	
				minus.len = tmp.len + i;
				if (minus <= ag1)
					l = m + 1;
				else
					r = m;
			}
			tmp=ag2*BigNum(ans.x[i]=l-1);
			minus.reset();
			REP(j,0,tmp.len-1)
				minus.x[i+j] = tmp.x[j];	
			minus.len = tmp.len+i-1;
			ag1 = ag1-minus;
		}
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator % (BigNum ag){
		return *this-*this/ag*ag;
	}
}x[2],tmp;

char s1[300], s2[300];
char s[300];

void all_output(){
	int ssss[100];
	int id=1;
	REP(i,1,1000000){
		LL v = i;
		int ns=0;
		while (v){
			ssss[ns++] = v%10;
			v /= 10;
		}
		int sign=1;
		REP(j,0,ns-1){
			if (ssss[j] != ssss[ns-j-1]){
				sign=0;
				break;
			}
		}
		if (!sign)
			continue;
		v = (LL)i*i;
		ns=0;
		while (v){
			ssss[ns++] = v%10;
			v /= 10;
		}
		sign=1;
		REP(j,0,ns-1){
			if (ssss[j] != ssss[ns-j-1]){
				sign=0;
				break;
			}
		}
		if (sign)
			printf("#%d: %d %I64d\n", id++, i, (LL)i*i);
	}
}

int dfs(int cur, int n, int id){
	int res=0;
	if (cur >= n){
		s[cur]=0;
		REP(i,0,cur-1)
			s[i+cur] = s[cur-1-i];
		s[2*cur] = 0;
		tmp = BigNum(s);
		tmp = tmp * tmp;
		if (tmp <= x[id]){
			string ss = tmp.str();
			int sign=1;
			REP(i,0,(int)ss.length()-1){
				if (ss[i] != ss[ss.length()-1-i]){
					sign=0;
					break;
				}
			}
			if (sign){
				//BigNum(s).print(); putchar(' '); tmp.print();puts("");
				res++;
			}
		}
		REP(i,0,cur-2)
			s[i+cur] = s[cur-2-i];
		s[cur*2-1]=0;
		tmp = BigNum(s);
		tmp = tmp * tmp;
		if (tmp <= x[id]){
			string ss = tmp.str();
			int sign=1;
			REP(i,0,(int)ss.length()-1){
				if (ss[i] != ss[ss.length()-1-i]){
					sign=0;
					break;
				}
			}
			if (sign){
				//BigNum(s).print(); putchar(' '); tmp.print();puts("");
				res++;
			}
		}
		return res;
	}
	int re;
	if (cur){
		s[cur]='0';
		re = dfs(cur+1,n,id);
		res += re;
		if (!re)
			return res;
	}
	s[cur]='1';
	re = dfs(cur+1,n,id);
	res += re;
	if (!re)
		return res;
	if (cur == n-1 || cur == 0){
		s[cur]='2';
		re = dfs(cur+1,n,id);
		res += re;
		if (!re)
			return res;
	}
	return res;
}

int solve(int id, int len){
	int ans=0;
//	puts("start");
	REP(i,1,len){
		REP(j,0,len-1)
			s[j] = '1';
		s[i]=0;
		tmp = BigNum(s);
		tmp = tmp * tmp;
		//printf("#%d: ", i);
		//tmp.print();
		//puts("");
		if (tmp > x[id])
			break;
		ans += dfs(0,i,id);
	}
	s[0]='9';
	s[1]=0;
	tmp = BigNum(s);
	if (tmp <= x[id]){
//		BigNum(s).print ); putchar(' '); tmp.print();puts("");
		ans++;
	}
//	puts("end");
	return ans;
}

int main(){
//	all_output();
//	double time1=clock();
//	freopen("C.in", "r",stdin);
	int nT; scanf("%d", &nT);
	REP(i,1,nT){
		scanf("%s %s", s1,s2); 
		x[0] = BigNum(s1)-BigNum(1);
		x[1] = BigNum(s2);
		int len1=strlen(s1);
		int len2=strlen(s2);
//		printf ("%d %d\n", solve(1,len2), solve(0,len1));
		printf("Case #%d: %d\n", i, solve(1,len2) - solve(0,len1)); 
	}
//	printf("%lf\n", (clock()-time1)/1000.0);
	
	return 0;
}

