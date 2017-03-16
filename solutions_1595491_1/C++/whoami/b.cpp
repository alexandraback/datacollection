#include <stdio.h>
#include <algorithm>
int n,m,min,su[101],print;
void pro(){
	int i,a;
	for(i=n-1;i>=0;i--){
		a=su[i]/3;
		if(su[i]%3==0){
			if(a>=min)
				print++;
			else if(a+1>=min && m!=0 && a>=1){
				m--;
				print++;
			}
		}
		else if(su[i]%3==1){
			if(a+1>=min)
				print++;
		}
		else{
			if(a+1>=min)
				print++;
			else if(a+2>=min && m!=0){
				print++;
				m--;
			}
		}
	}
}
int main(){
	int i,test,testt;
	FILE *in,*out;
	in=fopen("input.txt","r");
	fscanf(in,"%d",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fscanf(in,"%d %d %d",&n,&m,&min);
		for(i=0;i<n;i++)
			fscanf(in,"%d",&su[i]);
		std::sort(su,su+n);
		print=0;
		pro();
		fprintf(out,"Case #%d: %d\n",test,print);
	}
	fcloseall();
	return 0;
}
