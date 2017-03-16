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

char s[1001000];
int len,K;

int mat[][5]={
	{
		
	},
	{
		0,1,2,3,4
	},
	{
		0,2,-1,4,-3
	},
	{
		0,3,-4,-1,2
	},
	{
		0,4,3,-2,-1
	}
};

void solve(int& now,int& idxi,int& idxk){
    for(int i=0; i<len; i++)
    {
        int x=0;
        if(s[i]=='i')x=2;
        else if(s[i]=='j')x=3;
        else x=4;
        int pre=1;
        if(now<0)pre=-1;
        now=pre*mat[abs(now)][x];
        if(-1==idxi&&now==2)
        {
            idxi=i;
        }
    }

    now=1;
    for(int i=len-1; i>=0; i--)
    {
        int x=0;
        if(s[i]=='i')x=2;
        else if(s[i]=='j')x=3;
        else x=4;
        int pre=1;
        if(now<0)pre=-1;
        now=pre*mat[x][abs(now)];
        if(-1==idxk&&now==4)
        {
            idxk=i;
        }
    }
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		scanf("%d%d",&len,&K);
		scanf("%s",s);
		for(int i=1;i<K;i++){
			for(int j=0;j<len;j++){
				s[j+i*len]=s[j];
			}
		}
		len*=K;
		int now=1,idxi=-1,idxk=-1;
		solve(now,idxi,idxk);
		printf("Case #%d: ",_);
		if(now!=-1){
			puts("NO");
		}
		else if(idxi==-1||idxk==-1||idxi+len-idxk>len){
			puts("NO");
		}
		else puts("YES");
	}
	return 0;
}