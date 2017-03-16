

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define maxn 210
#define mod 1000000007
#define LL long long
int arr[maxn];
string str[maxn];
int N;
int parent[maxn];
int mark[maxn];
int find(int x){
	if(parent[x]!=x){
		parent[x]=find(parent[x]);
	}
	return parent[x];
}
int Union(int a, int b){
	if (a==b) return 1;
	int fa = find(a), fb = find(b);
	if (fa==fb) return 0;
	parent[fa] = fb;
	return 1;
}
int check(string ss, char c){
	int n = ss.length();
	int i;
	for (i = 0;i < n; i++){
		if (ss[i]!=c)break;
	}
	if (i==n) return 2;
	if(i!=0){
		for ( ; i< n; i++){
			if (ss[i]==c)return -1;
		}
		return 1;
	}
	else{
		for (i = n-1;i >=0;i --){
			if (ss[i]!=c)break;
		}
		if (i==n-1) {
			for (i = 0;i <n; i++)
				if (ss[i]==c) return 3;
			return 4;
		}
		for ( ; i>=0 ;i--)
			if (ss[i]==c)
				return -1;
		return 0;
	}
}


int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int t,cas;
	int i,j,k,A,B,C;
	scanf("%d",&t);
	for (cas = 1; cas <= t; cas ++){
		
		scanf("%d",&N);
		for (i =0;i < N;i ++){
			parent[i] = i;
		}
		for (i = 0;i < N; i++){
			cin>>str[i];
		}
		LL ans=1;
		int flag  =0;
		for (char c = 'a'; c<='z'&&!flag; c++){
			int one=-1,hav=0;
			A=B=-1;C=0;
			for (i = 0;i < N;i ++){
				int tmp = check(str[i], c);
				if (tmp==-1) flag = 1;
				
				if (tmp==0){
					if (A==-1) A = i;
					else flag = 1;
					one = i;
				}
				
				if (tmp==1){
					if (B==-1) B = i;
					else flag = 1;
					one = i;
				}
				if (tmp==2){
					arr[C++] = i;
					one = i;
				}
				if (tmp==3) hav ++;
			}
			if (hav>1) flag = 1;
			if (one!=-1&&hav>0) flag = 1;
			if (one!=-1){
				for (i = 1;i <=C;i ++){
					ans*=i;ans%=mod;
				}
				for (i = 0;i < C;i ++)
					if (!Union(arr[i], one))
						flag = 1;
				if (A!=-1) {
					if (!Union(one, A))
						flag = 1;
				}
				if (B!=-1) {
					if (!Union(one, B))
						flag = 1;
				}
			}
		}
		int tot = 0;
		memset(mark,0,sizeof(mark));
		for (i = 0; i< N; i++)
			mark[find(i)] = 1;
		for (i = 0;i <N; i++){
			if(mark[i])tot++;
		}
		for (i = 1;i <= tot; i++){
			ans*=i;
			ans%=mod;
		}
		printf("Case #%d: ", cas);
		if (flag) ans = 0;
		cout<<ans<<endl;
	}
	return 0;
}
			
			
			
			
			
			
			
			
			
			
			
			
			
