#include <cstdio>
#include <cassert>

typedef long long int ll;

const ll infty = 1e18;

int lprz[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};

int zprz[4][4] = {
	{1, 1, 1, 1},
	{1, -1, 1, -1},
	{1, -1, -1, 1},
	{1, 1, -1, -1}
};

struct kwaternion
{
	int znak, liczba;

	explicit kwaternion(char c = '1') : znak(1)
	{
		if(c == '1')
			liczba = 0;
		else if(c == 'i')
			liczba = 1;
		else if(c == 'j')
			liczba = 2;
		else if(c == 'k')
			liczba = 3;
		else
			assert(false);
	}

	kwaternion & operator *= (const kwaternion & k)
	{
		znak *= k.znak * zprz[liczba][k.liczba];
		liczba = lprz[liczba][k.liczba];
		return *this;
	}

	const kwaternion operator * (const kwaternion & k) const
	{
		kwaternion q(*this);
		return q *= k;
	}

	kwaternion & operator *= (int x)
	{
		assert(x == 1 || x == -1);
		znak *= x;
		return *this;
	}

	const kwaternion operator * (int x) const
	{
		kwaternion q(*this);
		return q *= x;
	}

	const kwaternion operator ^ (ll pot) const
	{
		kwaternion wyn;
		kwaternion x(*this);
		while(pot)
		{
			if(pot % 2 == 1)
				wyn *= x;
			x *= x;
			pot /= 2;
		}
		return wyn;
	}

	bool operator == (const kwaternion & k) const
	{
		return znak == k.znak && liczba == k.liczba;
	}

	bool operator != (const kwaternion & k) const
	{
		return !(*this == k);
	}
};

kwaternion jeden('1');

int l;
const int powtorz = 30;
kwaternion tab[powtorz * 10005];
ll x;
ll d;
int pozycja;

const kwaternion nast()
{
	if(pozycja >= d)
		throw 1;
	return tab[pozycja++];
}

bool przyp()
{
	scanf("%d%lld", &l, &x);
	d = l * x;
	for(int i = 0; i < l; i++)
	{
		char c;
		scanf(" %c", &c);
		tab[i] = kwaternion(c);
	}
	for(int i = 1; i < powtorz; i++)
		for(int j = 0; j < l; j++)
			tab[i * l + j] = tab[j];
	pozycja = 0;

	try
	{
		for(int i = 1; i <= 2; i++)
		{
			kwaternion k;
			while(true)
			{
				k *= nast();
				if(pozycja == powtorz * l)
					throw 1;
				if(k.znak == 1 && k.liczba == i)
					break;
			}
		}
		kwaternion s;
		while(pozycja % l)
			s *= nast();
		assert((d - pozycja) % l == 0);
		kwaternion cale;
		for(int i = 0; i < l; i++)
			cale *= tab[i];
		s = s * (cale ^ ((d - pozycja) / l));
		if(s != kwaternion('k'))
			throw 1;
	}
	catch (int zle)
	{
		return false;
	}
	return true;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %s\n", i, przyp() ? "YES" : "NO");
	return 0;
}
