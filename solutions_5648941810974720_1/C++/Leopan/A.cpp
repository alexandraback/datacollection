#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
char a[2000+10];
int cnt[26]={};
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,Case=0;
    scanf("%d",&T);
    while(T--){
        scanf("%s",a);
        int l=strlen(a);
        memset(cnt,0,sizeof(cnt));
        ans.clear();
        for(int i=0;i<l;i++)cnt[a[i]-'A']++;
        while(cnt['Z'-'A']){
            cnt['Z'-'A']--;
            cnt['E'-'A']--;
            cnt['R'-'A']--;
            cnt['O'-'A']--;
            ans.push_back(0);
        }
        while(cnt['W'-'A']){
            cnt['T'-'A']--;
            cnt['W'-'A']--;
            cnt['O'-'A']--;
            ans.push_back(2);
        }
        while(cnt['X'-'A']){
            cnt['S'-'A']--;
            cnt['I'-'A']--;
            cnt['X'-'A']--;
            ans.push_back(6);
        }
        while(cnt['S'-'A']){
            cnt['S'-'A']--;
            cnt['E'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
            cnt['N'-'A']--;
            ans.push_back(7);
        }
        while(cnt['G'-'A']){
            cnt['E'-'A']--;
            cnt['I'-'A']--;
            cnt['G'-'A']--;
            cnt['H'-'A']--;
            cnt['T'-'A']--;
            ans.push_back(8);
        }
        while(cnt['H'-'A']){
            cnt['T'-'A']--;
            cnt['H'-'A']--;
            cnt['R'-'A']--;
            cnt['E'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(3);
        }
        while(cnt['R'-'A']){
            cnt['F'-'A']--;
            cnt['O'-'A']--;
            cnt['U'-'A']--;
            cnt['R'-'A']--;
            ans.push_back(4);
        }
        while(cnt['O'-'A']){
            cnt['O'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(1);
        }
        while(cnt['F'-'A']){
            cnt['F'-'A']--;
            cnt['I'-'A']--;
            cnt['V'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(5);
        }
        while(cnt['N'-'A']){
            cnt['N'-'A']--;
            cnt['I'-'A']--;
            cnt['N'-'A']--;
            cnt['E'-'A']--;
            ans.push_back(9);
        }
        sort(ans.begin(),ans.end());
        printf("Case #%d: ",++Case);
        for(int i=0;i<ans.size();i++)printf("%d",ans[i]);
        puts("");
    }
    return 0;
}
