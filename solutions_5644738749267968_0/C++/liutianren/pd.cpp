#include <iostream>
//#include <iomanip>
using std::cin;
using std::cout;
using std::endl;

/*
struct pair
{
	float weight;
	bool owner;
};

const bool NAOMI = true;
const bool KEN = false;*/

inline void swap(double &a, double &b)
{
	double tmp = a;
	a = b;
	b = tmp;
}

double nlist[1000];
double klist[1000];

int maxGain(double* friends, double* enemy, unsigned int N)
{
	int gain = 0;
	while(N>0)
	{
		double _e = *enemy;
		enemy++;
		double bet = 4;
		int bet_tag = -1;
		double inf = 1;
		int inf_tag = 0;

		for(int i=0; i<N; i++)
		{
			if(friends[i] > _e && friends[i] < bet)
			{
				bet = friends[i];
				bet_tag = i;
			}
			if(friends[i] < inf)
			{
				inf = friends[i];
				inf_tag = i;
			}
		}

		if(bet_tag != -1)
		{
			gain++;
			swap(friends[bet_tag],friends[N-1]);	
		}
		else
		{
			swap(friends[inf_tag],friends[N-1]);
		}

		N--;
	}

	return gain;
}

void game()
{
	unsigned int N;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> nlist[i];
	for(int i=0; i<N; i++)
		cin >> klist[i];

	cout << maxGain(nlist,klist,N) << ' ' << N- maxGain(klist,nlist,N) << endl;
}

int main()
{
	int caseNum;
	cin >> caseNum;
	for(int t=1; t<=caseNum; t++)
	{
		cout<<"Case #"<<t<<": ";
		game();
	}
}