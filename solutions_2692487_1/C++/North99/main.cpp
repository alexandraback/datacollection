#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long mote[110],i,j,a,n,tNumF,tC,ct,cop;
long long cM;
bool eProst;

int main () {
	
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	
	scanf("%ld",&tC);
	
	while(tC--)
	{
		long min=20000000;
		memset(mote,0,sizeof(mote));
		ct++;
		scanf("%ld%ld",&a,&n);
		cM=0;tNumF=0;
		for(i=1;i<=n;i++)
			scanf("%ld",&mote[i]);
		sort(mote+1,mote+n+1);
		cM=a;
		if(ct==9)
			cM=a;
		long ok=1;
		for(i=1;i<=n;i++)
			if(cM>mote[i])
				cM+=mote[i];
			else{
				ok=0;
				break;
			}
		if(ok)
			printf("Case #%ld: 0\n",ct);
		else if(a==1)
			printf("Case #%ld: %ld\n",ct,n);
		else{
			eProst=0;
			cM=a;
			for(i=1;i<=n;i++){
				
				if(cM>mote[i])
					cM+=mote[i];
				else{
					long tNum=0;
					if(tNumF+n-i<min)
						min=tNumF+n-i+1;
					while(cM<=mote[i])
					{
						cM=cM+cM-1;
						tNum++;
					}
					cM+=mote[i];
					tNumF+=tNum;
					if(tNumF+n-i<min){
						min=tNumF+n;
						min-=i;
					}
				}
			}
			long cMin=min;
			if(eProst)
				continue;
			if(tNumF<=min)
				min=tNumF;
			if(min>n)
				min=n;
			if(cMin<min)
				min=cMin;
			printf("Case #%ld: %ld\n",ct,min);
		}
	}
	
	return 0;
}
