#include <cstdio>
using namespace std;

int multiply(int a, int b){
	//printf("test a=%d b=%d\n",a,b);
	bool neg =false;
	int res;
	if(a<0){
		neg=true;
		a*=-1;
	}
	if(b<0){
		neg=!neg;
		b*=-1;
	}
	if(a==b)res=-1;
	else if (a==1||b==1) res=a*b;
	else if(a==2){
		if(b==3) res=4;
		else res=-3;
	}
	else if(a==3){
		if(b==2) res=-4;
		else res=2;
	}
	else{
		if(b==2) res=3;
		else res=-2;
	}
	if(neg) res*=-1;
	//printf("res=%d\n\n",res);
	return res;
}

int main(){

	FILE*in=fopen("C-small-attempt0.in","r");
	FILE*out=fopen("out.txt","w");
	
	int t,l,y,z,p;
	long long int x;
	fscanf(in,"%d ",&t);
	
	for(int i=0;i<t;i++){
		fscanf(in,"%d %lld ",&l,&x);
		char str[l+1];
		fscanf(in,"%s ",&str[0]);
		y=1;
		bool diff=false;
		for(int j=0;j<l;j++){
			z=str[j]-103;
			y=multiply(y,z);
			if(j!=0)
				if(p!=z) diff=true;
			p=z;
		}
		bool pass=false;
		if(y==-1 && x%2==1 && diff) pass=true;
		else if(y!= 1 && y!=-1 && x%2==0 && x%4!=0 && diff) pass =true;
		if (pass){
			int fi=0, fk=0;
			y=1;
			z=1;
			while(y!=2 && fi<4*l){
				z=str[fi%l]-103;
				y=multiply(y,z);
				fi++;
			}
			if(y!=2)pass=false;
			y=1;
			while(pass && y!= 4 && fk<4*l){
				z=str[l-1-(fk%l)]-103;
				y=multiply(z,y);
				fk++;
			}
			if(y!=4)pass=false;
			double sum=fi+fk;
			if(sum/l>x)pass=false;
		}
		if(pass){
			fprintf(out,"Case #%d: YES\n",i+1);
		}
		else fprintf(out,"Case #%d: NO\n",i+1);
	}
}
