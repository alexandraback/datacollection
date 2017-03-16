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

const int L = 500;
const double eps = 1e-6;

const int size = 10000;
const int BN_AZ=500;
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
};//ans,l,r,m,t,x,tmp;

double x,t,tmp;
char s[L];

void solve(int T){
	//scanf("%s", s); x=BigNum(s);
	//scanf("%s", s); t=BigNum(s);
	scanf("%lf", &x); scanf("%lf", &t);

//	s[0] = '1'; REP(i,1,18) s[i] = '0'; s[19]=0;
	LL l = 0, r=1000000000000000000ll;
//	x.print(); puts("");
	while (l < r){
		double m = (double)((l + r) / 2);
		tmp = 2.0 * m * x + 2.0*m*m - m;
//		l.print(); putchar(' '); r.print(); putchar(' ');
//		tmp.print(); puts("");
		if (fabs(tmp - t) <= eps)
			l = r = (LL)m + 1;
		else if (tmp < t)
			l = (LL)m + 1;
		else 
			r = (LL)m;
	}
	printf("Case #%d: %I64d\n", T,l-1);
}

int main(){
	int nT; scanf("%d", &nT);
	REP(T,1,nT) solve(T);
	
	return 0;
}

