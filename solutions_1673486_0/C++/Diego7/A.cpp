#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main(int argc, const char *argv[])
{
	int T;
	cin >> T;
	cout.precision(6);
	cout.setf(ios::fixed,ios::floatfield);
	for (int t = 0; t < T; t ++)
	{
		int A, B;
		cin >> A >> B;

		vector<double> p(A);
		for (int i = 0; i < A; i ++)
			cin >> p[i];

		vector<double> newp(A+1);
		vector<double> truth(A+1);

		newp[0] = p[0];
		truth[0] = p[0];
		for (int i = 1; i < A; i ++)
		{
			truth[i] = truth[i-1]*p[i];
			newp[0] *= p[i];
		}

		double enter, type;
		enter = (B+2) * newp[0];
		type = (B-A+1)*newp[0];
		vector<double> back(A+1, 0.);
		//back[0] = (1+1+B-A+1)*newp[0];

		for (int j = 1; j <= A; j ++)
		{
			//cout << (j+j+B-A+1) << ", ";
			back[j] += (j+j+B-A+1)*newp[0];
		}
		//cout << endl;

		for (int i = 1; i < newp.size(); i ++)
		{
			if (i != newp.size()-1)
				//newp[i] = (newp[i-1]/p[A-i])*(1-p[A-i]);
				newp[i] = truth[A-i-1]*(1-p[A-i]);
			else
				newp[i] = 1-p[A-i];
			//	newp[i] = ((newp[i-1]/(1-p[A-i+1]))/p[A-i])*(1-p[A-i]);

			enter += (B+2)*newp[i];
			type += (B-A+2+B)*newp[i];

			for (int j = 1; j < i; j ++)
			{
				//cout << (j+j+B-A+1+B+1) << ", ";
				back[j] += (j+j+B-A+1+B+1)*newp[i];
			}
			for (int j = i; j <= A; j ++)
			{
				//cout << (j+j+B-A+1) << ", ";
				back[j] += (j+j+B-A+1)*newp[i];
			}
			//cout << endl;
		}

		//for (int j = 1; j < A+1; j ++)
		//{
		//	cout << (j+j+B-A+1+B+1) << ", ";
		//	back[j] += (j+j+B-A+1+B+1)*newp.back();
		//}
		//cout << endl;

		//for (int i = 0; i < newp.size(); i ++)
		//{
		//	cout << i << ": " << newp[i] << endl;
		//}
		double m = min(*min_element(back.begin()+1, back.end()), enter);
		m = min(m, type);
		//double m = min(enter, type);
		//for (int j = 1; j < back.size(); j ++)
		//{
		//	cout << "j: " << back[j] << endl;
		//}
		cout << "Case #" << t+1 << ": " << m << endl;
	}

	return 0;
}
