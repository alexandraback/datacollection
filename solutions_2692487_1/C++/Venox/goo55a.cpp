#include <iostream>
#include <queue>
#include <string>
#include <iomanip> 
#include <vector>
#include <list>
#include <utility> 
#include <iterator> 
#include <math.h> 
#include <algorithm> 
#include <stdio.h> 
using namespace std;
#define REP(i,T) for(int i=0;i<T;++i)
#define MP make_pair
#define PII pair<int,int>
#define BG begin
#define ND end
#define VI vector<int>
#define VB vector<bool>
#define ALL(i) i.BG(),i.ND()
#define FORI(i,a,b) for(int i=a;i<b;++i)
#define OUT(i) while(!i.empty())
#define GP(a,b) a[b.first][b.second]
#define EX(a,b) (a.find(b)!=a.end())
int judge(){
	int a,n;
	scanf("%d%d",&a,&n);

	vector<int> goals(n,0);

	REP(i,n){
		scanf("%d",&goals[i]);
	}
	if(a==1)return n;
	sort(ALL(goals));
	vector<int> stack;
	int ma=0;
	for(int i=0;i<n;++i){
		if(a>goals[i]){
			a+=goals[i];
		}
		else{
			stack.push_back(ma+n-i);
			while(a<=goals[i]){
				a+=a-1;
				ma++;
			}
			a+=goals[i];

		}
	}
	REP(i,stack.size()){
		ma=ma<stack[i]?ma:stack[i];
	}
	return ma;
}


int main(){
	int t;
	scanf("%d",&t);
	REP(tt,t){
		int ans=judge();
		printf("Case #%d: %d\n",tt+1,ans);
	}

	return 1;



}