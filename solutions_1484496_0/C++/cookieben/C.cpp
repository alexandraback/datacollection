#include<iostream>
#include<fstream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<map>
#include<algorithm>

using namespace std;

#define REP(i,a,b) for(int i=a;i<b;++i)

int used[2][3000000];

int main(int argc, char *argv[])
{

	if(argc!=3) return -1;
	
	ifstream fin(argv[1]);
	FILE* fp=fopen(argv[2],"w+");

	int T,N,s[600],sum,found,set1,set2,first;
	int two[21]={1,2,4,8,16,32,64,128,256,512,1024,
			 2048,4096,8192,16384,32768,65536,131072,
			 262144,524288,1048576};
	
	fin>>T;
	REP(i,0,T) {
		fin>>N;
		sum=0;
		REP(j,0,N)
			fin>>s[j];

		memset(used[0],0,sizeof(int)*3000000);
		found=0;
		REP(j,0,two[N]) {
			sum=0;
			
cout<<j<<endl;
			
			REP(k,0,N)
				if((j>>k)&1) {
				
cout<<k<<" "<<s[k]<<endl;
				
					sum+=s[k];
				}
			if(used[0][sum]==0) {
				used[0][sum]=1;
				used[1][sum]=j;
			}
			else {
				found=1;
				set1=used[1][sum];
				set2=j;
				break;
			}
			
//cin.get();
		}

		
		fprintf(fp,"Case #%d:\n",i+1);
		if(found) {
		
cout<<set1<<" "<<set2<<endl;

			first=1;
			REP(j,0,N)
				if((set1>>j)&1) {
					if(first) first=0;
					else fprintf(fp," ");
					fprintf(fp,"%d",s[j]);
				}
			fprintf(fp,"\n");
			
			first=1;
			REP(j,0,N)
				if((set2>>j)&1) {
					if(first) first=0;
					else fprintf(fp," ");
					fprintf(fp,"%d",s[j]);
				}
			fprintf(fp,"\n");
		}
		else {

cout<<"QQ\n";		
			fprintf(fp,"Impossible\n");
		}
	}
	
	fclose(fp);
	return 0;
}
