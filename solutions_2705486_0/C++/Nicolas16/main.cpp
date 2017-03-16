#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main()
{
	int i, j, T, p, k, l;
	ifstream fichier;
	fichier.open("garbled_email_dictionary.txt");
	int taillemaxi = 0;
	
	set<string> dico;
	set<string> dico1[10]; // On a enlevé la lettre x
	set<string> dico2[6][10];
	set<string>::iterator it;
	string t, m;
	
	for(i = 0; i < 521196; i++) // 521196
	{
		fichier >> t;
		dico.insert(t);
		for(j = 0; j < t.size(); j++)
		{
			m.resize(t.size()-1);
			for(k = 0; k < j; k++)
			{
				m[k] = t[k];
			}
			for(k = j+1; k < t.size(); k++)
			{
				m[k-1] = t[k];
			}
			dico1[j].insert(m);
		}
		
		for(j = 0; j < t.size(); j++)
		{
			for(l = j+5; l < t.size(); l++)
			{
				m.resize(t.size()-2);
				for(k = 0; k < j; k++)
				{
					m[k] = t[k];
				}
				for(k = j+1; k < l; k++)
				{
					m[k-1] = t[k];
				}
				for(k = l+1; k < t.size(); k++)
				{
					m[k-2] = t[k];
				}
				dico2[j][l].insert(m);
			}
		}
	}
	
	
	int minimum[5000][5];
	int position, last;
	int newposition, newlast;
	string s;
	
	
	scanf("%d\n", &T);
	
	for(p = 1; p <= T; p++)
	{
		printf("Case #%d: ", p);
		cin >> s;
		for(i = 0; i < 5000; i++) for(j = 0; j < 5; j++) minimum[i][j] = -1;
		minimum[0][4] = 0;
		
		for(position = 0; position < s.size(); position++)
		{
			for(last = 0; last <= 4; last++)
			{
				if(minimum[position][last] >= 0)
				{
					// On peut placer une erreur à partir de la lettre 4-last
					
					// Pas d'erreur
					t.resize(0);
					for(i = 1; i <= 10 && position+i-1 < s.size(); i++)
					{
						t.push_back(s[position+i-1]);
						it = dico.find(t);
						if(it != dico.end())
						{
							newposition = position+t.size();
							newlast = min((int)last + (int)t.size(),4);
							if(minimum[newposition][newlast] == -1 || minimum[newposition][newlast] > minimum[position][last]) minimum[newposition][newlast] = minimum[position][last];
						}
					}
					
					// Une erreur
					t.resize(0);
					for(i = 1; i <= 10 && position+i-1 < s.size(); i++)
					{
						t.push_back(s[position+i-1]);
						for(i = 4-last; i < t.size(); i++)
						{
							m.resize(t.size()-1);
			 				for(k = 0; k < i; k++)
							{
								m[k] = t[k];
							}
							for(k = i+1; k < t.size(); k++)
							{
								m[k-1] = t[k];
							}
							it = dico1[i].find(m);
							if(it != dico1[i].end())
							{
								newposition = position + t.size();
								newlast = min((int)t.size()-i-1,4);
								if(minimum[newposition][newlast] == -1 || minimum[newposition][newlast] > minimum[position][last] + 1) minimum[newposition][newlast] = minimum[position][last] + 1;
							}
						}
					}
					
					// Deux erreurs
					t.resize(0);
					for(i = 1; i <= 10 && position+i-1 < s.size(); i++)
					{
						t.push_back(s[position+i-1]);
						for(i = 4-last; i < t.size(); i++)
						{
							for(j = i+5; j < t.size(); j++)
							{
								m.resize(t.size()-2);
				 				for(k = 0; k < i; k++)
								{
									m[k] = t[k];
								}
								for(k = i+1; k < j; k++)
								{
									m[k-1] = t[k];
								}
								for(k = j+1; k < t.size(); k++)
								{
									m[k-2] = t[k];
								}
								it = dico2[i][j].find(m);
								if(it != dico2[i][j].end())
								{
									newposition = position + t.size();
									newlast = min((int)t.size()-j-1,4);
									if(minimum[newposition][newlast] == -1 || minimum[newposition][newlast] > minimum[position][last] + 2) minimum[newposition][newlast] = minimum[position][last] + 2;
								}
							}
						}
					}
				}
			}
		}
		
		int result = 5000;
		
		for(i = 0; i < 5; i++)
		{
			if(minimum[s.size()][i] != -1) result = min(result, minimum[s.size()][i]);
		}
		
		printf("%d\n", result);
	}

	return 0;
}
