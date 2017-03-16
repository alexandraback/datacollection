#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull reverse(ull x)
{
	ull r = 0;
	while (x % 10 == 0)
		x /= 10;
	while (x)
	{
		r *= 10;
		r += x % 10;
		x /= 10;
	}
	return r;
}

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	//	FILE * input;
	//	input = fopen("input.txt","r");

	int T;

	//	fread(&n, sizeof(int), 1, input);cout<<n<<endl; char cc=getchar();

	input >> T;// cout<<n<<endl;
	//cin >> T;

	ull N=1000001;
	int* a = new int[N];
	//int* a = (int*)malloc(sizeof(int)*N);
	

	//cout << N;
	
	a[0] = 0;
	

	for (ull i = 1; i < N; ++i)
	{
		if ((reverse(i) < i) && (i%10))
			a[i] = 1 + min(a[i - 1], a[reverse(i)]);
		else
			a[i] = 1 + a[i - 1];
	}
	//system("pause");

	int x;
	for (int t = 0; t < T; ++t)
	{
		input >> x;
		//cin >> x;

		output << "Case #" << t + 1 << ": " << a[x] << endl;
		//cout  << "Case #" << t + 1 << ": " << a[x] << endl;

		
	}
	//system("pause");
	//	fclose(input);
	input.close();
	output.close();
	//	system("pause");
	return 0;
}
