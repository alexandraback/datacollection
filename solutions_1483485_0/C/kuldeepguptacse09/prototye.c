#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define f(i,n) for(i=1;i<=n;i++)
#define fa(i,a,n) for(i=a;i<n;i++)
#define in(n) scanf("%d",&n)
#define MOD  1000000009ll
   
int main()
{
    int t,i,j,n,k,m;
    int a[30]={0};
    char s[1000];
    char *q1="ejp mysljylc kd kxveddknmc re jsicpdrysi",*a1="our language is impossible to understand",*q2="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",*a2="there are twenty six factorial possibilities",*q3="de kr kd eoya kw aej tysr re ujdr lkgc jv",*a3="so it is okay if you want to just give up";
    for(i=0;q1[i];i++)if(q1[i]!=' '){a[q1[i]-'a']=a1[i]-'a';}
    for(i=0;q2[i];i++){a[q2[i]-'a']=a2[i]-'a';}
    for(i=0;q3[i];i++){a[q3[i]-'a']=a3[i]-'a';}
    a['q'-'a']='z'-'a';
    a['z'-'a']='q'-'a';    
    //for(i=0;i<26;i++){printf("%c %c\n",i+'a',a[i]+'a');}
    freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
    in(t);
    gets(s);
    i=1;
    while(i<=t){
               gets(s);
               printf("Case #%d: ",i);
               for(j=0;s[j];j++)if(s[j]>='a'&&s[j]<='z')putchar(a[s[j]-'a']+'a');else putchar(s[j]);
               putchar('\n');
               
               i++;}
               
              // system("pause");
    
    return 0;}
