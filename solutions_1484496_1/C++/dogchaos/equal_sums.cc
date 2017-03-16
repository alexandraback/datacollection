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
int main()
{
	char c;
	int data_num, case_count = 1;
	cin >> data_num;
	long long trytime = 1;
	for(int i = 0 ; i < 500; i++)
	{
		trytime *= 2;
	}
	while(data_num != 0)
	{
		cout << "Case #" << case_count << ": "<<endl;

		int N;
		cin >> N;
		vector<int> S(N), tmpS(trytime);

		for(int i = 0; i < N; i++)
		{
			cin >> S[i];
		}

		for(long long i = 0; i < trytime; i++)
		{
			int tmp = 0, tmp2 = i;
			for(int j = 0; j < 500; j++)
			{
				if(tmp2 % 2 == 1)
					tmp += S[499-j];
				tmp2 = tmp2 / 2;
			}
			tmpS[i] = tmp;
		}
		bool bye= false;
		for(long long i = 0; i < trytime ; i++)
		{
			for(long long j = i+1; j < trytime ; j++)
			{
				if(tmpS[i] == tmpS[j])
				{
					for(int k = 0; k <500; k++)
					{
						if(i % 2 == 1)
							cout << S[499 - k] << " ";
						i = i / 2;
					}
					cout << endl;
					for(int k = 0; k < 500; k++)
					{
						if(j % 2 == 1)
							cout << S[499 - k] << " ";
						j = j / 2;
					}
					bye = true;
					break;
				}
			}
			if(bye)
				break;
		}

		if(!bye)
			cout <<"Impossible";

		cout << endl;
		data_num--;
		case_count++;
	}
	return 0;

}
