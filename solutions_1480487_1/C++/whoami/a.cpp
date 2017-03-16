#include <stdio.h>
int n,su[1001],sum;
double print[1001];
bool check(int i,double per){
	double score=per*sum+su[i],plus=0;
	int j;
	for(j=0;j<n;j++){
		if(j==i) continue;
		if(score>su[j])
			plus+=score-su[j];
	}
	if(plus>=sum*(1-per))
		return true;
	return false;
}
void pro(){
	int i;
	double low=0,high=1,mid;
	for(i=0;i<n;i++){
		low=0;high=1;
		while(1){
			mid=(low+high)/2;
			if(high-mid<0.000000001) break;
			if(check(i,mid))
				high=mid-0.000000001;
			else
				low=mid+0.000000001;
		}
		print[i]=mid;
	}
}
int main(){
	int testt,test,i;
	FILE *in,*out;
	in=fopen("input.in","r");
	fscanf(in,"%d",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fscanf(in,"%d",&n);
		sum=0;
		for(i=0;i<n;i++){
			fscanf(in,"%d",&su[i]);
			sum+=su[i];
		}
		pro();
		fprintf(out,"Case #%d:",test);
		for(i=0;i<n;i++)
			fprintf(out," %lf",print[i]*100);
		fprintf(out,"\n");
	}
	fcloseall();
	return 0;
}
