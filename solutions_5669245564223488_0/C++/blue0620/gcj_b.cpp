#include <stdio.h> 
#include <stdlib.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>


using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define MOD 1000000007
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
LL gcd(LL a,LL b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	ifstream ifs( "B-small-attempt5.in" );
	//ifstream ifs( "t.in" );
	ofstream ofs( "test.txt" );
	int T;
	ifs>>T;
	vector<long>answer;
	REP(i,T){
		int n;
		ifs>>n;
		vector<PII>tr(n);
		vector<int>sz(n);
		vector<int>a(n);
		REP(i,n){
			string temp;
			ifs>>temp;
			int t1=(unsigned int)(temp[0]-'a');
			int t2=(unsigned int)(temp[SZ(temp)-1]-'a');
			tr[i]=MP(t1,t2);
			sz[i]=SZ(temp);
			a[i]=i;
		}
		int check[100];
		long res=0;
		do{
			bool c=true,c2=true;
			REP(i,n)check[i]=0;
			REP(i,n-1){
				if(tr[a[i]].second==tr[a[i+1]].first){
					check[a[i]]=1;
					check[a[i+1]]=1;
				}
				
			}
			REP(i,n)if(check[i]==0)c=false;
			if(tr[a[0]].first==tr[a[n-1]].second){
				if(n!=1||(n==1&&sz[a[0]]!=1))c2=false;
			}
			if((n!=1&&c&&c2)||(n==1&&c2))res++;
		}while(next_permutation(a.begin(),a.end()));
		answer.PB(res);
	}
	REP(i,T){
		ofs<<"Case #"<<i+1<<": "<<answer[i]<<endl;
		cout<<"Case #"<<i+1<<": "<<answer[i]<<endl;
	}
	return 0;
}