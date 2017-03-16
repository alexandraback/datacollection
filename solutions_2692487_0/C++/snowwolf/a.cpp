#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}
int minvalue(int a,int b)
{
	return a<b?a:b;
}
int main(void)
{
	int test,count=0;
	FILE *fr=fopen("2.txt","r");
	FILE *fw=fopen("out.txt","w");
	fscanf(fr,"%d",&test);
	while(test--)
	{
		count++;
		int a,n;
		int size[110];
		fscanf(fr,"%d %d",&a,&n);
		int i;
		for(i=0;i<n;++i)
		{
			fscanf(fr,"%d",&size[i]);
		}
		sort(size,size+n,cmp);
		int result=0,maxresult=n;
		for(i=0;i<n;++i)
		{
			if(a>size[i])
			{
				a+=size[i];
			}
			else
			{
				int left=n-i;
				//int tmpresult=0;
				if(result+left<maxresult)
				{
					maxresult=result+left;
				}
				while(result<maxresult)//&&tmpresult<left)
				{
					int tmp=a-1;
					a+=tmp;
					result++;
					//tmpresult++;
					if(a>size[i])
					{
						a+=size[i];
						break;
					}
				}
				if(result==maxresult)
				{
					break;
				}
			}
		}
		fprintf(fw,"Case #%d: %d\n",count,result);
	}
	fclose(fr);
	fclose(fw);
	return 0;
}