#include<iostream>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
#include<complex>
#include<bitset>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<iomanip>
#include<utility>

#define pb push_back
#define pp pop_back
#define xx first
#define yy second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int maxn=1000+10;
const double eps=1e-9;
int m[maxn],h[maxn],d[maxn],p[2],s[2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){	
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>h[i]>>m[i];
			sum+=h[i];
		}
		cout<<"Case #"<<l<<": ";
		if(sum==1){
			cout<<0<<endl;
			continue;
		}
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		int num=0;
		for(int i=1;i<=n;i++){
			if(h[i]==2){
				p[0]=d[i],m[0]=s[i];
				p[1]=d[i],m[1]=s[i]+1;
			}
			else{
				p[num]=d[i],s[num]=m[i];
				num++;
			}
		}
		if(s[0]==s[1]){
			cout<<0<<endl;
			continue;
		}
		double ti=0;
		if(s[0]<s[1]){
			swap(s[0],s[1]);
			swap(p[0],p[1]);
		}
		int d1=360-p[0];
		int d2=360-p[1];
		double t1=(double)d1/360.*(double)s[0];
		double t2=(double)d2/360.*(double)s[1]+s[1];
		if(t2<=t1)cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}
