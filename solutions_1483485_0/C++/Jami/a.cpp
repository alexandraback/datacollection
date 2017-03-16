#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<iterator>
using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps 1e-9
#define i64 long long
#define MX 1000002

typedef pair<int,int> pii;

char mp[27]={"yhesocvxduiglbkrztnwjpfmaq"};

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	string a;
	int cs,t=1,i;
	getline(cin,a);
	sscanf(a.c_str(),"%d",&cs);
	while(cs--){
		getline(cin,a);
		for(i=0;i<a.size();i++){
			if(isalpha(a[i])){
				a[i]=mp[a[i]-'a'];
			}
		}
		cout<<"Case #"<<t++<<": "<<a<<endl;
	}
	return 0;
}


