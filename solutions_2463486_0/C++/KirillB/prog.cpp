#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
#include <time.h>
#include <fstream>
using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "C-small-attempt0";

void init(){
	freopen((problem_name+".in").c_str(),"rt",stdin);
	freopen((problem_name+".out").c_str(),"wt",stdout);
}

int check(long long val)
{
	vi res;
	while (val)
	{
		res.push_back(val%10);
		val/=10;
	}

	for (int i=0,j=sz(res)-1;i<j;i++,j--)
		if (res[i]!=res[j]) return 0;
	return 1;
}

vector <long long> arr;

int main() {

	init();

	int tst;

	scanf("%d\n",&tst);

/*	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(4);
	arr.push_back(9);
	arr.push_back(121);
*/
	
//	cout << lower_bound(arr.begin(),arr.end(),5)-arr.begin();

//	return 0;
	arr.push_back(0);
	//return 0;
	for (long long i=1;i<=10000000;i++) {
		if (check(i) && check(i*i)) {
			arr.push_back(i*i);
		//	cout << i*i << endl;
		}
	//	if (i%100000==0)
	//		cout << sz(arr) << endl;
	}

	arr.push_back(1ll<<60);

	//for (int i=0;i<sz(arr);i++)
	//	cout << arr[i] << " ";

//	cout << sz(arr);
//	return 0;

	for (int cas=1;cas<=tst;cas++)
	{
		
		long long a,b;
		scanf("%lld %lld",&a,&b);

		int l = lower_bound(arr.begin(),arr.end(),a)-arr.begin();
	//	cout << l;
		int r = lower_bound(arr.begin(),arr.end(),b+1)-arr.begin();
	//	cout << r;
		
	

		printf("Case #%d: %d\n",cas,r-l);
	}

	
	


	






	return 0;
}