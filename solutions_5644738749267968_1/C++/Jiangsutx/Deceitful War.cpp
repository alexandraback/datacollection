#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ofstream ofile;
	ifstream ifile;

	ofile.open("D-large-out.txt");		
	//ifile.open("D-small-attempt0.in");			
	ifile.open("D-large.in");	

	long T;
	int N;
	
	ifile>>T;
	double a[1001], b[1001];
	for (int iT=1; iT<=T;iT++)
	{
		ifile>>N;
		for (int i=1; i<=N; i++)
			ifile>>a[i];
		for (int i=1; i<=N; i++)
			ifile>>b[i];
		for (int i=1; i<=N-1; i++)
			for (int j=i+1; j<=N; j++)
			{
				if (a[i]>a[j])
				{
					double tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
				if (b[i]>b[j])
				{
					double tmp = b[i];
					b[i] = b[j];
					b[j] = tmp;
				}
			}
		int ha1 = 1, hb1 = 1, ha2 = 1, hb2 = 1;
		int ta1 = N, tb1 = N, ta2 = N, tb2 = N;
		int y = 0, z = 0;
		// for y
		int left = N;
		while (left>0)
		{
			int ptr_ha = ha1;
			while (a[ptr_ha]<b[hb1]) ptr_ha++;
			if (ptr_ha == ha1){ y++; ha1++; hb1++; left--;}
			else
			{
				left -= ptr_ha - ha1;
				ha1 = ptr_ha;
				tb1 -= ptr_ha - ha1;
			}
		}
					

		// for z
		for (int i=1; i<=N; i++)
		{
			int ptr_b = tb2;
			while (b[ptr_b]>a[ta2]) ptr_b--;
			if (ptr_b == tb2) { hb2++; z++;}
			else
			{
				tb2--;
			}
			ta2--;

		}
		ofile<<"Case #"<<iT<<": "<<y<<" "<<z<<endl;

	}
	ifile.close();
	ofile.close();
	system("pause");
}