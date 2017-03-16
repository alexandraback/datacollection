#include"iostream"
#include"fstream"
#include "iomanip""
#define cin fin
#define cout fout
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");

int main()
{
	double a[1000], b[1000],temp;
	int num,sum,k,z,flag,sum1,sum2;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> sum;
		if (sum == 1)
		{
			cin >> a[0];
			cin >> b[0];
			if (a[0]>b[0])
				sum1 = sum2 = 1;
			else
				sum1 = sum2 = 0;
			cout << "Case #" << i + 1 << ": ";
			cout << sum1 << " " << sum2 << endl;
			continue;
		}

			for (int j = 0; j<sum; j++)
			{
				cin >> temp;
				for (k = j - 1; k >= 0 && a[k]>temp; k--)
				{
					a[k + 1] = a[k];
	
				}
				a[k + 1] = temp;
			}

			for (int j = 0; j<sum; j++)
			{
				cin >> temp;
				for (k = j - 1; k >= 0 && b[k]>temp; k--)
				{
					b[k + 1] = b[k];

				}
				b[k + 1] = temp;
			}
		
		k = 0; z = 0; sum2 = 0;
		while (k < sum&&z<sum)
		{
			if (b[z]>a[k])
			{
				z++; k++;sum2++;
			}
			else
			{
				z++;
			}
		}
		sum2= sum -sum2;
		k = 0; z = 0; sum1 = 0;
		while (k < sum&&z<sum)
		{
			if (a[k] < b[z])
				k++;
			else
			{
				k++; z++;
				sum1++;
			}
		}

		
		cout << "Case #" << i + 1 << ": ";
		cout << sum1 << " " << sum2<<endl;
	}
	return 0;
}