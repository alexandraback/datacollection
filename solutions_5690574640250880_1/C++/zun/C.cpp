#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int R,C,M,R_,C_;

char A[55][55];
int B[55][55];

int compute(int x, int y) {
	int count=0;
	for(int i=x-1; i<x+2; i++) {
		for(int j=y-1; j<y+2; j++) {
			if(A[i][j]=='*') {
				count++;
			}
		}
	}
	return count;
}

bool check(){
	int r=-1,c=-1,count=0;
	int r1,c1;
	for(int i=1; i<=R; i++) {
	  for( int j=1; j<=C; j++) {
		  if(A[i][j]=='.') {
			  count++;
				r1=i;
				c1=j;
			  B[i][j] = compute(i,j);
				if(B[i][j]==0) {
				  r=i;
					c=j;
				}
			}
		}
	}
	//cout<<B[1][1]<<endl;
	//cout<<r<<c<<endl;
	if(r==-1 && c==-1) {
	  r=r1;
		c=c1;
	}
	bool visited[55][55];
	for( int i=0; i<=R; i++) {
	  for( int j=0; j<=C; j++) {
		  visited[i][j]=false;
		}
	}
	visited[r][c] = true;
	pair<int, int> temp = make_pair(r,c);
	A[r][c]='c';
	queue<pair<int, int> > bfs;
	bfs.push(temp);
	while(!bfs.empty()) {
		count--;
	  temp = bfs.front();
		int a = temp.first;
		int b = temp.second;
		if(B[a][b]==0) {
		  //cout<<0<<endl;
			for( int i=a-1; i<a+2; i++) {
				for( int j=b-1; j<b+2; j++) {
				  if(!visited[i][j] && i>0 && j>0&& i<=R && j<=C) {
					  visited[i][j] = true;
						temp = make_pair(i,j);
						bfs.push(temp);
					}
				}
			}
		}
		bfs.pop();
	}
	//cout<<count<<endl;
	if(count==0) {
		return true;
	}
	A[r][c]='.';
	return false;
}

int main() {
  ifstream fin("C.in");
	ofstream fout("C.out");
	int t;
	fin>>t;
	for( int p=1; p<=t; p++) {
		fout<<"Case #"<<p<<":"<<endl;
		fin>>R>>C>>M;
		R_ = R;
		C_ = C;
		for(int i=0; i<=R+1; i++) {
		  for(int j=0; j<=C+1; j++) {
			  B[i][j] = 0;
				A[i][j] = '.';
			}
		}
		int maxi = min(R_,C_);
		while(M>=maxi) {
			if(R_>C_) {
			  R_;
				for(int i=1; i<=C_; i++) {
				  A[R_][i] = '*';
					B[R_][i] = -1;
				}
				R_--;
			}
			else {
				for(int i=1; i<=R_; i++) {
				  A[i][C_] = '*';
					B[i][C_] = -1;
				}
				C_--;
			}
			M-=maxi;
			maxi = min(R_,C_);
		}
		int M_ = M==maxi-1? M-1 : M;
		//cout<<M_<<endl;
		if(R_>C_) {
			for(int i=C_; i>C_-M_; i--) {
				A[R_][i] = '*';
				B[R_][i] = -1;
			}
			R_--;
		}
		else {
			for(int i=R_; i>R_-M_; i--) {
				A[i][C_] = '*';
				B[i][C_] = -1;
			}
			C_--;
		}
		if(M!=maxi-1 || M==0) {
			for(int m=1; m<=R; m++) {
				for( int n=1; n<=C; n++) {
			//		cout<<A[m][n];
				}
				//cout<<endl;
			}
		  if(check()) {
				for(int i=1; i<=R; i++) {
				  for( int j=1; j<=C; j++) {
						if(B[i][j]==0) {
							i=R;
							break;
						}
					}
				}
				for(int i=1; i<=R; i++) {
				  for( int j=1; j<=C; j++) {
					  fout<<A[i][j];
					}
					fout<<endl;
				}
			}
			else fout<<"Impossible"<<endl;
		}
		else {
			bool flag = true; 
		  for(int i=1; i<=R_; i++) {
			  for( int j=1; j<=C_; j++) {
				  if(A[i][j]=='.') {
						//cout<<0<<endl;
					  A[i][j]='*';
						B[i][j]=-1;
					/*	for(int m=1; m<=R; m++) {
							for( int n=1; n<=C; n++) {
								cout<<A[m][n];
							}
							cout<<endl;
						}*/
						if(check()) {
							for(int m=1; m<=R; m++) {
								for( int n=1; n<=C; n++) {
									if(B[m][n]==0) {
										m=R;
										break;
									}
								}
							}
							flag=false;
								i=R_;
								for(int m=1; m<=R; m++) {
									for( int n=1; n<=C; n++) {
										fout<<A[m][n];
									}
									fout<<endl;
								}
							break;
						}
						A[i][j]='.';
						B[i][j]=0;
					}
				}
			}
			if(flag) {
				fout<<"Impossible"<<endl;
			}
		}
	}
}	