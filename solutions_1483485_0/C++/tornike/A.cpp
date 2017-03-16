#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[30];
string s1,s2,s3,s4,s5,s6;
int T;
char text[500];
void fill()
{
s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
s2 = "our language is impossible to understand";
s3 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
s4 = "there are twenty six factorial possibilities";
s5 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
s6 = "so it is okay if you want to just give up";

 int i;
 for(i=0;i<s1.length();i++)
  if(s1[i]!=' ')
   a[s1[i]-'a'] = s2[i]-'a';
 for(i=0;i<s3.length();i++)
  if(s3[i]!=' ')
   a[s3[i]-'a'] = s4[i]-'a';
 for(i=0;i<s5.length();i++)
  if(s5[i]!=' ')
   a[s5[i]-'a'] = s6[i]-'a';
}
main()
{
 freopen("A.in","r",stdin);
 freopen("A.out","w",stdout);
 for(int i=0;i<=25;i++)
  a[i] =-1;
  fill();
 a[25] = 'q'-'a';
 a['q'-'a']='z'-'a';
 int i,j;
 string ans;
 scanf("%d",&T);
 cin.getline(text,500);
 for(j=1;j<=T;j++)
 {
  cin.getline(text,500);
  ans = "";
  for(i=0;i<strlen(text);i++)                 
   if(text[i]==' ') ans+=" ";
   else ans+=char(a[text[i]-'a']+'a');      
  printf("Case #%d: ",j);
  cout << ans << endl;
 }
 //system("pause");
      
}
