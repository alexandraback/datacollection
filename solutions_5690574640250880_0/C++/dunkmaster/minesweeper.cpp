#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int R,C,M;
		cin >> R >> C >> M;
		int empty = R*C - M;
		bool possible = true;
		if(empty==2 || empty==3 || empty==5||empty==7){
			if(R!=1 && C!=1){
				possible = false;
			}
		}
		if(empty%2==1 && empty > 1 && (R==2 || C==2)){
			possible = false;
		}

		cout<<"Case #"<<t+1<<": "<<endl;
		if(!possible){
			cout<<"Impossible"<<endl;
		} else {
			int grid[R][C];
			for(int i=0;i<R;i++)
				for(int j=0;j<C;j++)
					grid[i][j] = 0;

			if(R==1){
				for(int i=0;i<empty;i++){
					grid[0][i] = 1;
				}
			} else if(C==1){
				for(int i=0;i<empty;i++){
					grid[i][0] = 1;
				}
			} else if(empty==4){
				grid[0][0] = 1;
				grid[0][1] = 1;
				grid[1][0] = 1;
				grid[1][1] = 1;
			} else if(R==2){
				for(int i=0;i<empty/2;i++){
					grid[0][i] = 1;
					grid[1][i] = 1;
				}
			} else if(C==2){
				for(int i=0;i<empty/2;i++){
					grid[i][0] = 1;
					grid[i][1] = 1;
				}
			} else {
				int mr = -1;
				int mc = -1;
				int subtract = 99999;
				bool lastrow = false;
				for(int i=3;i<=R;i++){
					for(int j=3;j<=C;j++){
						if(i*j>=empty){
							subtract = i*j - empty;
							if(subtract <= i || subtract <= j){
								mr = i;
								mc = j;
								
								if(subtract <=i){
									lastrow = false;
								} else {
									lastrow = true;
								}
								goto out;
							}
						}
					}
				}
				out:;
				for(int i=0;i<mr;i++){
					for(int j=0;j<mc;j++)
						grid[i][j] = 1;
				}
				if(lastrow){
					for(int i=mc-1,j=0;j<subtract;i--,j++){
						grid[mr-1][i] = 0;
					}
					if(subtract==mc-1){
						grid[mr-1][1] = 1;
						grid[mr-2][mc-1] = 0;
					}
				} else {
					for(int i=mr-1,j=0;j<subtract;i--,j++){
						grid[i][mc-1] = 0;
					}
					if(subtract==mr-1){
						grid[1][mc-1] = 1;
						grid[mr-1][mc-2] = 0;
					}
				}
			}
			grid[0][0] = 2;
			for(int i=0;i<R;i++){
				for(int j=0;j<C;j++){
					if(grid[i][j]==0){
						cout<<"*";
					} else if(grid[i][j]==1){
						cout<<".";
					} else {
						cout<<"c";
					}
				}
				cout<<endl;
			}
		}
	}
}
