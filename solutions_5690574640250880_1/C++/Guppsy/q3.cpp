#include <iostream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;

int main(){

	freopen("q3.txt", "r", stdin);
	freopen("q3.out", "w", stdout);

	int cases;
	cin>>cases;

	for(int i=0;i<cases;i++){
		int r, c, m;
		cin>>r>>c>>m;

		//cout<<"Case #"<<i+1<<": "<<r<<" "<<c<<" "<<m<<" "<<r*c - m<<endl;

		cout<<"Case #"<<i+1<<": "<<endl;

		vector<vector<char>> v(r, vector<char>(c, '*'));

		int sq;
		int free = r*c - m;
		int free_ = free;
		sq = ceil(sqrt((double)free));

		int hor, ver;
		
		if(sq >= c){
			ver = c;
			hor = free/c;
			if(free%c != 0)
				hor++;
		}
		else if(sq >= r){
			hor = r;
			ver = free/r;
			if(free%r != 0)
				ver++;
		}
		else{
			ver = sq;
			hor = sq;
		}

		bool do_ = false;
		if(free == ver*(hor-1)+1 || free == hor*(ver-1)+1)
			do_ = true;

		if(free != r*c){
			/*if (free == 1){
				cout<<"Impossible"<<endl;
				continue;
			}*/

			if((free == 3 || free == 2) && r!=1 && c!=1){
				cout<<"Impossible"<<endl;
				continue;
			}
		}

		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				if(j==0 && k==0){
					v[j][k] = 'c'; free--; continue;
				}
				if(j < hor && k < ver && free > 0){
					if(free == 2 && do_ && m>0 && ver>1 && hor>1 && k==ver-1){
						v[j][k] = '*';
						m--;
						continue;
					}
					v[j][k] = '.';
					free--;
				}
				else{
					v[j][k] = '*';
					m--;
				}
			}
		}

		if(m != 0)
			cout<<"err"<<endl;

		for(int j=0;j<r;j++){
			int sum = 0;
			for(int k=0;k<c;k++){
				if(v[j][k] == '.' || v[j][k] == 'c')
					sum++;
			}

			if(sum == 1 && c>1 && free_ != 1){
				cout<<"Impossible"<<endl;
				goto ext;
			}
		}

		for(int k=0;k<c;k++){
			int sum = 0;
			for(int j=0;j<r;j++){
				if(v[j][k] == '.' || v[j][k] == 'c')
					sum++;
			}

			if(sum == 1 && r>1 && free_ != 1){
				cout<<"Impossible"<<endl;
				goto ext;
			}
		}

		for(int j=0;j<r;j++){
			for(int k=0;k<c;k++){
				cout<<v[j][k];
			}
			cout<<endl;
		}

ext:
		;
	}
	return 0;
}