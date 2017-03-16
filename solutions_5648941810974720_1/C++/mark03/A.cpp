#include<bits/stdc++.h>
using namespace std;

string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int ord[] = {0,2,6,8,7,4,1,9,3,5};
char l[] = {'Z','W','X','G','S','U','O','N','T','F'};

void foo()
{
	string S;
	cin >> S;
	vector<int> lett(300), ris(100);

	for(int i=0;i<S.size();++i) lett[S[i]]++;
	
	for(int i=0; i<10;++i)
	{
		int conta = 0;
		int numero = ord[i];
		char disc = l[i];
		string ing = num[numero];

		conta = lett[disc];
		if(numero == 9) conta/=2;
		ris[numero] = conta;

		for(int j=0; j<ing.size();++j)
			lett[ing[j]] -= conta;
	}

	for(int i=0;i<300;++i)
		assert(lett[i] == 0);

	for(int i=0;i<10;++i)
		for(int j=0;j<ris[i];++j)
			cout<<i;
}

int main()
{
	int T;
	cin>>T;
	
	for(int i=0; i<T; ++i)
	{
		cout << "Case #" << i+1 << ": ";
		foo();
		cout << "\n";
	}

	return 0;
}
