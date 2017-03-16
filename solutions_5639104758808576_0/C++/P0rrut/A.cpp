#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;
int S;
string p;
int T;
int main(){
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> S >> p; 
    int res =0 ;
    int tot =0;
    FOR(i,S+1){
      if(p[i]=='0') continue;
      if(i>tot){
        res+=i-tot;
        tot = i;
      }
      tot+=p[i]-'0';
    }
    cout << res << endl;
  }

	return 0;
}
