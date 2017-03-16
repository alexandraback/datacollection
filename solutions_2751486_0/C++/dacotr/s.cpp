#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<bitset>
#include<map>
#include<set>
#include<climits>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<cctype>
#include<queue>
#include<sstream>
#include <stack>
#include <list>
#include <numeric>
#define INT_MAX 2147483647
#define INT_MIN -2147483647 //2^31-1
#define pi acos(-1.0)
#define N 1000000
#define LL unsigned long long
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define assign(x,n) x=(int*)calloc(n,4)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define SWAP(a,b) a= a^b, b=a^b, a=a^b
typedef  long long int ull;
using namespace std;

bool fn(string s,int n){
     int c=0;
     for(int i=0;i<s.length();i++){
             if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')c=0;
             else c++;
             if(c>=n){return 1;}
             }
      return 0;
     }
int main()
{
//freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);

int t,tc=1;read(t);
while(t--){
           string s,s1;
           int n,l;
           
           cin>>s;read(n);
           l=s.length();
           int c=0;
           for(int i=0;i<l;i++){
                   for(int j=1;j<=l-i;j++){
                           s1=s.substr(i,j);
                           //cout<<s1<<endl;
                           if(fn(s1,n))c++;//cout<<s1<<endl;}
                           }
                   
                   }
          printf("Case #%d: %d\n",tc++,c);
           
           }

//system("pause");
return 0;
}

