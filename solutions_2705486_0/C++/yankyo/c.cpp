
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int index(char c)
{
	return (c == '.') ? 0 : c - 'a' + 1;
}


const int MAX = 28;

struct node
{
	node** next;
	bool final;
	bool hasnext;

	void add(const char *s)
	{
		char c = s[0];
		if (c == 0)
		{
			final = true;
			return;
		}

		int i = index(c);
		if (next == 0) initnext();
		if (next[i] == 0)
		{
			next[i] = new node();
		}
		next[i]->add(s+1);
	}

	void add(const string &str)
	{
		return add(str.c_str());
	}

	void initnext()
	{
		next = new node*[MAX];
		for (int i = 0; i < MAX; i++) next[i] = 0;
	}

	node()
	{
		next = 0;
		final = false;
	}
};

node *mother = new node();

struct nodeptr
{
	node *n;
	int dotcnt;
	int lastdot;
	string hist;

	void test(bool &advance, bool &newword, bool &dot)
	{
		advance = (n->next != 0);
		newword = (n->final);
		dot = advance && (lastdot >= 5);
	}

	nodeptr advance(char c)
	{
		return nodeptr(n->next[index(c)], dotcnt, lastdot+1, hist + "a");
	}

	nodeptr newword(char c)
	{
		return nodeptr(mother->next[index(c)], dotcnt, lastdot+1, hist + "n");
	}

	nodeptr newworddot(char c)
	{
		return nodeptr(mother->next[0], dotcnt+1, 1, hist + "N");
	}

	nodeptr dot(char c)
	{
		return nodeptr(n->next[0], dotcnt+1, 1, hist + ".");
	}

	bool valid()
	{
		return (n != 0);
	}

	bool final()
	{
		return n->final;
	}

	nodeptr(node *_n, int dc, int ld, string h)
	{
		n = _n;
		dotcnt = dc;
		lastdot = ld;
		hist = h;
	}
};


list<nodeptr> advance(list<nodeptr> &l, char c)
{
	list<nodeptr> res;
	bool a, n, d;

	//cout << "Advance" << endl;

	for (list<nodeptr>::iterator i = l.begin(); i != l.end(); ++i)
	{
		i->test(a, n, d);
		//cout << "Test: " << a << " " << n << " " << d << endl;
		if (a)
		{
			nodeptr np = i->advance(c);
			if (np.valid()) res.push_back(np);
		}

		if (n)
		{
			nodeptr np = i->newword(c);
			if (np.valid()) res.push_back(np);
		}

		if (d)
		{
			nodeptr np = i->dot(c);
			if (np.valid()) res.push_back(np);
		}

		if (n && d)
		{
			nodeptr np = i->newworddot(c);
			if (np.valid()) res.push_back(np);
		}
	}

	return res;
}


void readdict()
{
	ifstream f("garbled_email_dictionary.txt");
	string s;

	while (f >> s)
	{
		mother->add(s);
		//cout << s << endl;

		// add garbled
		for (int i = 0; i < s.length(); i++)
		{
			string s2 = s;
			s2[i] = '.';
			mother->add(s2);
			//cout << s2 << endl;
		}

		// add double-garbled
		if (s.length() > 5)
		{
			for (int i = 0; i < s.length() - 5; i++)
			{
				for (int j = i+5; j < s.length(); j++)
				{
					string s2 = s;
					s2[i] = '.';
					s2[j] = '.';
					mother->add(s2);
					//cout << s2 << endl;
				}
			}
		}
	}
}


int main()
{
	readdict();

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		string s;
		cin >> s;

		list<nodeptr> l;
		l.push_back(nodeptr(mother, 0, 5, ""));

		for (int i = 0; i < s.length(); i++)
		{
			l = advance(l, s[i]);
		}

		int min = s.length(); 
		for (list<nodeptr>::iterator i = l.begin(); i != l.end(); ++i)
		{
			if (i->final() && i->dotcnt < min)
			{
				//cout << "new min " << i->dotcnt << " with " << i->hist << endl;
				min = i->dotcnt;
			}
		}

		cout << "Case #" << t << ": " << min << endl;
	}

	return 0;
}

