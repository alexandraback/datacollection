#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<bitset>
#define pii pair<int,int>
#define A first
#define B second
using namespace std;
int n,J,ct,ns2,ns3;
char s[10001],s2[10001],s3[10001];
void Do(){
    scanf("%s",s); ns2 = ns3 = 0;
    s2[ns2++] = s[0];
    for(int i=1;s[i]!='\0';i++){
        if(s[i] >= s2[ns2-1]) s2[ns2++] = s[i];
        else s3[ns3++] = s[i];
    }
    for(int i=ns2-1;i>=0;i--) printf("%c",s2[i]);
    for(int i=0;i<ns3;i++) printf("%c",s3[i]);
}
int main(){
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int rr=1;rr<=T;rr++){
        printf("Case #%d: ",rr);
        Do();
        printf("\n");
    }
    return 0;
}
