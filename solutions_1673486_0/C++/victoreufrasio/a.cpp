#include<iostream>
#include<stdio.h>

using namespace std;


int main()
{
	int T;
	int N;
	float p[100000];
	float p_acumulado[100000];
	int A, B;
	cin >> T;
	int teste = 1;
	float probabilidade_de_acertar;
	float expected;
	float new_expected;
	
	while(teste <= T)
	{
		probabilidade_de_acertar = 1;
		expected = 0;
		cin >> A;
		cin >> B;
		
		for(int i=0; i<A; i++)
		{
			cin >> p[i];
			probabilidade_de_acertar *= p[i];
			p_acumulado[i] = probabilidade_de_acertar;
		}
		
		//case 1 = keep typing
		expected = (float)probabilidade_de_acertar*(B-A+1) + (float)(1-probabilidade_de_acertar)*(A+2*(B-A)+2);
		
		//case 3 = press enter
		if(2+A+(B-A) < expected)
		{
			expected = (float)2+A+(B-A);
		}

		new_expected = 1;
		//case 2 = press backspace k times
		for(int k=1; k<=A; k++)
		{
			new_expected = (float)(p_acumulado[A-1-k]*(2*k+(B-A)+1)) + (float)((1-p_acumulado[A-1-k])*(2*k+B-A+1+B+1));
			if(new_expected < expected)
			{
				expected = new_expected;
			}
		}
		
		cout << "Case #" << teste++ << ": ";
		printf("%f\n", expected);
		
	}
	
	return 0;
}