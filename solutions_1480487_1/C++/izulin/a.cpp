#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void tst()
{
    int n;
    cin >> n;
    vector<pair<int,int> > inp(n);
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> inp[i].first;
        inp[i].second = i;
        sum += inp[i].first;
    }
    int oldsum = sum;
    sort(inp.begin(),inp.end());
    reverse(inp.begin(),inp.end());
    vector<double> ans(n);
    int ind = 0;
    for(;;ind++)
    {
        if((oldsum+sum)>=(n-ind)*inp[ind].first)
            break;

        ans[inp[ind].second] = 0;
        sum -= inp[ind].first;
    }
    double lev = oldsum+sum;
    lev /= (n-ind);
    for(;ind<n;ind++)
    {
        ans[inp[ind].second] = (lev- inp[ind].first)/oldsum;
    }


    for(int i=0;i<n;i++)
        printf(" %.6lf",100*ans[i]);
    printf("\n");
}
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d:",i);
        tst();
    }
}
