#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <fstream>
using namespace std;
#define fon(i,n) for(i=0;i<n;++i)
#define re return
#define ll long long
const double EPS = 1E-9;const int INF = 1000000000;const ll INF64 = (ll)1E18;const double PI = 3.1415926535897932384626433832795;

ll x,y;

typedef struct{ll a,b;}tpo;

bool tcomp(tpo a,tpo b){
	return a.a>b.a;
}
bool vow(char a){
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')re true;
	re false;
}
int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("output.txt");
	
	ll i,j,n,m,T,t,k,A,B,k1,k2,k3,j1,j2,j3;
	cin>>T;
	char *s=new char[8000000];
	int *all=new int[8000000],iall;
	ll slen=8000000-1,sum;
	for(t=0;t<T;++t){
		memset(s,0,slen+1);
		cin>>s>>n;slen=strlen(s);

		iall=0;
		int prev=0;
		for(i=0;i<slen;++i){
			if(!vow(s[i]))prev++;else prev=0;
			if(prev>=n)all[iall++]=i-n+1;
		}
		sum=0;
		if(iall>=0){
			prev=-1;
			for(i=0;i<iall;++i){
				sum+=(all[i]-prev)*(slen-(all[i]+n-1));
				prev=all[i];
			}
		}
		cout<<"Case #"<<t+1<<": "<<sum<<endl;
	}
	re 0;
}