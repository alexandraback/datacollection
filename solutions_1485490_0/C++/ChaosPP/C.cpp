#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

vector< pair< long long, int > > A;
vector< pair< long long, int > > B;
map<string, long long> MAP;

long long Matching(long long Ain, int Aout, long long Bin, int Bout, long long cost)
{
	char temp[200];
	sprintf(temp, "%lld%d%lld%d", Ain, Aout, Bin, Bout);

	if (MAP.find(temp) != MAP.end())
		return MAP[temp];

	if (Aout == A.size() || Bout == B.size())
		return cost;

	long long result[5];
	for (int i=0; i<5; i++)
		result[i] = 0;

	if (A[Aout].second == B[Bout].second) {
		if (A[Aout].first - Ain == B[Bout].first - Bin) {
			result[0] = Matching(0, Aout+1, 0, Bout+1, cost + A[Aout].first - Ain);
		}

		else {
			if (A[Aout].first - Ain < B[Bout].first - Bin)
				result[1] = Matching(0, Aout+1, Bin + (A[Aout].first - Ain), Bout, cost + A[Aout].first - Ain);
			else
				result[2] = Matching(Ain + (B[Bout].first - Bin), Aout, 0, Bout+1, cost + B[Bout].first - Bin);
		}
	}
	else {
		result[3] = Matching(0, Aout+1, Bin, Bout, cost);
		result[4] = Matching(Ain, Aout, 0, Bout+1, cost);
	}

	long long max_result = 0;
	for (int i=0; i<5; i++) {
		if (result[i] > max_result)
			max_result = result[i];
	}

	MAP[temp] = cost;
	return max_result;
}

int main()
{
	FILE *fp = fopen("C-small-attempt2.in", "r");
	FILE *fout = fopen("output.txt", "w");
	int T;

	fscanf(fp, "%d", &T);
	for (int w=0; w<T; w++) {
		A.clear();
		B.clear();
		MAP.clear();

		int a, b;
		fscanf(fp, "%d %d", &a, &b);
		pair<long long, int> temp;
		for (int i=0; i<a; i++) {
			fscanf(fp, "%lld %d", &(temp.first), &(temp.second));
			A.push_back(temp);
		}

		for (int i=0; i<b; i++) {
			fscanf(fp, "%lld %d", &(temp.first), &(temp.second));
			B.push_back(temp);
		}

		long long result = 0;

		result = Matching(0, 0, 0, 0, 0);

		fprintf(fout, "Case #%d: %lld\n", w+1, result);
		printf("Case #%d: %lld\n", w+1, result);
	}

	return 0;
}