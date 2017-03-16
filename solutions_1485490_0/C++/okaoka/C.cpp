#define _USE_MATH_DEFINES
#define INF 100000000
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;

static const double EPS = 1e-8;

struct DATA{
	int id;
	ll num;
};

int tx[] = {1,0};
int ty[] = {0,1};

ll gSum = 0;
//
//void dfs(int idx,struct DATA* toy,struct DATA* box,ll tmp,ll sum,int M,int N,int i){
//	for(int j=idx;j<M;j++){
//		if(toy[j].id == box[i].id && tmp >= toy[j].num){
//			dfs(j+1,toy,box,tmp,sum,M,N,i);
//			tmp -= toy[j].num;
//			sum += toy[j].num;
//			idx = j+1;
//			dfs(idx,toy,box,tmp,sum,M,N,i);
//
//		}
//		else if(toy[j].id == box[i].id && tmp < toy[j].num){
//			sum += tmp;
//			idx = j+1;
//			dfs(idx,toy,box,tmp,sum,M,N,i);
//			break;
//		}
//	}
//
//	gSum = max(gSum,sum);
//
//}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		struct DATA box[100];
		struct DATA toy[100];

		int N,M;
		scanf("%d %d",&N,&M);

		for(int i=0;i<N;i++){
			ll a,A;
			scanf("%lld %lld",&a,&A);
			box[i].num = a;
			box[i].id = A;		
		}
		for(int i=0;i<M;i++){
			ll b,B;
			scanf("%lld %lld",&b,&B);
			toy[i].num = b;
			toy[i].id = B;
		}

		ll res = 0;
		struct DATA toytmp[100];
		struct DATA boxtmp[100];
		memcpy(toytmp,toy,sizeof(struct DATA)*M);
		memcpy(boxtmp,box,sizeof(struct DATA)*N);

		for(int S=0;S<=(1<<N)-1;S++){
			memcpy(box,boxtmp,sizeof(struct DATA)*N);
			int idx=0;
			ll sum=0;
			
			gSum = 0;
			memcpy(toy,toytmp,sizeof(struct DATA)*M);
			for(int i=0;i<N;i++){	

				if(S & (1<<i)){
					ll tmp = box[i].num;
					
					//dfs(idx,toy,box,tmp,sum,M,N,i);
					//sum = gSum;

					for(int j=idx;j<M;j++){
						if(toy[j].id == box[i].id && toy[j].num>0 && box[i].num >0){		
							sum += min(box[i].num,toy[j].num);
							ll num = min(box[i].num,toy[j].num);
							toy[j].num -= num;
							box[i].num -= num;
							idx=j;
						}
					}
				}

			}

			res = max(sum,res);
		}

		printf("Case #%d: %lld\n",t+1,res);
	}
}

