#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
using namespace std;

int main(int argc, char * argv[])
{
	ifstream fin("input.txt"); 
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string str;
	getline(fin, str);
	
	const int T = atoi(str.c_str());

	ofstream fout("output.txt");
	for( int aaa = 0; aaa < T ; aaa++)
	{
		getline(fin, str);
		istringstream iss(str);
		int N;
		iss >> N;
		//cout << "N: " << N << endl << endl;

		vector<vector<int> > adjList;
		vector<bool> root(N, true);
		for(int bbb = 0; bbb < N; bbb++)
		{
			getline(fin, str);		iss.clear(); iss.str(str);
			int M;
			iss >> M;
			//cout << " M: " << M << endl;
			vector<int> edgeList;
			for(int ccc = 0; ccc < M; ccc ++)
			{
				int nTemp;
				iss >> nTemp;
				edgeList.push_back(nTemp - 1);
				root[nTemp-1] = false;
			}
			adjList.push_back(edgeList);
		}
		bool isDiag = false;
		for(int bbb = 0; bbb< N; bbb++)
		{
			vector<int> toVisit;
			if(root[bbb])
			{
				vector<bool> visited(N, false);
				//cout << "ROot: " << bbb << endl;
				for(vector<int>::iterator it_al =adjList[bbb].begin(); it_al < adjList[bbb].end(); it_al++)
				{
					//cout << bbb << *it_al << endl;
					toVisit.push_back(*it_al);
				}

				while(!toVisit.empty())
				{
					int curr = toVisit.back();
					//cout << curr << endl;
					toVisit.pop_back();
					if(visited[curr] == true){
						//cout << "Found: " << bbb << " " << curr<<endl;
						isDiag = true;
						bbb= N;
						break;
					}

					else
						visited[curr] = true;

					for(vector<int>::iterator it_al = adjList[curr].begin(); it_al < adjList[curr].end(); it_al++)
					{
						toVisit.push_back(*it_al);
					}
				}
			}
		}
		if(isDiag)
			fout << "Case #" << aaa+1 << ": Yes" <<  endl;
		else
			fout << "Case #" << aaa+1 << ": No" <<  endl;

			//cout << endl << endl;
		//fout << fixed << setprecision(6) << "Case #" << aaa+1 << ": " << setprecision(6) << static_cast<double>( minKey )<< setprecision(6) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
