#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

long long r,t,T;

bool check(long long n){
	if((n*(2*r+2*n-1)) <= t)
		return true;
	else
		return false;
}

int main(){
	int l;
	cin>>T;
	for(int l=1;l<=T;l++){
		cout<<"Case #"<<l<<": ";
		cin>>r>>t;
		int i=1,j=sqrt(t/2)+1;
		while(i<j){
			int k=(i+j)/2+1;
			if(check(k))
				i=k;
			else
				j=k-1;
		}
		cout<<i<<endl;
	}
	return 0;
}
		
