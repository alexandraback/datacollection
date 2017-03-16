#include<iostream>
#include<fstream>
using namespace std;
struct Data{

	char arr[200];
	bool first;
	bool last;
};

long factorial(int n)
{
	int i;
	long result = 1;

	for (i = 1; i <= n; i++)
		result = result*i;

	return (result);
}

long Npr(int n, int r)
{
	long result;

	result = factorial(n) / factorial(n - r);

	return result;
}



int main(){
	int i, j, k,m,n, test_cases,N,count;
	Data *info;
	ifstream fin("int.in");
	ofstream fout("H2_Output.txt");
	fin >> test_cases;
	for (i = 0; i < test_cases; i++){
		fin >> N;
		info = new Data[N];
		//fin.ignore();
		for (j = 0; j < N; j++){
			fin>>info[j].arr;
			info[j].first = false;
			info[j].last = false;
		}

		for (j = 0; j < N; j++){
			if (info[j].last)
				continue;
			m = strlen(info[j].arr);
			for (k = 0; k < N; k++){
				if (k == j || info[k].last)
					continue;

				if (info[j].arr[m - 1] == info[k].arr[0]){
					info[j].last = true;
					info[k].first = true;
					break;
				}
			}
		}
		count = 0;
		for (j = 0; j < N; j++){
			if (info[j].first)
				count++;
		}
		fout << "Case #" << i + 1 << ": ";
		if (count == 0){
			fout << count << endl;
		}
		else{
			int a = N - count;
			long ans = a*Npr(a, a);
			fout << ans << endl;
		}

	}
	system("pause");
	return 0;
}