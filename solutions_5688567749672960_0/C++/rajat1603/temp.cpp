#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
int rev(int num){
	int x  = 0;
	while(num){
		x = x*10;
		x+=num%10;
		num/=10;
	}
	return x;
}
const int N = 1000001;
int dist[N]={0};
int main(){
	dist[1]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		if(node>=N){
			continue;
		}
		if(dist[node+1]==0){
			dist[node+1] = dist[node]+ 1;
			q.push(node+1);
		}
		int x = rev ( node );
		if(dist[x]==0){
			dist [ x ] = dist[node] + 1;
			q.push(x);
		}
	}
	int t=scan();
	int tc = 0;
	while(t--){
		int n=scan();
		printf("Case #%d: %d\n",++tc,dist[n]);
	}
}