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

//rand()/(RAND_MAX+1.0)
//srand(time(0));
//

template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c=getchar(),c==EOF) return 0; //EOF
   while(c!='-'&&(c<'0'|c>'9')) c=getchar();
   sgn=(c=='-')?-1:1;
   ret=(c=='-')?0:(c-'0');
   while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
   ret*=sgn;
   return 1;
}

bool vis[40];
int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		int C,D,V;
		scanf("%d%d%d",&C,&D,&V);
		memset(vis,0,sizeof(vis));
		vector<int> a;
		for(int i=0;i<D;i++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
		}
		for(int i=1;i<(1<<D);i++){
			int s=0;
			for(int j=0;j<D;j++){
				if((i>>j)&1){
					s+=a[j];
				}
			}
			if(s<=V)vis[s]=true;
		}
		int ret=0;
		for(int i=1;i<=V;i++){
			if(!vis[i]){
				ret++;
				a.push_back(i);
				for(int j=1;j<(1<<a.size());j++){
					int s=0;
					for(int k=0;k<a.size();k++){
						if((j>>k)&1){
							s+=a[k];
						}
					}
					if(s<=V)vis[s]=true;
				}
			}
		}
		printf("Case #%d: %d\n",_,ret);
	}
	return 0;
}