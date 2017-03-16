#include <iostream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	freopen("q4.txt", "r", stdin);
	freopen("q4.out", "w", stdout);

	int cases;
	cin>>cases;

	for(int i=0;i<cases;i++){
		int n;
		cin>>n;

		vector<pair<double, int>> vals;

		for(int j=0;j<n;j++){
			double d;
			cin>>d;
			vals.push_back(make_pair(d, 1));
		}

		for(int j=0;j<n;j++){
			double d;
			cin>>d;
			vals.push_back(make_pair(d, -1));
		}

		sort(vals.begin(), vals.end());
		
		int deceit = 0;
		int war = 0;

		for(int j=0;j<2*n;j++)
			if(vals[j].second == -1)
				break;
			else
				deceit++;

		int a = 0;
		int b = 0;
		for(int j=2*n-1;j>-1;j--){
			a += vals[j].second;
			if(a > war)
				war = a;
			if(a < b)
				b = a;
		}

		cout<<"Case #"<<i+1<<": "<<n - max(deceit, abs(b))<<" "<<war<<endl;

		/*cout<<"Case #"<<i+1<<"("<<n<<"): ";
		if(n-deceit+b < 0)
			cout<<0<<" "<<war<<endl;
		else
			cout<<n-deceit+b<<" "<<war<<endl;
		
		for(int j=0;j<2*n;j++)
			cout<<" "<<vals[j].first<<"("<<vals[j].second<<") ";
		cout<<endl;*/

	}
	return 0;
}