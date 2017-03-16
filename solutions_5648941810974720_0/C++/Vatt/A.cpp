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


char s[2005];
int n;
int num[50];
int ans[50];
int co;
int main(int argc, char *argv[])
{
	cint1(t);
	while(t--) {
		co++;
		scanf("%s",s);
		n=strlen(s);
		MSET(num,0);
		MSET(ans,0);
		for(int i=0;i<n;i++) {
			num[s[i]-'A']++;
		}
		//0
		while(num['Z'-'A']!=0) {
			ans[0]++;
			num['Z'-'A']--;
			num['E'-'A']--;
			num['R'-'A']--;
			num['O'-'A']--;
		}
		//2
		while(num['W'-'A']!=0) {
			ans[2]++;
			num['T'-'A']--;
			num['W'-'A']--;
			num['O'-'A']--;
		}
		//6
		while(num['X'-'A']!=0) {
			ans[6]++;
			num['S'-'A']--;
			num['I'-'A']--;
			num['X'-'A']--;
		}
		//8
		while(num['G'-'A']!=0) {
			ans[8]++;
			num['E'-'A']--;
			num['I'-'A']--;
			num['G'-'A']--;
			num['H'-'A']--;
			num['T'-'A']--;
		}
		//7
		while(num['S'-'A']!=0) {
			ans[7]++;
			num['S'-'A']--;
			num['E'-'A']--;
			num['V'-'A']--;
			num['E'-'A']--;
			num['N'-'A']--;
		}
		//5
		while(num['V'-'A']!=0) {
			ans[5]++;
			num['F'-'A']--;
			num['I'-'A']--;
			num['V'-'A']--;
			num['E'-'A']--;
		}
		//4
		while(num['F'-'A']!=0) {
			ans[4]++;
			num['F'-'A']--;
			num['O'-'A']--;
			num['U'-'A']--;
			num['R'-'A']--;
		}
		//1
		while(num['O'-'A']!=0) {
			ans[1]++;
			num['O'-'A']--;
			num['N'-'A']--;
			num['E'-'A']--;
		}
		//3
		while(num['H'-'A']!=0) {
			ans[3]++;
			num['T'-'A']--;
			num['H'-'A']--;
			num['R'-'A']--;
			num['E'-'A']--;
			num['E'-'A']--;
		}
		//9
		while(num['N'-'A']!=0) {
			ans[9]++;
			num['N'-'A']--;
			num['I'-'A']--;
			num['N'-'A']--;
			num['E'-'A']--;
		}
		printf("Case #%d: ",co);
		for(int i=0;i<=9;i++) {
			for(int j=0;j<ans[i];j++) {
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
