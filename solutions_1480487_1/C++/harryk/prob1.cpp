#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main(){
	//ofstream fout("out.txt");
	ifstream fin("A-large.in");
	FILE *fp;
	fp = fopen("out1.txt","w");
	int t,n,a[201],sum,x=0,i,sum1,n1,sum2;
	//char a[101],b[101];
	fin>>t;
	//fin.ignore(1);
	double ans,p;
	while(t--){
		fin>>n;
		sum=0;
		sum1=0;
		sum2=0;
		x++;
		fin.ignore(1);
		for(i=0;i<n;i++){
			fin>>a[i];
			//fin.ignore(1);
			sum+=a[i];
		}
		sum1=0;
		n1=n;
		//
		for(i=0;i<n;i++){
			//(((float)(2*sum/n))-a[i]
			sum2=(int)(2*sum)/n;
			if(sum2<a[i])
				//sum1+=a[i];
			//else
			 { n1--;}
			 else sum1+=a[i];//p=(((float)(2*sum/n))-a[i]);
			//else p=0.0;//(a[i]-((float)(2*sum/n)));
			//ans = (p*(100.0/sum));
			//fprintf(fp,"%f ",ans);
			//fout<<ans<<" ";
		}
		sum1=sum+sum1;
		fprintf(fp,"Case #%d: ",x);
		//fout<<"Case #"<<x<<": ";
		for(i=0;i<n;i++){
			//(((float)(2*sum/n))-a[i]
			if(((float)(2*sum/n))>((float)a[i]))
				p=((((double)sum1/(double)n1))-a[i]);
			else p=0.0;//(a[i]-((float)(2*sum/n)));
			ans = ((double)p*(100.0/(double)sum));
			fprintf(fp,"%lf ",ans);
			//fout<<ans<<" ";
		}
		//fprintf(fp,"\n sum1=%d n1=%d sum= %d\n",sum1,n1,sum);
		fprintf(fp,"\n");
	}
	fclose(fp);
 	return 0;
}
	
		
