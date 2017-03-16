#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define FORR(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define FORE(i,n) for(int i=0;i<=(int)(n);++i)
#define MP(X,Y) make_pair(X,Y)
typedef pair<int,int> ipair;
typedef long long int64;
#define MF(X,val) memset(X,val,sizeof(X))
const double eps=1.0e-6;


//const int MAX_N=1000001;
const int MAX_N=51;

char cells[MAX_N][MAX_N];
int masks[MAX_N][MAX_N];

int dx[]={1,-1,1,0,-1,1,0,-1};
int dy[]={0,0,1,1,1,-1,-1,-1};

int dfs(int y,int x,int R,int C){
	int nx,ny;
	int count=1;
	masks[y][x]=true;
	bool flag=true;
	FOR(i,8){
		ny=y+dy[i];
		nx=x+dx[i];
		if(nx>=0&&nx<C&&ny>=0&&ny<R){
			if(cells[ny][nx]=='*'){
				flag=false;
				break;
			}
		}
	}
	if(flag){
		FOR(i,8){
			ny=y+dy[i];
			nx=x+dx[i];
			if(nx>=0&&nx<C&&ny>=0&&ny<R){
				if(!masks[ny][nx])
					count+=dfs(ny,nx,R,C);
			}
		}
	}
	return count;
}

bool draw(int R,int C,int M){
	MF(cells,'*');
	int r,c,t;
	t=R*C-M;
	if(R==1){
		FOR(i,t)cells[0][i]='.';
		return true;
	}else if(C==1){
		FOR(i,t)cells[i][0]='.';
		return true;
	}else if(t==1){
		cells[0][0]='.';
		return true;
	}else if((R==2||C==2)&&t%2==1){
		return false;
	}

	REP(i,2,R+1)REP(j,2,C+1){
		int s=t-i*j;
		if((s<i+j)&&s!=1&&s>=0){			
			if(s<i||s<j){
				FOR(ii,i)FOR(jj,j)cells[ii][jj]='.';
				if(i!=R){
					FOR(ii,s)cells[i][ii]='.';
				}else{
					FOR(ii,s)cells[ii][j]='.';
				}
			}else if(i!=R&&j!=C&&s>3){
				FOR(ii,i)FOR(jj,j)cells[ii][jj]='.';
				int s1,s2;
				s1=j;
				s2=s-s1;
				while(s2<2){
					s1--;
					s2++;
				}
				FOR(ii,s1)cells[i][ii]='.';
				FOR(ii,s2)cells[ii][j]='.';
			}else{
				continue;
			}	
			return true;
		}
	}

	return false;
}

int main(int argc,char** argv){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int TC;
	cin>>TC;
	int R,C,M;
	int row,col;
	REP(tc,1,TC+1){
		cin>>R>>C>>M;
		MF(masks,false);
		MF(cells,'*');		
		bool flag=draw(R,C,M);
		//if(!flag){
		//	cout<<R<<" "<<C<<" "<<M<<endl;
		//}
		printf("Case #%d:\n",tc);
		if(flag){
			cells[0][0]='c';
			FOR(i,R){
				FOR(j,C)cout<<cells[i][j];
				cout<<endl;
			}
		}else{
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}