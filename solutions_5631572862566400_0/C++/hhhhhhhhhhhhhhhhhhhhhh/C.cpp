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

int f[1010],a[1010];
bool judge(int tot){
	for(int i=0;i<tot;i++){
		int x=a[i];
		if(a[(i+tot-1)%tot]==f[x]||a[(i+1)%tot]==f[x])continue;
		return false;
	}
	return true;
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		int ret=0;
		int n;scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&f[i]);
			f[i]--;
		}
		for(int i=1;i<(1<<n);i++){
			int cc=0;
			for(int j=0;j<n;j++){
				if((i>>j)&1)a[cc++]=j;
			}
			do{
				if(judge(cc)){
					ret=max(ret,__builtin_popcount(i));
					break;
				}
			}while(next_permutation(a,a+cc));
		}
		printf("Case #%d: %d\n",_,ret);
	}
	return 0;
}