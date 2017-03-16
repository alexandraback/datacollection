#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1000ll*1000ll*1000ll*1000ll*1000ll*1000ll + 1000ll;
char A[20];
char B[20];

ll dn(int n)
{
	ll res = 1;
	for(int i = 0; i < n; ++i)
		res *= 10;
	return res;
}
ll Mins(const char* X)
{
	ll res = 0;
	for(int i = 0; X[i] > 0; ++i)
	{
		res *= 10;
		if(X[i] != '?')
			res += X[i] - '0';
	}
	return res;
}
ll Maxs(const char* X)
{
	ll res = 0;
	for(int i = 0; X[i] > 0; ++i)
	{
		res *= 10;
		if(X[i] != '?')
			res += X[i] - '0';
		else
			res += 9;
	}
	return res;
}
string Maxuj(const char* X)
{
	string t(X);
	for(int i = 0; i < t.size(); ++i)
		if(t[i] == '?')
			t[i] = '9';
	return t;
}
string Minuj(const char* X)
{
	string t(X);
	for(int i = 0; i < t.size(); ++i)
		if(t[i] == '?')
			t[i] = '0';
	return t;
}

string tmpA;
string tmpB;
ll Dif;
bool warunek(ll ma, ll mb)
{
	ll na = Maxs(tmpA.c_str());
	ll nb = Maxs(tmpB.c_str());
	if(ma < na) return true;
	if(ma == na && mb < nb) return true;
	return false;
}
void Check()
{	

	if(abs(Mins(A) - Maxs(B)) < Dif || (abs(Mins(A) - Maxs(B)) == Dif && warunek(Mins(A), Maxs(B))))
	{
		Dif = abs(Mins(A) - Maxs(B));
		tmpA = Minuj(A);
		tmpB = Maxuj(B);
	}
	if(abs(Mins(B) - Maxs(A)) < Dif || (abs(Mins(B) - Maxs(A)) == Dif && warunek(Maxs(A), Mins(B))))
	{
		Dif = abs(Mins(B) - Maxs(A));
		tmpB = Minuj(B);
		tmpA = Maxuj(A);
	}
}
void solver()
{
	Dif = INF;
	tmpA = "99999999999999999";
	tmpB = "99999999999999999";
	scanf("%s%s", A, B);
	for(int i = 0; A[i] != 0; ++i)
	{
		if(A[i] == '?' && B[i] == '?')
		{
			A[i] = '0';
			B[i] = '1';
			Check();
			A[i] = '1';
			B[i] = '0';
			Check();
			A[i] = B[i] = '0';
			Check();
		}
		if(A[i] == '?' && B[i] != '?')
		{
			A[i] = max((int)'0', B[i]-1);
			Check();
			A[i] = min((int)'9', B[i]+1);
			Check();
			A[i] = B[i];
			Check();
		}
		if(A[i] != '?' && B[i] == '?')
		{
			B[i] = max((int)'0', A[i]-1);
			Check();
			B[i] = min((int)'9', A[i]+1);
			Check();
			B[i] = A[i];
			Check();
		}		
		if(A[i] != '?' && B[i] != '?')
			Check();
	}
	//printf("%s %s ", A, B);
	printf("%s %s", tmpA.c_str(), tmpB.c_str());
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);
		solver();
		puts("");
	}
	
	
	return 0;
}
