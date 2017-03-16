#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main ()
{
	ofstream cout;
	cout.open("recycled_large.out");
	ifstream cin;
	cin.open("C-small-attempt0.in");

	int T, temp, rem, A, B;

	int **LUT= new int* [2000001];
	for (int i=0; i<2000001; i++)
		LUT[i]=new int [6];

	for (int n=0; n<2000001; n++)
	{
		rem=n;
		int digits=0;
		while (rem>0){
			rem=rem/10;
			digits++;
		}
		rem=n;
		int preffix=n;
		for (int j=1; j<=6;j++)
		{
			rem=rem/10;
			if (rem==0) LUT[n][j-1]=-1;
			else{
				int suffix = n%(int)(pow(10.0,j));
				suffix = suffix*(pow(10.0,(digits-j)));
				preffix = preffix/10;
				temp = suffix+preffix;
				bool found=false;
				for (int i=0; i<6; i++)
					if (LUT[n][i]==temp)
						found=true;
				if (!found)
					LUT[n][j-1]=temp;
				else
					LUT[n][j-1]=-1;
			}
		}
	}

	cout<<"Ready"<<endl;
	cin>>T;

	for (int t=1; t<=T; t++)
	{
		cin>>A>>B;
		int count=0;
		for (int n=A; n<=B; n++)
		{
			for (int i=0; i<6; i++)
				if (LUT[n][i]>=A && LUT[n][i]<=B && n<LUT[n][i])
					count++;
		}

		cout<<"Case #"<<t<<": "<<count<<endl;
	}


	return 0;
}