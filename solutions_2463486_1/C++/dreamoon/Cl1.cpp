#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int cs;
vector<long long>d;
int main(){
    int T,A,B,i,j;
    for(i=1;i<=10000000;i++){
        char s[16];
        sprintf(s,"%d",i);
        int len=strlen(s);
        for(j=0;j<len;j++)
            if(s[j]!=s[len-1-j])break;
        if(j==len){
            sprintf(s,"%I64d",(long long)i*i);
            len=strlen(s);
            for(j=0;j<len;j++)
                if(s[j]!=s[len-1-j])break;
            if(j==len){
                d.push_back((long long)i*i);
                fprintf(stderr,"[%I64d]\n",d.back());
            }
        }
    }
    fprintf(stderr,"end\n");
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&A,&B);
        printf("Case #%d: ",++cs);
        int an=0;
        for(i=0;i<d.size();i++)if(A<=d[i]&&d[i]<=B)an++;
        printf("%d\n",an);
        
    }
}
