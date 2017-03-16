#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-small-attempt1 (1).in","r",stdin);
    freopen("outputEEE.o","w",stdout);
    int t,i,j;
    map<char,int>mp;
    vector<int>ans;
    string s;
    scanf("%d",&t);
    for(int ca=1; ca<=t; ca++)
    {
        cin >> s;
        for(i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
        }
        if(mp['W']>0)
        {
            mp['T']-=mp['W'];
            mp['O']-=mp['W'];
            for(j=0; j<mp['W']; j++) ans.push_back(2);
            mp['W']=0;
        }
        if(mp['Z']>0)
        {
            mp['E']-=mp['Z'];
            mp['R']-=mp['Z'];
            mp['O']-=mp['Z'];
            for(j=0; j<mp['Z']; j++) ans.push_back(0);
            mp['Z']=0;
        }
        if(mp['X'])
        {
            mp['S']-=mp['X'];
            mp['I']-=mp['X'];
            for(j=0; j<mp['X']; j++) ans.push_back(6);
            mp['X']=0;
        }
        if(mp['S'])
        {
            mp['E']-=(2*mp['S']);
            mp['V']-=mp['S'];
            mp['N']-=mp['S'];
            for(j=0; j<mp['S']; j++) ans.push_back(7);
           mp['S']=0;
        }
        if(mp['G']>0)
        {
            mp['E']-=mp['G'];
            mp['I']-=mp['G'];
            mp['H']-=mp['G'];
            mp['T']-=mp['G'];
            for(j=0; j<mp['G']; j++) ans.push_back(8);
           mp['G']=0;
        }
        if(mp['U']>0)
        {
            mp['F']-=mp['U'];
            mp['O']-=mp['U'];
            mp['R']-=mp['U'];
            for(j=0; j<mp['U']; j++) ans.push_back(4);
           mp['U']=0;
        }
        if(mp['H']>0)
        {
             mp['T']-=mp['H'];
            mp['E']-=(2*mp['H']);
            mp['R']-=mp['H'];
            for(j=0; j<mp['H']; j++) ans.push_back(3);
           mp['H']=0;
        }
        if(mp['F']>0)
        {
            mp['E']-=mp['F'];
            mp['I']-=mp['F'];
            mp['V']-=mp['F'];
            for(j=0; j<mp['F']; j++) ans.push_back(5);
           mp['F']=0;
        }
        if(mp['O']>0)
        {
            mp['E']-=mp['O'];
            mp['N']-=mp['O'];
            for(j=0; j<mp['O']; j++) ans.push_back(1);
        }
        if(mp['N']>0)
        {
            for(j=0; j<mp['N']/2; j++) ans.push_back(9);
        }
        sort(ans.begin(),ans.end());
        cout << "Case #"<<ca<<": ";
        for(i=0; i<ans.size(); i++)
        {
            cout << ans[i];
        }
        cout<< endl;
        ans.clear();
        mp.clear();
    }

}
