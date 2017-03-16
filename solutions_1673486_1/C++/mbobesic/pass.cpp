#include<cstdio>

using namespace std;

float prob[99999+1];
 
int main(){
	
	int t;
	FILE *fp=fopen("A-large.in", "r");
	FILE *fo=fopen("output.txt","w");
	fscanf(fp,"%d",&t);
	
	for(int i=0;i<t;i++){
		int a,b;
		fscanf(fp,"%d%d",&a,&b);
		double total_prob=1;
		for(int j=0;j<a;j++){
			float temp;
			fscanf(fp,"%f",&temp);
			prob[j] = temp;
			total_prob*=temp;
		}
		
		double min = total_prob*((b-a)+1)+(1-total_prob)*(2+(b-a)+b);
		double temp = 2+b;
		
		if(temp<min)
			min = temp;
			
		double current_prob = total_prob;
		
		for(int j=a-1;j>=0;j--){
			current_prob /=prob[j];
			double temp = current_prob*((b-a)+1+2*(a-j))+(1-current_prob)*(2+(b-a)+b+2*(a-j));
			if(temp<min)
				min = temp;
		}
		fprintf(fo,"Case #%d: %f\n", (i+1),min);
		
	}
	fclose(fp);
}