#include <iostream>
#include <cstdio>

#define unsuz(x) (!(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'))

using namespace std;

int N,M,sayac,res;
string S;

int main()
{
	int i,j,k,t,T;

	cin >> T;
	for(t=1;t<=T;t++)
	{
		res=0;
		cout << "Case #" << t << ": ";
		cin >> S >> M;
		N=S.size();
	
		for(i=0;i<N;i++)
			for(j=i;j<N;j++)
			{
				for(k=i;k<=j;k++)
				{
					sayac=0;
					while(k<=j && unsuz(S[k]))
					{
						sayac++;
						k++;
					}
					if(sayac) k--;
					if(sayac >= M) { res++; break; }
				}
			}
		printf("%d\n",res);
	}


	return 0;
}
