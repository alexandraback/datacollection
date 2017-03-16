#include <fstream>
#include <algorithm>
using namespace std;
int T,R,N,M,K;
int val[7];
int res[4];
int resNum=0;
int flag[6]={0};
int main()
{
	
	ifstream fin("C-small-1-attempt0.in");
	ofstream fout("C-small-1-attempt0.out");
	fin>>T;
	fin>>R>>N>>M>>K;
	fout<<"Case #1:"<<endl;
	for(int t=0;t<R;t++)
	{
		
		fill(flag,flag+6,0);
		for(int j=0;j<K;j++)
		{
			fin>>val[j];
			if(val[j]%5==0)
			{
				if(val[j]%125==0)
				{
					flag[5]=3;
				}
				else if(val[j]%25==0)
				{
					flag[5]=(flag[5]<=2)?2:flag[5];
				}
				else
				{
					flag[5]=(flag[5]<=1)?1:flag[5];
				}
			}
			if(val[j]%3==0)
			{
				if(val[j]%27==0)
				{
					flag[3]=3;
				}
				else if(val[j]%9==0)
				{
					flag[3]=(flag[3]<=2)?2:flag[3];
				}
				else
				{
					flag[3]=(flag[3]<=1)?1:flag[3];
				}
			}
			if(val[j]%2==0)
			{
				if(val[j]%8==0)
				{
					flag[2]=3;
				}
				else if(val[j]%4==0)
				{
					flag[2]=(flag[2]<=2)?2:flag[2];
				}
				else
				{
					flag[2]=(flag[2]<=1)?1:flag[2];
				}
			}
		}
		resNum=0;
		for(int i=2;i<=M;i++)
		{
			resNum+=flag[i];
			for(int j=0;j<flag[i];j++)
			{
				fout<<i;
			}
		}
		if(resNum<3)
		{
			for(int i=resNum+1;i<=3;i++)
			{
				fout<<"2";
			}

		}
		fout<<endl;

	}
	fin.close();
	fout.close();
	return 0;
}

