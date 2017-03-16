#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, N, s[200], sum, sumzero, numzero, flag;
	long double number;
	cin>>T;
	for (int i = 0; i < T; i++)	{
		cin>>N;
		sum=0;
		number=0;
		sumzero=0;
		numzero=0;
		for (int j = 0; j < N; j++) {
			cin>>s[j];
			sum=sum+s[j];
		}
		number=2*(long double)sum/N;
		do {
			flag=0;
			for (int j = 0; j < N; j++) {
				if (number<=s[j]) {
					sumzero=sumzero+s[j];
					numzero++;
					s[j]=-1;
					flag=1;
				}
			}
			number=(2*(long double)sum - sumzero)/(N-numzero);			
		}while (flag);
		cout<<"Case #"<<i+1<<": ";
		for (int j = 0; j < N; j++) {
			if (s[j]==-1)
			{
				cout<<"0 ";
			}
			else
				cout<<setprecision(10)<<(number-s[j])*100/sum<<" ";
		}
		cout<<"\n";	
	}
	return 0;
}