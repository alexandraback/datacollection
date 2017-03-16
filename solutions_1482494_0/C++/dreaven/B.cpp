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



ifstream infile;
ofstream outfile;

string inputfilename = "B-small-attempt3.in";
string outputfilename = "b.out";


//string inputfilename = "test.txt";
//string outputfilename = "test.out";






int main()
{
	
	infile.open(inputfilename, ios::in);
	outfile.open(outputfilename, ios::out);

	int i,j,k,m,n,M,N,T;

	string line;
	istringstream ss;

	getline(infile,line);
	ss.clear();
	ss.str(line);

	ss>> T;

	bool flag[1005];
	for(i=1;i<=T;i++)
	{
	    
	    getline(infile,line);
		ss.clear();
		ss.str(line);

	     ss>> N;

	     multimap<int,int> a,b;
	     a.clear();
	     b.clear();
	     int t1,t2;

	     int aaa[2000];
	     int bbb[2000];
	    for(j=0;j<N;j++)
	    {
		flag[j]=true;
		getline(infile,line);
		ss.clear();
		ss.str(line);
		ss>>t1>>t2;

		a.insert(mp(t1,j));
		b.insert(mp(t2,j));
		aaa[j] = t1;
		bbb[j] = t2;

	    }

	    int total = 0, step=0;
	    multimap<int,int>::iterator itera,iterb, it1,it2,it3;

	    itera=a.begin();
	    iterb=b.begin();
	    bool q = true;


	    while(iterb!=b.end())
	    {
		int point = iterb->first;
		int index = iterb->second;

		if(total>=point)
		{
		    if(flag[index]==false)
		    {
			 total+=1;
			

		    }
		    else
		    {
		    	total+=2;
		   
		   	flag[index] = false;
		    }

		    iterb++;
		    step++;

		    if(iterb == b.end())
				break;
		   
		}


		else
		{
		    while(  itera!= a.end() && flag[ itera->second ] == false )
			itera++;

		    if (itera==a.end())
		    {
			q = false;
			break;
		    }

		    if (total < itera->first)
		    {
			q = false;
			break;
		    }


		    it1 = itera;
		    it2 = it1;
		    it3 = it1;
		    int large = itera->second;
		    while(it2 != a.end())
		    {
			if( flag[it2->second]==false)
			{ it2++;   continue;}

			if ( bbb[it2->second] > bbb[large] && total>= it2->first)
			{
			    it3 = it2;
			    large = it2->second;
			}

			it2++;
			
		    }


    
		    
			flag[large] = false;
			total +=1;
		
			step++;
		    


		}

	    }

	    if (q==false)
		outfile<<"Case #"<<i<<": Too Bad"<<endl;
	    else
		outfile<<"Case #"<<i<<": "<< step<<endl;






	}

	




	

	







	infile.close();
	outfile.close();

	
	


}
