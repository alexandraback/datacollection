#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;
int a[1000005];
int add(int a,int b){
	int temp=a+b;
	if(temp>1000000)
		return 1000001;
	else return temp;
}
int main(){
	int C;
	scanf("%d",&C);
	for(int Case=1; Case<=C; Case++){
		int A, N;
		scanf("%d%d", &A, &N);
		for(int i=0; i<N; i++)
			scanf("%d",&a[i]);
		sort(a, a+N);
		int ans=999999999;
		if(A==1)
			ans=N;
		else{
			int now=0,size=A;
			for(int i=0;i<N;i++){
				int last=now;
				while(size<=a[i]){
					size=add(size,size-1);
					now++;
				}
				size=add(size,a[i]);
				ans=min(ans, min(last+N-i, now+N-i-1));
			}
		}
		printf("Case #%d: %d\n",Case,ans);
	}
}

