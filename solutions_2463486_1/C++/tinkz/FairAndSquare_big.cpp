#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <locale>
#include <sstream>
#include <deque>


#define FOR(i,a,b) for(int(i)=a;i<b;i++)
#define MAX 200004
#define mp make_pair
using namespace std;

typedef long long ll;
ll arr[]={1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004};

int main() {
	int t;
	cin>>t;
	ll a,b;
	int lower = -1;
	int upper = 0;
	int num =1;
	while (t--) {
		cin>>a>>b;
		lower = -1;
		upper = 0;
		for(int i=0;i<39;i++)
			if(a > arr[i])
				lower = i;
		for (int i=0;i<39;i++) {
			if(b >= arr[i] )
				upper = i;
		}
		cout<<"Case #"<<num<<": "<<upper - lower<<endl;
		num++;
	}
	
	
	return 0;
}