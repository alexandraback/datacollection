#include<bits/stdc++.h>
using namespace std;
char s[1005];
vector<char> v;
bool good(int n,char c)
{
    if(c>v[0]) return 1;
    if(c<v[0]) return 0;
    for(int i=1;i<n;i++){
        if(v[i-1]>v[i]) return 1;
        if(v[i-1]<v[i]) return 0;
    }
    return 0;
}
main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);


    int t;
    scanf("%d",&t);
    for(int kase=1;kase<=t;kase++){
        printf("Case #%d: ",kase);
        scanf("%s",s);
        int n=strlen(s);
        v.clear();
        v.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(good(i,s[i])){
                v.insert(v.begin(),s[i]);
            }
            else{
                v.push_back(s[i]);
            }
        }
        for(char c:v) putchar(c);
        putchar('\n');
    }
}
