double __min(double A, double B){
	return A < B ? A : B;
}

int main(){
	int T,A,B,i,k,t;
	double P[100008],res;
	double exp_bk,exp_entr,exp_keystr,ans;
	scanf("%d",&T);
	t=1;
	while(t<=T){
		scanf("%d",&A);
		scanf("%d",&B);
		for(i=1;i<=A;i++){
			scanf("%lf",&P[i]);
		}
		exp_entr = B + 2;
		
		exp_bk = 1000000000;
		res = B + 1;
		for(i=1;i<=A;i++){
			k = A - i + 1;
			exp_bk = __min(2*k + B - A + 1 + B + 1 - res,exp_bk);
			res *= P[i];
		}
		
		exp_keystr = B - A + 1 + B + 1 - res;
		
		ans = __min(__min(exp_entr,exp_bk),exp_keystr);
		printf("Case #%d: %.6f\n",t,ans);
		t++;
	}
}