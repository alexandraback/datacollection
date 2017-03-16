#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin;
	fin.open("B-large.in");
	ofstream fout;
	fout.open("Bans.txt");
	int T;
	int N;
	int num;
	bool improve;
	int cur;
	int second;
	int index;
	fin>>T;
	int star[1000][2];
	bool finish[1000][2];
	for (int i=1;i<=T;i++)
	{
		fin>>N;
		for (int j=0;j<N;j++)
		{
			fin>>star[j][0];
			fin>>star[j][1];
			finish[j][0]=false;
			finish[j][1]=false;
		}
		cur=0;
		num=0;
		while(1)
		{
			improve=false;
			for (int j=0;j<N;j++)
			{
				if (finish[j][1]==false && star[j][1]<=cur)
				{
					finish[j][1]=true;
					if (finish[j][0]==false)
					{
						finish[j][0]=true;
						cur=cur+2;
					}
					else
					{
						cur=cur+1;
					}
					improve=true;
					break;
				}
			}
			if (improve==true)
			{
				num++;
				continue;
			}

			second=-1;
			for (int j=0;j<N;j++)
			{
				if (finish[j][0]==false && star[j][0]<=cur)
				{
					if (star[j][1]>second)
					{
						second=star[j][1];
						index=j;
					}
				}
			}
			if (second==-1)
			{
				improve=false;
			}
			else
			{
				finish[index][0]=true;
				cur=cur+1;
				improve=true;
			}
			if (improve==true)
			{
				num++;
				continue;
			}

			improve=true;
			for (int j=0;j<N;j++)
			{
				if (finish[j][1]==false)
				{
					improve=false;
					break;
				}
			}
			if (improve==true)
			{
				fout<<"Case #"<<i<<": "<<num<<endl;
			}
			else
			{
				fout<<"Case #"<<i<<": Too Bad"<<endl;
			}
			break;			
		}
	}
	fin.close();
	fout.close();
	return 0;
}