main(){
int T1,T;
int N,P[200],N1;
int Judge_total,Aud_total;
double ans[200];
int i;
scanf("%d",&T);
for(T1=1;T1<=T;T1++){
	Judge_total=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&P[i]);
		Judge_total+=P[i];
	}
	Aud_total=Judge_total;
	printf("Case #%d:",T1);
	N1=N;
	for(i=0;i<N;i++){
		ans[i]=((2.0/(double)(N))-((double)(P[i]))/((double)(Aud_total)))*100.0;
		if(ans[i]<0.0){
			ans[i]=-1.0;
			N1--;
			Judge_total-= P[i];
		}
	}
	for(i=0;i<N;i++){
		if(ans[i] != -1.0 )
			ans[i]=(((1.0+(((double)Judge_total)/((double)Aud_total)))/(double)(N1))-((double)(P[i]))/((double)(Aud_total)))*100.0;
		else
			ans[i]=0.0;
		printf(" %f",ans[i]);
	}
	printf("\n");
}
}
