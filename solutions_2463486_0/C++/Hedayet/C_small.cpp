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

int isPal(int n){
    string str="";
    while(n){
        str+=(char)(n%10+'0');
        n/=10;
    }
    string a = str;
    reverse(a.begin(),a.end());
    if(a==str)return 1;
    return 0;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int kas,ret[1009]={0};
	cin>>kas;
	for(int i=1;i<=1000;i++){
	    int x = i*i;

	    ret[i]+=ret[i-1];
	    if(x>1000)continue;
	    if(isPal(i))
	    ret[x]=isPal(x);
	}
	rep(cas,kas){
	    int A,B;
	    cin>>A>>B;
	    printf("Case #%d: ",cas+1);
	    cout<<ret[B]-ret[A-1]<<endl;
	}
return 0;
}
