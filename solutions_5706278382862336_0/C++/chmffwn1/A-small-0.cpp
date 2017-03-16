#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define ms0(x) memset((x),0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int st[110][110];

int main(){
    ios_base::sync_with_stdio(false);
    freopen("A-small-0.in", "r", stdin);
    freopen("A-small-0.out", "w", stdout);
    int T;
    cin>>T;
    rep(i,0,T){
    	string test;
    	cin>>test;
    	string t1="",t2="";
    	int ok=1;
    	rep(j,0,test.length()){
    		if(test[j]=='/'){ok=0;continue;}
    		if(ok) t1+=test[j];
    		else t2+=test[j];
    	}
    	ll it1;
    	ll it2;
    	istringstream(t1)>>it1;
    	istringstream(t2)>>it2;
    	ll it2l=it2;
    	ll it1l=it1;
    	// cout<<it1<<" "<<t2<<endl;
    	ok=1;
    	int gen=0;
    	ll rmd=0;
    	for(;;){
    		if(it2%(ll)2==0){
    			gen++;
    			it2/=(ll)2;
    		}else if(it2==1){
    			break;
    		}else{
    			rmd=it2;
    			break;
    		}
    	}
    	// cout<<rmd<<" "<<it1<<" ";
    	if(rmd!=0) if((it1%rmd!=0)||it1<rmd) ok=0;
    	if(ok) if(rmd!=0) it1/=rmd;
    	cout<<"Case #"<<i+1<<": ";
    	if(ok){
    		gen=0;
    		double jud=(double)it1l/it2l;
    		double t=(double)1/2;
    		for(;;){
    			gen++;
    			if(t<=jud){
    				break;
    			}
    			t/=2;
    		}
    		cout<<gen<<endl;
    	}else{
    		cout<<"impossible"<<endl;
    	}
    	
    }
	return 0;
}
