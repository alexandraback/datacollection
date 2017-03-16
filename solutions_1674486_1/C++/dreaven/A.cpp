#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <utility>
#include <iomanip>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;

struct Point
{
    int x,y;
    
    Point(int a, int b)
    {
	x = a;
	y = b;
    }
};



void dfs(int **a, int number, int N,  vi& c, bool & flag)
{
	
	int i,j,k;

	for(j=0;j<N;j++)
	{
		if(j==number)
			continue;
		if(a[number][j])
			{if( c[j] )
				{
					flag = true;
					return;
				}
			else
			{
				c[j] = true;
				dfs(a, j, N ,c, flag);
			}
		}
	}

		

}

int main()
{
	ifstream infile;
	ofstream outfile;

	string inputfilename = "A-large.in";
	string outputfilename = "output1.txt";
	
	//string inputfilename = "A-large.in";
	//string inputfilename = "A-large-practice.in";
	//string outputfilename = "a-large.out";

	infile.open(inputfilename, ios::in);
	outfile.open(outputfilename, ios::out);

	int i,j,k,m,n,M,N,T,A,B;

	string line;
	istringstream ss;

	getline(infile,line);
	ss.clear();
	ss.str(line);

	ss>>T;
	int **a = new int*[1001];
	for(i=0;i<1001;i++)
		a[i] = new int[1001];
	
	for(i=1;i<=T;i++)
	{
		getline(infile,line);
		ss.clear();
		ss.str(line);
		ss>>N;

		for(k=0;k<N;k++)
			for(j=0;j<N;j++)
				a[k][j] = 0;

		

		for(k=0;k<N;k++)
		{
			getline(infile,line);
			ss.clear();
			ss.str(line);
			ss>>M;
			for(j=0;j<M;j++)
			{
				int temp;
				ss>>temp;
				a[k][temp-1] = 1;
			}

		}

		vi b;
		b.clear();

		bool flag = false;

		for(k=0;k<N;k++)
		{
			flag = false;
			for(j=0;j<N;j++)
				if(a[j][k])
					{flag = true; break;}
			if (!flag)
				b.push_back(k);
		}

		flag = false;

		vi c(N,0);

		
		
		for(j=0;j<b.size();j++)
		{
			int num = b[j];
			flag = false;
			for (k=0;k<N;k++)
				c[k]=0;

			dfs(a, num, N,  c, flag);
			if (flag)
				break;

			
		}
	    



		if(flag)
			outfile<<"Case #"<<i<<": Yes"<<endl;
		else
			outfile<<"Case #"<<i<<": No"<<endl;

		
		

    
	    
	}

	

	

	infile.close();
	outfile.close();

	cout<<"Program Completed"<<endl;
	


}
