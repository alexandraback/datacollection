#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

long long int Top[1005];
int Top_n=0;

void Init(){
	Top[Top_n++]=1;
	for(int i=3; ; i+=2){
		Top[Top_n]=Top[Top_n-1]+i*2-1;
		Top_n++;
		if(Top[Top_n-1]>1000000) break;	
	}
//	printf("%d\n",Top_n);
}

int main(){
	int T;
	Init();
	scanf("%d",&T);
	for(int Case=1; Case<=T; Case++){
		int N,X,Y;
		scanf("%d%d%d",&N,&X,&Y);
		if(X<0) X=X*(-1);
		if((X+Y)/2>=708) printf("Case #%d: 0.0\n",Case); 
		else if( (X+Y)%2==1 ) printf("Case #%d: 0.0\n",Case);
		else if(N>Top[(X+Y)/2]) printf("Case #%d: 1.0\n",Case);
		else if(N==Top[(X+Y)/2]) printf("Case #%d: 1.0\n",Case);
		else{
			double ans;
			long long int Small=Top[(X+Y)/2-1]+Y+1, Large=Top[(X+Y)/2]-X;
			if(X==0) Small=Large=Top[(X+Y)/2];
			//printf("S:%d L:%d\n",Small,Large);
			if(N<Small) printf("Case #%d: 0.0\n",Case);
			else if(N>=Large) printf("Case #%d: 1.0\n",Case);
			else if(N==Small) printf("Case #%d: %.8lf\n",Case,pow(0.5,Y+1));
			else{
				double tmp=pow(0.5,Y+1);
				if(N-Small<0){ printf("Case #%d: 0.0\n",Case); continue;}
				ans=tmp;
				double k=0.25;
				tmp=0;
				for(int i=Y+2; i<Y+2+N-Small; i++){
					tmp+=pow(0.5,i);
				}
				tmp*=(Y+1);
				ans+=tmp;
	//			ans=(1-tmp)/(double)(Large-Small)+tmp;
				printf("Case #%d: %.8lf\n",Case,ans);
			}
		}
	}
	return 0;
}
