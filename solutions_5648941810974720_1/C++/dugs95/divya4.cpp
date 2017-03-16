#include <bits/stdc++.h>
using namespace std;
int mark[30];
int main()
{
    // your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        memset(mark,0,sizeof(mark));
        //cout<<s<<endl;
        for(int i=0;i<s.length();i++)
        {
            mark[s[i]-'A']++;
        }
        vector<int> ans;
        
        if(mark['Z'-'A']>=1)
        {
            while(mark['Z'-'A'])
            {
                ans.push_back(0);
                mark[25]--;
                mark[4]--;
                mark['R'-'A']--;
                mark['O'-'A']--;
            }
        }
        if(mark['W'-'A']>0)
        {
            while(mark['W'-'A'])
            {
                ans.push_back(2);
                mark['T'-'A']--;
                mark['W'-'A']--;
                mark['O'-'A']--;
            }
        }
        if(mark['U'-'A']>0)
        {
            while(mark['U'-'A'])
            {
                ans.push_back(4);
                mark['F'-'A']--;
                mark['U'-'A']--;
                mark['R'-'A']--;
                mark['O'-'A']--;
            }
        }
        if(mark['X'-'A']>0)
        {
            while(mark['X'-'A'])
            {
                ans.push_back(6);
                
                mark['X'-'A']--;
                mark['I'-'A']--;
                mark['S'-'A']--;
            }
        }
        
        if(mark['G'-'A']>0)
        {
            while(mark['G'-'A'])
            {
                ans.push_back(8);
                mark['E'-'A']--;
                mark['I'-'A']--;
                mark['G'-'A']--;
                mark['H'-'A']--;
                mark['T'-'A']--;
            }
        }
        if(mark['F'-'A']>0)
        {
            while(mark['F'-'A'])
            {
                ans.push_back(5);
                mark['E'-'A']--;
                mark['I'-'A']--;
                mark['F'-'A']--;
                mark['V'-'A']--;
                
            }
        }
        if(mark['V'-'A']>0)
        {
            while(mark['V'-'A'])
            {
                ans.push_back(7);
                mark['E'-'A']--;
                mark['E'-'A']--;
                mark['S'-'A']--;
                mark['V'-'A']--;
                mark['N'-'A']--;
            }
        }
        if(mark['I'-'A']>0)
        {
            while(mark['I'-'A'])
            {
                ans.push_back(9);
                mark['E'-'A']--;
                mark['N'-'A']--;
                mark['I'-'A']--;
                mark['N'-'A']--;
            }
        }
        
        if(mark['O'-'A']>0)
        {
            while(mark['O'-'A'])
            {
                ans.push_back(1);
                mark['E'-'A']--;
                mark['O'-'A']--;
                mark['N'-'A']--;
            }
        }
        if(mark['E'-'A']>0)
        {
            while(mark['E'-'A'])
            {
                ans.push_back(3);
                mark['E'-'A']--;
                mark['E'-'A']--;
                mark['T'-'A']--;
                mark['H'-'A']--;
                mark['R'-'A']--;
            }
        }
        
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}