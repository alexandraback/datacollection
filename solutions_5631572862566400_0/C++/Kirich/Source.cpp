#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int conn[1006];
bool is_part[1006];
int N;

void clear()
{
	for (int i = 1; i <= N; i++)
		conn[1006] = 0;
}

void clear_part()
{
	for (int i = 1; i <= N; i++)
		is_part[i] = false;
}

int max_size = 0;

void seek(int person, int size)
{
	if (max_size < size)
		max_size = size;

	for (int i = 1; i <= N; i++)
	{
		if (conn[i] == person && !is_part[i])
		{
			is_part[i] = true;
			seek(i, size + 1);
			is_part[i] = false;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		clear();
		for (int j = 1; j <= N; j++)
		{
			int fr;
			cin >> fr;
			conn[j] = fr;
		}

		int max_count = 1;

		for (int j = 1; j <= N; j++)
		{
			int count = 1;
			clear_part();
			int next = conn[j];
			is_part[j] = true;
			max_size = 0;
			while (!is_part[next])
			{
				is_part[next] = true;
				next = conn[next];
				count++;
			}

			if (next == j)
			{
				if (max_count < count && next != conn[conn[next]])
					max_count = count;
			}
			else
			{
				if (next == conn[conn[next]])
				{
					seek(conn[next], 0);
					max_count = count + max_size > max_count ? count + max_size : max_count;
				}
			}
		}

		printf("Case #%d: %d\n", i + 1, max_count);
	}
	return 0;
}