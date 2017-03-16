#include<iostream>
#include<algorithm>
using namespace std;

typedef struct a {
	int* vals;
};

int main() {
	int cnt;
	cin >> cnt;
	for (int itr = 0; itr < cnt; itr++)
	{
		cout << "Case #" << itr + 1 << ": ";
		int num;
		cin >> num;
		a* input = new a[num * 2 - 1];
		int max = 0;
		for (int i = 0; i < num*2-1; i++)
		{
			input[i].vals = new int[num];
			for (int j = 0; j < num; j++)
			{
				cin >> input[i].vals[j];
				if (input[i].vals[j]>max) {
					max = input[i].vals[j];
				}
			}
		}
		int* result = new int[max + 1];
		for (int i = 0; i < max+1; i++)
		{
			result[i] = 0;;
		}
		for (int i = 0; i < num * 2 - 1; i++)
		{
			for (int j = 0; j < num; j++)
			{
				result[input[i].vals[j]]++;
			}
		}
		int* emptynum = new int[num];
		int idx = 0;
		for (int i = 0; i < max+1; i++)
		{
			if (result[i] % 2 == 1) {
				emptynum[idx] = i;
				idx++;
			}
		}
		for (int i = 0; i < idx; i++)
		{
			cout << emptynum[i] << " ";
		}
		cout << endl;
	}
	return 0;
}