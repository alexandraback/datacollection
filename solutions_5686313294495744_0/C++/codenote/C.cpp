#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> ii;
void Solve(int);
int main()
{
    freopen("C:\\Users\\dell\\Downloads\\inputc.txt","r",stdin);
    freopen("C:\\Users\\dell\\Downloads\\outputc.txt","w",stdout);
    int tc,t;
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++) Solve(t);
    return 0;
}
void Solve(int TestCase)
{
    int n,ans = 0;
    ii prs[1005];
    scanf("%d",&n);
    map <string,int> mp;
    int id = 0;
    for(int i = 1 ; i<=n ; i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(mp.count(s1) == 0)
        {
            id++;
            mp[s1] = id;
        }
        if(mp.count(s2) == 0)
        {
            id++;
            mp[s2] = id;
        }
        prs[i] = ii(mp[s1],mp[s2]);
    }
    int p2 = pow(2,n);
    for(int j = 0 ; j<p2 ; j++)
    {
        int temp = j;
        set <ii> fake;
        vector <ii> org;
        for(int i = 1 ; i<=n ; i++)
        {
            if(temp%2 == 0) fake.insert(prs[i]);
            else org.push_back(prs[i]);
            temp /= 2;
        }
        int sz = org.size();
        if(sz > 1)
        {
            for(int i = 0 ; i<sz ; i++)
            {
                for(int k = 0 ; k<sz ; k++)
                {
                    if(i != k)
                    {
                        fake.erase(ii(org[i].first,org[k].second));
                    }
                }
            }
            if(fake.size() == 0)
            {
                ans = max(ans,n-sz);
            }
        }
     }
    printf("Case #%d: %d",TestCase,ans);
    printf("\n");
}
