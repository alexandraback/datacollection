#include<cstdio> 
#include<cstring> 
#include<cctype> 
#include<cmath> 
#include<cstdlib> 
#include<ctime> 
#include<iostream> 
#include<iomanip> 
#include<sstream> 
#include<vector> 
#include<string> 
#include<queue> 
#include<stack> 
#include<utility> 
#include<algorithm> 
#include<map> 
#include<set> 
#include<bitset> 
#include<sstream>
#include<limits>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;

int main(){
	int T,A,B,K;
	scanf("%d",&T);
	//printf("%d*\n",7&11);
	for(int caso=1;caso<=T;caso++){
		scanf("%d%d%d",&A,&B,&K);
		int c=0;
		for(int i=0;i<A;i++)
			for(int j=0;j<B;j++){
				if((i&j)<K){c++;}
			}
		printf("Case #%d: %d\n",caso,c);
	}
	return 0;
}
