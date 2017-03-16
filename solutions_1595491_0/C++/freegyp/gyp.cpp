#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
int maxns(int total)
{
	switch(total%3)
	{
		case 0:return total/3;break;
		case 1:return (total-1)/3+1;break;
		default:return (total-2)/3+1;break;
	}
}
int main()
{
	ifstream gin("B-small-attempt1.in");
	ofstream gout("gypBsmall.out");
	int T,N,S,p;
	gin>>T;
	for(int i=0;i<T;i++)
	{
		gin>>N>>S>>p;
		int changable=0,already=0;
		for(int j=0;j<N;j++)
		{
			int temp;gin>>temp;
			if(maxns(temp)==p-1&&((temp%3==0&&p!=1)||temp%3==2))changable++;
			else if(maxns(temp)>=p)already++;
		}
		gout<<"Case #"<<i+1<<": ";
		if(changable>=S)gout<<already+S<<endl;
		else gout<<already+changable<<endl;
	}
	gout.close();
	gin.close();
	return 0;
}
