#include<stdio.h>
char keys[100000];
char goal[100000];
char type[100000];
int nkeys,ngoal,num;
int maxx = 0;
int sum = 0;
int rec(int k){
	if( k == num ){
		int cur = 0;
		for(int i = 0 ; i <= num-ngoal ; i++ ){
			int chk = 1;
			for(int j = 0 ; j < ngoal ; j++ ){
				if( type[i+j] != goal[j] ) chk = 0;
			}
			if( chk ){
				cur++;
			}
		}
		if( cur > maxx ) maxx = cur;
		sum += cur ;
		return 0;
	}
	for(int i = 0 ; i < nkeys ; i++ ){
		type[k] = keys[i];
		rec(k+1);
	}
}
int power(int x,int y){
	int res = 1;
	for(int i = 0 ; i< y ; i++ ) res *=x;
	return res;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ; e++ ){
		maxx = 0;
		sum = 0;
		scanf("%d %d %d",&nkeys,&ngoal,&num);
		scanf("%s",keys);
		scanf("%s",goal);

		rec(0);
		sum = power(nkeys,num)*maxx-sum;
		printf("Case #%d: %.7lf\n",e+1,((double)sum)/power(nkeys,num));
	}
}
