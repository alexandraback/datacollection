#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int n,t;
char s[1001];
int main()
{
    //freopen("in.txt","r",stdin);
      //  freopen("out.txt","w",stdout);

scanf("%d",&t );

for(int tt=1;tt<=t;tt++){
    scanf(" %s",&s);
    int sz=strlen(s);
    string ans="";
    ans+=s[0];
    for(int i=1;i<sz;i++){
        if(s[i]>=ans[0]){
            string temp=s[i]+ans;
           swap(ans,temp);
        }else{
        ans+=s[i];
        }

    }
    printf("Case #%d: %s\n",tt,ans.c_str());


}

    return 0;
}
