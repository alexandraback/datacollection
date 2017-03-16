// Author : SAGORIKA DAS
// Google Code Jam
// A. Counting Sheep

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
               int n;
               scanf("%d",&n);
               if(n == 0){
                   	printf("Case #%d: INSOMNIA\n",cas);
                   	cas++;
                   	continue;
               }
               int f[10],cnt =10;
               CLEAR(f);
               ll d=n;
               while(cnt != 0){
                        ll tmp = d;
                        while(tmp){
                         int i = tmp%10;
                         if(f[i] == 0){
                                 cnt--;
                                 f[i] = 1;
                                 }        
                                 tmp = tmp/10;   
                        } 
                        d += n;
               }
        d -=n;       
    	printf("Case #%d: %lld\n",cas,d);
    	cas++;
	}
	return 0;
}
