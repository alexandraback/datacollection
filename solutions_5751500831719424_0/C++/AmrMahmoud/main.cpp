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
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t;
    cin >> t;
    int tt=t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        string edit[105],input[105];
        int arr[n][26];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++)
        {
            cin >> input[i];
            edit[i]+=input[i][0];
            for(int j=1;j<(int)input[i].size();j++)
            {
                if(input[i][j] != input[i][j-1])
                {
                    edit[i]+=input[i][j];
                }
            }
        }
        printf("Case #%d: ",tt-t);
        if(edit[0] == edit[1])
        {
            int counter=0,k=0;
            for(int i=0;i<input[0].size();i++)
            {
                int temp=0,temp2=1;
                while(input[1][k]==input[0][i] && k < input[1].size())
                {
                    k++;
                    temp++;
                }
                while(input[0][i] == input[0][i+1])
                {
                    i++;
                    temp2++;
                }
                counter+=abs(temp-temp2);
            }
            printf("%d\n",counter);
        }
        else printf("Fegla Won\n");
    }
    return 0;
}
