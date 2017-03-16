#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int **f12,**f13,**f23;
int j=0,p=0,s=0,k=0;

int main() 
{
	FILE *fin1 = fopen("point.in","r+");
	FILE *fin2 = fopen("point.out","w+");


	int t=0;
	fscanf(fin1, "%d",&t);
	int u=1;
	while(t-->0)
	{
		fscanf(fin1, "%d%d%d%d",&j,&p,&s,&k);
		
		fprintf(fin2,"Case #%d: ",u);u++;

		f12=new int*[j];
		for(int i=0;i<j;i++)
		{
			f12[i]=new int[p];
			for(int jj=0;jj<p;jj++)
			{
				f12[i][jj]=0;
			}
		}
		f13=new int*[j];
		for(int i=0;i<j;i++)
		{
			f13[i]=new int[s];
			for(int jj=0;jj<s;jj++)
			{
				f13[i][jj]=0;
			}
		}
		f23=new int*[p];
		for(int i=0;i<p;i++)
		{
			f23[i]=new int[s];
			for(int jj=0;jj<s;jj++)
			{
				f23[i][jj]=0;
			}
		}
		vector<pair<pair<int,int>, int> > res;
		for(int ii=0;ii<j;ii++)
		{
			for(int jj=0;jj<p;jj++)
			{
				if(f12[ii][jj]>=k)
				{
					continue;
				}
				for(int kk=0;kk<s;kk++)
				{
					if(f12[ii][jj]>=k || f13[ii][kk]>=k || f23[jj][kk]>=k)
					{
						continue;
					}
					f12[ii][jj]++;
					f13[ii][kk]++;
					f23[jj][kk]++;

					res.push_back(make_pair<pair<int,int>, int>(make_pair<int,int>(ii+1,jj+1),kk+1));
				}
			}
		}

		fprintf(fin2,"%d\n",res.size());
		for(int i=0;i<res.size();i++)
		{
			fprintf(fin2,"%d %d %d\n",res[i].first.first,res[i].first.second,res[i].second);
		}
		
	}
	return 0;
}