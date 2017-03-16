#include"iostream"
#include"fstream"
#include "iomanip""
#define cin fin
#define cout fout
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");

double Get(double c, double f, double x)
{
	double time=0,v=2.0,temp1,temp2,temp3;
	
	while (1)
	{
		temp1 = c / v;
		temp2 = x / v;
		temp3 = x / (v + f);
		if (temp2 <= temp3 + temp1)
		{
			time += temp2;
			break;
		}
		else
		{
			time += temp1;
			v += f;
		}
	}
	return time;
}

int main()
{
	int num;
	double c, f, x,time,v;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		v = 2.0;
		cin >> c >> f >> x;
		cout << "Case #" << i + 1 << ": ";
		time = Get(c, f, x);
		cout << setiosflags(ios::fixed);
		cout << setprecision(7) << time<< endl;
	}
	return 0;
}