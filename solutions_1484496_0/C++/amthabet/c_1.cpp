#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<memory.h>
using namespace std;

int arr[100];
int mask[3000000];

int main()	{

	//freopen("c_1_sample.in","rt",stdin);

	freopen("c_1_small.in","rt",stdin);
	freopen("c_1_small.out","wt",stdout);

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>arr[i];
		}
		memset(mask, 0, sizeof(mask));
		int mask1 = -1, mask2 = -1;
		for(int i=1;i+1<(1<<20);i++) {
			int sum = 0;
			for(int j=0;j<20;j++) {
				if(i&(1<<j)) sum += arr[j];
			}
			if(mask[sum] != 0) {
				mask1 = mask[sum];
				mask2 = i;
				break;
			}
			mask[sum] = i;
		}

		cout<<"Case #"<<tt<<":"<<endl;
		if(mask1 != -1) {
			string seb = "";
			for(int j=0;j<20;j++) if(mask1&(1<<j)) {
				cout<<seb<<arr[j];
				seb = " ";
			}
			cout<<endl;
			seb = "";
			for(int j=0;j<20;j++) if(mask2&(1<<j)) {
				cout<<seb<<arr[j];
				seb = " ";
			}
			cout<<endl;
		}
		else cout<<"Impossible"<<endl;
	}

	return 0;
}