#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int vowel(char c){
    if(c!='a' && c!='e' && c!='u' && c!='o' && c!='i')
        return 0;
    else return 1;
}
int main()
{
    
    int t,tt=1;
    FILE *fr=fopen("/Users/akshaykhanna/Downloads/A-small-attempt0-1.in.txt","r");
    FILE *fw=fopen("/Users/akshaykhanna/Desktop/out.txt","w");
    fscanf(fr,"%d",&t);
    while (tt<=t) {
        char str[1000001];
        int a[1000001],len;
        fscanf(fr,"%s",str);
        len=(int)strlen(str);
        int k,i;
        fscanf(fr,"%d",&k);
        for (i=0; str[i]!='\0'; i++) {
            if(vowel(str[i]))
                a[i]=0;
            else if(i>0)
                a[i]=a[i-1]+1;
            else a[i]=1;
        }
        long long int sum=0,p=0;
        for (i=0; str[i]!='\0'; i++) {
            if(a[i]>=k){
                int j=i+k;
                while(a[j]<k)
                    j++;
                j++;
                if(j>len)
                    j=len;
                sum+=((i+1-k)*(j-i-1)+(i+1-k)+(j-i-1)+1);
                //printf("%d-- %d\n",t,((i+1-k)*(len-i-1)+(i+1-k)+(len-i-1)+1));
                p++;
            }
        }
        p--;
        sum-=((p*(p+1))/2);
        fprintf(fw,"Case #%d: %lld\n",tt,sum);
        tt++;
    }
    return 0;
}