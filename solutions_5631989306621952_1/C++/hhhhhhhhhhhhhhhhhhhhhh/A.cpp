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

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		string s;
		cin>>s;
		string ret;
		for(int i=0;i<s.size();i++){
			ret=max(ret+s[i],s[i]+ret);
		}
		printf("Case #%d: ",_);
		cout<<ret<<endl;
	}
	return 0;
}