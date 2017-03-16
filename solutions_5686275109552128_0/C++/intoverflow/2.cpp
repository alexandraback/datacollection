#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
int main()
{
int t;
cin>>t;

	for (int i=0;i<t;i++)
	{
	int d,p;
	cin>>d;
	multiset<int> list;
	
		for (int j=0;j<d;j++)
		{
		cin>>p;
		list.insert(p);
		}
		multiset<int>::reverse_iterator rit;
		multiset<int>::reverse_iterator rit2;
		int turns=0;
		rit=list.rbegin();
		int min=*rit;
		
		for (rit=list.rbegin();*rit>2;)
		{
			int ct=list.count(*rit);
			for (int j=0;j<ct;j++)
			{
				list.insert(*rit/2);
				if (*rit%2==0) {list.insert(*rit/2);}
				else {list.insert(*rit/2+1);}
				turns++;
			}
			list.erase(*rit);
			rit=list.rbegin();
			if (min>*rit+turns) min=*rit+turns;
		rit=list.rbegin();
		}
		cout<<"Case #"<<i+1<<": "<<min<<"\n";
	}
}