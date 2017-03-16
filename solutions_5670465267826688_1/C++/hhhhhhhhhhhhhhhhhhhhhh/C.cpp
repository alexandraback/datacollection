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

char s[100100];
long long len,K;
bool vis[20];
void solve(int& idxi,int& idxk){
	memset(vis,0,sizeof(vis));
	idxi=0;
	int now=1;
    for(int i=0;idxi<4*len; i=(i+1)%len)
    {
        int x=0;
        if(s[i]=='i')x=2;
        else if(s[i]=='j')x=3;
        else x=4;
        int pre=1;
        if(now<0)pre=-1;
        now=pre*mat[abs(now)][x];
        vis[now+10]=true;
        idxi++;
        if(now==2){
            break;
        }
    }
    if(!vis[12]){
    	idxi=-1;
    }
    
    now=1;
    memset(vis,0,sizeof(vis));
    idxk=0;
    for(int i=len-1;idxk<4*len; i=(i+len-1)%len)
    {
        int x=0;
        if(s[i]=='i')x=2;
        else if(s[i]=='j')x=3;
        else x=4;
        int pre=1;
        if(now<0)pre=-1;
        now=pre*mat[x][abs(now)];
        vis[now+10]=true;
        idxk++;
        if(now==4){
            break;
        }
    }
    if(!vis[14]){
    	idxk=-1;
    }
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){
		cin>>len>>K;
		scanf("%s",s);
		
		printf("Case #%d: ",_);
		int now=1;
		for(int i=0;i<len;i++){
			int x=0;
			if(s[i]=='i')x=2;
			else if(s[i]=='j')x=3;
			else x=4;
			int pre=1;
			if(now<0)pre=-1;
			now=pre*mat[abs(now)][x];
		}
		if(-1==now&&(K&1)){
			int idxi=-1,idxk=-1;
			solve(idxi,idxk);
			if(-1==idxi||-1==idxk)puts("NO");
			else if(idxi+idxk>K*len)puts("NO");
			else puts("YES");
		}
		else if(abs(now)>1&&(0==(K&1))&&((K>>1)&1)){
			int idxi=-1,idxk=-1;
			solve(idxi,idxk);
			if(-1==idxi||-1==idxk)puts("NO");
			else if(idxi+idxk>K*len)puts("NO");
			else puts("YES");
		}
		else puts("NO");
	}
}