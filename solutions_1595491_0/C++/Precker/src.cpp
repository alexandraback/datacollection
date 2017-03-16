#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int data[3];
	bool used;
};

int main()
{
	int t[200];
	node NData[100];
	int T,N,S,P;
	cin>>T;
	int num=1;
	while(T--)
	{
		
		cin>>N>>S>>P;
		for(int i=0;i<N;i++)
		{
			cin>>t[i];
		}
		for(int i=0;i<N;i++)
		{
			NData[i].data[0]=t[i]/3;
			NData[i].data[1]=(t[i]-t[i]/3)/2;
			NData[i].data[2]=t[i]-NData[i].data[0]-NData[i].data[1];
			NData[i].used=false;
		}
		for(int i=0;i<N;i++)
		{
			if((NData[i].data[2]-NData[i].data[0]==1)&&(NData[i].data[1]-NData[i].data[0]==0))
			{
				NData[i].used=true;
			}
		}
		bool noChange=false;
		while(S>0&&!noChange)
		{
			int maxAAA=-1,maxPosAAA=-1,maxABB=-1,maxPosABB=-1;
			noChange=true;
			for(int i=0;i<N;i++)
			{
				if(NData[i].used==false)
				{
					noChange=false;
					if(NData[i].data[0]==NData[i].data[1])//AAA
					{
						if(NData[i].data[2]>maxAAA)
						{
							maxAAA=NData[i].data[2];
							maxPosAAA=i;
						}
					}
					else	//A(A+1)(A+1)
					{
						if(NData[i].data[2]>maxABB)
						{
							maxABB=NData[i].data[2];
							maxPosABB=i;
						}
					}
				}
			}
			//找到了AAA模式的最大候选和A(A+1)(A+1)模式的最大候选
			if(maxAAA>=P)//已经及格，无需处理
			{
				NData[maxPosAAA].used=true;
				continue;
			}
			if(maxABB>=P)
			{
				NData[maxPosABB].used=true;
				continue;
			}
			if(noChange)
			{
				break;
			}
			//当没有直接可以及格的对象时，考虑Surprising化，让更多解及格
			if(maxAAA+1>=maxABB+1)//AAA模式可变为(A-1)(A)(A+1):(A必须大于1),A(A+1)(A+1)可变为AA(A+2)
			{
				if(NData[maxPosAAA].data[0]>=1)
				{
					NData[maxPosAAA].data[0]-=1;
					NData[maxPosAAA].data[2]+=1;
					NData[maxPosAAA].used=true;
					S--;
				}
				else//该值无法转换，则设定为used
				{
					NData[maxPosAAA].used=true;
				}
			}
			else
			{
				NData[maxPosABB].data[1]-=1;
				NData[maxPosABB].data[2]+=1;
				NData[maxPosABB].used=true;
				S--;
			}
		}

		//统计结果
		int res=0;
		for(int i=0;i<N;i++)
		{
			if(NData[i].data[2]>=P)
				res++;
		}
		printf("Case #%d: %d\n",num++,res);
	}
	return 0;
}