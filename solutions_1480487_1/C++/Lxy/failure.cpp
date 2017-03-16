#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
FILE *fin = fopen("A-large.in","r");
FILE *fout = fopen("out.txt","w");
int data[205];
bool vis[205];
double sum;
int nn;
void dfs(int n)
{
	int i;
	double ssum = sum / (double)n;
	int flag = 0;
	double sum1 =0;
	for(i =0;i<nn;++i)
		if(!vis[i]){
			if(data[i] > ssum){
				flag =1;
				break;
			} else sum1 += data[i];
		}
		if(flag==1){
			int cnt =0;
			for(i=0;i<nn;++i)
				if(!vis[i]){
					if(data[i]>ssum){
						vis[i] = true;
						sum -= data[i];
					} else cnt++;
				}
			dfs(cnt);
		} else {
			double ans;
			for(i=0;i<nn;++i){
				if(vis[i]) ans = 0.0;
					else ans = (double)(ssum - data[i])/ (double)(sum - sum1);
					ans *= 100.0;
					fprintf(fout," %.8lf",ans);
			}
			return;
		}
}
int main()
{	
	int ca; fscanf(fin,"%d",&ca);
	int k = 0;
	while(ca--){
		sum =0;
	fprintf(fout,"Case #%d:",++k);
	if(k==9){
		int j = 1;
	}
	int i; 
	int n;
	memset(vis,0,sizeof(vis));
	fscanf(fin,"%d",&n);
	nn = n;
	for(i=0;i<n;++i){
		fscanf(fin,"%d",&data[i]);
		sum += data[i];
	}
	sum *= 2.0;
	dfs(n);
	fprintf(fout,"\n");
	}
	return 0;
}