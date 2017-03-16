#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>


using namespace std;

const int inf = 1000*1000*1000;

char a[64][64];
string solveOne(int r,int c, int m){
	if(r == 1){
		for(int i=0; i<m; i++){
			a[0][i] = '*';
		}
	}else{
		for(int i=0; i<m; i++){
			a[i][0] = '*';
		}
	}
	a[r-1][c-1] = 'c';
	string ans = "";
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			ans+=a[i][j];
		}
		ans+='\n';
	}
	return ans;
}
string solveTwo(int r,int c, int m){
	if(m%2 == 1 || r*c-4<m){
		return "Impossible\n";
	}
	if(r==2){
		for(int i=0; i<m/2; i++){
			a[0][i] = '*';
			a[1][i] = '*';
		}
	}else{
		for(int i=0; i<m/2; i++){
			a[i][0] = '*';
			a[i][1] = '*';
		}
	}
	a[r-1][c-1] = 'c';
	string ans = "";
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			ans+=a[i][j];
		}
		ans+='\n';
	}
	return ans;
}
string solveAlmost(int r,int c,int m){
	memset(a,'*',sizeof(a));
	a[r-1][c-1] = 'c';
	string ans = "";
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			ans+=a[i][j];
		}
		ans+='\n';
	}
	return ans;
}

string solve(){
	int r,c,m;
	cin>>r>>c>>m;
	memset(a,'.',sizeof(a));
	if(r*c-1 == m) return solveAlmost(r,c,m);
	if(r == 1 || c == 1) return solveOne(r,c,m);
	if(r == 2 || c == 2) return solveTwo(r,c,m);
	int w=r-2,h=c-2;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			if(m>0){
				a[i][j]='*';
				m--;
			}
		}
	}
	if(m>0){
		if(m%2){
			m++;
			a[w-1][h-1] = '.';
			if(m>2*(w+h-2))	return "Impossible\n";
			for(int i=0; i<h-1; i++){
				if(m>0){
					a[r-2][i]='*';
					a[r-1][i]='*';
					m-=2;
				}
			}
			for(int i=0; i<w-1; i++){
				if(m>0){
					a[i][c-1]='*';
					a[i][c-2]='*';
					m-=2;
				}
			}
		}else{
			if(m>2*(w+h))	return "Impossible\n";
			for(int i=0; i<h; i++){
				if(m>0){
					a[r-2][i]='*';
					a[r-1][i]='*';
					m-=2;
				}
			}
			for(int i=0; i<w; i++){
				if(m>0){
					a[i][c-1]='*';
					a[i][c-2]='*';
					m-=2;
				}
			}
		}
	}
	a[r-1][c-1] = 'c';
	string ans = "";
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			ans+=a[i][j];
		}
		ans+='\n';
	}
	return ans;
}


int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		cout.setf(ios::fixed);
		cout.precision(7);
		cout<<"Case #"<<i<<":"<<endl<<solve()<<endl;
	}
	cout.flush();
    return 0;
}