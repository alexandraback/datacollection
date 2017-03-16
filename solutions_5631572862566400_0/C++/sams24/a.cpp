#include <deque>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct chain
{
	unsigned adj;
	unsigned len;
};

int main()
{
	unsigned t;

	unsigned prev, curr, next;
	cin >> t;

	unsigned temp;
	unsigned n;


	fstream fout;
	fout.open("c_output.out", ios::out);

	unsigned bff[1009];
	bool visited[1009];
	unsigned ans;


	for(unsigned i=1; i<=t; i++)
	{
		cin >> n;
		cout << " n is " << n << endl;

		ans = 2;		
		for(unsigned l=1; l<=n; l++)
		{
			cin >> bff[l];
		}

	   unsigned longest_ending_at[1009][1009];

	   for(unsigned p=1; p<=n; p++)
	   {
		   for(unsigned q=1; q<=n; q++)
		   {
			   longest_ending_at[p][q] = 0;
		   }
	   }

	   deque<deque<unsigned> > consider;
		for(unsigned l=1; l<=n; l++)
		{
			for(unsigned m=1; m<=n; m++)
			{
				visited[m] = false;
			}

			temp = 0;
			prev = 0;
			curr = l;

			while(true)
			{
				visited[curr] = true;
				temp ++;

				if(longest_ending_at[l][curr] < temp)
				{
					longest_ending_at[l][curr] = temp;
				}			
				next = bff[curr];
	

				if(visited[next])
				{
					if(next != l && next != prev)
					{
						break;
					}
					if(next == prev)
					{
						// we can find a thing ending at curr
						deque<unsigned> temp;
						for(unsigned hi=1; hi<=n; hi++)
						{
							if(visited[hi])
							{
								temp.push_back(hi);
							}
						}
						temp.push_back(curr);
						consider.push_back(temp);
					}
					if(temp > ans)
					{
						ans = temp;
					}
					break;
				}
				else
				{
					prev = curr;
					curr = next;
				}
			}
		}

		for(unsigned z=0; z<consider.size(); z++)
		{
			unsigned even = 0;
			unsigned first_time = 0;
			unsigned max = 0;
			bool done;
			for(unsigned i1=1; i1<=n; i1++)
			{
				done = false;
				next = i1;
				unsigned iterat = 0;
				while(done == false && next != consider[z].back() && iterat <= n){
					iterat++;
					for(unsigned lp=0; lp<consider[z].size(); lp++)
					{
						if(consider[z][lp] == next)
						{done = true; break;}

					}
					next = bff[next];
					
				}

				if(done)
				{ continue;
				}
				if(longest_ending_at[i1][consider[z].back()] != 0)
				{
					cout << "£" << i1 << endl;
					even ++;
					if(longest_ending_at[i1][consider[z].back()] == consider[z].size()-2 && first_time == 0)
					{
						first_time = 1;
					}
					else
					{
						if(longest_ending_at[i1][consider[z].back()] > max)
						{
							max = longest_ending_at[i1][consider[z].back()];
						}
					}
				}
			}
			if(even >=2)
			{
				if(max + consider[z].size() -2 > ans)
				{
					ans = max + consider[z].size()-2;
				}
			}
			
		}
		


		fout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
