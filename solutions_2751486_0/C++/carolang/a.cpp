#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T, n;
	string s;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>s>>n;
		int contador = 0;
		int consonantes = 0;
		int tam = s.size();
		int actual = 0;
		for(int i=0;i<tam;i++)
		{
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				consonantes = 0;
			}
			else
			{
				consonantes++;
				if(consonantes >= n)
				{
					
					int valorAnterior, valorPosterior;
					valorAnterior = i - n - actual + 2;
					valorPosterior = tam - i;
					//cout<<"c"<<contador<<endl;
					//cout<<valorAnterior<<" "<<valorPosterior<<endl;
					contador += valorAnterior * valorPosterior;
					//cout<<'c'<<contador<<endl;
					actual+= valorAnterior;
					consonantes --;
				}
			}
		}
		cout<<"Case #"<<t+1<<": "<<contador<<endl;
	}
}
