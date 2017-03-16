#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
int main()
{
 freopen("c.in","r",stdin);
 freopen("c.out","w",stdout);
 int t,p;scanf("%d",&t);
 for(p=1;p<=t;p++)
 {printf("Case #%d: ",p);
  long long a,b,o=0;scanf("%I64d%I64d",&a,&b);
  if((a<=1ll)&&(1ll<=b)){o++;}
  if((a<=4ll)&&(4ll<=b)){o++;}
  if((a<=9ll)&&(9ll<=b)){o++;}
  if((a<=121ll)&&(121ll<=b)){o++;}
  if((a<=484ll)&&(484ll<=b)){o++;}
  if((a<=10201ll)&&(10201ll<=b)){o++;}
  if((a<=12321ll)&&(12321ll<=b)){o++;}
  if((a<=14641ll)&&(14641ll<=b)){o++;}
  if((a<=40804ll)&&(40804ll<=b)){o++;}
  if((a<=44944ll)&&(44944ll<=b)){o++;}
  if((a<=1002001ll)&&(1002001ll<=b)){o++;}
  if((a<=1234321ll)&&(1234321ll<=b)){o++;}
  if((a<=4008004ll)&&(4008004ll<=b)){o++;}
  if((a<=100020001ll)&&(100020001ll<=b)){o++;}
  if((a<=102030201ll)&&(102030201ll<=b)){o++;}
  if((a<=104060401ll)&&(104060401ll<=b)){o++;}
  if((a<=121242121ll)&&(121242121ll<=b)){o++;}
  if((a<=123454321ll)&&(123454321ll<=b)){o++;}
  if((a<=125686521ll)&&(125686521ll<=b)){o++;}
  if((a<=400080004ll)&&(400080004ll<=b)){o++;}
  if((a<=404090404ll)&&(404090404ll<=b)){o++;}
  if((a<=10000200001ll)&&(10000200001ll<=b)){o++;}
  if((a<=10221412201ll)&&(10221412201ll<=b)){o++;}
  if((a<=12102420121ll)&&(12102420121ll<=b)){o++;}
  if((a<=12345654321ll)&&(12345654321ll<=b)){o++;}
  if((a<=40000800004ll)&&(40000800004ll<=b)){o++;}
  if((a<=1000002000001ll)&&(1000002000001ll<=b)){o++;}
  if((a<=1002003002001ll)&&(1002003002001ll<=b)){o++;}
  if((a<=1004006004001ll)&&(1004006004001ll<=b)){o++;}
  if((a<=1020304030201ll)&&(1020304030201ll<=b)){o++;}
  if((a<=1022325232201ll)&&(1022325232201ll<=b)){o++;}
  if((a<=1024348434201ll)&&(1024348434201ll<=b)){o++;}
  if((a<=1210024200121ll)&&(1210024200121ll<=b)){o++;}
  if((a<=1212225222121ll)&&(1212225222121ll<=b)){o++;}
  if((a<=1214428244121ll)&&(1214428244121ll<=b)){o++;}
  if((a<=1232346432321ll)&&(1232346432321ll<=b)){o++;}
  if((a<=1234567654321ll)&&(1234567654321ll<=b)){o++;}
  if((a<=4000008000004ll)&&(4000008000004ll<=b)){o++;}
  if((a<=4004009004004ll)&&(4004009004004ll<=b)){o++;}
  printf("%I64d\n",o);
 }
}