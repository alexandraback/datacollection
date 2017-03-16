#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int arr[55][55];

ll Power(int num,int times) {
	int i;
	ll ans = 1;
	for(i = 0;i < times;i++) {
		ans = ans*2;	
	}
	return ans;
}

int main() {
	int i,j,b,t,tc;
	ll pow,val,rem,m;
	ios::sync_with_stdio(false);
	freopen("input4.txt","r",stdin);
	freopen("output.txt","w",stdout);		
	cin>>t;
	tc = 0;
	while(t--) {
		cin>>b>>m;
		
		for(i = 1;i <= (b-1);i++) {
			for(j = 1;j <= b;j++) {
				if(i < j)
					arr[i][j] = 1;
				else
					arr[i][j] = 0;
			}
		}
		val = Power(2,b-2);
		cout<<"Case #"<<++tc<<": ";
		if(val < m) {
			cout<<"IMPOSSIBLE"<<endl;
		}
		else {
			rem = val - m;
			pow = 1;
			for(i = 0;i < 64;i++) {
				if(rem&pow) {
					arr[i+2][b] = 0;  
				}
				pow = pow*2;		
			}	
			cout<<"POSSIBLE"<<endl;	
			for(i= 1;i <= b;i++) {
				for(j = 1;j <= b;j++) {
					cout<<arr[i][j];
				}
				cout<<endl;
			}
		}	

	}

	
}
