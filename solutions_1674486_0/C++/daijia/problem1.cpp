#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector <bool> > relation;
vector< vector <int > > countnumber;

void mygod(int j,int k)
{
	int i;
	
	for(i =0;i<countnumber.size();i++)
	{
		if(relation[k][i])
		{
			countnumber[j][i]++;
			mygod(j,i);
		}
	}
}
int main()
{
	int T;
	ofstream outfile("C:\\Users\\fog\\Desktop\\exam.txt");
	cin>>T;
	int i,j,k;
	for(i=0;i<T;i++)
	{
		int classnumber;
		cin>>classnumber;

		relation.clear();
		countnumber.clear();

		countnumber.resize(classnumber);
		for(j =0;j<classnumber;j++)
		{
			countnumber[j].resize(classnumber);
		}
		
		for(j =0;j<classnumber;j++)
		{
			for( k =0;k<classnumber;k++)
				countnumber[j][k] = 0;
		}

		relation.resize(classnumber);
		for(j =0;j<classnumber;j++)
		{
			relation[j].resize(classnumber);
		}
		for(j =0;j<classnumber;j++)
		{
			for( k =0;k<classnumber;k++)
				relation[j][k] = false;
		}
		for(j =0;j<classnumber;j++)
		{
			int inhernumber;
			cin>>inhernumber;
			for(k=0;k<inhernumber;k++)
			{
				int temp;
				cin>>temp;
				relation[j][temp-1] = true;
			}
		}

		for(j=0;j<classnumber;j++)
		{
			for(k=0;k<classnumber;k++)
			{
				if( relation[j][k] == true)
				{
					countnumber[j][k]++;
					mygod(j,k);
				}
			}
		}

		for(j=0;j<classnumber;j++)
		{
			for(k=0;k<classnumber;k++)
			{
				if(countnumber[j][k]>1)
				{
					outfile<<"Case #"<<i+1<<": Yes"<<endl;
					goto somewhere;
				}

			}
		}

		
		outfile<<"Case #"<<i+1<<": No"<<endl;


        somewhere:
		continue;
	}
	return 0;
}

