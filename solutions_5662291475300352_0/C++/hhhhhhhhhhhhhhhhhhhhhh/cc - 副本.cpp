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

long long d[2000],N[2000],H[2000];
pair<long long,long long> re[2000];
int cc;
const double eps=1e-9;

int sgn(double x){
    if(fabs(x)<eps)return 0;
    return x<0?-1:1;
}

int main(){
	freopen("C-small-1-attempt2.in","r",stdin);
	freopen("C-small-1-attempt2.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        int tot;
        scanf("%d",&tot);
        cc=0;
        for(int i=0;i<tot;i++){
            cin>>d[i]>>N[i]>>H[i];
            for(int j=0;j<N[i];j++){
                re[cc++]=make_pair(H[i],d[i]);
            }
        }
        sort(re,re+cc);
        if(cc==1){
            if(0==d[0])printf("Case #%d: 1\n",_);
            else printf("Case #%d: 0\n",_);
        }
        else{
        	H[0]=re[0].first,H[1]=re[1].first;
        	d[0]=re[0].second,d[1]=re[1].second;
            if(H[1]*(360-d[1])-(720-d[0])*H[0]>=0)printf("Case #%d: 1\n",_);
            else printf("Case #%d: 0\n",_);
        }
    }
    return 0;
}
