#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000001];
int rev(int x){
	if(x<10)return x;
	int i, b[10]={0}, y=x, ans=0;
	for(i=0;i<10&&y;i++, y/=10){
		b[i]=y%10;
	}
	i--;
	for(y=1;i>=0;i--, y*=10){
		ans+=b[i]*y;
	}
	return ans;
}

int main(){
	int N, i, TN, ca=0;
	scanf("%d", &TN);
	for(i=0;i<=20;i++){a[i]=i;}
	for(i=21;i<=1000000;i++){
		int rr=rev(i);
		// if(i==32)
		// 	printf("%d %d\n", a[i-1], a[rr]);
		if(rr<i&&i%10)
			a[i]=min(a[i-1]+1, a[rr]+1);
		else a[i]=a[i-1]+1;
		
	}
	while(TN--){
		scanf("%d", &N);
		printf("Case #%d: %d\n", ++ca, a[N]);
	}
	return 0;
}