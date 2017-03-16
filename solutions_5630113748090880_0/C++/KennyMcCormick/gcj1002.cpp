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
int T;
int N;
int mark[2510];
int main(){
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("ans","w",stdout);
	cin>>T;
	rep(cas,1,T){
		cin>>N;
		mem(mark);
		rep(i,1,2*N-1){
			rep(j,1,N){
				int num;
				cin>>num;
				mark[num]++;
			}
		}
		cout<<"Case #"<<cas<<":";
		rep(i,1,2500)
		if(mark[i]%2) cout<<" "<<i;
		cout<<endl;
	}
}
