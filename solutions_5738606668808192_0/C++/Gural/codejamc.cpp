#include<bits/stdc++.h>
#define maxn 500009
#define INF 1000000007
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mid(a,b) (a+b)/2
#define sz size()
#define ll long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define tr(i, c) for(typeof((c).begin()) i = (c).begin(); i!=(c).end(); i++)
using namespace std;
int arr[maxn];
int main(){
	freopen("1.out", "w", stdout);
	int qw;
	cin>>qw;
	cout << "Case #1:\n";
	int n,J,cur = 0,r,u,i,j;
	cin>>n>>J;
	i = 3;
	j = 4;
	while(J){
		memset(arr,0,sizeof(arr));
		arr[1] = 1;
		for(int t=2;t<=cur+1;t++){
			arr[t] = 0;
		}
		arr[cur+2] = 1;
		arr[n] = 1;
		arr[n-1] = 1;
		arr[i] = 1;
		arr[j] = 1;
		j+=2;
		if(j+2>n && i+4<=n){
			j = cur + 4;
			i+=2;
		}
		if(i+4>n && j+2>n){
			cur+=2;
			i = cur+3;
			j = cur+4;
		}
		for(int i=1;i<=n;i++){
			cout<<arr[i];
		}
		cout<<" ";
		for(int i=3;i<=10;i++)
			cout<<i<<' ';
		cout<<11;
		cout<<endl;
		J--;
	}

return 0;
}

