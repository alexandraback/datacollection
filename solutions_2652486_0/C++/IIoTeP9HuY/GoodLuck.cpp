#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <cassert>
#include <algorithm>
#include <memory.h>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "C-small-1-attempt1.bin";
const char* outputFile = "C-small-1-attempt1.out";
//const char* inputFile = "bin";
//const char* outputFile = "out";

int append(int x, int y)
{
	return x * 10 + y;
}

vector<int> split(int x)
{
	vector<int> ans;
	while (x)
	{
		ans.push_back(x % 10);
		x /= 10;
	}
	return ans;
}

class Solver
{
public:
	std::vector<int> solveTest()
	{
		std::vector<int> answer;
		cin >> R >> N >> M >> K;
		products.resize(K);
		possibleNumbers.clear();
		gen(N, 2, 0);
		for (int i = 0; i < R; ++i)
		{
			countsOrig.clear();
			for (int j = 0; j < K; ++j)
			{
				cin >> products[j];
				++countsOrig[products[j]];
			}
			sort(products.begin(), products.end(), greater<int>());
			double maxLikelihood = 0;
			int bestNumber = 222;

			for (int j = 0; j < possibleNumbers.size(); ++j)
			{
				int number = possibleNumbers[j];
				//DB(number);
				test(number, maxLikelihood, bestNumber);
			}
			answer.push_back(bestNumber);
		}
		return answer;
	}

	bool test(int number, double& maxLikelihood, int& bestNumber)
	{
		//DB(number);
		vector<int> numbers = split(number);
		unordered_map<int, int> numberProducts;
		for (int mask = 0; mask < (1 << N); ++mask)
		{
			int product = 1;
			for (int k = 0; k < N; ++k)
			{
				if (mask & (1 << k))
				{
					product *= numbers[k];
				}
			}
			++numberProducts[product];
		}
		double likelihood = 1;
		unordered_map<int, int> counts = countsOrig;
		for (auto productIterator : countsOrig)
		{
			int product = productIterator.first;
			//DB(productIterator.first);
			//DB(productIterator.second);
			if (numberProducts.find(product) == numberProducts.end())
			{
				//DB("here");
				//DB(product);
				//DB(countsOrig.size());
				return false;
			}
			else
			{
				for (int t = 0; t < counts[product]; ++t)
				{
					likelihood *= (double(numberProducts[product]) / (1 << N));
				}
				counts.erase(product);
			}
		}
		if (!counts.empty())
			return false;

		DB(number);
		DB(likelihood);
		if (likelihood >= maxLikelihood)
		{
			maxLikelihood = likelihood;
			bestNumber = number;
		}
	}

	void gen(int leftSteps, int lastMax, int currentNumber) 
	{
		if (leftSteps == 0)
		{
			possibleNumbers.push_back(currentNumber);
			return;
		}
		for (int i = lastMax; i <= M; ++i)
		{
			int nextNumber = append(currentNumber, i);
			gen(leftSteps - 1, i, nextNumber);
		}
	}

	int R, N, M, K;
	vector<int> products;
	unordered_map<int, int> countsOrig;
	vector<int> possibleNumbers;
};

int main()
{
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	Solver solver;
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		vector<int> answer = solver.solveTest();
		printf("Case #%d:\n", testNumber);
		for (int i = 0; i < answer.size(); ++i)
		{
			cout << answer[i] << endl;
		}
	}
	return 0;
}
