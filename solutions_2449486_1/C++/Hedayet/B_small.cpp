//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>

using namespace std;

#define mp make_pair
#define rep(i,n) for(int i=0,_n=n;i<_n;i++)
#define reps(i,s,n) for(int i=s,_n=n;i<_n;i++)
#define pi 2.0*acos(0.0)
#define MAX 2147483647
#define MIN -2147483647
#define torad(a) (a*pi)/180.0;
#define eps 0.000000001
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front

typedef long long ll;
typedef vector<int>VI;
typedef map<string,int> MSI;
typedef set<int>SI;
typedef pair<int,int>PAR;
typedef vector<PAR>VP;

#define inn(n) scanf("%d",&n)

int b[109][109],yes[109][109],N,M,R[109],C[109];

void __clear(){
    memset(R,0,sizeof(R));
    memset(C,0,sizeof(C));
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int kas;
	inn(kas);
	rep(cas,kas){
	    __clear();
	    inn(N);
	    inn(M);
	    rep(i,N){
	        rep(j,M){
	            cin>>b[i][j];
	            yes[i][j]=1;
	            R[i]=max(R[i],b[i][j]);
	            C[j]=max(C[j],b[i][j]);
	        }
	    }

	    rep(i,N){
	        rep(j,M){
	            if(R[i]>b[i][j]&&C[j]>b[i][j]){
	                yes[i][j]=0;
                }
	        }
	    }

	    int success=1;

	    rep(i,N){
	        rep(j,M){
	            success&=yes[i][j];
	        }
	    }
	    string str[]={"NO","YES"};

	    printf("Case #%d: %s\n",cas+1,str[success].c_str());
	}
return 0;
}
