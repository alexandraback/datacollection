#include <iostream>

using namespace std;

int ativ[20000000];
int gasto[20000000];
int e, r, t;
int resp;
int main()
{
	int n, count = 0;
	cin >> n;
	while(count < n)
	{
		count++;
		cin >> e >> r >> t;
		for(int i = 0; i < t; i++)
			cin >> ativ[i];

		if(r > e)
			r = e;
		resp = 0;
		int numRec = e/r;
		if(e%r != 0)
			numRec++;
		int energia = e;
		for(int i = 0; i < t; i++)
		{
			int max = 0;
			int imax = 0;
			for(int j = 0; i + j < t && j < numRec; j++)
			{
				if(ativ[i+j] > max)
				{
					max = ativ[i+j];
					imax = i+j;
				}
			}
			if(imax == i)
			{
				resp += energia*ativ[i];
				energia = 0;
			}
			if(energia == e)
			{
				resp += ativ[i]*r;
				energia -= r;
			}
			if(energia < e)
			{
				energia += r;
				if(energia > e)
					energia = e;
			}
		}
		cout <<"Case #" << count << ": " << resp << endl;
	}
	return 0;
}
