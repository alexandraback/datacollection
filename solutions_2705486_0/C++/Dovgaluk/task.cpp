#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

int states;

struct G
{
	G(G *p, char cc) : final(false), parent(p), c(cc)
	{
		for (int i = 0 ; i < 26 ; ++i)
			next[i] = NULL;
		++states; 
	}

	std::string name()
	{
		if (parent)
			return parent->name() + c;
		else
			return std::string(1, c);
	}

	G *parent;
	char c;
	bool final;
	G *next[26];
};

G root(NULL, 0);

void add(G *node, const char *s)
{
	if (!*s)
	{
		node->final = true;
		return;
	}
	int i = *s - 'a';
	if (!node->next[i])
		node->next[i] = new G(node, *s);
	add(node->next[i], s + 1);
}

void add_string(const std::string &s)
{
	add(&root, s.c_str());
}

void make_dict()
{
	std::ifstream in("garbled_email_dictionary.txt");
	std::string s;
	while (in >> s)
	{
		add_string(s);
	}
}

typedef std::vector<G*> V;
typedef std::map<G*, int> M;

void addM(M &m, G *g, int cnt)
{
	M::iterator mi = m.find(g);
	if (mi != m.end())
	{
		if (mi->second > cnt)
			mi->second = cnt;
	}
	else
	{
		m.insert(std::make_pair(g, cnt));
	}
//	std::cout << "\taddM: " << g->name() << " " << cnt << "\n";
	if (g->final && g != &root)
		addM(m, &root, cnt);
}

void addR(M &m, G *g, const char *s, int cnt, size_t i, size_t last, const std::string &ss)
{
	if (i >= last)
	{
//		std::cout << "addR: " << ss << "\n";
		addM(m, g, cnt);
	}
	else
	{
		int c = *s - 'a';
		if (g->next[c])
		{
			addR(m, g->next[c], s + 1, cnt, i + 1, last, ss + *s);
			if (g->next[c]->final)
				addR(m, &root, s + 1, cnt, i + 1, last, ss + *s);
		}
	}
}

int main()
{
	make_dict();
	//std::cout << states << "\n";

	int T;
	std::cin >> T;
	for (int t = 1 ; t <= T ; ++t)
	{
		std::string s;
		std::cin >> s;
		std::vector<M> m(s.size() + 1);

		m[0][&root] = 0;
		for (size_t i = 0 ; i < s.size() ; ++i)
		{
//			std::cout << "Step " << i << "\n";
			int c = s[i] - 'a';
			for (M::iterator mi = m[i].begin() ; mi != m[i].end() ; ++mi)
			{
				// move
				G *next = mi->first->next[c];
				if (next)
				{
					addM(m[i + 1], next, mi->second);
				}
				// change and move 4
				for (int j = 0 ; j < 26 ; ++j)
					if (j != c && mi->first->next[j])
					{
						size_t last = std::min(s.size(), i + 5);
						addR(m[last], mi->first->next[j], s.c_str() + i + 1, mi->second + 1, i + 1, last, std::string() + char(j + 'a'));
						if (mi->first->next[j]->final)
							addR(m[last], &root, s.c_str() + i + 1, mi->second + 1, i + 1, last, std::string() + char(j + 'a'));
					}
			}
		}
		if (m[s.size()].find(&root) == m[s.size()].end()) std::cout << "ERROR! ";
		std::cout << "Case #" << t << ": " << m[s.size()][&root] << "\n";
	}
	return 0;
}

