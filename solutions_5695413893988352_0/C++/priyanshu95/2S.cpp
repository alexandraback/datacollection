#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair

using namespace std;
string C, J;
int arr[2][4];
int ans1 = 999999, ans2 = 999999;
string A1, A2;
int min_abs = 9999999;
string curr_a, curr_b;
void generate(int pos, int val1,int val2)
{
	if(pos == C.size())
	{
		//cout << val1 << '\t' << val2 << endl;
		if(abs(val1-val2) < min_abs)
		{
			min_abs = abs(val1-val2);
			ans1 = val1;	ans2 = val2;
			A1 = curr_a;
			A2 = curr_b;
			return;
		}
		else if(abs(val1-val2) == min_abs)
		{
			if(val1 < ans1)
			{
				ans1 = val1;
				ans2 = val2;
				A1 = curr_a;
				A2 = curr_b;
			}
			else if(val1 == ans1 && val2 < ans2)
			{
				ans2 = val2;
				A1 = curr_a;
				A2 = curr_b;
			}
			return;
		}
		return;
	}
	if(arr[0][pos] == -1)
	{
		for(int i = 0; i < 10; i++)
		{
			int v1 = val1*10 + i;
			if(arr[1][pos] == -1)
			{
				for(int j = 0; j < 10; j++)
				{
					int v2 = val2*10 + j;
					curr_a += ('0'+i);
					curr_b += ('0'+j);
					generate(pos+1, v1, v2);
					curr_a.erase(curr_a.end()-1);
					curr_b.erase(curr_b.end()-1);
				}
			}
			else
			{
				curr_a += ('0'+i);
				curr_b += ('0'+arr[1][pos]);
				generate(pos+1, v1, val2*10 + arr[1][pos]);
				curr_a.erase(curr_a.end()-1);
				curr_b.erase(curr_b.end()-1);
			}
		}
	}
	else
	{
		int v1 = val1*10 + arr[0][pos];
		if(arr[1][pos] == -1)
		{
			for(int j = 0; j < 10; j++)
			{
				int v2 = val2*10 + j;
				curr_a += '0'+arr[0][pos];
				curr_b += ('0'+j);
				generate(pos+1, v1, v2);
				curr_a.erase(curr_a.end()-1);
				curr_b.erase(curr_b.end()-1);
			}
		}
		else
		{
			curr_a += ('0'+arr[0][pos]);
			curr_b += ('0'+arr[1][pos]);
			generate(pos+1, v1, val2*10 + arr[1][pos]);
			curr_a.erase(curr_a.end()-1);
			curr_b.erase(curr_b.end()-1);
		}
	}
}

int main()
{
	int T;	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cin >> C >> J;
		ans1 = 999999; ans2 = 9999999;
		min_abs = 9999999;
		for(int i = 0; i < C.size(); i++)
		{
			if(C[i] == '?')
				arr[0][i] = -1;
			else
				arr[0][i] = C[i] - '0';
			if(J[i] == '?')
				arr[1][i] = -1;
			else
				arr[1][i] = J[i] - '0';
		}
		generate(0, 0, 0);
		cout << "Case #"<<t << ": " << A1 << " " << A2 << endl;
		//cout << "Absoulute diff is : " << min_abs << endl;
	}
	return 0;
}
