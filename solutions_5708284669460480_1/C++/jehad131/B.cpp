#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <set>

#define SZ 100006
#define INF (1<<29)
using namespace std;



int S,K,L;

string tg,key;



int Next[105][105];

int F[105];


void init()
{
  // let m be the length of the pattern 

  F[0] = F[1] = 0; // always true
  //cout<<L<<endl;
  
  for(int i = 2; i <= L; i++) {
  	F[i] = 0;
    // j is the index of the largest next partial match 
    // (the largest suffix/prefix) of the string under  
    // index i - 1
    int j = F[i - 1];
    for( ; ; ) {
      // check to see if the last character of string i - 
      // - pattern[i - 1] "expands" the current "candidate"
      // best partial match - the prefix under index j
      if(tg[j] == tg[i - 1]) { 
        F[i] = j + 1; break; 
      }
      // if we cannot "expand" even the empty string
      if(j == 0) { F[i] = 0; break; }
      // else go to the next best "candidate" partial match
      j = F[j];
    }
    //cout<<i<<" "<<F[i]<<endl;

  }

	for(int i=0;i<=L;i++) {
		for(int j=0;j<K;j++) {

			int cur = i;
			Next[i][j] = 0;
			while(1) {
				if(tg[cur] == key[j]) {
					Next[i][j] = cur+1;
					break;
				}
				else if(cur==0) break;
				cur = F[cur];
			}
			//cout<<i<<" "<<Next[i][j]<<endl;

  		}
  	}


}

double dp[105][105];
int vis[105][105] , True;

double back(int pos,int cnt)
{
	if(vis[pos][cnt] == True) return dp[pos][cnt];
	
	vis[pos][cnt] = True;
	dp[pos][cnt] = 0;

	if(cnt == S) {
		if(pos==L) dp[pos][cnt] = 1.0;
		return dp[pos][cnt];
	}
	double p = 1.0/K;
	double ret = 0;
	if(pos==L) ret = 1;
	for(int i=0;i<K;i++) {
		ret += p*back(Next[pos][i],cnt+1);
	}
	dp[pos][cnt] = ret;
	return dp[pos][cnt];

}

double back2(int pos,int cnt)
{
	if(vis[pos][cnt] == True) return dp[pos][cnt];
	
	vis[pos][cnt] = True;
	dp[pos][cnt] = 0;

	if(cnt == S) {
		if(pos==L) dp[pos][cnt] = 1.0;
		return dp[pos][cnt];
	}
	double p = 1.0/K;
	double ret = 0;
	if(pos==L) ret = 1;
	double mxx = 0;
	for(int i=0;i<K;i++) {
		mxx = max(mxx,back2(Next[pos][i],cnt+1));
	}
	ret += mxx;
	dp[pos][cnt] = ret;
	return dp[pos][cnt];

}

int main()
{
	freopen("Bsm.txt","rt",stdin);
	freopen("Ban4.txt","wt",stdout);
	int tst,cas;
	scanf("%d",&tst);
	for(cas=1;cas<=tst;cas++) {
		
		scanf("%d%d%d",&K,&L,&S);
		cin>>key>>tg;
		init();
		True++;
		double ans = back(0,0);
		True++;
		double mx = back2(0,0);
		//cout<<ans<<" "<<mx<<endl;

		printf("Case #%d: %.8lf\n",cas,mx-ans);


	}
	return 0;
}