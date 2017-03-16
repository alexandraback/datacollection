#include<stdio.h>
#include<algorithm>

int data[107];

using namespace std;
int min(int x,int y){
	if(x>y) return y;
	return x;
}
int main()
{
	FILE *fi=fopen("A-small-attempt1.in","r");
	FILE *fo=fopen("A-small-attempt1.out","w");
	int a,n,T,t,i,result,cnt;

	fscanf(fi,"%d",&T);
	for(t=0;t<T;t++){
		fscanf(fi,"%d %d",&a,&n);
		for(i=0;i<n;i++)
			fscanf(fi,"%d",&data[i]);
		std :: sort(data,data+n);
		cnt=0;
		result=2147483647;
		for(i=0;i<n;i++){
			if(a>data[i]) a+=data[i];
			else {
				result=min(result,cnt+n-i);
				while(1){
					cnt++;
					a=a*2-1;
					if(a>data[i]) {a+=data[i];break;}
					if(a==1) break;
				}
			}
		}
		result=min(result,cnt+n-i);
		fprintf(fo,"Case #%d: %d\n",t+1,result);
	}
	return 0;
}