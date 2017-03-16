#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 0;
	while(count < n)
	{
		count++;
		long long int r, t;
		cin >> r >> t;
		long long int i = 0;
		long long int iProx = 2;
		long long int resp = (2*r + 2 - 1);
		bool maior = 0;
		/*for(i = 1; resp < t; i++)
		{
			resp = 	i*(2*r+2*i-1);
		}*/
		if(resp > t)
			i = 0;
		else
		{
			long long int direita;
			if(t/r < 1000000000)
				direita = (t/r) + 1;
			else
				direita = 1000000000;
			long long int esquerda = 0;
			i = direita/2;
			resp = 	i*(2*r+2*i-1);
			while(direita - esquerda != 1 && resp != t)
			{
				if(resp < t)
					esquerda = i;
				else
					direita = i;
				i = (direita+esquerda)/2;
				resp = 	i*(2*r+2*i-1);
			}
			if(resp > t)
				i--;
		}
		/*if(resp != t)
			i -= 2;
		else
			i -= 1;*/
		cout << "Case #" << count << ": "<<i<< endl;
	}
	return 0;
}
