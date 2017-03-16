// created by Marchecnko Vadim [midav7]
// I did it just for fun =)
// v 0.7

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <conio.h>
#include <cmath>
#include <map>
#include <set>
#include <climits>

#define foread freopen("input.txt","r",stdin)
#define fowrite freopen("output.txt","w",stdout)
#define pi 3.141592

using namespace std;
long long s[50];
int main(){
foread;
fowrite;
s[1]=1;
s[2]=4;
s[3]=9;
s[4]=121;
s[5]=484;
s[6]=10201;
s[7]=12321;
s[8]=14641;
s[9]=40804;
s[10]=44944;
s[11]=1002001;
s[12]=1234321;
s[13]=4008004;
s[14]=100020001;
s[15]=102030201;
s[16]=104060401;
s[17]=121242121;
s[18]=123454321;
s[19]=125686521;
s[20]=400080004;
s[21]=404090404;
s[22]=10000200001;
s[23]=10221412201;
s[24]=12102420121;
s[25]=12345654321;
s[26]=40000800004;
s[27]=1000002000001;
s[28]=1002003002001;
s[29]=1004006004001;
s[30]=1020304030201;
s[31]=1022325232201;
s[32]=1024348434201;
s[33]=1210024200121;
s[34]=1212225222121;
s[35]=1214428244121;
s[36]=1232346432321;
s[37]=1234567654321;
s[38]=4000008000004;
s[39]=4004009004004;
s[40]=100000020000001;
s[41]=100220141022001;
s[42]=102012040210201;
s[43]=102234363432201;
s[44]=121000242000121;
s[45]=121242363242121;
s[46]=123212464212321;
s[47]=123456787654321;
s[48]=400000080000004;
int t,ans;
long long a,b;
scanf("%d",&t);
for (int kk=1; kk<=t; ++kk)
 {
   scanf("%I64d %I64d",&a,&b);
   ans=0;
   for (int i=1; i<=48; ++i)
     if (a<=s[i] && s[i]<=b)  ++ans;
   printf("Case #%d: %d\n",kk,ans);
 }
return 0;
}





