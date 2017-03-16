#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int tc,len,cnt[28];
char ipt[2005];

vector<int>ans;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,k;
    scanf("%d",&tc);
    for(k=1;k<=tc;k++) {
        scanf("%s",&ipt);
        len = strlen(ipt);
        for(i=0;i<len;i++) cnt[ipt[i]-'A']++;
        ans.clear();
        while(cnt['W'-'A']>0) {
            cnt['T'-'A']--;
            cnt['W'-'A']--;
            cnt['O'-'A']--;
            ans.push_back(2);
        }
        while(cnt['X'-'A']>0) {
            cnt['S'-'A']--;
            cnt['I'-'A']--;
            cnt['X'-'A']--;
            ans.push_back(6);
        }
        while(cnt['Z'-'A']>0) {
            cnt['Z'-'A']--;
            cnt['E'-'A']--;
            cnt['R'-'A']--;
            cnt['O'-'A']--;
            ans.push_back(0);
        }
        while(cnt['U'-'A']>0) {
            cnt['F'-'A']--;
            cnt['O'-'A']--;
            cnt['U'-'A']--;
            cnt['R'-'A']--;
            ans.push_back(4);
        }
        while(cnt['G'-'A']>0) {
            cnt['E'-'A']--;
            cnt['I'-'A']--;
            cnt['G'-'A']--;
            cnt['H'-'A']--;
            cnt['T'-'A']--;
            ans.push_back(8);
        }
        while(cnt['H'-'A']>0) {
            cnt['T'-'A']--;
            cnt['H'-'A']--;
            cnt['R'-'A']--;
            cnt['E'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(3);
        }
        while(cnt['F'-'A']>0) {
            cnt['F'-'A']--;
            cnt['I'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(5);
        }
        while(cnt['O'-'A']>0) {
            cnt['O'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(1);
        }
        while(cnt['S'-'A']>0) {
            cnt['S'-'A']--;
            cnt['E'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
            cnt['N'-'A']--;
            ans.push_back(7);
        }
        while(cnt['I'-'A']>0) {
            cnt['N'-'A']--;
            cnt['I'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(9);
        }
        sort(ans.begin(),ans.end());
        printf("Case #%d: ",k);
        for(i=0;i<ans.size();i++) {
            printf("%d",ans[i]);
        }
        puts("");
        for(i=0;i<len;i++) ipt[i] = 0;
        for(i=0;i<27;i++) cnt[i] = 0;
    }
}
