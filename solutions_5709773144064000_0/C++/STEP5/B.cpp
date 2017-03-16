#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
	{
		double C, F, X;
		cin>>C>>F>>X;

		int K = X / C - 2 / F;
		if(K < 0)
			K = 0;

		double time = 0.0;
		for(int i=0; i<K; i++)
		{
			time += C / (2 + i * F);
		}
		time += X / (2 + K * F);

		fixed(cout);
		cout<<setprecision(7);
		cout<<"Case #"<<t<<": "<<time<<endl;
	}

    return 0;
}
