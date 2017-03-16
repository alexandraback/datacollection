
#include <iostream>
#include <list>

using namespace std;

const int LEN = 110;
const int BASE = 10;

struct pal
{
	int len;
	int data[LEN];

	pal()
	{
		len = 1;
		for (int i = 0; i < LEN; i++) data[i] = 0;
	}

	pal(const pal &p)
	{
		len = p.len;
		for (int i = 0; i < LEN; i++) data[i] = p.data[i];
	}

	void halfNormalize(int from)
	{
		int pos = from;
		while (pos < len)
		{
			int bb = len == 1 ? 4 : (pos == len-1 || pos == from) ? 3 : 2;
			if (data[pos] >= bb)
			{
				if (pos == len-1)
				{
					len++;
					data[pos+1] = data[pos] / bb;
				} else
				{
					data[pos+1] += data[pos] / bb;
				}
				data[pos] %= bb;
			}
			pos++;
		}
	}

	void normalize(int from = 0)
	{
		int pos = from;
		while (pos < len)
		{
			if (data[pos] >= BASE)
			{
				if (pos == len-1)
				{
					len++;
					data[pos+1] = data[pos] / BASE;
				} else
				{
					data[pos+1] += data[pos] / BASE;
				}
				data[pos] %= BASE;
			}
			pos++;
		}
		//while (pos < LEN) data[pos++] = 0;
	}

	void set(int i)
	{
		len = 1;
		data[0] = i;
		normalize();
	}

	void set(const pal &p)
	{
		len = p.len;
		for (int i = 0; i < len; i++) data[i] = p.data[i];
	}

	void add(const pal &p)
	{
		if (len < p.len) len = p.len;
		for (int i = 0; i < len; i++) data[i] += p.data[i];
		normalize();
	}

	void mul10()
	{
		if (zero()) return;
		len++;
		for (int i = len-1; i > 0; i--) data[i] = data[i-1];
		data[0] = 0;
	}

	void mul(int c)
	{
		for (int i = 0; i < len; i++) data[i] *= c;
		normalize();
	}

	void addShiftedMultiply(const pal &p, int shift, int mul)
	{
		for (int i = 0; i < p.len; i++)
		{
			if (len <= i+shift) len = i+shift+1;
			data[i+shift] += mul * p.data[i];
		}
	}

	pal mul(const pal &p)
	{
		pal c;

		for (int i = 0; i < len; i++)
		{
			if (data[i] != 0) c.addShiftedMultiply(p, i, data[i]);
		}
		c.normalize();
		set(c);
	}

	bool zero()
	{
		return (len == 1 && data[0] == 0);
	}

	bool is()
	{
		if (len == 1) return true;
		for (int i = (len-1)/2; i >= 0; i--) if (data[i] != data[len-1-i]) return false;
		return true;
	}

	void next()
	{
		int l2 = len/2;
		data[l2]++;
		normalize(l2);
		if (len > 1) for (int i = (len-1)/2; i >= 0; i--) data[i] = data[len-1-i];
	}

	void nextViable()
	{
		int l2 = len/2;
		int nonzeros = 9;

		while (nonzeros > 5)
		{
			data[l2]++;
			halfNormalize(l2);

			nonzeros = 0;
			for (int i = l2; i < len; i++) if (data[i] != 0) nonzeros++;
		}
		//halfNormalize(l2);

		if (len > 1) for (int i = (len-1)/2; i >= 0; i--) data[i] = data[len-1-i];
	}

	string toStr() const
	{
		string out = "";
		for (int i = len-1; i >= 0; i--) out += ('0' + data[i]);
		return out;
	}

	void fromStr(const string &s)
	{
		len = s.length();
		for (int i = 0; i < len; i++) data[i] = s[len-1-i] - '0';
	}
};


bool operator <= (const pal &p1, const pal &p2)
{
	if (p1.len < p2.len) return true;
	if (p1.len > p2.len) return false;
	for (int i = p1.len-1; i >= 0; i--)
	{
		if (p1.data[i] < p2.data[i]) return true;
		if (p1.data[i] > p2.data[i]) return false;
	}
	return true;
}

bool operator == (const pal &p1, const pal &p2)
{
	if (p1.len != p2.len) return false;
	for (int i = p1.len-1; i >= 0; i--) if (p1.data[i] != p2.data[i]) return false;
	return true;
}


int main()
{
	pal p, r, max;
	p.set(1);
	r.set(1);
	max.set(1);

	for (int i = 0; i < 6; i++) max.mul10();

	list<pal> l;

	while (r <= max)
	{
		if (r.is())
		{
			//cout << p.toStr() << " -> " << r.toStr() << endl;
			l.push_back(r);
		}

		//p.nextViable();
		p.next();
		r.set(p);
		r.mul(p);
	}

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		string sA, sB;
		cin >> sA >> sB;

		pal A, B;
		A.fromStr(sA);
		B.fromStr(sB);

		//cout << "  == " << A.toStr() << " " << B.toStr() << " ==" << endl;

		int count = 0;
		for(list<pal>::iterator i = l.begin(); i != l.end(); ++i)
		{
			if ((A <= *i) && (*i <= B))
			{
				//cout << " counting " << (*i).toStr() << "!!" << endl;
				count++;
			}
		}

		cout << "Case #" << (t+1) << ": " << count << endl;
	}

	return 0;
}


