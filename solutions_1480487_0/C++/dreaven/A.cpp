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



bool isok(const vi & b, int number, double k, int S)
{
	int N = b.size();
	bool flag = true;
	double res = number + S*k;
	int i;
	double x = 1-k;
	double temp;
	for(i = 0;i<N;i++)
	{
		if(b[i]==number &&flag)
		{ flag= false; continue;}

		temp = (res - b[i] )/S;
		if (temp <0)
			continue;
		else
			x = x- temp;
		if (x<0)
			return true;

		
	}
	return false;


}


double compute(const vi & b, int number, int S)
{
	double start = 0;
	double upp = 1.00;
	double temp = 0.50;
	int i;
	for(i=0;i<30;i++)
	{
		if(isok(b,number,temp, S))	
		{
			upp = temp;
			
		}
		else
		{
			start = temp;
		}

		temp = (start+upp)/2;
	}

	return temp;
}

int main()
{
	ifstream infile;
	ofstream outfile;

	//string inputfilename = "test_in.txt";
	string outputfilename = "test_out.txt";
	
	string inputfilename = "A-small-attempt1.in";
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
	
	for(i=1;i<=T;i++)
	{
		getline(infile,line);
		ss.clear();
		ss.str(line);
		ss>>N;
		vi a(N,0);
		int total = 0;
		for(j=0;j<N;j++)
		{ ss>>a[j]; total+=a[j];
		cout<<a[j];}

		vi b = a;
		

		cout<<endl;

		vector<double> res(N,0);

		for(j=0;j<N;j++)
		
		{
		  res[j] = compute(b,a[j],total);

		}

		
		
	    



		
		outfile<<"Case #"<<i<<": ";

		char c[90];
		for(j=0;j<N;j++)
		{
			sprintf(c,"%.9f",res[j]*100);
			outfile<<c<<" ";
		}
		outfile<<endl;
		

    
	    
	}

	

	

	infile.close();
	outfile.close();

	cout<<"Program Completed"<<endl;
	


}
