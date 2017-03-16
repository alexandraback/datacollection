#include <iostream>
using namespace std;

int main()
{
	int T;
	long A,B;
	char q;
	
	cin >> T;
	for(int t=1;t<=T;t++)
	{
		cin >> A >> q >> B;
		for(int i=2;i*i<=max(A,B);i++)
		{
			while(A%i == B%i && A%i==0)
				A/=i, B/=i;
		}
		
		while(A>=2 && B%2==0)
			A/=2, B/=2;
		int res=0;
		while(B%2==0)
			B/=2, res++;
		
		cout << "Case #" << t << ": ";
		if(B==1)
			cout << res << endl;
		else
			cout << "impossible" << endl;
	}
	
	return 0;
}

