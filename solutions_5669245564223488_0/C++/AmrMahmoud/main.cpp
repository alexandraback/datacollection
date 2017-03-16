#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807
#define INF 2000000000
#define PI acos(-1.0)
#define EPS 1e-9
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair

using namespace std;
int n;
string input[15];
bool b[15][15],visited[15];

LL res = 0;

bool check(string tr)
{
    bool arr[27];
    memset(arr,false,sizeof(arr));
    for(int i=0;i<tr.size();i++)
    {
        if(arr[tr[i]-'a'])
            return false;
        while(tr[i+1] == tr[i])
            i++;
        arr[tr[i]-'a'] = true;
    }
    return true;
}

void solve(int k,string temp,int counter)
{
    if(counter == n)
    {
        if(check(temp))
            res++,res%=mod;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && b[k][i])
        {
            visited[i] = true;
            solve(i,temp+input[i],counter+1);
            visited[i] = false;
        }
    }
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    //cin.sync_with_stdio(false);
    int t;
    cin >> t;
    int counter=0;
    while(t--)
    {
        memset(b,false,sizeof(b));
        res = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            cin >> input[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j)
                {
                    bool valid = true;
                    string temp = input[i] + input[j];
                    for(int k=0;k<n && valid;k++)
                    {
                        if(k != i && k != j)
                        {
                            for(int l=0;l<input[k].size() && valid;l++)
                                for(int m=1;m<temp.size()-1 && valid;m++)
                                    if(input[k][l] == temp[m] && temp[m] != temp[0] && temp[m] != temp[temp.size()-1])
                                        valid = false;
                        }
                    }
                    if(valid)
                        b[i][j] = true;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            memset(visited,false,sizeof(visited));
            visited[i] =true;
            solve(i,input[i],1);
        }
        printf("Case #%d: %I64d\n",++counter,res);
    }
    return 0;
}
