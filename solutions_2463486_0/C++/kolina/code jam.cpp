#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool prov(long long x){
	vector<long long> d;
	while (x){
		d.push_back(x%10);
		x/=10;
	}
	long long i=0,j=(int)d.size()-1;
	while (i<j)
		if (d[i]!=d[j])
			return false;
		else{
			++i;
			--j;
		}
	return true;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long pal[]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};
	int test;
	cin >>test;
	for (int i=1; i<=test; ++i){
		long long a,b;
		cin >>a >>b;
		int count=0;
		for (int j=0; j<39 && pal[j]<=b; ++j)
			if (pal[j]>=a)
				++count;
		cout <<"Case #" <<i <<": " <<count <<endl;
	}
	return 0;
}