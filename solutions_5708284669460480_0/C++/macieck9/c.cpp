#include<iostream>
#include<vector>

using namespace std;

int pow(int a, int b)
{
	int x = 1;
	for (int i = 0; i < b; i++) x *= a;
	return x;
}
vector<string> V;
int P[1000];

int main()
{
    ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
    for (int t = 1; t <= tt; t++)	    
	{
		cerr << t << "\n";
		V.clear();
		int k,l,s;
		cin >> k >> l >> s;
		string A;
		cin >> A;
		string S;
		cin >> S;
		for (int i = 0; i < pow(k,s); i++)
		{
			string X = "";
			int z = i;
			for (int j = 0; j < s; j++)
			{
				X += A[z%k];
				z /= k;
			}	
			V.push_back(X);
		}
		int mx = 0;
		double ans = 0;
		for (int i = 0; i < V.size(); i++)
		{
			//cout << V[i] << "\n";
			int cnt = 0;
			int j = 0;
			string S1 = "#"+S+"#"+V[i];
			for (int i = 2; i < S1.size(); i++)
			{
				while(j and S1[i] != S1[j+1]) j = P[j];
				if (S1[i] == S1[j+1]) j++;
				P[i] = j;
				if (P[i] == S.size()) cnt++;
			}
			mx = max(mx,cnt);
			ans += 1.0*cnt/V.size();
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(7);
		cout << "Case #" << t << ": " << mx-ans << "\n";
	}

    return 0;
}
