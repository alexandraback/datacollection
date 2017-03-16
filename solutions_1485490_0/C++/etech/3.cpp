//Besm Allah

#include<iostream>
#include<algorithm>
#include<map>
using namespace std;



const int N = 100+ 10;


long long cA[N] , A[N] , cB[N] , B[N];
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef pair<pii,pll> piill;
map<piill,bool>mark;
map<piill,long long>dyn;

long long mem(int v , int u , long long remainA,long long remainB){
//	cout<<"s -- "<<v<<" "<<u<<" "<<remainA<<" "<<remainB<<" "<<endl;
	if(v==0 || u == 0)
		return 0;
	if(mark[piill(pii(v,u),pll(remainA,remainB))])
		return dyn[piill(pii(v,u),pll(remainA,remainB))];
	mark[piill(pii(v,u),pll(remainA,remainB))]=1;
	long long ans = 0;
	if(A[v] != B[u])
		ans = max(mem(v,u-1,remainA,cB[u-1]),mem(v-1,u,cA[v-1],remainB));
	else{
		if(remainA == remainB){
			ans = mem(v-1,u-1,cA[v-1],cB[u-1]) + remainA;
		}else if(remainA  > remainB){
			ans = mem(v , u-1 , remainA-remainB, cB[u-1]) + remainB; 
		}else{
			ans = mem(v-1,u , cA[v-1] , remainB-remainA) + remainA;
		}
	}
//	cout<<"e -- "<<v<<" "<<u<<" "<<remainA<<" "<<remainB<<" "<<ans<<endl;
	return dyn[piill(pii(v,u),pll(remainA,remainB))]=ans;
}

int main(){
	int T;
	cin >> T;
	int cse=0;
while(T--){
	cse++;
	int n,m;
	cin>>n>>m;
	long long a,b;
	for(int i = 1 ; i <= n ; i++){
		cin>>a>>b;
		if(b == A[i-1]){
			cA[i-1]+=a;
		i--;
		n--;
		}else{
			cA[i] = a;
			A[i] = b;
		}
	}
	for(int i = 1 ; i <= m ; i++){
		cin>>a>>b;
		if(b == B[i-1]){
			cB[i-1]+=a;
		i--;
		m--;
		}
		else{
			cB[i] = a;
			B[i] = b;
		}
	}
	mark.clear();
	dyn.clear();
	
	cout<<"Case #"<<cse<<": "<<mem(n,m,cA[n],cB[m])<<endl;
}
}
