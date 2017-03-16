#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <ctime>
using namespace std;

#define pii pair<int,int>
#define MPII make_pair<int,int>
#define PLL pair<lng,lng>
#define MPLL make_pair<lng,lng>
#define PI 3.1415926535897932384626433832795
#define DEG2RAD (PI/180.0)
#define RAD2DEG (1.0/DEG2RAD)
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define forn(i,n) for(int i=0;i<n;++i)
#define fornr(i,n) for(int i=n-1;i>=0;--i)
#define forn1(i,n) for(int i=0;i<n+1;++i)
#define forv(i,v) for(int i=0;i<v.size();++i)
#define forvr(i,v) for(int i=v.size()-1;i>=0;--i)
#define fors(i,s) for(int i=0;i<s.length();++i)
#define EPS 1e-12
#define eps EPS
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)
#define maxll ((1LL<<62)-1+(1LL<<62))
#define SQ(a) ((a)*(a))
#define SWAP(t,a,b) {t ____tmpasdasdasd=(a);(a)=(b);(b)=____tmpasdasdasd;}
#define abs(a) ((a)<0?-(a):(a))
#define ALL(a) (a).begin(),(a).end()


bool isPali(string s) {
	return s == string(s.rbegin(), s.rend());
}

int main(){
	freopen("c:\\jam\\2013\\c1.in","r",stdin);
	freopen("c:\\jam\\2013\\c1.out","w",stdout);

	int tc;
	cin>>tc;
	
	long long all_poli[100];
	int num = 0;

	for (long long i = ceil(sqrt(1)); i <= floor(sqrt(100000000000000)); i++) {
			if (isPali(std::to_string(i)) && isPali(std::to_string(i*i)))  {
				//cout<<i*i<<endl;
				all_poli[num++] = i*i;				
			}
	}

	forn(q,tc){
		long long N, M, ret;
		cin >> N;
		cin >> M;
		ret = 0;

		forn (i, num) {
			if (all_poli[i]>=N && all_poli[i]<=M) 
				ret++;
		}

		cout <<"Case #"<<q+1<<": "<<ret<<endl;		
	}

	return 0;
}
