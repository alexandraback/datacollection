#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <set>
#include <deque>
#include <math.h>

using namespace std;

void VisitANode(queue<int>& NextNodeToVisit, vector< vector<int> > next_tab, list<int>& AlreadyVisited)
{
	vector<int>::iterator it;
	for (it=next_tab[NextNodeToVisit.front()].begin(); it<next_tab[NextNodeToVisit.front()].end(); it++)
	{
		AlreadyVisited.push_back(*it);
		NextNodeToVisit.push(*it);
	}
	NextNodeToVisit.pop();
}

int main( )
{
	vector< vector<int> > next_tab;
	vector<int> row;
	vector<int>::iterator it;
	list<int>::iterator it_list;
	list<int> AlreadyVisited;
	queue<int> NextNodeToVisit;
	bool DiamondInheritance= false;
	int VisitNumber[1001];
	for (int i = 0; i<1001;i++)
			VisitNumber[i]= 0;
	int t, tt=0, N, temp, nbNextCurrentNode;
	FILE * INPUT = NULL;
	INPUT = fopen( "input.txt", "r");
	FILE * OUTPUT = NULL;
	OUTPUT = fopen( "output.txt", "w");

	fscanf(INPUT,"%d\n", &tt);
	for( t = 1; t <= tt;  ++t )
	{
		fprintf(OUTPUT, "Case #%d: ", t);
		fscanf(INPUT,"%d",&N);
		for( int i = 1; i <= N;  ++i )
		{
			fscanf(INPUT,"%d",&nbNextCurrentNode);
			if(nbNextCurrentNode !=0)
			{
				for( int j = 1; j <= nbNextCurrentNode;  ++j )
				{
					fscanf(INPUT,"%d",&temp);
					row.push_back(temp);
				}
			}
			else
			{
				row.push_back(0);
			}
			next_tab.push_back(row);
			row.clear();
		}
		DiamondInheritance = false;
		for(int i = 0; i<N ; i++)//Gestion départ de chaque noeud
		{
			if(next_tab[i].front() == 0)
				continue;
			for (it=next_tab[i].begin(); it<next_tab[i].end(); it++)
			{
				AlreadyVisited.push_back(*it);
				NextNodeToVisit.push(*it);
			}

			while(!NextNodeToVisit.empty())
			{
				//VisitANode(NextNodeToVisit, next_tab, AlreadyVisited);
				int CurrentNodeVisited = NextNodeToVisit.front();
				NextNodeToVisit.pop();
				if(next_tab[CurrentNodeVisited-1].front() == 0)
					continue;
				for (it=next_tab[CurrentNodeVisited-1].begin(); it!=next_tab[CurrentNodeVisited-1].end(); it++)
				{
					AlreadyVisited.push_back(*it);
					NextNodeToVisit.push(*it);
				}

			}
			for (it_list=AlreadyVisited.begin(); it_list!=AlreadyVisited.end(); it_list++)
			{
				VisitNumber[*it_list]++;
			}


			for (int i = 0; i<1001;i++)
			{
				if(VisitNumber[i]>1)
				{
					DiamondInheritance=true;
				}
				VisitNumber[i]= 0;
			}

			AlreadyVisited.clear();
			if (DiamondInheritance==true)
				break;
		}
		next_tab.clear();
		if (DiamondInheritance==true)
		{
			fprintf(OUTPUT, "Yes\n");
		}
		else
		{
			fprintf(OUTPUT, "No\n");
		}
	}

}