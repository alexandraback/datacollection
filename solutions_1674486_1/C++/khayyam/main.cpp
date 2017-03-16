#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define LL __int64
#define MIN(a,b) (((a)<(b))?(a):(b))
int M[1001][11];
int C[3][1002][1002];
int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		int N;
		cin>>N;
		memset(C,0,sizeof(C));
		for(int i=1;i<=N;++i){
			cin>>M[i][0];
			for(int j=1;j<=M[i][0];++j){
				cin>>M[i][j];
				C[1][i][M[i][j]]=1;
				C[2][i][M[i][j]]=1;
			}
		}
		int prev=0;
		int current=1;
		bool found=false;
		for(int len=2;(len<=N) && (!found);++len){
			prev=1-prev;
			current=1-current;
			for(int i=1;(i<=N) && (!found);++i){
				for(int j=1;(j<=N) && (!found);++j)if(i!=j){
					int cnt=0;
					for(int k=1;k<=M[i][0];++k){
						int mid=M[i][k];
						if(C[prev][mid][j]>0){
							++cnt;
						}
					}
					C[current][i][j]=cnt;
					C[2][i][j]+=cnt;
					if(C[2][i][j]>1){
						found=true;
					}
				}
			}
		}
		if(found){
			printf("Case #%d: Yes\n",c);
		}else{
			printf("Case #%d: No\n",c);
		}
	}

	return 0;
}

