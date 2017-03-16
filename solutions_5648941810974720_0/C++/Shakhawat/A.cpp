#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,cased=0;
    string s;
    int cnt[30];
//    freopen("a.txt","r",stdin);
//    freopen("b.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        cin>>s;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.size();i++)
            cnt[s[i]-'A']++;
        int eliminate=0;
//        cout<<s<<endl;
        vector<int>ans;
        while(eliminate<s.size())
        {
//            cout<<"OK"<<endl;
            if(cnt['Z'-'A'])
            {
                ans.push_back(0);
                cnt['Z'-'A']--;
                cnt['E'-'A']--;
                cnt['R'-'A']--;
                cnt['O'-'A']--;
                eliminate+=4;
            }
            else if(cnt['W'-'A'])
            {
                ans.push_back(2);
                cnt['T'-'A']--;
                cnt['W'-'A']--;
                cnt['O'-'A']--;
                eliminate+=3;
            }
            else if(cnt['X'-'A'])
            {
                ans.push_back(6);
                cnt['S'-'A']--;
                cnt['I'-'A']--;
                cnt['X'-'A']--;
                eliminate+=3;
            }
            else if(cnt['G'-'A'])
            {
                ans.push_back(8);
                cnt['E'-'A']--;
                cnt['I'-'A']--;
                cnt['G'-'A']--;
                cnt['H'-'A']--;
                cnt['T'-'A']--;
                eliminate+=5;
            }
            else if(cnt['S'-'A'])
            {
                ans.push_back(7);
                cnt['E'-'A']--;
                cnt['S'-'A']--;
                cnt['V'-'A']--;
                cnt['E'-'A']--;
                cnt['N'-'A']--;
                eliminate+=5;
            }
            else if(cnt['U'-'A'])
            {
                ans.push_back(4);
                cnt['F'-'A']--;
                cnt['O'-'A']--;
                cnt['U'-'A']--;
                cnt['R'-'A']--;
                eliminate+=4;
            }
            else if(cnt['F'-'A'])
            {
                ans.push_back(5);
                cnt['F'-'A']--;
                cnt['I'-'A']--;
                cnt['V'-'A']--;
                cnt['E'-'A']--;
                eliminate+=4;
            }
            else if(cnt['O'-'A'])
            {
                ans.push_back(1);
                cnt['O'-'A']--;
                cnt['N'-'A']--;
                cnt['E'-'A']--;
                eliminate+=3;
            }
            else if(cnt['R'-'A'])
            {
                ans.push_back(3);
                cnt['T'-'A']--;
                cnt['H'-'A']--;
                cnt['R'-'A']--;
                cnt['E'-'A']--;
                cnt['E'-'A']--;
                eliminate+=5;
            }
            else if(cnt['I'-'A'])
            {
                ans.push_back(9);
                cnt['N'-'A']--;
                cnt['I'-'A']--;
                cnt['N'-'A']--;
                cnt['E'-'A']--;
                eliminate+=4;
            }
            else break;

        }
        sort(ans.begin(),ans.end());
        printf("Case #%d: ",++cased);
        for(int i=0;i<ans.size();i++)
            printf("%d",ans[i]);
        printf("\n");
    }
    return 0;
}
