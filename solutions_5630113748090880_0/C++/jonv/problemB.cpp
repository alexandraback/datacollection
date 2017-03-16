#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
//#include <set>
#define ll long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
//typedef vector<map<int, int> > vmapii;

int N;
vvi mat;
//vmapii maps;
//set<int> numbers;

int main()
{
	int T, nt;
	cin >> T;
	nt = 0;
	while(nt < T)
	{
		cin >> N;
		mat.assign(2*N-1, vi(N));
		map<int, int> mainmap;
		//numbers.clear();
		for (int i = 0; i < 2*N-1; ++i)
		{
			for (int j = 0; j < N; ++j)	{
				cin >> mat[i][j];
				//numbers.insert(mat[i][j]);
				if (mainmap.find(mat[i][j])==mainmap.end())
					mainmap[mat[i][j]] = 1;
				else
					mainmap[mat[i][j]] = mainmap[mat[i][j]] + 1;
			}
		}
		//maps.clear();
		/*
		for (set<int>::iterator i = 0; i < count; ++i)
		{
		}
		*/
		int nelems = 0;
		vector<int> elems;
		for (int i = 0; i < 2*N-1; ++i)
		{
			for (int j = 0; j < N; ++j)	{
				if (mainmap.find(mat[i][j])!=mainmap.end())
				{
					if (mainmap[mat[i][j]]%2 == 1) {
						elems.push_back(mat[i][j]);
						map<int,int>::iterator it = mainmap.find(mat[i][j]);
						mainmap.erase(it);
						if(elems.size() == N)
							break;
					}
				}
			}
			if(elems.size() == N)
				break;
		}
		sort(elems.begin(), elems.end());

		nt++;
		cout << "Case #" << nt << ": ";
		for (int i = 0; i < N; ++i)
		 {
		 	cout << elems[i] << " ";
		 } 
		 cout << endl;
	}
}