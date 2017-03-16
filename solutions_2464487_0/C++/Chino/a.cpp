#include <cstdio>
#include <cmath>

long long int sum(long long int n, long long int r){
	return n*(2*r+2*n-3);
}

long long int binSearch(long long int ini, long long int end, long long int t, long long int r){
	long long int mid = (end+ini)/2;
	long long int s = sum(mid, r);
	long long int s1 = sum(mid+1, r);
	//printf("%lld %lld %lld == %lld\n",ini, mid, end, s);
	if(s<=t && s1>t){
		return mid;
	}else if(s<=t){
		return binSearch(mid, end, t, r);
	}else{
		return binSearch(ini, mid, t, r);
	}
}

int main(int argc, char *argv[]){
	int T;
	scanf("%d\n",&T);
	
	long long int r, t;
	
	for(int cases=0; cases<T; cases++){
		scanf("%lld %lld\n", &r, &t);
		long long int s=0;
		long long int i = binSearch(0, t, t, r+1);
		//for(i=1; ; i++){
		//	s = sum(i, r+1);
		//	printf("%lld %lld\n", i, s);
		//	if(s>t){break;}
		//}
		
		printf("Case #%d: %lld\n", cases+1, i);
		
	}
	
}

