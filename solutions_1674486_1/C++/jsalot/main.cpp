/*
 * main.cpp
 *
 *  Created on: May 6, 2012
 *      Author: sercan
 */

#include <iostream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

using namespace std;

template<typename T>
class Node
{
public:
	Node():
		value(0)
	{
	}

	~Node()
	{
		//for (int i=0; i<children.size(); i++)
		//delete children[i];
	}

	Node* findChild(const T& v, int& i)
	{
		for (; i<children.size(); i++)
			if (children[i]->value == v)
				return children[i];
		return NULL;
	}

	Node* findParent(const T& v, int& i)
	{
		for (; i<parents.size(); i++)
			if (parents[i]->value == v)
				return parents[i];
		return NULL;
	}

	vector<Node*> children;
	vector<Node*> parents;
	T value;
};

Node<int> nodes[1000];

void remove(int& j)
{
	for (int k = 0; k < nodes[j].children.size(); k++)
	{
		int parentIndex = 0;
		if (nodes[j].children[k]->findParent(j, parentIndex))
			nodes[j].children[k]->parents.erase(
					nodes[j].children[k]->parents.begin() + parentIndex);
		else
			cerr << "AMANINI COOO" << endl;
	}
	for (int k = 0; k < nodes[j].parents.size(); k++)
	{
		//cerr << "setting parent: " << k << " "<< nodes[j].parents[k]->value+1 <<endl;
		int childIndex = 0;
		if (nodes[j].parents[k]->findChild(j, childIndex))
		{
			nodes[j].parents[k]->children.erase(
					nodes[j].parents[k]->children.begin() + childIndex);

			for (int l = 0; l < nodes[j].children.size(); l++)
			{
				nodes[j].parents[k]->children.push_back(nodes[j].children[l]);
				nodes[j].children[l]->parents.push_back(nodes[j].parents[k]);
			}
		}
		else
			cerr << "AMANINI BOOO" << endl;
	}
	nodes[j].children.clear();
	nodes[j].parents.clear();
}

void printAll(int& N)
{
	for (int j = 0; j < N; j++)
	{
		if (!nodes[j].children.empty())
		{
			cerr << "node: " << j + 1 << " children: ";
			for (int k = 0; k < nodes[j].children.size(); k++)
			{
				cerr << nodes[j].children[k]->value + 1 << " ";
			}
			cerr << endl;
		}

	}

}

void solve(int i)
{
	cout << "Case #" << i << ": ";

	int N;
	cin >> N;

	for (int j=0; j<N; j++)
	{
		nodes[j].children.clear();
		nodes[j].parents.clear();
		nodes[j].value = j;
	}
	for (int j=0; j<N; j++)
	{
		int Mj;
		cin >> Mj;
		for (int k=0; k<Mj; k++)
		{
			int inheritedFrom;
			cin >> inheritedFrom;
			inheritedFrom--;

			nodes[j].children.push_back(nodes+inheritedFrom);
			nodes[inheritedFrom].parents.push_back(nodes+j);
		}
	}

	cerr << "BEFORE: " << endl;
	printAll(N);

	bool done = false;
	while (!done)
	{
		for (int j=0; j<N; j++)
		{
			if (nodes[j].children.size() > 1)
			{
				for (int k=0; k<nodes[j].children.size(); k++)
				{
					int index = k+1;
					if (nodes[j].findChild(nodes[j].children[k]->value, index) != NULL)
					{
						cout << "Yes" << endl;
						return;
					}
				}
			}

	/*		if (nodes[j].children.size() == 1)
			{
				remove(j);
			}

			if (nodes[j].children.size() == 0 && nodes[j].parents.size() == 1)
			{
				remove(j);
			}
*/
			if (nodes[j].children.size() > 0 && nodes[j].parents.size() > 0)
			{
				remove(j);
			}
		}
		done = true;
		for (int j=0; j<N; j++)
		{
			if (/*nodes[j].children.size() == 1 ||
					nodes[j].children.size() == 0 && nodes[j].parents.size() == 1 || */
					nodes[j].children.size() > 0 && nodes[j].parents.size() > 0)
			{
				done = false;
				break;
			}
		}
	}

	cerr << "AFTER: " << endl;
	printAll(N);

	for (int j=0; j<N; j++)
	{
		if (nodes[j].children.size() > 1)
		{
			for (int k=0; k<nodes[j].children.size(); k++)
			{
				int index = k+1;
				if (nodes[j].findChild(nodes[j].children[k]->value, index) != NULL)
				{
					cout << "Yes" << endl;
					return;
				}
			}
		}
	}

	cout << "No" << endl;
}

int main(int argc, char* argv[])
{
	int numberOfCases;
	cin >> numberOfCases;

	// read till the end of line just to be sure "gets" will work
	char line[1024];
	cin.getline(line, 1024);

	for (int i = 1; i <= numberOfCases; i++)
		solve(i);

	return 0;
}
