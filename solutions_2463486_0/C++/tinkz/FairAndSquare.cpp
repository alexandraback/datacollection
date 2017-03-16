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
vector<int> counter(1004,0);

bool pallindrome(int a) {
	int b = a;
	int s = 0;
	while (a != 0) {
		int r = a%10;
		s = s*10 + r;
		a /= 10;
	}
	if(b == s)
		return true;
	return false;
}

bool sq(int a) {
	
	int b = sqrt(a);
	if(b*b == a)
		return true;
	return false;
}

void preprocess() {
	
	for (int i=1; i<= 1000; i++) {
		if (pallindrome(i)) {
			if(sq(i) && pallindrome(int(sqrt(i))))
				counter[i] = counter[i-1]+1;
			else
				counter[i] = counter[i-1];
		}
		else
			counter[i] = counter[i-1];
	}
}

int main() {
	int t;
	cin>>t;
	preprocess();
	int a,b;
	int num=1;
	while (t--) {
		cin>>a>>b;
		cout<<"Case #"<<num<<": "<<counter[b]-counter[a-1]<<endl;
		num++;
		
	}
	
	
	return 0;
}