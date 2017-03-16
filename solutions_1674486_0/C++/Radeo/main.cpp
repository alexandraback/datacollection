#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;
vector<int> he;
vector<int> se;
bool flag=false;
void check(vector< vector<int> > v, int a)
{
    for(int j=0; j<v[a].size(); j++)
    {
         //if(count (he.begin(), he.end(), v[a][j])>0)
              //return true;
         //else
         //{
		      //cout <<v[a][j]+1;
			  if(count (he.begin(), he.end(), v[a][j])>0)
				  flag=true;
              he.push_back(v[a][j]);
			  check(v,v[a][j]);


              //if(check(v,v[a][j]))
                   //return true;
        // }
    }
  
}

string solve(vector< vector<int> > v)
{   //cout << endl << v.size() << ":" << endl;
    for(int i=0; i<v.size(); i++)
    {
		//cout << "x";
         he.erase(he.begin(),he.end());
		 flag=false;
		 check(v,i);
		 if(flag)
			 return "Yes";
		 

         
    }
    return "No";
}

int main()
{
	ifstream infile ("A-small-attempt0.in");
	ofstream outfile("A.out");

	int N, C, H, V;
	infile >> N;
	string line;
	char tab[1000];
	getline (infile,line);
	for(int i=0; i<N; i++)
	{
        outfile << "Case #" << i+1 << ": ";
        infile >> C;
        vector< vector<int> > v;
        getline (infile,line);
        for(int j=0; j<C; j++)
        {
              infile >> H;
              vector<int> tmp;
              for(int k=0; k<H; k++)
              {
                   infile >> V;
                   tmp.push_back(V-1);
              }
              v.push_back(tmp);
        }  
        getline (infile,line);
        outfile << solve(v);
        outfile << "\n";
       
    }


	infile.close();
	outfile.close();
	system("pause");
}
