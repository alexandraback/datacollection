#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct MyStruct
{
	int a,b;
	bool aFlag,bFlag;
	int index;
};

bool haveFinished(MyStruct * m,int n)
{
	bool result=true;
	for(int i=0;i<n;i++)
	{
		if(m[i].bFlag==false)
		{
			result=false;
			return result;
		}
	}
	return result;
}

bool pr1(MyStruct m1,MyStruct m2)
{
	if(m1.a!=m2.a)
	{
		return m1.a<m2.a; 
	}
	return m1.b<m1.b;
}

bool pr2(MyStruct m1,MyStruct m2)
{
	return m1.b<m2.b;
}

int main()
{
	ifstream fin("B-small-attempt3.in");
	ofstream fout("r.txt");
	vector<MyStruct> newM;

	int T,N;
	MyStruct * m;
	fin>>T;
	for(int i=0;i<T;i++)
	{
		fin>>N;
		int haveStars=0;

		if(i==30)
		{
			int a;
			a=1;
		}

		m=new MyStruct[N];
		for(int j=0;j<N;j++)
		{
			fin>>m[j].a>>m[j].b;
			m[j].aFlag=false;
			m[j].bFlag=false;
			m[j].index=j;
		}

		int step=0;
		bool canGo=true;
	
		while(true)
		{
			newM.clear();
			if(haveFinished(m,N))
			{
				canGo=true;
				break;
			}

			for(int j=0;j<N;j++)
			{
				if(m[j].bFlag==false)
				{
					MyStruct t=m[j];
					newM.push_back(t);
				}
			}
			sort(newM.begin(),newM.end(),pr2);
			
			if(newM[0].b<=haveStars)
			{
				if(newM[0].aFlag==true)
				{
					haveStars+=1;
				}
				else
				{
					haveStars+=2;
				}
				m[newM[0].index].bFlag=true;
				canGo=true;
				step++;
				newM.clear();
				continue;
			}
			else
			{
				canGo=false;
			}
			newM.clear();
			if(canGo==false)
			{
				
				for(int j=0;j<N;j++)
				{
					if(m[j].aFlag==false && m[j].bFlag==false)
					{
						MyStruct t=m[j];
						newM.push_back(t);
					}
				
				}

				if(newM.size()==0)
				{
					canGo=false;
					newM.clear();
					break;
				}
				sort(newM.begin(),newM.end(),pr1);
				if(newM[0].a<=haveStars)
				{
					haveStars++;
					m[newM[0].index].aFlag=true;
					canGo=true;
					step++;
					newM.clear();
					continue;
				}
				else
				{
					canGo=false;
					newM.clear();
					break;
				}
			}


			newM.clear();
		}

		cout<<"Case #"<<i+1<<": ";
		fout<<"Case #"<<i+1<<": ";
		if(canGo)
		{
			cout<<step<<endl;
			fout<<step<<endl;
		}
		else
		{
			cout<<"Too Bad"<<endl;
			fout<<"Too Bad"<<endl;
		}



		delete[] m;
	}

	return 0;
}