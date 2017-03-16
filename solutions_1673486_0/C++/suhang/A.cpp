#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const	int N=100010;

int		A,B,id;
double	p[N],res,tmp;

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int test;
	
	for (scanf("%d",&test);test--;){
		scanf("%d%d",&A,&B);
		p[0]=1;
		for (int i=1;i<=A;i++)
			scanf("%lf",&p[i]),p[i]*=p[i-1];
		
		res=B+2;
		
		for (int i=0;i<A;i++){
			tmp=i+p[A-i]*(B-A+1+i)+(1-p[A-i])*(B-A+1+i+B+1);
			res=min(res,tmp);
		}
		
		printf("Case #%d: %.6lf\n",++id,res);
	}
	
	return 0;
}
