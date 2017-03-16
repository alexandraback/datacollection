#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("D.in");
ofstream fout("D.out");

int T;
double n[1001];
double k[1001];

void qsort(double a[],int x,int y)
{
    int p,q;
    double num,temp;
    p=x;q=y;num=a[(x+y)/2];
    while(q>=p)
    {
        while(a[p]<num)p++;
        while(a[q]>num)q--;
        if(q>=p)
        {
            temp=a[p];
            a[p]=a[q];
            a[q]=temp;
            p++;q--;
        }
        if(q>x)qsort(a,x,q);
        if(p<y)qsort(a,p,y);
    }
}

int main(){
	fin>>T;
	for(int z=1;z<=T;z++){
	
	int N;
	
	int wpts,dwpts=0;	
	
	fin>>N;
	
	for(int i=1;i<=N;i++)fin>>n[i];
	for(int i=1;i<=N;i++)fin>>k[i];
	
	qsort(n,1,N);
	qsort(k,1,N);
	
	int ncurr=1,kcurr=1;
	for(;ncurr<=N;ncurr++){
		for(;k[kcurr]<n[ncurr]&&kcurr<=N;kcurr++);
		if(kcurr==N+1)break;
		kcurr++;		
	}
	if(kcurr==N+1)wpts=N-ncurr+1;
	else wpts=0;
	
	ncurr=1;
	int kmin=1;
	for(;ncurr<=N;ncurr++){
		if(n[ncurr]>k[kmin]){
			dwpts++;
			kmin++;
		}
	}		
	
	fout<<"Case #"<<z<<": "<<dwpts<<' '<<wpts<<endl;
	
	}
	return 0;
}
