//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
 
using namespace std;

long tests;
long n;
short ev[10050][10050];
string L;
int X;
long ts;

long get(char x)
{
 if (x=='i')return 1+1;
 if (x=='j') return 2+1;
 if (x=='k') return 3+1;
}

long op(long a,long b)
{
     if (a<0&&b<0)return op(-a,-b);
     if (a<0)return -op(-a,b);
     if (b<0)return -op(a,-b);
     if (a==1) return b;
     if (b==1)return a;
     if (a==b)return -1;
     a--;
     b--;
     if (a==1&&b==2)return 4;
     if (a==1&&b==3) return -3;
     if (a==2&&b==1) return -4;
     if (a==3&&b==1) return 3;
     if (a==2&&b==3) return 2;
     return -2;
}

int main(){
//freopen("k.in","r",stdin);
//freopen("k.out","w",stdout);
freopen("C:/input.txt","r",stdin);
freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>tests;
long ts=0;
for (;tests;--tests)
{
    ++ts;
    cin>>L>>X;
    string res;
    string Ll;
    cin>>Ll;
    for (int i=1;i<=X;i++)
     res+=Ll;
    
    n=res.size();
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (j==i)
             ev[i][j]=get(res[i]);
            else ev[i][j]=op(ev[i][j-1],get(res[j]));
        }
    }
//    cout<<ev[0][2]<<" "<<ev[3][5]<<" "<<ev[6][n-1]<<endl;
    
    int found=0;
    for (int i=0;i<n;i++)
     for (int j=i+1;j+1<n;j++)
     {
      if (ev[0][i]==2&&ev[i+1][j]==3&&ev[j+1][n-1]==4)
       found=1;
     }
     string A="NO";if (found)A="YES";
    cout<<"Case #"<<ts<<": "<<A<<endl;
}

cin.get();cin.get();
return 0;}
