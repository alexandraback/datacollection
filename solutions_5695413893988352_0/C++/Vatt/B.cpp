// spnauT
//
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int _b=(b),i=(a); i<_b; ++i)
#define ROF(i,b,a) for(int _a=(a),i=(b); i>_a; --i)
#define REP(n) for(int _n=(n); --_n>=0;)
#define _1 first
#define _2 second
#define PB(x) push_back(x)
#define SZ(x) int((x).size())
#define MT(x) (x).empty()
#define ALL(x) (x).begin(), (x).end()
#define MSET(m,v) memset(m,v,sizeof(m))
#define MAX_PQ(T) priority_queue <T>
#define MIN_PQ(T) priority_queue <T,vector<T>,greater<T>>
#define IO() {ios_base::sync_with_stdio(0); cin.tie(0);}
#define nl '\n'
#define cint1(a) int a; cin>>a
#define cint2(a,b) int a,b; cin>>a>>b
#define cint3(a,b,c) int a,b,c; cin>>a>>b>>c
#define MP(a,b) make_pair((a),(b))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI; typedef vector<LL> VL; typedef vector<PII> VP;
template<class A, class B> inline bool mina(A &x, B y) {return(y<x)?(x=y,1):0;}
template<class A, class B> inline bool maxa(A &x, B y) {return(x<y)?(x=y,1):0;}
template<class A, class B> inline A geta(A &x, const B y) {A t=x;x=y;return t;}

#define MAXN (10005)
#define MAXX (1e18)
int co;
char s1[20],s2[20];
int num1[20],num2[20];
int n;
void print_num(LL h) {
	int tmp[20];
	for(int i=0;i<n;i++) {
		tmp[i]=(h%10);
		h/=10;
	}
	for(int i=n-1;i>=0;i--) {
		cout << tmp[i];
	}
}
pair<LL,LL> min_max (int h) {
	LL minn = 0;
	LL maxx = 0;
	for(int i=h;i<n;i++) {
		minn*=10;
		maxx*=10;
		if(num1[i]!=-1) {
			minn+=num1[i];
		}
		if(num2[i]==-1) {
			maxx+=9;
		}
		else {
			maxx+=num2[i];
		}
	}
	return MP(minn,maxx);
}
pair<LL,LL> max_min (int h) {
	LL minn = 0;
	LL maxx = 0;
	for(int i=h;i<n;i++) {
		minn*=10;
		maxx*=10;
		if(num2[i]!=-1) {
			minn+=num2[i];
		}
		if(num1[i]==-1) {
			maxx+=9;
		}
		else {
			maxx+=num1[i];
		}
	}
	return MP(maxx,minn);
}
int main(int argc, char *argv[])
{
	cint1(t);
	while(t--) {
		co++;
		scanf("%s %s",s1,s2);
		n = strlen(s1);
		MSET(num1,0);
		MSET(num2,0);
		for(int i=0;i<n;i++) {
			if(s1[i]=='?') {
				num1[i]=-1;
			}
			else {
				num1[i]=s1[i]-'0';
			}
			if(s2[i]=='?') {
				num2[i]=-1;
			}
			else {
				num2[i]=s2[i]-'0';
			}
		}

		bool ch=0;
		LL tmp = 0;
		for(int i=0;i<n;i++) {
			tmp*=10;
			//printf("%d %d %d\n",i,num1[i],num2[i]);
			if(num1[i]!=num2[i] && num1[i]!=-1 && num2[i]!=-1) {
				ch=1; break;
			}
			else {
				if(num1[i]!=-1) {
					tmp+=num1[i];
				}
				else if(num2[i]!=-1){
					tmp+=num2[i];
				}
			}
		}
		printf("Case #%d: ",co);
		if(!ch) {
			print_num(tmp);
			cout << " ";
			print_num(tmp);
			cout << endl;
			continue;
		}

		pair<LL,pair<LL, LL> > ans = MP(MAXX,MP(0,0));
		LL base = 1;
		LL now =0;
		for(int i=0;i<n-1;i++) {
			base*=10;
		}
		for(int i=0;i<n;i++) {
			if(num1[i]==-1) {
				if(num2[i]==-1) {
					pair<LL, LL> tmp = min_max(i+1);
					ans = min(ans, MP(base+tmp._1-tmp._2,MP(now+base+tmp._1,now+tmp._2)));
					tmp = max_min(i+1);
					ans = min(ans, MP(base+tmp._2-tmp._1,MP(now+tmp._1,now+base+tmp._2)));
				}
				else {
					if(num2[i]!=9) {
						pair<LL, LL> tmp = min_max(i+1);
						ans = min(ans, MP(base+tmp._1-tmp._2,MP(now+base*(num2[i]+1)+tmp._1,now+base*(num2[i])+tmp._2)));
					}
					if(num2[i]!=0) {
						pair<LL, LL> tmp = max_min(i+1);
						ans = min(ans,MP(base+tmp._2-tmp._1,MP(now+base*(num2[i]-1)+tmp._1, now+base*(num2[i])+tmp._2)));
					}
					now+=base*num2[i];
				}
			}
			else {
				if(num2[i]==-1) {
					if(num1[i]!=0) {
						pair<LL, LL> tmp = min_max(i+1);
						ans = min(ans, MP(base+tmp._1-tmp._2,MP(now+base*num1[i]+tmp._1,now+base*(num1[i]-1)+tmp._2)));
					}
					if(num1[i]!=9) {
						pair<LL, LL> tmp = max_min(i+1);
						ans = min(ans, MP(base+tmp._2-tmp._1,MP(now+base*num1[i]+tmp._1,now+base*(num1[i]+1)+tmp._2)));
					}
					now+=base*num1[i];
				}
				else {
					if(num1[i]==num2[i]) {
						now+=base*num1[i];
					}
					else if(num1[i]<num2[i]) {
						pair<LL,LL> tmp = max_min(i+1);
						//cout << "hi " << tmp._1 << " " << tmp._2 << endl;
						ans = min(ans,MP((num2[i]-num1[i])*base+tmp._2-tmp._1,MP(now+num1[i]*base+tmp._1,now+num2[i]*base+tmp._2)));
						break;
					}
					else {
						pair<LL,LL> tmp = min_max(i+1);
						ans = min(ans,MP((num1[i]-num2[i])*base+tmp._1-tmp._2,MP(now+num1[i]*base+tmp._1,now+num2[i]*base+tmp._2)));
						break;
					}
				}
			}
			base/=10;
		}
		print_num(ans._2._1);
		cout << " ";
		print_num(ans._2._2);
		cout << endl;
	}
	return 0;
}
