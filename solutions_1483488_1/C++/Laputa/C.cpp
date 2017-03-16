#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;

bool visit[2000005];
int queue[20];

int main()
{
	int T;
	scanf("%d",&T);
	int a,b,tmp,cnt,TT=T;
	int base,times,ans,cntque;
	//set<int>::iterator left,right;
	//set<int> ins;
	bool jump;
	while(T--)
	{
		scanf("%d%d",&a,&b);
		memset(visit,0,sizeof(visit));
		ans=0;		
		if(a<10) {base=1;times=0;}
		else if(a<100) {base=10;times=1;}
		else if(a<1000) {base=100;times=2;}
		else if(a<10000) {base=1000;times=3;}
		else if(a<100000) {base=10000;times=4;}
		else if(a<1000000) {base=100000;times=5;}
		else if(a<10000000) {base=1000000;times=6;}
		for(int i=a;i<b;i++)
		{
			if(visit[i]) continue;
			visit[i]=true;
			//ins.clear();
			//ins.insert(i);
			tmp=i;
			cntque=1;
			queue[0]=i;
			jump=false;
			cnt=1;
			for(int j=0;j<times;j++)
			{
				tmp=tmp/base+(tmp%base)*10;
				//ins.insert(tmp);
				for(int k=0;k<cntque;k++)
				{
					if(queue[k]==tmp) {jump=true;break;}
				}
				if(jump) break;
				queue[cntque++]=tmp;
				if( tmp<=b && tmp>=a ) cnt++;
				if(tmp<=2000000) visit[tmp]=true;
			}			
			/*while(left!=right)
			{
				left++;
				cnt++;
			}*/
			//int cnt=upper_bound(ins.begin(),ins.end(),a)-lower_bound(ins.begin(),ins.end(),b);
			ans+=cnt*(cnt-1)/2;
		}
		//printf("%lld\n",ans);
		printf("Case #%d: %d\n",TT-T,ans);
	
	}
	return 0;
}