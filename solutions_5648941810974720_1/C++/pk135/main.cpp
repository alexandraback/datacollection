#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<cstring>
#include<time.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pll pair<ll,ll>
#define ppll pair<ll, pair<ll,ll> >
#define inf 1000000007

int main()
{
    ll t,n,i,j;
    string s;
    vector<ll> cnt,ans;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>s;
        n=s.length();
        cnt.resize(26,0);
        for(i=0;i<n;i++)
            cnt[int(s[i])-65]++;
        /*for(i=0;i<26;i++)
            cout<<cnt[i]<<" ";
        cout<<endl;*/
        while(cnt[int('Z')-65])
        {
            ans.push_back(0);
            cnt[int('Z')-65]--;
            cnt[int('E')-65]--;
            cnt[int('R')-65]--;
            cnt[int('O')-65]--;
        }
        while(cnt[int('W')-65])
        {
            ans.push_back(2);
            cnt[int('T')-65]--;
            cnt[int('W')-65]--;
            cnt[int('O')-65]--;
        }
        while(cnt[int('U')-65])
        {
            ans.push_back(4);
            cnt[int('F')-65]--;
            cnt[int('O')-65]--;
            cnt[int('U')-65]--;
            cnt[int('R')-65]--;
        }
        while(cnt[int('X')-65])
        {
            ans.push_back(6);
            cnt[int('S')-65]--;
            cnt[int('I')-65]--;
            cnt[int('X')-65]--;
        }
        while(cnt[int('G')-65])
        {
            ans.push_back(8);
            cnt[int('E')-65]--;
            cnt[int('I')-65]--;
            cnt[int('G')-65]--;
            cnt[int('H')-65]--;
            cnt[int('T')-65]--;
        }
        while(cnt[int('H')-65])
        {
            ans.push_back(3);
            cnt[int('T')-65]--;
            cnt[int('H')-65]--;
            cnt[int('R')-65]--;
            cnt[int('E')-65]--;
            cnt[int('E')-65]--;
        }
        while(cnt[int('O')-65])
        {
            ans.push_back(1);
            cnt[int('O')-65]--;
            cnt[int('N')-65]--;
            cnt[int('E')-65]--;
        }
        while(cnt[int('F')-65])
        {
            ans.push_back(5);
            cnt[int('F')-65]--;
            cnt[int('I')-65]--;
            cnt[int('V')-65]--;
            cnt[int('E')-65]--;
        }
        while(cnt[int('V')-65])
        {
            ans.push_back(7);
            cnt[int('S')-65]--;
            cnt[int('E')-65]--;
            cnt[int('V')-65]--;
            cnt[int('E')-65]--;
            cnt[int('N')-65]--;
        }
        while(cnt[int('N')-65])
        {
            ans.push_back(9);
            cnt[int('N')-65]--;
            cnt[int('I')-65]--;
            cnt[int('N')-65]--;
            cnt[int('E')-65]--;
        }
        sort(ans.begin(),ans.end());
        cout<<"Case #"<<j<<": ";
        for(i=0;i<ans.size();i++)
            cout<<ans[i];
        cout<<endl;
        ans.clear();
        cnt.clear();
    }
}
