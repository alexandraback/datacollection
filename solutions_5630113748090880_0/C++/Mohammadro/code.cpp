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

int cnt[5000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int l=1;l<=t;l++){
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		for(int i=1;i<2*n;i++){
			for(int j=0;j<n;j++){
				int x;
				cin>>x;
				cnt[x]++;
			}
		}
		cout<<"Case #"<<l<<":";
		for(int i=0;i<5000;i++){
			if(cnt[i]%2){
				cout<<" "<<i;		
			}
		}
		cout<<endl;
	}
	return 0;
}
