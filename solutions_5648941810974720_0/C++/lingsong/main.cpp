//
//
//  noob
//
//  Created by Lingsong Zeng on 2/29/16.
//  Copyright © 2016 Lingsong Zeng. All rights reserved.
//



#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        char a[30]={0};
        string s;
        cin>>s;
        int num[20]={0};
        for(int i=0;i<s.size();i++)
            a[s[i]-'A']++;
        num[0]=a['Z'-'A'];
        for(int i=0;i<num[0];i++)
        {
            a['Z'-'A']--;
            a['E'-'A']--;
            a['R'-'A']--;
            a['O'-'A']--;
        }
        num[2]=a['W'-'A'];
        for(int i=0;i<num[2];i++)
        {
            a['T'-'A']--;
            a['W'-'A']--;
            a['O'-'A']--;
        }
        num[4]=a['U'-'A'];
        for(int i=0;i<num[4];i++)
        {
            a['F'-'A']--;
            a['O'-'A']--;
            a['U'-'A']--;
            a['R'-'A']--;
        }
        num[6]=a['X'-'A'];
        for(int i=0;i<num[6];i++)
        {
            a['S'-'A']--;
            a['I'-'A']--;
            a['X'-'A']--;
        }
        num[1]=a['O'-'A'];
        for(int i=0;i<num[1];i++)
        {
            a['O'-'A']--;
            a['N'-'A']--;
            a['E'-'A']--;
        }
        num[5]=a['F'-'A'];
        for(int i=0;i<num[5];i++)
        {
            a['F'-'A']--;
            a['I'-'A']--;
            a['V'-'A']--;
            a['E'-'A']--;
        }
        num[7]=a['S'-'A'];
        for(int i=0;i<num[7];i++)
        {
            a['S'-'A']--;
            a['E'-'A']--;
            a['V'-'A']--;
            a['E'-'A']--;
            a['N'-'A']--;
        }
        num[8]=a['G'-'A'];
        for(int i=0;i<num[8];i++)
        {
            a['E'-'A']--;
            a['I'-'A']--;
            a['G'-'A']--;
            a['H'-'A']--;
            a['T'-'A']--;
        }
        num[9]=a['I'-'A'];
        for(int i=0;i<num[9];i++)
        {
            a['N'-'A']--;
            a['I'-'A']--;
            a['N'-'A']--;
            a['E'-'A']--;
        }
        num[3]=a['T'-'A'];
        for(int i=0;i<num[3];i++)
        {
            a['T'-'A']--;
            a['H'-'A']--;
            a['R'-'A']--;
            a['E'-'A']--;
            a['E'-'A']--;
        }
        for(int i=0;i<10;i++)
            for(int j=0;j<num[i];j++)
                cout<<i;
        cout<<endl;
    }
}