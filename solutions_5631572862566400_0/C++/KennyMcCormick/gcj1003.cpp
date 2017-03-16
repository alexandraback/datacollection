#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
using namespace std;
#define rep(i, j, k) for(int i = j; i <= k; i++)
#define repm(i, j, k) for(int i = j; i >= k; i--)
#define mem(a) memset(a, 0, sizeof(a))
#define mp make_pair
typedef long long ll;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int bff[12];
int T,N;
int mxans;
int permut[12];
int cnt;
bool examine(){
	if(permut[cnt]!=bff[permut[1]]&&permut[2]!=bff[permut[1]])
	return 0;
	if(permut[cnt-1]!=bff[permut[cnt]]&&permut[1]!=bff[permut[cnt]])
	return 0;
	rep(i,2,cnt-1)
	if(permut[i-1]!=bff[permut[i]]&&permut[i+1]!=bff[permut[i]])
	return 0;
	return 1;
}
int main(){
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("ans","w",stdout);
	cin>>T;
	rep(cas,1,T){
		mxans=2;
		cin>>N;
		rep(i,1,N)
		cin>>bff[i];
		rep(i,7,(1<<N)-1){
			mem(permut);
			cnt=0;
			rep(j,1,N){
				if(i&(1<<(j-1))){
					++cnt;
					permut[cnt]=j;
				}
			}
			if(cnt<=mxans)
			continue;
			int fst=permut[1];
			do{
				if(examine()){
					mxans=cnt;
					break;
				}
			}
			while(next_permutation(permut+1,permut+1+cnt)&&permut[1]==fst);
		}
		cout<<"Case #"<<cas<<": "<<mxans<<endl;
	}
}
