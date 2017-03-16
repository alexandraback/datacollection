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






double compute(vector<double> & prob, int A, int B)
{
    double res = 100000000;

    double p=1;
    int i;
    int N = prob.size();
    for(i=0;i<N;i++)
	p*=prob[i];

    res = p*(B-A+1)+ (1-p)*(B-A+1 + B + 1);

    double giveup;
    if(A==B)
   	giveup = p + (1-p)*(B+2);
    else
	giveup = 1 + B + 1;

    if (res>giveup)
	res = giveup;


    
    for(i=1;i<A;i++)
    {
	p = p/prob[N-i];

	double temp = p*(i+B-A+i+1) + (1-p)*(i+B-A+i+1+B+1);

	if (res >temp)
	    res = temp;

    }

    return res;



}




int main()
{
	ifstream infile;
	ofstream outfile;

	//string inputfilename = "test_in.txt";
	//string outputfilename = "test_out.txt";
	
	string inputfilename = "A-large.in";
	string outputfilename = "a-large.out";

	infile.open(inputfilename, ios::in);
	outfile.open(outputfilename, ios::out);

	int i,j,k,m,n,M,N,T,A,B;

	string line;
	istringstream ss;

	getline(infile,line);
	ss.clear();
	ss.str(line);

	ss>> T;

	vector<double > prob;
	
	for(i=1;i<=T;i++)
	{
	    getline(infile,line);
	    ss.clear();
	    ss.str(line);

	    ss>>A>>B;

	    prob.resize(A,0);

	    getline(infile,line);
	    ss.clear();
	    ss.str(line);

	    for(j=0;j<A;j++)
		ss>>prob[j];


	    double res = compute(prob,A,B);

		char c[90];

		sprintf(c,"%20f", res );

		cout<<c<<endl;



		outfile.precision(19);
		outfile<<"Case #"<<i<<": "<<c<<endl;


	    
	    
	}

	//cout<<line<<endl;

	




	

	







	infile.close();
	outfile.close();


	int a32532;

	
	


}
