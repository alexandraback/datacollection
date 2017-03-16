#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	long long int p,q;
	 FILE *ifp,*ofp;
	 ifp = fopen("A-large.in","r");
	 ofp = fopen("output2.in","w");
	 fscanf(ifp,"%d",&t);
	//scanf("%d",&t);
	for(int k=0;k<t;k++){
		//fscanf(ifp,"%d%d",&i,&j);
		char arr[30];
		int b;
		int a;
		fscanf(ifp,"%s",arr);
		for(int i=0;i<30;i++){
			if(arr[i]=='/')
				a=i;
			if(arr[i]=='\0'){
				b=i;
				break;
			}
		}
		//printf("%d %d\n",a,b);
		long long int temp=1;
		p=0;
		q=0;
		for(int i=a-1;i>=0;i--){
			p+=temp*(long)(arr[i]-'0');
			temp*=10;
		}
		temp=1;
		for(int i=b-1;i>a;i--){
			q+=temp*(long)(arr[i]-'0');
			temp*=10;
		}
		long long int zz = std::__gcd(p,q);
		p=p/zz;
		q=q/zz;
		//printf("%d %d\n",p,q);
		// if(z==0)
		// 	fprintf(ofp,"Case #%d: %d\n",k+1,temp);
		// 	//cout<<"Case #"<<k+1<<" :"<<temp<<endl;
		// else
		// 	fprintf(ofp,"Case #%d: Fegla Won\n",k+1);
		// 	//cout<<"Case #"<<k+1<<" :"<<"Fegla Won"<<endl;
		//printf("%d %d\n",q,p);
		double c = log2(q);
		int d = log2(p);
		if(c==floor(c)){
			fprintf(ofp,"Case #%d: %d\n",k+1,(int)c - d);
		}
		else
			fprintf(ofp,"Case #%d: impossible\n",k+1);
		//printf("%d%d%d",a,b,a-b);
	// }
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
