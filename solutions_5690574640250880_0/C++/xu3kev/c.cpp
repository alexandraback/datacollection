#include<iostream>
#include<stdio.h>
using namespace std;
int r,c;
int m;
int mp[10][10];
int mp2[10][10];
int sx,sy;
int dfs2(int x,int y){
	if(mp2[x][y]!=0)
		return 0;
	mp2[x][y]=1;
	int ct=1;
	if(mp[x][y]==0){
		int i=x;
		int j=y;
		if(i-1>=0&&mp[i-1][j]!=11){
			ct+=dfs2(i-1,j);;
		}
		if(j-1>=0&&mp[i][j-1]!=11){
			ct+=dfs2(i,j-1);;
		}
		if(i+1<r&&mp[i+1][j]!=11){
			ct+=dfs2(i+1,j);;
		}
		if(j+1<c&&mp[i][j+1]!=11){
			ct+=dfs2(i,j+1);;
		}
		if(i-1>=0&&j+1<c&&mp[i-1][j+1]!=11){
			ct+=dfs2(i-1,j+1);;
		}
		if(i+1<r&&j+1<c&&mp[i+1][j+1]!=11){
			ct+=dfs2(i+1,j+1);;
		}
		if(i-1>=0&&j-1>=0&&mp[i-1][j-1]!=11){
			ct+=dfs2(i-1,j-1);;
		}
		if(i+1<r&&j-1>=0&&mp[i+1][j-1]!=11){
			ct+=dfs2(i+1,j-1);;
		}
	}
	return ct;
	
}
bool dfs(int x,int y,int rm){
		if(rm<0)
			return false;
		if(x==r){
			if(rm!=0)
				return false;
			sx=-1;
			sy=-1;
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					if(mp[i][j]<=10){
						int& ct=mp[i][j];
						ct=0;
						if(i-1>=0&&mp[i-1][j]==11){
							++ct;
						}
						if(j-1>=0&&mp[i][j-1]==11){
							++ct;
						}
						if(i+1<r&&mp[i+1][j]==11){
							++ct;
						}
						if(j+1<c&&mp[i][j+1]==11){
							++ct;
						}
						if(i-1>=0&&j+1<c&&mp[i-1][j+1]==11){
							++ct;
						}
						if(i+1<r&&j+1<c&&mp[i+1][j+1]==11){
							++ct;
						}
						if(i-1>=0&&j-1>=0&&mp[i-1][j-1]==11){
							++ct;
						}
						if(i+1<r&&j-1>=0&&mp[i+1][j-1]==11){
							++ct;
						}
						if(ct==0){
							sx=i;
							sy=j;
						}
					}
				}
			}
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					mp2[i][j]=0;
				}
			}
			if(sx<0){
				return false;
			}
			//cout<<dfs2(sx,sy)<<endl;
			int tmp=dfs2(sx,sy);
			//if(dfs2(sx,sy)+m==r*c){
			if(tmp+m==r*c){
				//for(int i=0;i<r;++i){
				//	for(int j=0;j<c;++j){
				//		if(mp[i][j]==11)
				//			printf("*");
				//		else
				//			printf(".");
				//	}
				//	printf("\n");
				//}
				//	printf("\n");
				//	printf("\n");
				//	printf("\n");
				return true;
			}
			else
				return false;
		}
		int px=x;
		int py=y;
		if(y==c-1){
			y=0;
			++x;
		}
		else{
			++y;
		}
		mp[px][py]=11;
		if(dfs(x,y,rm-1)){
			return true;
		}
		mp[px][py]=10;
		if(dfs(x,y,rm)){
			return true;
		}
		return false;
}
int main(){
	int TT;
	cin>>TT;
	for(int T=1;T<=TT;++T){
		cin>>r>>c>>m;

		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
			}
		}

		printf("Case #%d:",T);
		if(r*c-m==1){
			printf("\n");
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					if(i==0&&j==0){
						printf("c");
					}
					else
						printf("*");
				}
				printf("\n");
			}
		}
		else if(dfs(0,0,m)){
			//printf("%d\n",dfs(0,0,m));
				printf("\n");
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					if(i==sx&&j==sy){
						printf("c");
					}
					else if(mp[i][j]==11)
						printf("*");
					else
						printf(".");
				}
				printf("\n");
			}
		}
		else{
				printf("\n");
				printf("Impossible\n");
		}
	}
	return 0;
}
