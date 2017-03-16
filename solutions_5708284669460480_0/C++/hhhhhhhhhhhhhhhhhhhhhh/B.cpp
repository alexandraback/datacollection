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

char A[110],B[110];
int lena,lenb,L;
int f[110];
void update(char P[]){
	int len=strlen(P);
	f[0]=f[1]=0;
	for(int i=1;i<len;i++){
		int j=f[i];
		while(j&&P[i]!=P[j])j=f[j];
		f[i+1]=(P[i]==P[j]?j+1:0);
	}
}

int dp[110][110];
int cal1(){
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<L;i++){
		for(int j=0;j<lenb;j++){
			if(dp[i][j]<0)continue;
			for(int k=0;k<lena;k++){
				int aa=j;
				while(aa&&A[k]!=B[aa])aa=f[aa];
				int add=0;
				if(A[k]==B[aa]){
					aa++;
				}
				if(aa==lenb){
					add++;
					aa=f[aa];
				}
				dp[i+1][aa]=max(dp[i+1][aa],dp[i][j]+add);
			}
		}
	}
	int ret=0;
	for(int j=0;j<lenb;j++){
		if(dp[L][j])ret=max(ret,dp[L][j]);
	}
	return ret;
}

double x=0;
double dp2[110][110][110];
double cal2(double dp[110][110][110],int tot){
	dp[0][0][0]=1;
	for(int i=0;i<L;i++){
		for(int j=0;j<lenb;j++){
			for(int tt=0;tt<=tot;tt++){
				if(dp[i][j][tt]<0)continue;
				for(int k=0;k<lena;k++){
					int aa=j;
					while(aa&&A[k]!=B[aa])aa=f[aa];
					int add=0;
					if(A[k]==B[aa])aa++;
					if(aa==lenb){
						add++;
						aa=f[aa];
					}
					dp[i+1][aa][tt+add]+=dp[i][j][tt]/lena;
				}
			}
		}
	}
	double ret=0;
	for(int j=0;j<lenb;j++){
		for(int tt=0;tt<=tot;tt++){
			if(dp[L][j][tt]>1e-10){
				//cout<<j<<" "<<tt<<" "<<dp[L][j][tt]<<endl;
			}
			ret+=dp[L][j][tt]*(tot-tt);
		}
	}
	return ret;
}

int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int test;
	scanf("%d",&test);
	for(int _=1;_<=test;_++){		
		scanf("%d%d%d",&lena,&lenb,&L);
		scanf("%s",A);
		scanf("%s",B);
		update(B);
		int tmp=cal1();
		//cout<<tmp<<endl;
		memset(dp2,0,sizeof(dp2));
		double ret=cal2(dp2,tmp);
		printf("Case #%d: %.10f\n",_,ret);
	}
	return 0;
}