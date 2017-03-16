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

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
    int tt=t;
    while(t--)
    {
        int a,b,k,counter=0;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if((i & j) < k)
                    counter++;
            }
        }
        printf("Case #%d: ",tt-t);
        printf("%d\n",counter);
    }
    /*int t;
    cin >> t;
    int tt=t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string inputs[n],input[n];
        for(int i=0;i<n;i++)
        {
            cin >> input[i];
            inputs[i]+=input[i][0];
            for(int j=1;j<input[i].size();j++)
            {
                if(input[i][j] != input[i][j-1])
                {
                    inputs[i]+=input[i][j];
                }
            }
        }
        bool equall = true;
        for(int i=1;i<n;i++)
        {
            if(inputs[i] != inputs[i-1])
            {
                equall = false;
                break;
            }
        }
        printf("Case #%d: ",tt-t);
        if(equall)
        {
            int arr1[27],arr2[27],counter=0;
            memset(arr1,0,sizeof(arr1));
            memset(arr2,0,sizeof(arr2));
            for(int i=0;i<input[0].size();i++)
            {
                arr1[input[0][i]-'a']++;
            }
            for(int i=0;i<input[1].size();i++)
            {
                arr2[input[1][i]-'a']++;
            }
            for(int i=0;i<27;i++)
            {
                counter+=abs(arr1[i]-arr2[i]);
            }
            printf("%d\n",counter);
        }
        else printf("Fegla Won\n");
    }*/
    return 0;
}
