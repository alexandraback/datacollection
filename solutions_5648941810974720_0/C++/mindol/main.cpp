#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char str[2010];
int cnt[26];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for(int mindol=1;mindol<=tc;mindol++)
    {
        vector<int> ans;
        for(int i=0;i<26;i++)
            cnt[i]=0;
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++)
            cnt[str[i]-'A']++;

        while(cnt['X'-'A'])
        {
            cnt['S'-'A']--, cnt['I'-'A']--, cnt['X'-'A']--;
            ans.push_back(6);
        } // now, no 6

        while(cnt['S'-'A'])
        {
            cnt['S'-'A']--, cnt['E'-'A']--, cnt['V'-'A']--, cnt['E'-'A']--, cnt['N'-'A']--;
            ans.push_back(7);
        } // now, no 6,7

        while(cnt['G'-'A'])
        {
            cnt['E'-'A']--, cnt['I'-'A']--, cnt['G'-'A']--, cnt['H'-'A']--, cnt['T'-'A']--;
            ans.push_back(8);
        } // now, no 6,7,8

        while(cnt['V'-'A'])
        {
            cnt['F'-'A']--, cnt['I'-'A']--, cnt['V'-'A']--, cnt['E'-'A']--;
            ans.push_back(5);
        } // now, no 5,6,7,8

        while(cnt['I'-'A'])
        {
            cnt['N'-'A']--, cnt['I'-'A']--, cnt['N'-'A']--, cnt['E'-'A']--;
            ans.push_back(9);
        } // now, no 5,6,7,8,9

        while(cnt['Z'-'A'])
        {
            cnt['Z'-'A']--, cnt['E'-'A']--, cnt['R'-'A']--, cnt['O'-'A']--;
            ans.push_back(0);
        } // now, no 0,5,6,7,8,9

        while(cnt['F'-'A'])
        {
            cnt['F'-'A']--, cnt['O'-'A']--, cnt['U'-'A']--, cnt['R'-'A']--;
            ans.push_back(4);
        } // now, no 0,4,5,6,7,8,9

        while(cnt['H'-'A'])
        {
            cnt['T'-'A']--, cnt['H'-'A']--, cnt['R'-'A']--, cnt['E'-'A']--, cnt['E'-'A']--;
            ans.push_back(3);
        } // now, no 0,3,4,5,6,7,8,9

        while(cnt['W'-'A'])
        {
            cnt['T'-'A']--, cnt['W'-'A']--, cnt['O'-'A']--;
            ans.push_back(2);
        } // now, no 0,2,3,4,5,6,7,8,9

        while(cnt['O'-'A'])
        {
            cnt['O'-'A']--, cnt['N'-'A']--, cnt['E'-'A']--;
            ans.push_back(1);
        } // now, no 0,1,2,3,4,5,6,7,8,9

        sort(ans.begin(),ans.end());
        printf("Case #%d: ",mindol);
        for(int i=0;i<ans.size();i++)
            printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
