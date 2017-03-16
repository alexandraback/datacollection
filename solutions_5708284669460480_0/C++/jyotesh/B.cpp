#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int counts[26];
string keys, required;
vector<string> possible_words;

void generate_all(int, int, int, string);
int count_occurrences(int, int, int);

int main()
{
	int count, i, K, L, length, maxcount, S, t, totalcount, T;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B.out", "w", stdout);
	cin >> T;
	for (t = 1; t <= T; t++)
	{
		cin >> K >> L >> S;
		cin >> keys;
		cin >> required;
		for (i = 0; i < 26; i++)
			counts[i] = 0;
		for (i = 0; i < K; i++)
			counts[keys[i] - 'A']++;
		for (i = 0; i < L; i++)
			if (counts[required[i] - 'A'] == 0)
				break;
		if (i < L)
		{
			printf("Case #%d: %.6lf\n", t, 0);
			continue;
		}
		possible_words.clear();
		generate_all(0, K, S, "");
		length = possible_words.size();
		maxcount = totalcount = 0;
		for (i = 0; i < length; i++)
		{
			count = count_occurrences(i, S, L);
			totalcount += count;
			if (maxcount < count)
				maxcount = count;
		}
		printf("Case #%d: %.6lf\n", t, (double)maxcount - ((double)totalcount) / length);
		fprintf(stderr, "Case #%d\n", t);
	}
	return 0;
}

void generate_all(int pos, int K, int S, string current)
{
	int i;
	if (pos == S)
	{
		possible_words.push_back(current);
		return;
	}
	for (i = 0; i < K; i++)
		generate_all(pos + 1, K, S, current + keys[i]);
}

int count_occurrences(int index, int S, int L)
{
	int count, i, j;
	count = 0;
	for (i = 0; i < S - L + 1; i++)
	{
		for (j = 0; j < L; j++)
			if (possible_words[index][i + j] != required[j])
				break;
		if (j == L)
			count++;
	}
	return count;
}