#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define pb(VALUE) push_back(VALUE)
#define pob() pop_back()
#define mp(FST,SEC) make_pair(FST,SEC)
#define len(STR) STR.length()
#define F first
#define S second
#define INF 2000000000

#define refresh(ARRAY,TARGET,VALUE) frdn(DEFINED_I,0,TARGET)ARRAY[DEFINED_I]=VALUE
#define watch(VALUE) {cout<<#VALUE;printf("=");cout<<VALUE;printf("\n");}
#define stop exit(0)

using namespace std;

string a[600000];
int f[10000];
int n,m,k,t;
string s;


int main(){ 
     
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
     scanf("%d",&t);
     for(int p=1;p<=t;p++)
        {
           cin >> s >> n;
           int un=0;
           int u=-1;
           long long ans=0;
           int o=0;
           for(int i=0;i<len(s);i++)
            {
              if (s[i]=='a'|s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='e') {u=i;o=0; continue;}
              o++;
              if (o==n){
                        int k1=u-un+1+1;
                        int k2=len(s)-i;
                        ans+=(long long)k1*k2;
                        un=u+2;   
                        u++;
                        o--;
                        }
                         
            }                      
           cout << "Case #" << p << ": " << ans << endl;
        }
return 0;
}
