#include<stdio.h>
#include<stdlib.h>
#include<bitset>

using namespace std;

#define MAX_SIZE	100

bitset<MAX_SIZE>	mem;
int m[305];
int c,d,v;

void fill(int sum,int cn) {
	if(cn<0) return;
	//printf("Processing coin %d = %d with %d repeats from sum: %d\n",cn,m[cn],c, sum);
	for(int i=0;i<=c;++i) {
		int csum=sum+i*m[cn];
		if(csum>v) break;	// overlimit
		//printf("Fill: %d\n",csum);
		mem[csum]=1;
		fill(csum,cn-1);	// rest sum
	}
}



int main(int argc, char** argv) {
	int tsts;

	scanf("%d",&tsts);
	for(int t=1;t<=tsts;++t) {
		int add=0;
		// read data
		scanf("%d %d %d",&c,&d,&v);
		for(int i=0;i<d;++i) scanf("%d",&(m[i]));
		// reset memory
		mem.reset();
		fill(0,d-1);
		for(int i=1;i<=v;++i) {
			//printf("Find hole: %d\n",i);
			if(mem[i]==0) {
				m[d+add]=i;
				++add;
				fill(0,d+add-1);
			}
		}
		
		printf("Case #%d: %d\n",t,add);
	}

	return 0;
}
