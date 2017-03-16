#include <stdio.h>
#include <iostream>
#include<fstream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
#include <list>
#include <utility>
#include<complex>

using namespace std;



int main(int argc, char *argv[])
{

	ifstream infile;
	infile.open("input.in",ifstream::in);
	ofstream outfile;
	outfile.open("output.in",ofstream::out);
	bool uni;
	int t;
	infile>>t;
	list<unsigned int> digits;


	for (int tt=0;tt<t;tt++)
	{

	unsigned long int A,B,n;
	unsigned long int repair=0;
	vector<unsigned int> nn;
	vector<unsigned int> ress;
	infile>>A>>B;

	for (n=A;n<B;n++)
	{
	unsigned long int reduced=n;
	while(reduced!=0){
		digits.push_front(reduced%10);
		reduced=reduced/10;
	}

	for (int j=0;j<(int)digits.size();j++){
		int temp=*digits.begin();
		digits.push_back(temp);
		digits.pop_front();


		int mul=1;
		unsigned long int recons=0;
		for (list<unsigned int>::reverse_iterator kk=digits.rbegin();kk!=digits.rend();++kk)
		{

			recons=recons+(*kk)*mul;
			mul=mul*10;
		}

		if ((recons>n)&(recons<=B))
		{

			uni=true;
			for(vector<unsigned int>::iterator kk=nn.begin(),rr=ress.begin();kk!=nn.end();++kk,++rr)
					{

						if ((n==(*kk))&(recons==(*rr)))
							uni=false;

					}
			if( uni==true)
			{
				repair=repair+1;
				nn.push_back(n);
				ress.push_back(recons);
			}
			cout<<n<<'\t'<<recons<<'\t'<<repair<<'\n';
		}
	}
	digits.clear();
	nn.clear();
	ress.clear();
	}

	outfile<<"Case #"<<tt+1<<": "<<repair<<"\n";
	cout<<repair;
	cout<<'\n';
	}
	//end of t*/

	infile.close();
	outfile.close();
}




