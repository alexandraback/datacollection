#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 1010;
int A[maxn],B[maxn];
int vis[maxn];
struct cmp1{
   bool operator ()(int &a,int &b){
   return A[a]>A[b];//最小值优先
  }
};
struct cmp2{
   bool operator ()(int &a,int &b){
   return B[a]>B[b];//最小值优先
  }
};
int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("B-small-attempt3.out","w",stdout);
    int T,N;
    int ans;
    cin>>T;
    for(int cas=0;cas<T;cas++){
        cin >> N;
        ans = 0;
        priority_queue<int, vector<int>, cmp1 > queA;
        priority_queue<int, vector<int>, cmp2 > queB;
        while(!queA.empty())
            queA.pop();
        while(!queB.empty())
            queB.pop();
        for(int i = 0 ; i < N ; i++){
            scanf("%d%d",A+i,B+i);
            queA.push(i);
            queB.push(i);
        }
        //printf("topa=%d\n",A[queA.top()]);
        memset(vis,0,sizeof(vis));
        int tmp=0;
        while(!queB.empty()){
            if(tmp>=B[queB.top()]){
                tmp+=2;
                if(vis[queB.top()]==1)
                    tmp-=1;
                vis[queB.top()]=2;
                ans++;
                queB.pop();
            }
            else if((!queA.empty()) && tmp>=A[queA.top()]){
                if(vis[queA.top()]==0){
                    tmp+=1;
                    ans++;
                    vis[queA.top()]=1;
                }
                queA.pop();
            }
            else
                break;
        }
        printf("Case #%d: ", cas+1);
        if(queB.empty())
            printf("%d\n",ans);
        else
            printf("Too Bad\n");
    }
    return 0;
}
