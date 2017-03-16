#include<iostream>
using namespace std;

int main()
{
	int T, t = 0, n, i;
	int J[200], Js, Js2;
	double res[200];
	int bad;
		
	for(cin >> T; T--;)
	{
		cin >> n;
		
		Js = 0;
		for(i = 0; i < n; i++)
		{
			cin >> J[i];
			Js += J[i];
		}
		
		//Js2 = Js;
		Js2 = 0;
		bad = 0;
		for(i = 0; i < n; i++)
		{
			res[i] = (double)(Js * 2 - n * J[i]) / n / Js * 100.0;
			if(res[i] < 0)
			{
				bad++;
				res[i] = 0;
				Js2 += J[i];
			}
		}

		printf("Case #%d: ", ++t);
		
		if(bad)
		{
			//cout << "! ";
			for(i = 0; i < n; i++)
			{
				if(res[i] == 0) continue;
				
				res[i] = (double)(Js * 2 - (n - bad) * J[i] - Js2) / (n - bad) / Js * 100.0;
			}
		}
		
		for(i = 0; i < n ; i++)
		{
			printf("%.6f", res[i]);
			if(i != n - 1) cout << " ";
		}
		cout << endl;
	}
}