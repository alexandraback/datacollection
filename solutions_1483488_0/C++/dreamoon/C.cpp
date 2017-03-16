#include<stdio.h>
#include<set>
#include<string.h>
#include<algorithm>
using namespace std;
int d[2000000][7];
int main(){
    int i,cs=0,j,k,T,A,B;
    for(i=1;i<2000000;i++){
        char s[24]={};
        sprintf(s,"%d",i);
        k=strlen(s);
        int kk=0;
        set<int>H;
        for(j=0;j<k-1;j++){
            s[k+j]=s[j];
            int tmp=atoi(s+j+1);
            if(!H.count(tmp)){
                H.insert(tmp);
                d[i][kk++]=tmp;
            }
        }
    }
    scanf("%d",&T);
    while(T--){
        int an=0;
        scanf("%d%d",&A,&B);
        for(i=A;i<B;i++){
            for(j=0;j<7;j++)
                if(d[i][j]>i&&d[i][j]<=B)an++;
        }
        printf("Case #%d: %d\n",++cs,an);
    }
}
