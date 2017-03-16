#include <stdio.h>
int test,print,a,b;
void pro(){
	int i,s,gob,save;
	for(i=a;i<=b;i++){
		s=i;
		gob=1;
		while(s>=10){
			s/=10;
			gob*=10;
		}
		save=i%10;
		s=i/10+save*gob;
		while(s!=i){
			if(a<=s && s<=b)
				print++;
			save=s%10;
			s=s/10+save*gob;
		}
	}
	print/=2;
}
int main(){
	int test,testt;
	FILE *in,*out;
	in=fopen("input.txt","r");
	fscanf(in,"%d",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fscanf(in,"%d %d",&a,&b);
		print=0;
		pro();
		fprintf(out,"Case #%d: %d\n",test,print);
	}
	fcloseall();
	return 0;
}
