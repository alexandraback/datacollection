#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

using namespace std;

int A,N,a[100010];
int T;
int main()
{
    freopen("C://input.txt","r",stdin);
    freopen("C://output.txt","w",stdout);
    cin>>T;
    int cas=0;
    while(T--)
    {
        cin>>A>>N;
        for(int i=1;i<=N;i++)
            cin>>a[i];
        sort(a+1,a+1+N);
        int ans=999999999;
        for(int i=0;i<=N;i++)
        {
            int end=N-i;
            int sum=A;
            int temp=i;
            for(int j=1;j<=end;j++)
            {
                if(sum>a[j])
                    sum+=a[j];
                else
                {
                    if(sum<=1)
                    {
                        temp=ans;
                        break;
                    }
                    while(sum<=a[j])
                    {
                        sum+=sum-1;
                        temp++;
                    }
                    j--;
                }
            }
            ans=min(ans,temp);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
}
