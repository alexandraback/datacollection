/* shivamrana */
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
#define f0r(i,n) for(int i=0;i<n;i++)
#define fOr(i,n) for(int i=1;i<=n;i++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%I64d",&a)
#define pi(a) printf("%d",a)
#define pl(a) printf("%I64d",a)
#define n(l) cout<<endl
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define pb(a) push_back(a)
using namespace std;
int check(vector<string> state)
{
    for(int i=0;i<4;i++)
    if((state[i][0]=='O'||state[i][0]=='T')&&(state[i][1]=='O'||state[i][1]=='T')&&(state[i][2]=='O'||state[i][2]=='T')&&(state[i][3]=='O'||state[i][3]=='T'))
    return 0;
    
    for(int i=0;i<4;i++)
    if((state[0][i]=='O'||state[0][i]=='T')&&(state[1][i]=='O'||state[1][i]=='T')&&(state[2][i]=='O'||state[2][i]=='T')&&(state[3][i]=='O'||state[3][i]=='T'))
    return 0;
    
    if((state[0][0]=='O'||state[0][0]=='T')&&(state[1][1]=='O'||state[1][1]=='T')&&(state[2][2]=='O'||state[2][2]=='T')&&(state[3][3]=='O'||state[3][3]=='T'))
    return 0;
    
    if((state[0][3]=='O'||state[0][3]=='T')&&(state[1][2]=='O'||state[1][2]=='T')&&(state[2][1]=='O'||state[2][1]=='T')&&(state[3][0]=='O'||state[3][0]=='T'))
    return 0;
    
    for(int i=0;i<4;i++)
    if((state[i][0]=='X'||state[i][0]=='T')&&(state[i][1]=='X'||state[i][1]=='T')&&(state[i][2]=='X'||state[i][2]=='T')&&(state[i][3]=='X'||state[i][3]=='T'))
    return 1;

    for(int i=0;i<4;i++)
    if((state[0][i]=='X'||state[0][i]=='T')&&(state[1][i]=='X'||state[1][i]=='T')&&(state[2][i]=='X'||state[2][i]=='T')&&(state[3][i]=='X'||state[3][i]=='T'))
    return 1;
    
    if((state[0][0]=='X'||state[0][0]=='T')&&(state[1][1]=='X'||state[1][1]=='T')&&(state[2][2]=='X'||state[2][2]=='T')&&(state[3][3]=='X'||state[3][3]=='T'))
    return 1;

    if((state[0][3]=='X'||state[0][3]=='T')&&(state[1][2]=='X'||state[1][2]=='T')&&(state[2][1]=='X'||state[2][1]=='T')&&(state[3][0]=='X'||state[3][0]=='T'))
    return 1;
    
    for(int  i=0;i<4;i++)
    for(int j=0;j<4;j++)
    if(state[i][j]=='.')
    return 3;
    return 2;
}
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    cin>>t;
    for(int cases=1;cases<=t;cases++)
    {
    vector<string> board;
    for(int i=0;i<4;i++)
    {
    string temp;
    cin>>temp;
    board.push_back(temp);
    }
    int w;
    w=check(board);
    if(w==0)
    printf("Case #%d: O won\n",cases);
    else if(w==1)
    printf("Case #%d: X won\n",cases);
    else if(w==2)
    printf("Case #%d: Draw\n",cases);
    else if(w==3)
    printf("Case #%d: Game has not completed\n",cases);
    }
return 0;
}
