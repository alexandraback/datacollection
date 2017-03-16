#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(__typeof((X).begin()) it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)x.size())

using namespace std;

struct timer{
	time_t start;
	timer(){start=clock();}
	~timer(){cerr<<1.*(clock()-start)/CLOCKS_PER_SEC<<" secs"<<endl;}
};

typedef istringstream iss;
typedef long long ll;
typedef pair<int,int> pi;
typedef stringstream sst;
typedef vector<int> vi;

int N,X,Y;
double nCr[2010][2010];

#pragma comment(lib,"mpir.lib")
#include <mpir.h>

int main(){
	int T;
	cin>>T;
	
	
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		//
		
		cin>>N>>X>>Y;
		if(X<0)X*=-1;
		
		int sum=0,group=0;
		while(1){
			if(sum + group*2+1 > N)break;
			sum += group*2+1;
			group += 2;
		}
		int rest=N-sum;
		//cerr<<sum<<" "<<group<<" "<<rest<<endl;
		if(X+Y < group)cout<<1<<endl;
		else if(X+Y > group)cout<<0<<endl;
		else{
			if(X==0)cout<<0<<endl;
			else if(rest >= group + Y+1)cout<<1<<endl;
			else{
				//cerr<<"? "<<group<<" "<<rest<<endl;
				mpf_t x;
				mpf_init2(x,20);
				rep2(i,Y+1,rest+1){
					mpf_t y;
					mpf_init2(y,20);
					mpf_set_d(y,1);
					
					rep(j,i){
						//cerr<<"* "<<rest-j<<" / "<<j+1<<endl;
						mpf_mul_ui(y,y,rest-j);
						mpf_div_ui(y,y,j+1);
					}
					
					mpf_add(x,x,y);
					
					mpf_clear(y);
				}
				
				mpf_t z;
				mpf_init2(z,20);
				mpf_set_d(z,1);
				
				rep(i,rest)mpf_mul_ui(z,z,2);
				mpf_div(x,x,z);
				
				cout<<setprecision(16)<<x<<endl;
				mpf_clear(x);
			}
		}
		
		
		//
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
