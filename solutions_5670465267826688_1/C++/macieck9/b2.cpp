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
		long long n,k;
		cin >> n >> k;
		string S1;
		cin >> S1;
		for (int i = 0; i < S1.size(); i++)
		{
			if (S1[i] == 'i') S1[i] = 1;
			else if (S1[i] == 'j') S1[i] = 2;
			else if (S1[i] == 'k') S1[i] = 3;
		}
		if (n == 1) {cout << "Case #" << t << ": " << "NO\n"; continue;}
		string S = S1;
		n = S.size();
		S += S[0];
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
		for (int i = 0; i < S.size(); i++)
		{
			for (int j = i+1; j < S.size(); j++)
			{
				T[j][i] = (Q(T[j][n-1])*Q(T[0][i])).x;
			}
		}
		bool ok = false;
		for (int i = 0; i < n and !ok; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Q x = Q(T[0][i]);
				Q y = Q(T[i+1][j]);
				Q z = Q(T[j+1][n-1]);
				int l = j-i;
				if (l <= 0) l += n;
				l += i + n-j;
				if (n-1-j <= 0) l += n;
				l /= n;
				//cout << i << " " << j << " " << l << "\n";
				Q a = Q(T[i+1][i]);
				Q b = Q(T[j+1][j]);
				Q c = Q(T[0][n-1]);
				//cout << (int)x.x << " " << (int)y.x << " " << (int)z.x << "\n";
				//cout << (int)a.x << " " << (int)b.x << " " << (int)c.x << "\n\n";
				if (x.x == 1) l += 0;
				else if ((x*a).x == 1) l++;
				else if ((x*a*a).x == 1) l += 2;
				else if ((x*a*a*a).x == 1) l += 3;
				else continue;
				if (y.x == 2) l += 0;
				else if ((y*b).x == 2) l++;
				else if ((y*b*b).x == 2) l += 2;
				else if ((y*b*b*b).x == 2) l += 3;
				else continue;
				if (z.x == 3) l += 0;
				else if ((z*c).x == 3) l++;
				else if ((z*c*c).x == 3) l += 2;
				else if ((z*c*c*c).x == 3) l += 3;
				else continue;
				int d = 4;
				if (a.x == 0 or b.x == 0 or c.x == 0) d = 1;
				else if (a.x == 4 or b.x == 4 or c.x == 4) d = 2;
				if (l <= k and (k-l)%d == 0) {ok = true; /*cout << i << " " << j << " " << k << " " << l << " " << d << "\n";*/ break;}
			}
		}
		cout << "Case #" << t << ": " << (ok == true ? "YES" : "NO") << "\n";
		memset(T,0,sizeof(T));
	}
	

    return 0;
}
