									/*ba yade oo */
//Mehrdad AP

#include <iostream>
#include <string>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) ((x)*(x))
#define EPS 1e-7
#define INF 100000000
#define MAX 1000009
#define MODE 1000000007
#define Left(x) (2*x)
#define Right(x) ((2*(x)+1)
//#define inRange(x,y) (x>=0 && x<N && y>=0 && y<M)

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef long long int lli;

int sz[110];

int main ()
{
	//freopen("input.in",r,stdin);
	//freopen("output.out",w,stdout);
	
	int tc,ans,x,cursz,TC=0,N;

	cin>>tc;
	while (tc--){
		cin>>x>>N;
		for (int i=0;i<N;i++) scanf("%d",sz+i);
		sort(sz,sz+N);
		ans=N;
		
		for (int i=0;i<N && x!=1;i++){
			int prev=0;
			cursz=x;
			for (int j=0;j<=i;j++){
				if (cursz>sz[j]) cursz+=sz[j];
				else {
					while (cursz<=sz[j]){
						prev++;
						cursz+=(cursz-1);
					}
					cursz+=sz[j];
				}
			}
			int nxt=N;
			for (int j=i+1;j<N;j++){
				if (cursz>sz[j]) cursz+=sz[j];
				else{
					nxt=j;break;
				}
			}
			ans= min (ans,prev+(N-nxt));

		}


		printf("Case #%d: %d\n",++TC,ans);

	}



	return 0;
}
