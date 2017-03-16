#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#define PI 1
#include <queue>
#define PB(a)  push_back(a)
#define FOR(i,a)    for(int i = 0;i<(a);i++)
#define REP(i,a,b)  for(int i = (a);i<(b);i++)
#define SZ(a)   ((signed)a.size())
#define STACKSIZE 100001

using namespace std;

vector<int>v;

struct stack
{
    int top;
    int items[STACKSIZE];
};

void push(struct stack *ps, int x)
{
    if (ps->top == STACKSIZE-1)
    {
        printf("Error: stack overflow\n");
        getchar();
        exit(0);
    }
    else
    {
        ps->top += 1;
        int top = ps->top;
        ps->items [top] = x;
    }
}

bool isEmpty(struct stack *ps)
{
    return (ps->top == -1)? true : false;
}

int pop(struct stack *ps)
{
    int temp;
    if (ps->top == -1)
    {
        printf("Error: stack underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        int top = ps->top;
        temp = ps->items [top];
        ps->top -= 1;
        return temp;
    }
}

void getNGE(int arr[], int n)
{
    int i = 0;
    struct stack s;
    s.top = -1;
    int element, next;
    push(&s, arr[0]);
    for (i=1; i<n; i++)
    {
        next = arr[i];

        if (isEmpty(&s) == false)
        {
            element = pop(&s);
            while (element < next)
            {
                v.PB(next);
                if(isEmpty(&s) == true)
                   break;
                element = pop(&s);
            }
            if (element > next)
                push(&s, element);
        }
        push(&s, next);
    }
    while(isEmpty(&s) == false)
    {
        element = pop(&s);
        next = -1;
        v.PB(next);
    }
}

int caseno = 1;

void solve(){
    v.clear();
    int ans = 0;
    long long e,r,n;
    cin>>e>>r>>n;
    int arr[10001];
    FOR(i,n)    cin>>arr[i];
    int total = e;
    int dp[100][100] = {{0}};
    dp[0][e] = 1;
    int a ;
    FOR(i,n){
        REP(k,0,e + 1){
            if(!dp[i][k])   continue;
            REP(j,0,k + 1){
                dp[i + 1][(k - j - 1 + r)%e + 1] = max(dp[i + 1][(k - j - 1 + r)%e + 1] , j*arr[i] + dp[i][k]);
            }
        }
    }
    FOR(i,e + 1){
        ans = max(ans,dp[n][i]);
    }
    //getNGE(arr,n);
    //FOR(i,SZ(v))    cout<<v[i]<<" ";
    //FOR(i,n)

    cout<<"Case #"<<caseno<<": "<<ans - 1<<"\n";
    caseno++;
}

int main(){
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    int t;
    cin>>t;
    FOR(i,t)    solve();
    return 0;
}
