#include<cstdio>
int main(){
    int i,j,arr[10],t,freq[26];
    char str[3000];
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%s",str);
        for(j=0;j<26;j++)
            freq[j]=0;
        for(j=0;j<10;j++)
            arr[j]=0;
        for(j=0;str[j]!='\0';j++){
            freq[str[j]-'A']=freq[str[j]-'A']+1;
        }
        arr[0]=freq['Z'-'A'];
        arr[4]=freq['U'-'A'];
        arr[6]=freq['X'-'A'];
        arr[8]=freq['G'-'A'];
        arr[3]=freq['H'-'A']-arr[8];
        arr[7]=freq['S'-'A']-arr[6];
        arr[5]=freq['V'-'A']-arr[7];
        arr[2]=freq['W'-'A'];
        arr[1]=freq['O'-'A']-arr[0]-arr[2]-arr[4];
        arr[9]=(freq['N'-'A']-arr[1]-arr[7])/2;
        printf("Case #%d: ",i);
        for(j=0;j<10;j++){
            while(arr[j]--){
                printf("%d",j);
            }
        }
        printf("\n");
    }
    return 0;
}
