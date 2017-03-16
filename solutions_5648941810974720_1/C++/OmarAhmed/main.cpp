#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int t,let[33];
vector<int>ans;
char s[2222];
string ss[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main()
{
   // freopen("in.txt","r",stdin);
       // freopen("out.txt","w",stdout);

scanf("%d",&t);
for(int tt=1;tt<=t;tt++){
        ans.clear();
        memset(let,0,sizeof(0));
            scanf(" %s",&s);
    int sz=strlen(s);
    for(int i=0;i<sz;i++){
        int pos=s[i]-'A';
        let[pos]++;
    }
    int all=0;
    if(let['Z'-'A']){
        all=let['Z'-'A'];
        let['Z'-'A']-=all;
        let['E'-'A']-=all;
        let['R'-'A']-=all;
        let['O'-'A']-=all;
        for(int qq=0;qq<all;qq++){ans.push_back(0);}
    }
    if(let['G'-'A']){
        all=let['G'-'A'];
        let['E'-'A']-=all;
        let['I'-'A']-=all;
        let['G'-'A']-=all;
        let['H'-'A']-=all;
        let['T'-'A']-=all;
        for(int qq=0;qq<all;qq++){ans.push_back(8);}
    }

    if(let['X'-'A']){
        all=let['X'-'A'];
        let['S'-'A']-=all;
        let['I'-'A']-=all;
        let['X'-'A']-=all;
        for(int qq=0;qq<all;qq++){ans.push_back(6);}
    }

    if(let['W'-'A']){
        all=let['W'-'A'];
                let['T'-'A']-=all;
                let['W'-'A']-=all;
                let['O'-'A']-=all;
        for(int qq=0;qq<all;qq++){ans.push_back(2);}
    }
    if(let['U'-'A']){
        all=let['U'-'A'];
        let['F'-'A']-=all;
        let['O'-'A']-=all;
        let['U'-'A']-=all;
        let['R'-'A']-=all;
        for(int qq=0;qq<all;qq++){ans.push_back(4);}
    }


    for(int i=0;i<10;i++){
        string dig=ss[i];
        int ok=1,mn=22222;
        for(int j=0;j<dig.size();j++){
            int pos=dig[j]-'A';
            if(!let[pos]){ok=0;break;}
            mn=min(let[pos],mn);
        }
        if(ok){
        for(int j=0;j<dig.size();j++){
            int pos=dig[j]-'A';
       let[pos]-=mn;
       }
       for(int j=0;j<mn;j++){ans.push_back(i);}
        }
    }
 printf("Case #%d: ",tt);
 sort(ans.begin(),ans.end());
 for(int i=0;i<ans.size();i++){printf("%d",ans[i]);}
 printf("\n");



}

   return 0;
}
