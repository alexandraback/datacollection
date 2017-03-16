#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
using namespace std;

bool v[11];
int sum;
int calc(int  x){
	while(x>0){
		if (v[x%10]==false){
			sum++;
			v[x%10]=true;
		}
		x/=10;
	} 
}

int work(int num,int x){
	int y=0;
	if (x==0){
		printf("Case #%d: INSOMNIA\n", num);
		return 0;
	}
	for (int i = 0; i < 10; ++i)
		v[i]=false;
	sum =0;
	while(sum<10){
		y+=x;
		calc(y);
	}
	printf("Case #%d: %d\n", num ,y);
}

int main(){
	int n,x;
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for (int i = 1; i <= n; ++i){
		cin>>x;
		work(i,x);
	}
	return 0;
}