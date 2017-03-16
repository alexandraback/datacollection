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

int main(){
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		int X,R,C;
		scanf("%d%d%d",&X,&R,&C);
		printf("Case #%d: ",_);
		if(1==X)puts("GABRIEL");
		else if(2==X&&(0==R%2||0==C%2))puts("GABRIEL");
		else if(3==X&&((0==R%3&&C>=2)||(R>=2&&0==C%3)))puts("GABRIEL");
		else if(4==X&&((0==R%4&&C>=3)||(R>=3&&0==C%4)))puts("GABRIEL");
		else if(5==X&&((0==R%5&&C>=4)||(R>=4&&0==C%5)))puts("GABRIEL");
		else if(6==X&&((0==R%6&&C>=5)||(R>=5&&0==C%6)))puts("GABRIEL");
		else puts("RICHARD");
	}
	return 0;
}