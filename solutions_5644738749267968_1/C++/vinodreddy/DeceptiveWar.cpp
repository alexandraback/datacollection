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
using namespace std;

#define f(i,a,b) for(int i = a;i < b;i++)
#define pb push_back
#define itr iterator
#define get(t) int t;in >> t;
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
    in >> t;
    f(ct,1,t+1){
                int n;
                in >> n;
                vd A,B;
                f(i,0,n){
                         double d;
                         in >> d;
                         A.pb(d);
                }
                f(i,0,n){
                         double d;
                         in >> d;
                         B.pb(d);
                }
                sort(A.begin(),A.end());
                sort(B.begin(),B.end());
                int bnt = 0,p = 0;
                f(i,0,n){
                         if(A[i] > B[p]){
                                 p++;
                                 bnt++;
                         }
                }
                                   
                int j = 0,cnt = 0;
                f(i,0,n){
                         while(j < n && A[i] > B[j])j++;
                         if(j >= n)break;
                         cnt++;
                         j++;
                         if(j >= n)break;
                }
	            out << "Case #" << ct << ": " << bnt << " " << n-cnt << endl;
    }
    in.close();
    out.close();
    get(wait);
}

