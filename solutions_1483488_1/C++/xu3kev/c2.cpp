#include<fstream>
#include<iostream>
#include<vector>
#include<stdlib.h>
int compare(const void* a,const void* b){
return *(int*)a-*(int*)b;
}
using namespace std;
int main(int args,char* argv[] ){
	ifstream in(argv[1]);
	ofstream out("c2.output");
	int T;
	int a,b;
	long long int count;
	int* li=new int[2000001];
	int tmp;
	int th;
	int pow;
	int x;
   int bu[10];
	int bus;
	for(int i=0;i<2000001;++i)
		li[i]=0;
	for(int i=1;i<2000001;++i){
		if(li[i]==0){
			tmp=i;
			pow=1;
			th=0;
			bus=1;
			bu[0]=i;
			while(tmp){
				tmp/=10;
				pow*=10;
				++th;
			}
			pow/=10;
			tmp=i;
			for(int i=0;i<th;++i){
				x=tmp%10;
				tmp/=10;
				tmp+=x*pow;
				if(x){
					bu[bus]=tmp;
					++bus;
				}
			}
//			cerr<<th;
			qsort(bu,bus,sizeof(int),compare);
			for(int i=1;i<bus;++i){
				if(bu[i]>2000000){
					li[bu[i-1]]=-1;
					break;
				}
				li[bu[i-1]]=bu[i];
			}
			if(bu[bus-1]<=2000000)
				li[bu[bus-1]]=-1;
		}
	}
	int ll;
	int y;
	bool g[2000001];
	
//	ll=101;
//	while(li[ll]>0){
//		cerr<<li[ll]<<" ";
//		ll=li[ll];
//	}

	in>>T;
	for(int i=1;i<=T;++i){
		in>>a>>b;
		count=0;
		for(int j=a;j<=b;++j)
			g[j]=false;
		for(int j=a;j<=b;++j){
			if(!g[j]){
				y=0;
				x=j;
				while(li[x]>0&&li[x]<=b){
					x=li[x];
					++y;
					g[x]=true;
				}
				count+=(y*(y+1)/2);
				g[j]=true;
			}
		}
		out<<"Case #"<<i<<": "<<count<<"\n";
	}
return 0;
}
