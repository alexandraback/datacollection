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


//void compare_sample()
//{
//	int myints[] = {32,71,12,45,26,80,53,33};
//	vector<int> myvector (myints, myints+8);        
//	vector<int>::iterator it;
//	sort (myvector.begin()+4, myvector.end(), compare);
//}
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
class ccc
{
	public:
		int index;
		int aneed;
		int bneed;
};
bool compare(ccc a, ccc b)
{
	return(a.bneed < b.bneed);
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
		int total = 0;
		int stars = 0;
		int get = 0;
		int tryy = 0;
		vector<bool> finish1(N, false), finish2(N, false);

	//	cout << N << endl;
		vector<ccc>  b(N);

		for(int i = 0; i < N; i++)
		{
			cin >> b[i].aneed >> b[i].bneed;
			b[i].index = i;
	//		cout << a[i].need << " " << b[i].need << endl;
		}

		sort(b.begin(), b.end(), compare);

		bool GG = false;
		while(get != N)
		{
			if(stars >= b[tryy].bneed)
			{
				//cout << stars << b[0].index << "b" << endl;
				if(finish1[b[tryy].index])
				{
					stars += 1;
				}
				else
					stars += 2;
				finish2[b[tryy].index] = true;
				get++;
				tryy++;
				total++;
				continue;
			}
			bool yoyoyo = false;
			for(int i = b.size() - 1; i >= 0; i--)
			{
				if(stars >= b[i].aneed & !finish1[b[i].index])
				{
					if(finish2[b[i].index])
					{
					}
					else
					{
						stars += 1;
						total++;
					}
					finish1[b[i].index] = true;
					yoyoyo = true;
					break;
				}
			}
			if(yoyoyo)
				continue;
			else
				break;
		}

		if(get != N)
			cout << "Too Bad";
		else
			cout << total;

		cout << endl;
		data_num--;
		case_count++;
	}
	return 0;

}
