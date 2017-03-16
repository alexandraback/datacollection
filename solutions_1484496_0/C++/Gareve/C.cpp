/**
* @author Gareve
*/
#define DEBUGs
#ifndef NDEBUG	
	#define DBG(a) cout<<__LINE__<<": "<<#a<<"= "<<a<<endl;
#else
	#define DBG(a) ;
#endif
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#define foreach(IT,C) for(typeof(C.begin())IT=C.begin();IT!=C.end();IT++)
#define L long long

using namespace std;

int n;
L sum;
L vc[509];
bool dp[2][2000009];

vector<long long> A[2000009],B[2000009];//a is less than B

void print(int y){
	for(int k=0;k<A[y].size();k++){
		if(k > 0)printf(" ");
		printf("%lld",A[y][k]);
	}
	printf("\n");
	for(int k=0;k<B[y].size();k++){
		if(k > 0)printf(" ");
		printf("%lld",B[y][k]);
	}
	printf("\n");
}
void test(int y){
	int sa = 0,sb = 0;
	foreach(it,A[y])sa+=*it;
	foreach(it,B[y])sb+=*it;

	if(!(sb - sa == y)){
		DBG(y);
		assert(false);
	}
}
void resuelva(){	
	scanf("%d",&n);

	sum = 0;
	for(int i=0;i<n;i++){
		scanf("%lld",&vc[i]);
	}

	memset(dp,false,sizeof(dp));

	int now=1,bef=0;
	dp[bef][0] = true;
	int mx = 0,nmx;
	int y;
	for(int i=0;i<n;i++){
		nmx = 0;
		for(int j=0;j<=mx;j++){
			if(dp[bef][j])
				dp[now][j] = true;
		}
		for(int j=0;j<=mx;j++){
			if(dp[bef][j] == false)continue;
			
			//not using anything
			if(dp[now][j] == false){

				dp[now][j] = true;
			}

			//add the biggest
			y = j + vc[i];
			//printf(":: %d %d [%d]\n",i,y,dp[now][y]);
			nmx = max(nmx,y);
			if(dp[now][y] == false){
				
				if(dp[now][y] == false and dp[bef][y] == false){
					A[y] = A[j];
					B[y] = B[j];
					B[y].push_back(vc[i]);
					//test(y);
				}
				//printf("+B[%d] %lld\n",y,vc[i]);
				
				dp[now][y] = true;
			}

			//add to the lowest
			y = j - vc[i];
			if(y > 0){
				if(dp[now][y] == false){
					if(dp[now][y] == false and dp[bef][y] == false){
						A[y] = A[j];
						B[y] = B[j];
						A[y].push_back(vc[i]);
						//test(y);
					}
					dp[now][y] = true;
				}
			}else if(y < 0){
				y = -y;
				if(dp[now][y] == false){
					if(dp[now][y] == false and dp[bef][y] == false){
						A[y] = B[j];
						B[y] = A[j];
						B[y].push_back(vc[i]);
						//test(y);
					}
					dp[now][y] = true;
				}
			}else{
				assert(y == 0);//:P
				//DBG(j);DBG(mx);

				A[y] = A[j];
				B[y] = B[j];

				//print(y);
				A[y].push_back(vc[i]);
				print(y);

				for(int k=0;k<=nmx;k++){
					A[k].clear();
					B[k].clear();
				}
				return;
			}
		}
		mx = nmx;
		swap(now,bef);
	}
	for(int k=0;k<=mx;k++){
		A[k].clear();
		B[k].clear();
	}
	printf("Impossible\n");
}
int main(){
	int nc;
	scanf("%d",&nc);
	for(int i=1;i<=nc;i++){
		printf("Case #%d:\n",i);
		resuelva();
	}
}