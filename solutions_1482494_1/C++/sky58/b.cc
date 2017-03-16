#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//priority_queue <int> p,q;
bool s1[1100],s2[1100];
int n1[1100],n2[1100];
int cal(int n){
	int star=0,time,i,now=0;
	for(time=0;;time++){
		if(now>=n) return time;
		rep(i,n){
			if(!s2[i] && n2[i]<=star){
				if(!s1[i]) star+=2;else star+=1;
				s1[i]=s2[i]=true;now++;break;
			}
		}
		if(i<n) continue;
		int mai=-1,ma=-1;
		rep(i,n){
			if(s1[i] || n1[i]>star) continue;
			if(ma<n2[i]){ma=n2[i];mai=i;}
		}
		//cout<<mai<<' '<<ma<<' '<<star<<endl;
		if(mai<0) return -1;
		s1[mai]=true;star+=1;
	}
	return -1;
}
int main()
{
	//priority_queue <int> p,q;
	int i,j,n,t,a,b;
	cin>>t;
	rep(i,t){
		cin>>n;memset(s1,false,sizeof(s1));memset(s2,false,sizeof(s2));
		rep(j,n){
			scanf("%d %d",&n1[j],&n2[j]);
		}
		//cout<<n1[0]<<' '<<n2[0]<<endl;
		int ret=cal(n);
		if(ret<0){
			printf("Case #%d: Too Bad\n",i+1);
		}
		else printf("Case #%d: %d\n",i+1,ret);
	}
	return 0;
}
