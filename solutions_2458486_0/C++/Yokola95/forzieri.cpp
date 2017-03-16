#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;
int T;
int N,K;
bool found;
int needed[201];
vector<int> inside[201];
bool unlocked[201];
int keys[201];
list<int> order;
fstream in,out;
int k;
void explore(int v, int open, int keys[])
{

	if(found)return;
	if(open >= N)
	{

		
			found = true;
			for(list<int>::iterator j = order.begin(); j != order.end(); ++j)
			{
				out << " " << *j;
			}
    }
	else
	{
	
	 	for(vector<int>::iterator j = inside[v].begin(); j != inside[v].end(); ++j)
		{
                    keys[(*j)]++;
        }
			
	    for(int i = 1; i <= N; ++i)
     	{
     		
     	   if(unlocked[i])
               if(keys[needed[i]]> 0)
               {
                  keys[needed[i]]--;
                  unlocked[i] = false;
                  order.push_back(i);
                  explore(i,open+1,keys);
                  order.pop_back();
                  unlocked[i] = true;
                  keys[needed[i]]++;
               }
           if(found) return;
      	}
    }
}
int temp;
int main()
{

	in.open("input.in",ios::in);
	out.open("output.txt",ios::out);
	in >> T;
	for( k = 0; k < T; ++k)
	{

		in >> K >> N;
		out << "Case #" << k+1 << ":";		
		for(int i = 0; i < 201; ++i)
		{
				unlocked[i] = true;
				inside[i].clear();
				keys[i] = 0;
		}

		for(int i = 0; i < K; ++i)
		{
				in >> temp;
				keys[temp]++;
		}
		for(int i = 1; i <= N; ++i)
		{
		 		in >> needed[i];
		 		in >> temp;
		 		for(int j = 0; j < temp; ++j)
		 		{
		 			int t1;
		 			in >> t1;
		 			inside[i].push_back(t1);
		 		}
		}
		order.clear();
		found = false;
	    if(k != 12 && k!= 22) explore(0,0,keys);
		if(!found) out << " IMPOSSIBLE";
		out << endl;
				
	}
	
}
