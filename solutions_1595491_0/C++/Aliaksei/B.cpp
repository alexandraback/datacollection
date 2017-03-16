#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	for (int cs=0; cs<T; ++cs)
	{
		int n, s, p;
		cin>>n>>s>>p;
		vector <int> a(n);
		for (int j=0; j<n; ++j) cin>>a[j];
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());

		int count=0;
		for (int j=0; j<n; ++j)
		{
			if (a[j]%3==0) {
				if (a[j]>=3*p) {++count; continue;}
				if (a[j]>=3*p-3&&s&&p-2>=0) {++count; --s ; continue;} 
			}
			else if(a[j]%3==1) {
				if (a[j]>=3*p-2) {++count; continue;}				
			}
			else {
				if (a[j]>=3*p-1) {++count; continue;}
				if (a[j]>=3*p-4&&s&&p-2>=0) {++count; --s ; continue;} 
			}
		}
		cout<<"Case #"<<cs+1<<": "<<count<<endl;
	}
}