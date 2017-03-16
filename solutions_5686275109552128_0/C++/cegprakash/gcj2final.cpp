#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <sstream>
#include <queue>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	freopen("gcj2.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,c=1,n,i,x,j;
	vector<int> arr;
	cin>>t;
	while(t--){
		arr.clear();
		cout<<"Case #"<<c++<<": ";
		cin>>n;
		int ans = 0;
		for(i=0;i<n;i++){
			cin>>x;
			arr.push_back(x);
			ans = max(ans,x);
		}
		for(i=1;i<=1000;i++){
			int sum = i;
			for(j=0;j<n;j++){
				sum+=arr[j]/i - (arr[j]%i==0);
			}
			ans = min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}