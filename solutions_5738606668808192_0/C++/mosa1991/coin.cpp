#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;


int main() {
	int n,m,t;
	cin >> t;
	cin >> n >> m;

	vector<ll> ans;
	for(ll i=2;i<=10;i++)
	{
	   double r = n/2;
	   ans.push_back(pow(i,r)+1);
	}	

	int tp = n/2;
	cout << "Case #1: " << endl;
        for(int i=0;i<m;i++)
	{
	    vector<int> v(n,0);
	    v[n-1] = v[0] = v[tp] = v[tp-1] = 1;
	
	     int k = i;
	     int r = 1;
	     while(k != 0)
             {
		if(k%2 == 1)
		{
		  v[r] = v[r+tp] = 1;	
		}
		k = k/2;
		r++;
	     }
	    for(int j=n-1;j>=0;j--)
		cout << v[j];
	    cout << " ";
	    for(int j=0;j<ans.size();j++)
		cout << ans[j] << " ";
	    cout << endl;
 
	}
	return 0;
}
