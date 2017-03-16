#include<iostream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    int l;
    cin >> l;
    for (int i = 1; i <= l; i++)
    {
		double c,f,x;
		cin >> c >> f >> x;
		double t = 0.0;
		double T = 0.0;
		double r = 2.0;
		double prev_t = 1000000000.0;
		double ans = 0.0;
		while(true)
		{
			t = x/r;
			if (T+t > prev_t) {ans = prev_t; break;}
			prev_t = T+t;
			T += c/r;
			r += f;
		}
		cout.setf(ios::floatfield,ios::fixed);
		cout.precision(7);
		cout << "Case #" << i << ": " << ans << "\n";
	}


    //system("pause");
    return 0;
}
