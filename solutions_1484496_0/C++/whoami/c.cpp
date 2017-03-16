#include <stdio.h>
int n,print[2][501],kk[2],su[501],rem[501];
bool fi;
void back(int k,int sum1,int sum2){
	if(sum1==sum2 && sum1!=0)
		fi=1;
	else if(k!=n){
		back(k+1,sum1,sum2);
		if(!fi){
			print[0][kk[0]++]=su[k];
			back(k+1,sum1+su[k],sum2);
			if(!fi){
				kk[0]--;
				print[1][kk[1]++]=su[k];
				back(k+1,sum1,sum2+su[k]);
				if(!fi)
					kk[1]--;
			}
		}
	}
}
int main(){
	int testt,test,i;
	FILE *in,*out;
	in=fopen("input.txt","r");
	fscanf(in,"%d",&testt);
	out=fopen("output.txt","w");
	for(test=1;test<=testt;test++){
		fscanf(in,"%d",&n);
		for(i=0;i<n;i++){
			fscanf(in,"%d",&su[i]);
		}
		kk[0]=kk[1]=0;
		fi=0;
		back(0,0,0);
		if(!fi){
			fprintf(out,"Case #%d: Impossible\n",test);
			continue;
		}
		fprintf(out,"Case #%d:\n",test);
		for(i=0;i<kk[0];i++)
			fprintf(out,"%d ",print[0][i]);
		fprintf(out,"\n");
		for(i=0;i<kk[1];i++)
			fprintf(out,"%d ",print[1][i]);
		fprintf(out,"\n");
	}
	fcloseall();
	return 0;
}
