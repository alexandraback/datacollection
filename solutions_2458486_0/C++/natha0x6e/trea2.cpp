#include <iostream>
#include <list>

using namespace std;


struct Node
{
	int value;
	Node * next;
};

//keys in each chest
list<int> inBox[200];
//key to open chest
int toOpen[200];

//my keys
int myKeysCount[200];

Node * chestsLeft_head;

int numKeys;
int numChests;

list<int> result;

int cache[25][2000000];
int cindex = 0;
bool notisLeft[200];

bool test()
{
	
	int cacheValue = 0;
	for(int i = 0;i < 20;i++)
	{
		cacheValue <<= 1;
		if(!notisLeft[i])
		{
			cacheValue++;
		}
	}
	if(cache[cindex][cacheValue])
	{
		return false;
	}
	cache[cindex][cacheValue] = true;
	
	bool res = false;
	if(chestsLeft_head != NULL)
	{
		
		Node * last = NULL;
		for(Node * it = chestsLeft_head;it != NULL && !res;it = it->next)
		{
			int box = it->value;
			if(myKeysCount[toOpen[box]] > 0)
			{
				myKeysCount[toOpen[box]]--;
				if(last == NULL)
				{
					chestsLeft_head = it->next;
				}
				else
				{
					last->next = it->next;
				}
				for(list<int>::iterator itt = inBox[box].begin();itt != inBox[box].end();itt++)
				{
					myKeysCount[*itt]++;
				}
				notisLeft[box] = true;
				
				bool r = test();
				
				if(r)
				{
					res = true;
					result.push_front(box);
				}
				
				notisLeft[box] = false;
				for(list<int>::iterator itt = inBox[box].begin();itt != inBox[box].end();itt++)
				{
					myKeysCount[*itt]--;
				}
				if(last == NULL)
				{
					chestsLeft_head = it;
				}
				else
				{
					last->next = it;
				}
				myKeysCount[toOpen[box]]++;
			}
			last = it;
		}
	}
	else
	{
		res = true;
	}
	
	return res;
}

int main(int argc,char *argv[])
{
	(void) argc;
	(void) argv;
	
	int numTests;
	
	cin >> numTests;
	
	
	for(int i = 0;i < numTests;i++)
	{
		chestsLeft_head = NULL;
		//keys in each chest
		for(int j = 0;j < 200;j++)
		{
			inBox[j] = list<int>();
			myKeysCount[j] = 0;
			notisLeft[j] = false;
		}
		result = list<int>();
		
		cin >> numKeys >> numChests;
		
		for(int j = 0;j < numKeys;j++)
		{
			int tmp;
			cin >> tmp;
			myKeysCount[tmp-1]++;
		}
		for(int j = 0;j < numChests;j++)
		{
			int numinBox;
			int xx;
			cin >> xx >> numinBox;
			toOpen[j] = xx - 1;
			for(int k = 0;k < numinBox;k++)
			{
				int tmp;
				cin >> tmp;
				inBox[j].push_back(tmp-1);
			}
			Node * old = chestsLeft_head;
			chestsLeft_head = new Node();
			chestsLeft_head->value = numChests - j - 1;
			chestsLeft_head->next = old;
		}
		
		bool r = test();
		
		cout << "Case #" << i+1 << ":";
		if(r)
		{
			for(list<int>::iterator it = result.begin();it != result.end();it++)
			{
				cout << " " << *it + 1;
			}
		}
		else
		{
			cout << " IMPOSSIBLE";
		}
		cout << endl;
		cindex++;
		
	}
	return 0;
}
