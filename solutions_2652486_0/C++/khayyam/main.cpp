#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
int cnt3[6][6][6];
int cnt2[6][6];
int cnt1[6];
int main(int argc, char *argv[]){
	int T;
	cin>>T;
	int R,N,M,K;
	cin>>R>>N>>M>>K;
	printf("Case #%d:\n",1);
	for(int r=0;r<R;++r){
		if(N==3){
			memset(cnt3, 0, sizeof(cnt3));
		}
		if(N==2){
			memset(cnt2, 0, sizeof(cnt2));
		}
		if(N==1){
			memset(cnt1, 0, sizeof(cnt1));
		}
		
		for(int i=0;i<K;++i){
			int k;
			cin>>k;
			if(k==1){
				continue;
			}
			if(N==1){
				cnt1[k]++;
			}
			if(N==2){
				int A[2];
				int B[2];
				for(A[0]=2;A[0]<=M;++A[0]){
					if(k==A[0]){
						B[0]=A[0];
						for(A[1]=2;A[1]<=M;++A[1]){
							B[1]=A[1];
							sort(B, B+2);
							cnt2[B[0]][B[1]]++;
						}
					}
					for(A[1]=2;A[1]<=M;++A[1]){
						B[0]=A[0];
						B[1]=A[1];
						int prod=A[0]*A[1];
						if(prod==k){
							sort(B,B+3);
							cnt2[B[0]][B[1]]++;
						}
					}
				}
			}
			if(N>=3){
				int A[3];
				int B[3];
				for(A[0]=2;A[0]<=M;++A[0]){
					if(A[0]==k){
						for(A[1]=2;A[1]<=M;++A[1]){
							for(A[2]=2;A[2]<=M;++A[2]){
								B[0]=A[0];
								B[1]=A[1];
								B[2]=A[2];
								sort(B,B+3);
								cnt3[B[0]][B[1]][B[2]]++;
							}
						}
					}
					for(A[1]=2;A[1]<=M;++A[1]){
						if(A[0]*A[1]==k){
							for(A[2]=2;A[2]<=M;++A[2]){
								B[0]=A[0];
								B[1]=A[1];
								B[2]=A[2];
								sort(B,B+3);
								cnt3[B[0]][B[1]][B[2]]+=2;
							}
						}
						for(A[2]=2;A[2]<=M;++A[2]){
							B[0]=A[0];
							B[1]=A[1];
							B[2]=A[2];
							int prod=A[0]*A[1]*A[2];
							if(prod==k){
								sort(B,B+3);
								cnt3[B[0]][B[1]][B[2]]+=4;
							}
						}
					}
				}
			}
		}
		if(N==1){
				int best=-1;
				int ibest=-1;
				for(int i=2;i<M;++i){
					if(cnt1[i]>best){
						best=cnt1[i];
						ibest=i;
					}
				}
				printf("%d\n",ibest);
			}
			if(N==2){
				int best=-1;
				int ibest[2]={-1,-1};
				for(int i=2;i<=M;++i){
					for(int j=i;j<=M;++j){
						if(cnt2[i][j]>best){
							best=cnt2[i][j];
							ibest[0]=i;
							ibest[1]=j;
						}
					}
				}
				printf("%d%d\n",ibest[0], ibest[1]);
			}
			if(N==3){
				int best=-1;
				int ibest[3]={-1,-1,-1};
				for(int a=2;a<=M;++a){
					for(int b=2;b<=M;++b){
						for(int c=2;c<=M;++c){
							if(cnt3[a][b][c]>best){
								best=cnt3[a][b][c];
								ibest[0]=a;
								ibest[1]=b;
								ibest[2]=c;
							}
						}
					}
				}
				printf("%d%d%d\n",ibest[0], ibest[1], ibest[2]);
			}
	}
	
	return 0;
}

