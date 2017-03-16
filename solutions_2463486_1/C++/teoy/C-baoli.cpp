#include "iostream"
#include "cstring"
#include "cstdio"
#include "vector"
#define PB push_back
using namespace std;
typedef long long LOL;
int num[20];
int gao(LOL x)
{
	int l=0;
	while(x!=0){
		num[++l]=x%10;
		x/=10;
	}
	for(int i=1;i<=l;i++){
		if(num[i]!=num[l-i+1]){
			return 0;
		}
	}
	return 1;
}
vector<LOL> v;
int main(void)
{	
	freopen("C-large-1.in","r",stdin);
	for(LOL i=1;i<=10000000;i++){
		if(gao(i)&&gao(i*i)){
			v.PB(i*i);
		}
	}
	int T,g=0;
	LOL x,y;
	scanf("%d",&T);
	while(T--){
		cin>>x>>y;
		int sum=0;
		for(int i=0;i<v.size();i++){
			if(v[i]>=x&&v[i]<=y){
				sum++;
			}
		}
		printf("Case #%d: %d\n",++g,sum);
	}
	return 0;
}