#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;


#define real int

vector<double> v1;
vector<double> v2;

vector<double> order;
int od1,od2,bd1,bd2;
int total;

//取过标为2
int getNormalStratgy(double input)
{
	int pos=-1;
	int smallest=0;
	for(int i=0;i<total;i++)
	{
		if(v2[i]==2) continue;
		else if(v2[i]<v2[smallest]) smallest=i;
		if(v2[i]>input)
		{
			if(pos==-1) pos=i;
			else if(v2[pos]>v2[i]) pos=i;
		}
	}

	if(pos==-1) return smallest;
	else return pos;
}

int getCheatStratgy(float input,int &realIndex)
{
	int index=getNormalStratgy(input);
	int t=0;
	if(v2[index]>input)
	{
		//give smallest one;
		for(int i=0;i<total;i++)
		{
			if(order[i]<=input)
			{
				if(order[i]<order[t]) t=i;
			}
		}
	}
	else
	{
		t=-1;
		for(int i=0;i<total;i++)
		{
			if(order[i]==2) continue;
			else
			{
				if(order[i]>v2[index])
				{
					if(t==-1) t=i;
					else if(order[i]<order[t]) t=i;
				}
			}
		}
	}
	realIndex=t;
	return index;
}

int getCheatStrategy2(int& realIndex)
{
	//从大到小骗
	int id1;
	for(int i=total-1;i>=0;i--)
	{
		id1=getNormalStratgy(order[i]);
		//选择刚好大于它的吃掉它
		bool find=false;
		for(int j=0;j<total;j++)
		{
			if(order[j]==2) continue;
			else
			{
				if(order[j]>v2[id1])
				{
					if(!find)
					{
						find=true;
						realIndex=j;
						break;
					}
				}
			}
		}
		if(find)
		{
			return id1;
		}
		else
		{
			continue;
		}

	}

	int usedIndex=0;
	for(int i=0;i<total;i++)
	{
		if(order[i]!=2)
		{
			usedIndex=i;
			break;
		}
	}
	realIndex=usedIndex;
	return getNormalStratgy(order[usedIndex]);
}


int getCheatStrategy3(int& realIndex)
{
	//每次选最大的来骗
	int id1;
	
	id1=getNormalStratgy(order[total-1]);
		//选择刚好大于它的吃掉它
	bool find=false;
	for(int j=0;j<total;j++)
	{
		if(order[j]==2) continue;
		else
		{
			if(order[j]>v2[id1])
			{
				if(!find)
				{
					find=true;
					realIndex=j;
					break;
				}
			}
		}
	}
	if(find)
	{
		return id1;
	}
		

	//找不到，出我最小的牌

	int usedIndex=-1;
	for(int i=0;i<total;i++)
	{
		if(order[i]!=2)
		{
			if(usedIndex==-1)
			{
				usedIndex=i;
				break;
			}
		}
	}
	realIndex=usedIndex;
	return id1;
}

void processOrder()
{
	vector<double> tempV2=v2;
	vector<double> tempOrder=order;
	od1=0;od2=0;
	for(int i=0;i<total;i++)
	{
		int index=getNormalStratgy(order[i]);
		if(v2[index]<order[i])
		{
			od2++;
		}
		order[i]=2;
		v2[index]=2; //used
	}

	v2=tempV2;
	order=tempOrder;
	for(int i=0;i<total;i++)
	{
		int index;
		int index2;
		index=getCheatStrategy3(index2);
		if(v2[index]<order[i])
		{
			od1++;
		}
		
		order[index2]=2;
		v2[index]=2;
	}
	v2=tempV2;
	order=tempOrder;
	if(od1>bd1) bd1=od1;
	if(od2>bd2) bd2=od2;
}

void createOrder(int depth)
{
	/*if(depth==total)
	{*/
		sort(v1.begin(),v1.end());
	
		order=v1;
		processOrder();
		return;
	/*}
	for(int j=0;j<total;j++)
	{
		if(v1[j]!=0)
		{
			order[depth]=v1[j];
			v1[j]=0;
			createOrder(depth+1);
			v1[j]=order[depth];
		}
	}	*/
}


void getNumber()
{
	bd1=0;bd2=0;
	createOrder(0);
}
void main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);

	int times;
	scanf("%d",&times);
	for(int time=1;time<=times;time++)
	{
		int size;
		scanf("%d",&size);
		v1.resize(size,0);
		v2.resize(size,0);
		order.resize(size,0);
		for(int i=0;i<size;i++)
		{
			scanf("%lf",&v1[i]);
		}
		for(int i=0;i<size;i++)
		{
			scanf("%lf",&v2[i]);
		}
		total=size;
		getNumber();
		printf("Case #%d: %d %d\n",time,bd1,bd2);
	}
}