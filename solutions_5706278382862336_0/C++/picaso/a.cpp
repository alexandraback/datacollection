#include <iostream>
#include <list>
#include <stack>
long long int gcd (long long  int a,long long  int b )
{
    long long int c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}
int main() {
    int t,p=1;
    FILE *fr=fopen("/Users/akshaykhanna/Downloads/A-small-attempt0.in-2.txt", "r");
    FILE *fw=fopen("/Users/akshaykhanna/Desktop/out.txt", "w");
    
    fscanf(fr,"%d",&t);
    while (p<=t) {
        char s[10];
        fscanf(fr,"%s",s);
        long long int num1=0,num2=0,i=0;
        while (s[i]!='/') {
            num1=num1*10 + s[i]-'0';
            i++;
        }
        i++;
        while (s[i]!='\0') {
            num2=num2*10 + s[i]-'0';
            i++;
        }
        if(num1>num2) fprintf(fw,"Case #%d: impossible\n",p);
        else{
            long long int k=gcd(num1,num2),cn=0;
            num1/=k;
            num2/=k;
            if((num2-(num2&-num2))==0){
                while (num1<num2) {
                    num2/=2;
                    cn++;
                }
                fprintf(fw,"Case #%d: %lld\n",p,cn);
            }
            else fprintf(fw,"Case #%d: impossible\n",p);
        }
        p++;
    }
    return 0;
}