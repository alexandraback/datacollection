#include<stdio.h>
#include<string.h>
#include<math.h>
  int test,count=1,ans,n,c,i,j,k;
int main(){
   
    char s[101];

    scanf("%d\n",&test);
    while(test--){
        ans=0;
        scanf("%s %d",s,&n);
        
        for(i=0;i<strlen(s);i++)
            for( j=i+n;j<=strlen(s);j++){
                c=0;
                for(k=i;k<j;k++){
                    if(s[k]=='a' || s[k]=='e' || s[k]=='i'|| s[k]=='o' || s[k]=='u')
                        c=0;
                    else
                        c++;
                    if(c>=n){
                        ans++;
                        break;
                    }
                }
            }
 
        printf("Case #%d: %d\n",count++,ans);
    }
    return 0;
}
 
