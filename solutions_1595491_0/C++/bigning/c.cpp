#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("out.txt");

	int T,N,S,p,* totalPoints;
	fin>>T;
	for(int i=0;i<T;i++)
	{
		fin>>N>>S>>p;
		totalPoints=new int[N];

		for(int j=0;j<N;j++)
			fin>>totalPoints[j];
		//sort(totalPoints,totalPoints+N);

		

		int num=0;
		int result=0,a,b,c;
		for(int j=0;j<N;j++)
		{
			if(totalPoints[j]==0)
				continue;
			if(totalPoints[j]>=3*p-2)
			{
				result++;continue;
			}
			if(totalPoints[j]>=3*p-4 && num<S)
			{
				num++;
				result++;
			}
		}
		if(p==0)
		{
			result=N;
		}
		else
		{
			if(p==1)
			{
				result=0;
				for(int j=0;j<N;j++)
				{
					if(totalPoints[j]>=1)
						result++;
				}
			}
		}

		cout<<"Case #"<<i+1<<": "<<result<<endl;
		fout<<"Case #"<<i+1<<": "<<result<<endl;
		delete[] totalPoints;
	}

	fin.close();
	fout.close();

	return 0;
}