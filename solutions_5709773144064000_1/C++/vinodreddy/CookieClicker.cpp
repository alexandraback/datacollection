#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
#include<iomanip>
using namespace std;

#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define itr iterator
#define get(t) int t;cin >> t;
#define fi first
#define se second
#define mp make_pair
#define foreach(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end(); it++)
#define all(x) x.begin(),x.end()


typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<double> vd;

inline void sfr (int *a)
{
    char c = 0;
    while(c<33)
    c = fgetc(stdin);
    *a = 0;
    while(c>33)
    {
               *a = *a*10 + c - '0';
               c = fgetc(stdin);
    }
}

inline void sfp(int a){
     char c[1000];
     sprintf(c,"%d",a);
     puts(c);
}

int main(){
    ofstream out;
    out.open("output.txt");
    ifstream in;
    in.open("input.txt");
    int t;
    cin >> t;
    f(ct,1,t+1){
               double c,f,x;
               cin >> c >> f >> x;
               if(x < c){
                    printf("Case #%d: %0.7lf \n",ct,x/2);
                    continue;
               }
               long long bnd = ceil((f*x-(f+2)*c)/(c*f));
               double val = 0;
               f(i,0,bnd){
                          val = val+c/(i*f+2);
               }
               if(bnd < 0)bnd = 0;
               val = val+(x)/(bnd*f+2);
               printf("Case #%d: %0.7lf \n",ct,val);
    }
    get(wait);
}

