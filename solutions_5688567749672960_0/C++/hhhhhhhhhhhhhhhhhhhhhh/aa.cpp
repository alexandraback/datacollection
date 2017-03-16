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

long long inv(long long x){
    long long ret=0;
    while(x){
        ret*=10;
        ret+=x%10;
        x/=10;
    }
    return ret;
}

long long dp[1001000];

int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
    int test;
    scanf("%d",&test);
    dp[0]=0;
    for(int i=1;i<=1000000;i++){
        dp[i]=dp[i-1]+1;
        int aa=inv(i);
        if(inv(aa)!=i)continue;
        if(aa<i)dp[i]=min(dp[i],dp[aa]+1);
        //if(i<20)cout<<dp[i]<<endl;
    }
    for(int _=1;_<=test;_++){
        long long x;
        cin>>x;
        printf("Case #%d: ",_);
        cout<<dp[x]<<endl;
    }
    return 0;
}
