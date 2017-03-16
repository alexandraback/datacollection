#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <cassert>
#include <iomanip>
using namespace std;
static const double EPS = 1e-9;
static const int mod = 100000007;
typedef long long ll;

string IntToString(int number){
	stringstream ss;
	ss << number;
	return ss.str();
}

void solve(){
	int r,c,m;
	cin>>r>>c>>m;
	//cout<<r<<" "<<c<<" "<<m<<endl;
	char buf[55][55];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			buf[i][j]='*';
		}
	}
	int ten=r*c-m;
	if(ten==0){
		cout<<"Impossible"<<endl;return;
	}
	if(r==1 || c==1){
		int co=0;
		for(int i=0;i<r && co<ten;i++){
			for(int j=0;j<c && co<ten;j++){
				buf[i][j]='.';
				co++;
			}
		}
		buf[0][0]='c';
	}else{
		if(ten==2 || ten==3 || ten==5 || ten==7){
			cout<<"Impossible"<<endl;return;
		}else if(ten==1){
			buf[0][0]='c';
		}else{
			buf[0][0]='c';
			buf[1][0]=buf[0][1]=buf[1][1]='.';
			ten-=4;
			if(r>2 && ten>1){
				buf[2][0]=buf[2][1]='.';
				ten-=2;
			}
			if(c>2 && ten>1){
				buf[0][2]=buf[1][2]='.';
				ten-=2;
			}
			for(int i=3;i<r && ten>1;i++){
				buf[i][0]=buf[i][1]='.';
				ten-=2;
			}
			for(int i=3;i<c && ten>1;i++){
				buf[0][i]=buf[1][i]='.';
				ten-=2;
			}
			if((r==2 || c==2) && ten==1){
				cout<<"Impossible"<<endl;return;
			}
			for(int i=1;i<r && ten>0;i++){
				for(int j=1;j<c && ten>0;j++){
					if(buf[i][j]=='*' && buf[i-1][j]=='.' && buf[i][j-1]=='.'){
						buf[i][j]='.';
						ten--;
					}
				}
			}
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<buf[i][j];
		}
		cout<<endl;
	}
}

int main() {
	// freopen ("input.txt", "r", stdin);
	// freopen ("output.txt", "w", stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cout<<"Case #"+IntToString(i+1)+":"<<endl;
		solve();
	}
}