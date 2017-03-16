#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii > vii;
typedef queue<int> qi;
typedef set<int> si;

#define RE(i,b) for(int i=0; i<(int)(b); i++)
#define REP(i,a,b) for(int i=(a); i<(int)(b); i++)
#define BREP(i,a,b) for(int i=(a)-1; i>=(b); i--)
#define FE(i,X) for(typeof((X).begin()) i=(X).begin(); i!=(X).end(); ++i)

#define INF 1000000000
#define MP make_pair
#define FI first
#define SE second
template<class t> void setmin(t &a, t b){a=min(a,b);}

int Xab[100][100],Xac[100][100],Xbc[100][100];

int main(){
	int TC;scanf("%d ",&TC);
	RE(tc,TC){
		printf("Case #%d: ",tc+1);
		int a,b,c,K;scanf("%d %d %d %d ",&a,&b,&c,&K);
		vector<pair<int,ii> > V,W;
		RE(i,100)RE(j,100){
			Xab[i][j]=0;
			Xac[i][j]=0;
			Xbc[i][j]=0;
		}
		RE(k,c)
		RE(j,b)
		RE(i,a){
			if(Xab[i][j]<K&&Xac[i][k]<K&&Xbc[j][k]<K){
				V.push_back(MP(i,MP(j,k)));
				Xab[i][j]++;
				Xac[i][k]++;
				Xbc[j][k]++;
			}
		}
// 			W.push_back(MP(i,MP(j,k)));
// 		RE(l,W.size()){
// 			pair<int,ii> H=W.size()
// 		int countf=-1;
// 		int i=0,j=0;
// 		RE(k,c){
// 			int countcb=0, countca=0;int same=0;ii B=MP(i,j);
// 			while(1){
// 				while(1){
// 					V.push_back(MP(i,MP(j,k)));
// 					if(i==0&&j==0){
// 						countf++;
// 					}
// 					if(MP(i,j)==B)
// 						same++;
// 					if(countf==K||(same==2&&MP(i,j)==B))
// 						break;
// 					i++;
// 					if(i==a){
// 						i=0;
// 						countca++;
// 						if(countca==K)
// 							break;
// 					}
// 				}
// 				if(countca==K||countf==K||(same==2&&MP(i,j)==B))
// 					break;
// 				j++;
// 				if(j==b){
// 					j=0;
// 					countcb++;
// 				}
// 				if(countcb==K)
// 					break;
// 			}
// 			if(countf==K)
// 				break;
// 		}
		
// 		RE(k,min(c,K)){
// 		int i=0,j=0,k=0, count =0,countk=0,counta=0;
// 		while(1){
// 			RE(l,min(b,K)){
// 				V.push_back(MP(i,MP(j,k)));
// 				j++;
// 				if(j==b){
// 					count++;
// 					j=0;
// 				}
// 			}
// 			if(i+1==a)
// 				counta++;
// 			if(counta==K)
// 				break;
// 			i=(i+1)%a;
// 			if(count==K){
// 				count=0;
// 				k++;
// 				countk++;
// 				i=0;
// 				j=0;
// 				if(countk==K||k==c)
// 					break;
// 			}
// 		}
// 		}
		printf("%d\n",V.size());
		RE(i,V.size())
			printf("%d %d %d\n",V[i].FI+1,V[i].SE.FI+1,V[i].SE.SE+1);
	}
	return 0;
}
