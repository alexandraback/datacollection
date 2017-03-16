#include <cstdio>
using namespace std;

int main(){

	FILE*in=fopen("A-large.in","r");
	FILE*out=fopen("out.txt","w");
	
	int t,sm,ans,current,add;
	char x;
	fscanf(in,"%d ",&t);
	
	for(int i=0;i<t;i++){
		ans=0;
		current=0;
		fscanf(in,"%d ",&sm);
		for(int j=0;j<sm+1;j++){
			fscanf(in,"%c ",&x);
			int k=x-48;
			if(k>0 && current<j){
				add=j-current;
				ans+=add;
				current+=add;
			}
			current+=k;
		}
		fprintf(out,"Case #%d: %d\n",i+1,ans);
	}

}
