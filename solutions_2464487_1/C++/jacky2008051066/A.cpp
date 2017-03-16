#include<iostream>
using namespace std;

typedef __int64 I;

I INF= 8000000000000000010;
I MAXN= 4000000000;

I getSum(I a, I n){
	if(n == 0)
		return 0;
	I b= a*(I)2+(n-(I)1);
	if(INF/n < b)
		return INF;
	return b*n/(I)2;
}

I bsearch(I r, I t, I left, I right){
	if(left == right)
		return left;
	I num= (left+right)/(2);
	I sum1= getSum(r, num*(I)2);
	I sum2= getSum(r, (num+1)*(I)2);
	if(sum1 <= t && t < sum2)
		return num;
	if(t < sum1)
		return bsearch(r, t, left, num-(I)1);
	if(sum2 <= t)
		return bsearch(r, t, num+(I)1, right);
}

int main(){
	freopen("A.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int cas= 1; cas <= T; cas++){
		I r, t;
		scanf("%I64d%I64d", &r, &t);
		I left= (I)0;
		I right= MAXN;
		I ans= bsearch(r, t, left, right);
		printf("Case #%d: %I64d\n", cas, ans);
	}
	return 0;
}