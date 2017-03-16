#include <iostream>
#include <cstdio>

using namespace std;

char trans[405]={0};
char str1[]="ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
char str2[]="ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
char str[505]={0};

int main()
{
 long i,j;
 long t;
 
 freopen("a.in","r",stdin);
 freopen("a.out","w",stdout);
 
 trans['y']='a';
 trans['e']='o';
 trans['q']='z';
 trans['z']='q';
 trans[' ']=' ';
 
 for(i=0;str1[i];i++)
   trans[str1[i]]=str2[i];
 scanf("%ld\n",&t);
 for(i=1;t;t--,i++)
   {
    gets(str);
    
    printf("Case #%ld: ",i);
    for(j=0;str[j];j++)
      printf("%c",trans[str[j]]);
    printf("\n");
   }
 
 
 return 0;
}
