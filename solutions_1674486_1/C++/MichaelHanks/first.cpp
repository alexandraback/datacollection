#include "stdafx.h"
#include <iostream>
#include <string> 

#include <fstream> 
using namespace std;
struct Node {
	int id;
	int num;
	Node* next;
};
bool isD = false;
bool CountN(int i, Node n[1001])
{

	n[i].num ++;
	if (n[i].num > 1)
		isD = true;
	if (isD == true)
		return true;
	Node *p = n[i].next;
	
	if ( p == NULL)
		return false;

	while ( p != NULL)
	{
		CountN(p->id,n);
		p = p->next;
	}

	return false;
}
int main()
{
	ifstream fin ("C:/A-large.in",ios::in);
	ofstream fout("C:/testout1.out"); 
	Node n[1001];
	int T,N,M,h;
	fin >> T;
	for ( int i = 1; i <= T; i++)
	{
		isD = false;
		fin >> N;
		for ( int s = 1 ; s <= N;s++)
		{
			n[s].next = NULL;
			n[s].id = s;
			n[s].num = 0;
		}

		for ( int j = 1 ; j<= N ;j++)
		{
			fin >> M;
			for ( int k = 0 ; k < M ; k++ )
			{
				fin >> h;
				Node *node = new Node();
				node->id  = j;
				node->next = n[h].next;
				n[h].next = node;
			}
		}
		int j;
		for ( j = N ; j > 0 ; j--)
		{
			for ( int s = 1 ; s <= N;s++)
				n[s].num = 0;
			bool isD1 = CountN(j, n);
			if ( isD == true)
				break;
		}
		if ( j == 0 )
			fout << "Case #" << i <<": No"<<endl;
		else
			fout << "Case #" << i <<": Yes"<<endl;
	}
	return 0;
}