#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool consonant(char x){
    return x!='a' && x!='e' && x!='i' && x!='o' && x!='u';
}

int n;
char str[1000010];

FILE * pread = fopen("inA.txt", "r");
FILE * pwrite = fopen("outA.txt", "w");

int main(){
    int i, j, k, cnt, len;
    int cses;
    fscanf(pread, "%d", &cses);
    for(j=1;j<=cses;j++){
    fscanf(pread, "%s", str);
    fscanf(pread, "%d", &k);
    len = strlen(str);
    cnt = 0;
    for(i=0;i<k;i++) if(consonant(str[i])) cnt++;
    
    int ans=0;
    int p=-1;
    for(i=k-1;i<len;i++){
        //printf("%d: cnt %d\n", i, cnt);
        if(cnt == k) p = i-k+1;
        ans+=p+1;
        if(consonant(str[i+1])) cnt++;
        if(consonant(str[i-k+1])) cnt--;
    }
    
    fprintf(pwrite, "Case #%d: %d\n", j, ans);
        
    }
    system("pause");
    return 0;
}
