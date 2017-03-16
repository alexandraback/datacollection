/*************************************************************************
    > File Name: fairSquare_small.cpp
    > Author: Hu Pengxiang
    > Mail: hpxiangsky@gmail.com 
    > Created Time: Sat 13 Apr 2013 09:21:52 AM CST
 ************************************************************************/
#define TEST 0 

#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<fstream>
#include<algorithm>
using namespace std;
class chess
{
public:
	list<int> keyIn;
	int			keyOpen;
};

class node
{
public:
	node():parent(NULL),chessOpened(-1), h(0)
	{
	}
	~node()
	{
		for(list<node *>::iterator iter = child.begin();iter != child.end();++iter)
		{
			delete *iter;
		}
	}
public:
	int chessOpened;
	int h;
	node *parent;
	list<node *> child;
};

class state
{
public:
	void display()
	{
		cout << "*******************************************" << endl;
		cout << "Key" << endl;
		for(list<int>::iterator iter = key.begin();iter != key.end();++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
		cout << "Chess left" << endl;
		for(list<int>::iterator iter = chessLeft.begin();iter != chessLeft.end();++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
public:
	list<int> key;
	list<int> chessLeft;
};

bool det(list<int> key, vector<chess> &chessInfo)
{
	map<int, int> has, need;

	for(list<int>::iterator iter = key.begin();iter != key.end();++iter)
	{
		has[*iter]++;
	}
	for(unsigned int i = 0;i < chessInfo.size();++i)
	{
		need[chessInfo[i].keyOpen]++;
		for(list<int>::iterator iter = chessInfo[i].keyIn.begin();iter != chessInfo[i].keyIn.end();++iter)
		{
			has[*iter]++;
		}
	}

	for(map<int, int>::iterator iter = has.begin();iter != has.end();++iter)
	{
		if(has[iter->first] < need[iter->first])
			return false;
	}
	return true;
}


const vector<int> solve(list<int> &key, vector<chess> &chessInfo)
{
	//initialize state
	state s;
	s.key = key;
	s.chessLeft.empty();
	for(unsigned int i = 0;i < chessInfo.size();++i)
		s.chessLeft.push_back(i);
	
	//initialize node
	node *head = new node();
	node *p = head;

	//chest whose key insilde include key open
	vector<bool> chestKeyInside;
	for(unsigned int i = 0;i < chessInfo.size();++i)
	{
		list<int>::iterator si = find(chessInfo[i].keyIn.begin(), chessInfo[i].keyIn.end(), chessInfo[i].keyOpen);
		chestKeyInside.push_back(si != chessInfo[i].keyIn.end());
	}

	bool ifBuild = true;
	while(1)
	{
		//build child
		if(ifBuild)
		{
		    for(list<int>::iterator iter = s.chessLeft.begin();iter != s.chessLeft.end();++iter)
		    {
			    int chess = *iter; 
			    int keyOpen = chessInfo[chess].keyOpen;

			    //find key
				list<int>::iterator si = find(s.key.begin(), s.key.end(), keyOpen);

			    //create child node
			    if(si != s.key.end())
			    {
				    node *child = new node;
				    child->chessOpened = *iter;
				    child->parent = p;
					child->h = p->h+1;
				    p->child.push_back(child);
			    }
		    }
        }
		
		
		bool ifLoad = false;
		//load one child
		if(p->child.size() != 0)
		{
			//refresh state
			p = *(p->child.begin());
			list<int>::iterator iter = find(s.key.begin(), s.key.end(), chessInfo[p->chessOpened].keyOpen);
			s.chessLeft.remove(p->chessOpened);
			s.key.erase(iter);
			s.key.merge(chessInfo[p->chessOpened].keyIn);
			ifBuild = true;
			ifLoad = true;
			if(TEST)
			{
				s.display();
				cout << "h " << p->h << endl;
			}
		}

		//judge 
		//delete child and return to parent
		bool toParent = false;
		if((s.key.size() == 0 && s.chessLeft.size() != 0) || (p->child.size() == 0 && !ifLoad))		//no key || key cannot open any chest
			toParent = true;
		
		bool keyInside = false;
		if(s.chessLeft.size() <= 20)
		{
		    for(list<int>::iterator iter = s.chessLeft.begin(); iter != s.chessLeft.end();++iter)
		    {
			    if(chestKeyInside[*iter])
			    {
				    list<int>::iterator si = find(s.key.begin(), s.key.end(), chessInfo[*iter].keyOpen);
				    if(si != s.key.end())
				    {
					    keyInside =false;
						continue;
				    }

				    bool exist = true;
				    for(list<int>::iterator iter2 = s.chessLeft.begin(); iter2 != s.chessLeft.end();++iter2)
				    {
					    if(iter2 != iter)
					    {
						    list<int>::iterator si2 = find(chessInfo[*iter2].keyIn.begin(), chessInfo[*iter2].keyIn.end(), 
						                                chessInfo[*iter].keyOpen);
						    if(si2 != chessInfo[*iter2].keyIn.end())
						    {
							    exist = false;
							    break;
						    }
					    }
				    }
				    if(exist)
					{
					    keyInside = true;
						break;
					}
			    }
		    }
        }
        
		toParent = toParent || keyInside;
		if(toParent)
		{
			ifBuild = false;
			while(p->child.size() == 0 && p->parent != NULL)
			{
				//refresh state
				s.chessLeft.push_back(p->chessOpened);
				s.chessLeft.sort();
				s.key.push_back(chessInfo[p->chessOpened].keyOpen);
				list<int> keyIn = chessInfo[p->chessOpened].keyIn;
				for(list<int>::iterator iter = keyIn.begin();iter != keyIn.end();++iter )
				{
					s.key.remove(*iter);
				}
				if(TEST)
				{
					s.display();
					cout << "h " << p->h << endl;
				}

				//return to parent node
				node *pFather = p->parent;
				pFather->child.remove(p);
				delete p;
				p = pFather;
			}
		}
		// judge success
		if(s.chessLeft.size() == 0)		//success
		{
			vector<int> result;
			do
			{
				result.push_back(p->chessOpened);
				p = p->parent;
			}
			while(p->parent != NULL);
			return result;
		}
		//judge failure
		if(p == head && p->child.size() == 0)
		{
			vector<int > result;
			return result;
		}
		if((s.chessLeft.size() == 1))
		{
			list<int> tmp = s.key;
			tmp.merge(chessInfo[*(s.chessLeft.begin())].keyIn);
			bool isExist = false;
			for(list<int>::iterator iter = tmp.begin();iter != tmp.end();++iter)
			{
				if(*iter == chessInfo[*(s.chessLeft.begin())].keyOpen)
				{
					isExist = true;
					break;
				}
			}
			if(!isExist)
			{
				vector<int > result;
				return result;
			}
		}
	}
}



int main()
{
	//open file
	int caseNum;
	char inFileName[10] = "small.in";
	ifstream f1;
	f1.open(inFileName, ios::in);	
	char outFileName[10] = "small.out";
	ofstream f2;
	f2.open(outFileName, ios::out);
	f1 >> caseNum;

	for(int c = 0;c < caseNum;++c)
	{
		//read data
		int K, N;	//init key number, chest number
		f1 >> K;
		f1 >> N;
		list<int> key;
		for(int i = 0;i < K;++i)
		{
			int tmp;
			f1 >> tmp;
			key.push_back(tmp);
		}
		vector<chess> chessInfo;
		for(int i = 0;i < N;++i)
		{
			chess c;
			f1 >> c.keyOpen;
			int keyNum;
			f1 >> keyNum;
			for(int j = 0;j < keyNum;++j)
			{
				int tmp;
				f1 >> tmp;
				c.keyIn.push_back(tmp);
			}
			chessInfo.push_back(c);

		}

		//display()
		/*
		cout << "key " << endl;
		for(list<int>::iterator iter = key.begin();iter != key.end();++iter)
		{
			cout << * iter << " ";
		}
		cout << endl;
		cout << "chest" << endl;
		for(unsigned int i = 0;i < chessInfo.size();++i)
		{
			cout << i+1 <<": key open ";
			cout << chessInfo[i].keyOpen;
			list<int> tmp = chessInfo[i].keyIn;
			cout << "  key in ";
			for(list<int>::iterator iter = tmp.begin();iter != tmp.end();++iter)
				cout << * iter << " ";
			cout << endl;
		}
		*/
		
		bool canSolve = det(key, chessInfo);
		if(!canSolve)
		{
			f2 << "Case #" << c+1 << ": IMPOSSIBLE" << endl;
		}
		else
		{
			//solve
			vector<int> result = solve(key, chessInfo);
			if(result.size() == 0)
				f2 << "Case #" << c+1 << ": IMPOSSIBLE" << endl;
			else
			{
				f2 << "Case #" << c+1 << ": " ;
				for(int kk = result.size()-1;kk >= 0;--kk)
					f2 << result[kk]+1 << " ";
				f2 << endl;
			}
		}
		cout << "Cass " << c+1 << "success " << endl;


	}
	return 0;
}
