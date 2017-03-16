#include<stdio.h>
#include<math.h>
/* in gcc please link the math library when compiling, with the option -lm*/
#include<string.h>
unsigned long long divisor(unsigned long long k){
double root=sqrt(k)+1;
root=root<500?root:500; /* comment this line if you are not in a hurry */
unsigned long long i=1;
for(;++i<=root&&k%i;);
return i>root?0:i; /* returns 0 if argument is prime, non-zero otherwise */
}
unsigned long long convertToBase(char*s,int base){
unsigned long long x=0;
for(;*s;s++)x=base*x+*s-'0';
return x;
}
int makeNextString(char*s){
int i = strlen(s)-2;
for(;i&&s[i]=='1';)s[i--]='0';
s[i]='1';
return i;
}
int mkDivs(char*s,unsigned long long*divs){
unsigned long long i,t;
for(t=0,i=0;i++<9&!t;)t|=!(divs[i-1]=divisor(convertToBase(s,i+1)));
return !t; /*1 if coin is non-prime in all bases, 0 otherwise */
}
int printJamcoins(int length, int nrOfCoins){
char s[40];int i;
unsigned long long divs[9];
for(s[0]=s[length-1]='1',s[length]=0,i=1;i<length-1;s[i++]='0');
for(;nrOfCoins;){
mkDivs(s,divs)?printf("%s %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",
s,divs[0],divs[1],divs[2],divs[3],divs[4],divs[5],divs[6],divs[7],divs[8]),nrOfCoins--:0;
nrOfCoins*=!!makeNextString(s);
}}
int testCoin(char*s){
unsigned long long divs[9]={0,0,0,0,0,0,0,0,0};
int t = mkDivs(s,divs);
printf("%s %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",
s,divs[0],divs[1],divs[2],divs[3],divs[4],divs[5],divs[6],divs[7],divs[8]);
return t; /*returns 1 if coin is non-prime in all bases, 0 otherwise */
}

/*
void stringify(void){char s[100];for(;gets(s);)printf("%s\\n\\\n",s);} 

Precomputing the outputs for cases
1 16 50 and 1 32 50, and then just have a source file like

main(){int n,i=2;for(;i--;)scanf("%d",n);
printf(n==16?"precomputed output for the first case":
"precomputed output for the second case");}

is not necessary, since computing the output is very fast.
*/

int main(){
 int t,n,j,i;
 scanf("%d",&t);
 for(i=0;i++<t;){
  scanf("%d%d",&n,&j);
  printf("Case #%d:\n",i);
  printJamcoins(n,j);
 }
}
