// Author : SAGORIKA DAS
// Google Code Jam
// B. Revenge of the Pancakes

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<string>
#define ull unsigned long long
#define ll long long
#define F first
#define S second
#define MOD 1000000007
#define inf 1000000006
#define pb push_back
#define MAX 100002
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define CLEAR(a) memset(a,0,sizeof a)
#define pii pair< int , int >
#define piii pair< int , pii >
#define piiii pair< int, piii >
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int T;scanf("%d",&T);
    int cas = 1;
    while(T--){
        deque<int> q;
        string s;
        cin >> s;
         REP(i,s.size()){
               if(s[i] == '+') q.pb(1);
               else q.pb(0);          
         }
         while(q.back() == 1){
            q.pop_back();
            if(q.empty()) break;
            }
            
         int ans = 0;
         while(!q.empty()){
         int f = q.front();
         while(q.front()== f){
         q.pop_front();
         if(q.empty()) break;
         }
         ans++;
         if(q.empty()) break;
         f = q.front();                  
         }
    	printf("Case #%d: %d\n",cas,ans);
    	cas++;
	}
	return 0;
}
