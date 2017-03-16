#include <bits/stdc++.h>

using namespace std;

string nums[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
string s;
int co[256];
vector<int> ans;

void make(int a,char u)
{
    int i;
    if(co[u])
    {
        int x=co[u];
        for(i=0;i<nums[a].size();i++)
            co[nums[a][i]]-=x;
        for(i=0;i<x;i++)
            ans.push_back(a);
    }
}

void getu()
{
    int i;
    for(i=0;i<s.size();i++)
    {
        co[s[i]]++;
    }
    make(0,'Z');
    make(2,'W');
    make(4,'U');
    make(6,'X');
    make(8,'G');
}

bool can(int d)
{
    int coo[256];
    memset(coo,0,sizeof co);
    int i;
    for(i=0;i<nums[d].size();i++)
    {
        coo[nums[d][i]]++;
    }
    for(i=0;i<256;i++)
        if(co[i]<coo[i]) return 0;
    return 1;
}

void get(int d)
{
    int coo[256];
    memset(coo,0,sizeof co);
    int i;
    for(i=0;i<nums[d].size();i++)
    {
        coo[nums[d][i]]++;
    }
    int maxi=100000;
    for(i=0;i<256;i++)
    {
        if(!coo[i]) continue;
        maxi=min(maxi,co[i]/coo[i]);
    }
    for(i=0;i<256;i++)
    {
        co[i]-=maxi*(coo[i]);
    }
    for(i=0;i<maxi;i++)
        ans.push_back(d);
}

int main()
{
    freopen("A_large.in","r",stdin);
    freopen("A_large.out","w",stdout);
    int t;
    cin >> t;
    int tc;
    for(tc=1;tc<=t;tc++)
    {
        cin >> s;
        ans.clear();
        memset(co,0,sizeof co);
        getu();
        int i;
        for(i=1;i<=9;i+=2)
        {
            if(can(i)) get(i);
        }
        cout << "Case #" << tc << ": ";
        sort(ans.begin(),ans.end());
        for(i=0;i<ans.size();i++)
            cout << ans[i];
        cout << endl;
    }
}
