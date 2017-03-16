#include<bits/stdc++.h>
using namespace std;
typedef pair<string, string> pss;
typedef long long ll;

ll tonum(string a)
{
	ll ris=0;
	for(int i=0;i<a.size();++i)
	{
		ris*=10;
		ris += a[i] - '0';
	}

	return ris;
}
pss best(pss a, pss b)
{
	pss sol;
	string A[2] = {a.first, a.second}, B[2] = {b.first, b.second};

	if(A[0] == "")
		return b;
	else if(B[0] == "")
		return a;
	else
	{
		ll deltaA = abs(tonum(A[0]) - tonum(A[1]));
		ll deltaB = abs(tonum(B[0]) - tonum(B[1]));

		if(deltaA < deltaB)
			sol = a;
		else if(deltaB < deltaA)
			sol = b;
		else sol = min(a, b);
	}

	return sol;
	
}

pss prova(string a, string b, int discr)
{
	bool fatto = false;

	if(a[discr] == '?' && b[discr] == '?')
	{
		a[discr] = '1', b[discr] = '0';
		fatto = true;
	}
	else if(a[discr] == '?' && b[discr] != '9')
	{
		a[discr] = b[discr] + 1;
		fatto = true;
	}
	else if(b[discr] == '?' && a[discr] != '0')
	{
		b[discr] = a[discr] - 1;
		fatto = true;
	}

	if(!fatto)
		return make_pair("", "");

	for(int i=0;i<discr;++i)
	{
		if(a[i] == '?' && b[i] == '?')
			a[i] = b[i] = '0';
		else if(a[i] == '?')
			a[i] = b[i];
		else if(b[i] == '?')
			b[i] = a[i];
	}
	
	for(int i=discr; i<a.size(); ++i)
	{
		if(a[i] == '?') a[i] = '0';
		if(b[i] == '?') b[i] = '9';
	}

	return make_pair(a,b);
}

pss calcola(string a, string b)
{
	int discr=-1;
	for(int i=0;i<a.size();++i)
	{
		if(a[i] == b[i] || a[i] == '?' || b[i] == '?') continue;
		discr = i;
		break;
	}

	if(discr==-1)
	{
		for(int i=0;i<a.size();++i)
		{
			if(a[i] == '?' && b[i] == '?')
				a[i] = b[i] = '0';
			else if(a[i] == '?')
				a[i] = b[i];
			else if(b[i] == '?')
				b[i] = a[i];
		}

		return make_pair(a,b);
	}

	pss sol = {"", ""};

	for(int i=0;i<discr;++i)
		sol = best(sol, prova(a,b,i));

	if(a[discr] > b[discr])
	{
		for(int i=0;i<discr;++i)
		{
			if(a[i] == '?' && b[i] == '?')
				a[i] = b[i] = '0';
			else if(a[i] == '?')
				a[i] = b[i];
			else if(b[i] == '?')
				b[i] = a[i];
		}
		
		for(int i=discr; i<a.size(); ++i)
		{
			if(a[i] == '?') a[i] = '0';
			if(b[i] == '?') b[i] = '9';
		}

		sol = best(sol, make_pair(a,b));
	}

	return sol;
}


void foo()
{
	string C,J;
	cin >> C >> J;

	pss solA, solB, sol;
	solA = calcola(C,J);
	solB = calcola(J,C);

	string A[2] = {solA.first, solA.second}, B[2] = {solB.second, solB.first};
	swap(solB.first, solB.second);

	if(A[0] == "")
		sol = solB;
	else if(B[0] == "")
		sol = solA;
	else
	{
		ll deltaA = abs(tonum(A[0]) - tonum(A[1]));
		ll deltaB = abs(tonum(B[0]) - tonum(B[1]));

		if(deltaA < deltaB)
			sol = solA;
		else if(deltaB < deltaA)
			sol = solB;
		else sol = min(solA, solB);
	}

	cout << sol.first << " " << sol.second;
}

int main()
{
	int T;
	cin >> T;
	
	for(int i=0;i<T;++i)
	{
		cout << "Case #" << i+1 << ": ";
		foo();
		cout << "\n";
	}

	return 0;
}
