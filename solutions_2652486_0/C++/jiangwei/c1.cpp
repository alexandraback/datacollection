#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector< int > numbers;
vector< vector<int> > products;

void add_number(int number, vector<int> &a, int N)
{
	numbers.push_back(number);
	vector<int> prods(1 << N);
	for (int mask = 0; mask < (1 << N); mask++)
	{
		int prod = 1;
		for (int i = 0; i < a.size(); i++)
		{
			if ( ((1 << i) & mask) == 0 ) continue;
			prod *= a[i];
		}
		prods[mask] = prod;
	}
	products.push_back(prods);
}

void init(int N, int M)
{
	if (N == 3)
	{
		numbers.clear();
		products.clear();

		for (int a1 = 2; a1 <= M; a1++)
			for (int a2 = a1; a2 <= M; a2++)
				for (int a3 = a2; a3 <= M; a3++)
				{
					vector<int> num(3);
					num[0] = a1; num[1] = a2; num[2] = a3;
					add_number(a1 * 100 + a2 * 10 + a3, num, N);
				}
	}
	else
	{
		// don't know	
	}
}

double calc_prob(vector<int> &obs, int index)
{
	double prob = 1;

	vector<int> &prod = products[index];

	for (int i = 0; i < obs.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < prod.size(); j++)
			if (prod[j] == obs[i])
				++count;
		prob *= (count * 1.0) / prod.size();
	}

	return prob;
}

int main()
{

	int T;
	cin >> T;
	cout << "Case #" << T << ": " << endl;
	int R, N, M, K;
	cin >> R >> N >> M >> K;
	init(N, M);

	while (--R >= 0)
	{
		vector<int> obs(K);
		for (int i = 0; i < K; i++)
		{
			cin >> obs[i];
		}
		int result = 0;
		double best_prob = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			double prob = calc_prob(obs, i);
			if (prob > best_prob)
			{
				best_prob = prob;
				result = i;
			}
		}
		cout << numbers[result] << endl;
	}

	return 0;
}
