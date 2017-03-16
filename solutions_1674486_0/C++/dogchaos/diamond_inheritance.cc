#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime[1000000];
vector<long long> prime;
void getPrime()
{
	for(long long i = 0; i < 1000000; i++)
	{
		isPrime[i] = true;
	}

	isPrime[0] = false;
	isPrime[1] = false;

	for(long long i = 2; i < 1000000; i++)
	{
		if(isPrime[i] == true)
		{
			prime.push_back(i);
			long long test = i * 2;
			while(test < 1000000)
			{
				isPrime[test] = false;
				test += i;
			}
		}
	}

}

bool compare(int a, int b)
{
	return(a < b);
}

void compare_sample()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvector (myints, myints+8);        
	vector<int>::iterator it;
	sort (myvector.begin()+4, myvector.end(), compare);
}
vector<vector<long long> > PT(502, vector<long long> (502, 1));

void create_pt()
{
	for(int i = 2; i <= 500; i++)
	{
		for(int j = 1; j < i; j++)
		{
			PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % 100003;
		}
	}
}

long long c_x_get_y(long long x, long long y)
{
	if(y == 0)
		return 1;
	long long ans = 1;
	for(int i = 0; i < y; i++)
	{
		ans *= (x - i);
		ans /= (i + 1);
	}
	return ans;
}

bool dfs(vector<vector<bool> > M, int start, vector<bool> &visited)
{
	for(int j = 1; j < M.size(); j++)
	{
		if(M[start][j])
		{
//			cout << "try" << start << ", " << j << endl;
			if(visited[j])
				return true;
			else
			{
				visited[j] = true;
				if(dfs(M, j, visited))
					return true;
			}
		}
	}
	return false;
}

int main()
{
	char c;
	int data_num, case_count = 1;
	cin >> data_num;
	while(data_num != 0)
	{
		cout << "Case #" << case_count << ": ";

		int N;
		cin >> N;
		vector<vector<bool> > M(N + 1, vector<bool>(N + 1, false));
		for(int i = 1; i < N + 1; i++)
		{
			int tmp;
			cin >> tmp;
			for(int j = 0; j < tmp; j++)
			{
				int tmptmp;
				cin >> tmptmp;
				M[i][tmptmp] = true;
				//cout << i << ", " << tmptmp << endl;
			}
		}

		bool find = false;
		for(int i = 1; i < N+1; i++)
		{
			vector<bool> visited(N+1, false);
			if(dfs(M, i, visited))
			{
				cout << "Yes";
				find = true;
				break;
			}
		}
		if(!find)
			cout << "No";

		cout << endl;
		data_num--;
		case_count++;
	}
	return 0;

}
