#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>

using namespace std;
int C,D,V;

bool money[31][2];
bool tmp_money[31][2];
int best=0;
//bool cache[30][30];

void make()
{
	for (int i = 1; i <= V-1; i++)
	{
		if(money[i][0])
		{
			for (int j = i+1; j <= V; j++)
			{
				if(i!=j && i+j<=V && money[j][0])
				{
					money[i+j][1]=true;
				}
			}
		}	
	}
}

void sol()
{
	int cnt=0;
	for (int i = 1; i <= V; i++)
	{
		if(!money[i][0] && !money[i][1])
		{
			cnt++;
		}
	}
	best=min(best,cnt);
}


void queen()
{
	for (int i = 1; i <= V; i++)
	{
		if(!money[i][0] && !money[i][1])
		{
			money[i][0]=money[i][1]=true;
			memcpy(tmp_money,money,sizeof(bool)*31*2);
			make();
			sol();
			money[i][0]=money[i][1]=false;
			memcpy(money,tmp_money,sizeof(bool)*31*2);
		}
	}
}

int main()
{
	ifstream OpenFile("C-small-attempt1.txt");
	ofstream SaveFile("ex_out.txt");

	int T;
	OpenFile>>T;

	for (int t = 0; t < T; t++)
	{
		best=987654321;
		memset(money,false,sizeof(bool)*31*2);
		OpenFile>>C>>D>>V;
		for (int i = 0; i < D; i++)
		{
			int tmp;
			OpenFile>>tmp;
			money[tmp][0]=true;
		}
		sol();
		SaveFile<<"Case #"<<t+1<<": "<<best<<endl;
	}
	
	OpenFile.close();
	SaveFile.close();

	return 0;
}