#include<iostream>

using namespace std;

char M[4][4] = {{0,1,2,3},
				{1,4,3,6},
				{2,7,4,1},
				{3,2,5,4}};

struct Q
{
	char x;
	Q() {}
	Q(char a) {x = a;}
	
	Q operator* (Q B)
	{
		int s = x>>2;
		s += B.x>>2;
		int c = M[x&3][B.x&3];
		c += s<<2;
		c &= 7;
		return Q(c);
	}
};

char T[10005][10005];

int main()
{
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++)
    {
		cerr << t << "\n";
		int n,k;
		cin >> n >> k;
		string S1;
		cin >> S1;
		for (int i = 0; i < S1.size(); i++)
		{
			if (S1[i] == 'i') S1[i] = 1;
			else if (S1[i] == 'j') S1[i] = 2;
			else if (S1[i] == 'k') S1[i] = 3;
		}
		string S = S1;
		for (int i = 0; i < k-1; i++) S += S1;
		n = S.size();
		for (int i = 0; i < S.size(); i++)
		{
			Q a = Q(S[i]);
			T[i][i] = a.x;
			for (int j = i+1; j < S.size(); j++)
			{
				a = a * Q(S[j]);
				T[i][j] = a.x;
			}
		}
		bool ok = false;
		for (int i = 0; i < S.size() and !ok; i++)
		{
			for (int j = i+1; j < S.size()-1; j++)
			{
				if (T[0][i] == 1 and T[i+1][j] == 2 and T[j+1][n-1] == 3) {ok = true; break;}
			}
		}
		cout << "Case #" << t << ": " << (ok == true ? "YES" : "NO") << "\n";
	}
	

    return 0;
}
