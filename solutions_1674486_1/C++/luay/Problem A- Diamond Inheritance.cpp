#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
using namespace std;

bool isDiamond;

int mat[1001][1001];
 map < pair <int,int>,int > visited;
void calc(int start,int current,int numberOfClasses);
int main()
{
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int numberOfClasses;
		cin >> numberOfClasses;
		isDiamond = false;
		
		for (int j = 0; j < numberOfClasses; j++)
		{
			int N;
			cin >> N;
			for (int x = 0; x < numberOfClasses; x++)
				mat[j][x] = 0;

			for (int y = 0; y < N; y++)
			{
				int temp;
				cin >> temp;
				mat[j][temp-1] = 1;
			}
		}
		for (int j = 0;j < numberOfClasses; j++)
		{
			visited.clear();
			calc(j,j,numberOfClasses);
			if (isDiamond)
			{
				cout << "Case #" << i + 1 << ": Yes" << endl;
				break;
			}
		}
		if (!isDiamond)
			{
				cout << "Case #" << i + 1 << ": No" << endl;
			}
		/*for (int j = 0; j < numberOfClasses; j++)
		{
			for (int x = 0; x < numberOfClasses; x++)
				cout << mat[j][x] << " ";
			cout << endl;
		}*/
	
	}
}

void calc(int start,int current,int numberOfClasses)
{
	visited[make_pair(start,current)]++;
	if (visited[make_pair(start,current)] > 1 || isDiamond)
	{
		isDiamond = true;
		return;
	}
	else
	{
		for (int i = 0; i < numberOfClasses; i++)
		{
			if (mat[current][i] == 1 && start!= i && i != current)
			{
				calc(start,i,numberOfClasses);
			}
		}
	}
}