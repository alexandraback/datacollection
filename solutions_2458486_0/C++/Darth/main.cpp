#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("file.in");
ofstream fout("file.out");

struct Player
{
	vector<int> path;
	vector<int> opened;
	vector<int> keys;
};

struct Chest
{
	int keyToOpen;
	int *keys;
	int keysNum;
};

void Test(int caseNum);

int main()
{
	int num;

	fin >> num;

	for (int i = 0; i < num; i++)
	{
		Test(i+1);
	}

	return 0;
}

int* copyInts(int * from, int num)
{
	int* to = new int[num];
	for (int i = 0; i < num; i ++)
	{
		to[i] = from[i];
	}
	return to;
}

int* copyExcept(int * from, int num, int key)
{
	bool used = false;
	int* to = new int[num - 1];
	for (int i = 0; i < num; i ++)
	{
		if (!used && from[i] == key) 
		{
			used = true;
			continue;
		}
		to[i] = from[i];
	}
	return to;
}


bool openedChest(int chestNum, Player &p)
{
	for (auto i = p.opened.begin(); i != p.opened.end(); i++)
		if (*i == chestNum) return true;
	return false;
}

bool hasKey(int key, Player &p)
{
	for (auto i = p.keys.begin(); i != p.keys.end(); i++)
		if (*i == key) return true;
	return false;
}

void removeKey(Player &p, int key)
{
	for (auto i = p.keys.begin(); i != p.keys.end(); i++)
		if (*i == key)
		{
			p.keys.erase(i);
			break;
		}
}

void DrawResult(Player& p, int caseNum)
{
	fout << "Case #" << caseNum << ": ";
	for (int i = 0; i < p.path.size(); i++)
	{
		fout << p.path[i] + 1;
		if (i < p.path.size() - 1 ) fout << " ";
	}
	fout << endl;
}

vector<Player> victory;
int numChest;
Chest* chestList;

void Go(Player& p)
{
	if (p.opened.size() == numChest)
	{
		victory.push_back(p);
		return;
	}
	for (int i = 0; i < numChest; i++)
	{
		if (!openedChest(i, p) && hasKey(chestList[i].keyToOpen, p))
		{
			Player player;
			player.keys = p.keys;
			removeKey(player, chestList[i].keyToOpen);
			player.opened = p.opened;
			player.opened.push_back(i);
			player.path = p.path;
			player.path.push_back(i);
				
			for (int k = 0; k < chestList[i].keysNum; k++)
			{
				player.keys.push_back(chestList[i].keys[k]);
			}

			Go(player);
		}
	}
}

void Test(int caseNum)
{
	int numKeys;
	int i, r;
	fin >> numKeys >> numChest;
	vector<int> keys;
	int key;


	for (i = 0; i < numKeys; i++)
	{
		fin >> key;
		keys.push_back(key);
	}

	chestList = new Chest[numChest];
	for (i = 0; i < numChest; i++)
	{
		fin >> chestList[i].keyToOpen >> chestList[i].keysNum;
		chestList[i].keys = new int[chestList[i].keysNum];
		for (r = 0; r < chestList[i].keysNum; r ++)
		{
			fin >> chestList[i].keys[r];
		}
	}

	vector<Player> p;
	vector<Player> next;
	//vector<Player> victory;

	Player player;
	player.keys = keys;
	p.push_back(player);

	bool used;
	while(1)
	{
		next.clear();
		for (r = 0; r < p.size(); r++)
		{
			Player player;
			used = false;
			player.keys = p[r].keys;
			player.opened = p[r].opened;
			player.path = p[r].path;
			for (i = 0; i < numChest; i++)
			{
				if (!openedChest(i, p[r]) && hasKey(chestList[i].keyToOpen, p[r]))
				{
					removeKey(player, chestList[i].keyToOpen);
					player.opened.push_back(i);
					player.path.push_back(i);
				
					for (int k = 0; k < chestList[i].keysNum; k++)
					{
						player.keys.push_back(chestList[i].keys[k]);
					}
					used = true;
				}
			}

			if (used)
			{
				if (player.opened.size() == numChest)
				{
					victory.push_back(player);
				} else {
					next.push_back(player);
				}
			}
		}

		if (next.size() == 0)
			break;

		p = next;
	}

	if (victory.size() > 0)
	{
		Player min;
		for (i = 0; i < victory.size(); i++)
		{
			if (min.opened.size() == 0)
			{
				min = victory[i];
				continue;
			}

			int r = 0;
			while (r < victory[i].path.size())
			{
				if (victory[i].opened[r] < min.opened[r])
				{
					min = victory[i];
					break;
				}
				if (victory[i].opened[r] > min.opened[r])
					break;

				r++;
			}
		}

		DrawResult(min, caseNum);
		return;
	}

	fout << "Case #" << caseNum << ": IMPOSSIBLE" << endl;
}