#include<iostream>
#include<fstream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;++i)

int main(int argc, char *argv[])
{

	if(argc!=3) return -1;
	
	ifstream fin(argv[1]);
	FILE* fp=fopen(argv[2],"w+");

	int T,N,s[500],sum;
	double x[500],y[500],t[500];
	double total,limit;
	
	fin>>T;
	REP(i,0,T) {
		fin>>N;
		sum=0;
		REP(j,0,N) {
			fin>>s[j];
			sum+=s[j];
		}

		REP(j,0,N) {
			x[j]=t[j]=((double)s[j])/((double)sum);
		}
		sort(t,t+N);
		total=0;
		for(int j=N-1;j>=0;--j) {
			total+=t[j];
			if((2.0-total)/((double)(j))>t[j])
			{
				limit=(2.0-total+t[j])/((double)(j+1));
				break;
			}
		}
		
		fprintf(fp,"Case #%d:",i+1);
		REP(j,0,N) {
			y[j]=(x[j]>=limit)?0:limit-x[j];
			fprintf(fp," %.6f",(y[j]>=0)?100.0*y[j]:0);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
	return 0;
}
