

#include"stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,t;
	cin>>t;
	for (int t1=0; t1<t; t1++){
		long long a,b,k;
		cin>>a>>b>>k;
	    long long ans=0;
		for (int i=0; i<a; i++)
			for (int j=0; j<b; j++)
				if ((i&j)<k) ans++;
		cout<<"Case #"<<t1+1<<": "<<ans<<endl;
	}


	//system("pause");

	return 0;

}