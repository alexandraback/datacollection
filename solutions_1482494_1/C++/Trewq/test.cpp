#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int lvl[1001][2];
int finish[1001];
int list1[1001],list2[1001];
bool cmp1(int a,int b)
{
	if(lvl[a][0]==lvl[b][0])
		return lvl[a][1]>lvl[b][1];
	return lvl[a][0]<lvl[b][0];
}
bool cmp2(int a,int b)
{
	return lvl[a][1]<lvl[b][1];
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n;
	int strsum,p1,p2,cnt;
	cin>>t;
	for(int cs=1;cs<=t;cs++)
	{
		cin>>n;
		memset(finish,0,sizeof(finish));
		for(int i=0;i<n;i++)
		{
			list1[i]=list2[i]=i;
			cin>>lvl[i][0]>>lvl[i][1];
		}
		
		sort(list2,list2+n,cmp2);
		cnt=strsum=p1=0;
		for(p2=0;p2<n;p2++)
		{
			while(strsum<lvl[list2[p2]][1])
			{
				int max2=-1,index=-1;
				for(int i=0;i<n;i++)
					if(!finish[i]&&strsum>=lvl[i][0]&&lvl[i][1]>max2)
					{
						max2=lvl[i][1];
						index=i;
					}
				if(index>=0)
				{
					finish[index]=1;
					strsum++;
					cnt++;
				}
				else
					break;
			}
			if(strsum>=lvl[list2[p2]][1])
			{
				strsum+=2-finish[list2[p2]];
				finish[list2[p2]]=2;
			}
			else
				break;
		}
		cout<<"Case #"<<cs<<": ";
		if(strsum==2*n)
			cout<<n+cnt<<endl;
		else
			cout<<"Too Bad"<<endl;
	}
	return 0;
}