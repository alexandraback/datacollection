#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<stack>
using namespace std;
int main(){
	int C;
	scanf("%d",&C);
	for(int Case=1; Case<=C; Case++){
		int E,R,N,v[10005];
		int prev[10005],next[10005];
		scanf("%d%d%d",&E,&R,&N);
		for(int i=0;i<N;i++)
			scanf("%d",&v[i]);
		stack<int> S;
		/*for(int i=0;i<N;i++){
			while(S.empty()==false && v[S.top()]<=v[i])
				S.pop();
			if(S.empty()==true)
				prev[i] = -1;
			else prev[i] = S.top();
			S.push(i);
		}
		while(S.empty()==false)
			S.pop();*/
		for(int i=N-1;i>=0;i--){
			while(S.empty()==false && v[S.top()]<v[i])
				S.pop();
			if(S.empty()==true)
				next[i] = -1;
			else next[i] = S.top();
			S.push(i);
		}
		int nowE = E;
		long long ans = 0;
		for(int i=0;i<N;i++){
			int use;
			if(next[i] == -1)
				use = nowE;
			else use = max(0, min(nowE + (next[i] - i) * R - E, nowE));
			ans += (long long)v[i] * use;
			nowE = min(nowE - use + R, E);
		}
		cout<<"Case #"<<Case<<": ";
		cout<<ans<<endl;
	}
}

