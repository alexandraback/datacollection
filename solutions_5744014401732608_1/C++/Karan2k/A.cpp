#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 100005
#define INF (ll)1e18
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

ll power[60];

int arr[60][60];

int main(){
	ios_base::sync_with_stdio(false);
	int t, T=1;
	cin>>t;

	power[0] = 1;

	for(int i=1 ; i<60 ; i++)
		power[i] = power[i-1] * 2ll;

	while(t--){
		int n;
		ll m;
		cin>>n>>m;

		if(power[n-2]<m){
			cout<<"Case #"<<T++<<": "<<"IMPOSSIBLE\n";
			continue;	
		}

		for(int i=1 ; i<60 ; i++)
			for(int j=1 ; j<60 ; j++)
				arr[i][j] = 0;

		for(int i=1 ; i<=n ; i++)
			for(int j=i+1 ; j<=n ; j++)
				arr[i][j] = 1;

		ll diff = power[n-2] - m;
		int l = n-1;

		while(diff){
			int temp = diff % 2;
			if(diff % 2 == 1)
				arr[1][l] = 0;
			l--;
			diff /= 2;
		}

		cout<<"Case #"<<T++<<": "<<"POSSIBLE\n";
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++)
				cout<<arr[i][j];
			cout<<"\n";
		}
	}

	return 0;
}