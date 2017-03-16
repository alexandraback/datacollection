#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define fill(a,v) memset(a, v, sizeof a)
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define sz size()
#define ln length()
#define forf(i,a,b) for(int i=a;i<b;i++)
#define forfa(i,a,b) for(int i=a;i<=b;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define mod 1000000007


int main() {
	int t;
	cin>>t;
	forf(z,1,t+1)
	{
		int f=0;
		cout<<"Case #"<<z<<": ";
		unsigned long long b,m,k;
		cin>>b>>m;
		k=1LL<<(b-2);
		if(m>k){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		else{
			cout<<"POSSIBLE\n";
			if(m==k){
				m--;
				f=1;
			}
			cout<<"0";
			//now print len(b-2);
			string ans;
			while(m!=0){
				ans+=(char)((m%2) + '0');
				m/=2;
			}
			string aa;
			for(int i=1;i<=((b-2)-ans.size());i++)
				aa = aa + '0';
			for(int i=ans.size()-1;i>=0;i--)
				aa = aa + ans[i];
			cout<<aa;
			if(f)
				cout<<"1";
			else
				cout<<"0";
			cout<<"\n";
			for(int i=1;i<b;i++)
			{
				for(int j=0;j<b;j++){
					if(j>i)
						cout<<"1";
					else
						cout<<"0";
				}
				cout<<"\n";
			}
		}
	}

	return 0;
}
