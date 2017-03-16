#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	FILE *fp=fopen("B-small-attempt1.in","r");
	FILE *fp2=fopen("out.txt","w");
	int data;
	fscanf(fp,"%d",&data);
	for(int i=1;i<=data;i++)
	{
		printf("Case #%d: ",i);
		fprintf(fp2,"Case #%d: ",i);
		int num;
		fscanf(fp,"%d",&num);
		multiset<pair<int,int> >se;
		for(int j=0;j<num;j++)
		{
			int za,zb;
			fscanf(fp,"%d%d",&za,&zb);
			se.insert(make_pair(zb,za));
		}
		int ret=0;
		int now=0;
		multiset<pair<int,int> >::iterator it;
		multiset<pair<int,int> >::iterator it2;
		for(int k=0;k<num;k++)
		{
			it2=se.end();
			for(;;)
			{
				it=se.begin();
				pair<int,int>beg=*it;
				if(beg.first<=now)
				{
					se.erase(it++);
					//printf("%d ",now);
					now+=2;
					ret++;
					if(beg.second==1000000000)
					{
						now--;
					}
					break;
				}
				if(it2==se.begin())
				{
					printf("Too Bad\n");
					fprintf(fp2,"Too Bad\n");
					goto l01;
				}
				it2--;
				pair<int,int>zan=*it2;
				if(zan.second<=now)
				{
					now++;
					ret++;
					se.erase(it2++);
					se.insert(make_pair(zan.first,1000000000));
					it2=se.end();
				}
			}
		}
		printf("%d\n",ret);
		fprintf(fp2,"%d\n",ret);
l01:;
	}
}