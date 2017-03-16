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

int tot[3000];
int main(){
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		memset(tot,0,sizeof(tot));
		int n;
		scanf("%d",&n);
		for(int i=0;i<2*n-1;i++){
			for(int j=0;j<n;j++){
				int x;
				scanf("%d",&x);
				tot[x]++;
			}
		}
		printf("Case #%d:",_);
		for(int i=1;i<=2500;i++){
			if(tot[i]&1)printf(" %d",i);
		}
		puts("");
	}
	return 0;
}