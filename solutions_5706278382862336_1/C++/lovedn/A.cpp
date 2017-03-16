//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

long long gcd(long long a,long long b){
	if(b==0)return a;
	return gcd(b,a%b);
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("al.out","w",stdout);
	int test;
	scanf("%d",&test);
	
	int ct=0;
	while(test--){
		long long a,b;
		scanf("%I64d/%I64d",&a,&b);
		long long g=gcd(a,b);
		a/=g;
		b/=g;
		int ret=1;
		bool judge=true;
		long long tmp=b;
		while(tmp>1){
			if(tmp&1)judge=false;
			tmp/=2;
		}
		while(a*2/b<1){
			b/=2;
			ret++;
		}
		printf("Case #%d: ",++ct);
		if(judge)cout<<ret<<endl;
		else cout<<"impossible"<<endl;
	}
	return 0;
}