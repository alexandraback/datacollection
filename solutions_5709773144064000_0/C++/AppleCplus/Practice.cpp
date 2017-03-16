#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
 
using namespace std;
 
#define ll long long
#define pi pair<int,int>
#define pll pair<ll,ll>
#define pii pair<int,pi>
#define X first
#define Y second
#define pb push_back
#define ab(x) ((x)<0?(-(x)):(x))
#define xx(x) ((x)*(x))
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vpi vector<pi>
#define vpll vector<pll>
#define ALL(x) (x).begin(),(x).end()
#define Max (1<<30)
#define LLMax (1ll<<60)
template<class T>string ToString(T t){stringstream s;s<<t;return s.str();}
template<class T>void ToOther(T&t,string a){stringstream s(a);s>>t;}
 

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int CC=0;
	int Test; cin>>Test; while(Test--){
		CC++;
		
		double A,B,C;
		cin>>A>>B>>C;

		double now=0.0;
		double inc=2.0;
		double rst=1e100;

		for(int i=0;i<1000000;i++){
			rst=min( rst , now + C/inc );
			
			
			now+= A/inc;
			inc+=B;
		}



		cout<<"Case #"<<CC<<": ";
		printf("%.9lf\n",rst);

	}
}