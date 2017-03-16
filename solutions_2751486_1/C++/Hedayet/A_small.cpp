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

bool vowel(char ch){
    string vo = "aeiou";
    rep(i,5)if(vo[i]==ch)return true;
    return false;
}

ll sum(int n){
    return ((ll)n*(n+1))/2;
}
ll ar[1000009];

int main()
{
	freopen("i2.txt","r",stdin);
	freopen("o2.txt","w",stdout);
	string str;
	int n,T,cas=0;

	cin>>T;

	while(T--){

	    cin>>str>>n;

	    memset(ar,0,sizeof(ar));

	    int cur = 0 ;
	    rep(i,str.size()){
	        if(vowel(str[i])){
	            cur=0;
	        }else{
	            cur++;
	            if(cur>=n){
	                ar[i-n+1]=str.size()-i;
	            }
	        }
	    }
	    ll ret=0;
	    for(int i=str.size()-1;i>=0;i--){
	        //cout<<ar[i]<<" "<<ar[i+1]<<endl;
	        if(ar[i+1]==0)ar[i+1]=-1;
	        int ct  = 0;
	        //if(!vowel(str[i]))ct=1;
	        ar[i]=max(ar[i],ar[i+1]+ct);
	        ret+=ar[i];
	    }
	    cout<<"Case #"<<++cas<<": "<<ret<<endl;
	}

return 0;
}
