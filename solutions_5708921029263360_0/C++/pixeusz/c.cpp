#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <list>

using namespace std;
using ll = long long;

#define LIM 1001
bool used[LIM];
int J, P, S, K;
int JPSK;

#define sLIM 11
int JP[sLIM][sLIM];
int JS[sLIM][sLIM];
int PS[sLIM][sLIM];

struct Trio
{
	int j, p, s;
	
	int ToNr() const
	{
		return j*100 + p*10 + s;
	}
	
	void Print() const
	{
		printf("%d %d %d\n", j+1, p+1, s+1);
	}
};

void SolveCase(int caseId);

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

bool IsTabu(const Trio &t)
{
	return JP[t.j][t.p] >= K
		|| JS[t.j][t.s] >= K
		|| PS[t.p][t.s] >= K;
}

bool NextTrio(Trio &t)
{
	auto nextTrio = [&t]()
	{
		if(++t.j >= J)
		{
			t.j = 0;
			if(++t.p >= P)
			{
				t.p = 0;
				if(++t.s >= S)
					t.s = 0;
			}
		}
	};
	for(int tryI = 1; tryI <= JPSK; ++tryI)
	{
		nextTrio();
		if(!used[t.ToNr()] && !IsTabu(t))
			return true;
	}
	return false;
}

void SolveCase(int caseId)
{
	printf("Case #%d: ", caseId);
	scanf("%d%d%d%d", &J, &P, &S, &K);
	JPSK = J * P * S * K;
	for(int i = 0; i < LIM; ++i)
		used[i] = false;
	for(int i = 0; i < sLIM; ++i)
	for(int j = 0; j < sLIM; ++j)
		JP[i][j] = JS[i][j] = PS[i][j] = 0;
		
	vector<Trio> result;
	
	Trio t{0, 0, 0};
	do
	{
		int tNr = t.ToNr();
		used[tNr] = true;
		result.push_back(t);
		++JP[t.j][t.p];	
		++JS[t.j][t.s];
		++PS[t.p][t.s];
		
	} while(NextTrio(t));
	
	printf("%d\n", (int)result.size());
	for(const auto& t : result)
		t.Print();
}
