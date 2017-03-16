#include<iostream>
#include<fstream>
#include<math.h>
#include<stdio.h>
#include<vector>

using namespace std;

class node
{
public:
	vector<int> inheritFrom;
	int inheritFromCount;
	vector<int> inheritTo;
	int inheritToCount;
	node()
	{
		inheritFromCount=0;
		inheritToCount=0;
	}
};

node nodes[1000];
int numberOfClasses;

bool searchForTarget(int myself, int target)
{
	for(int counter=0;counter<nodes[myself].inheritFromCount;counter++)
		if(nodes[myself].inheritFrom[counter]==target)
			return true;
	return false;
}


int nodeSearch(int myself, int target,int parent)
{
	int flag=0;
	if(searchForTarget(myself,target))
		flag++;
	if(myself!=parent &&flag==1)
		return 1;

	for(int counter=0;counter<numberOfClasses;counter++)
	{
		if(counter==myself || counter==target || counter==parent)
			continue;
		if(searchForTarget(myself,counter))
			flag+=nodeSearch(counter,target,myself);
		if(myself!=parent && flag>=1)
			break;
		if(myself==parent &&flag>=2)
			break;
	}

	return flag;

}



int main()
{
	int cases,counter,counter2,flag=0;
	bool found=false;
	

	ifstream in("A-small-attempt1.in");
	ofstream out("output.txt");

	in>>cases;

	for(counter=0;counter<cases;counter++)
	{
		in>>numberOfClasses;
		found=false;
		int temp;
		for(counter2=0;counter2<numberOfClasses;counter2++)
		{
			in>>nodes[counter2].inheritFromCount;
			for(int counter3=0;counter3<nodes[counter2].inheritFromCount;counter3++)
			{
				in>>temp;
				temp--;
				nodes[counter2].inheritFrom.push_back(temp);
				nodes[temp].inheritToCount++;
				nodes[temp].inheritTo.push_back(counter2);
			}
		}

		// Finished Reading in the input!

		for(counter2=0;counter2<numberOfClasses;counter2++)
		{
			for(int counter3=0;counter3<numberOfClasses;counter3++)
			{
				if(counter2==counter3)
					continue;
				//if(nodes[counter2].inheritFromCount!=0 && nodes[counter3].inheritToCount!=0)
					flag=nodeSearch(counter2,counter3,counter2);
				if(flag>=2)
				{
					out<<"Case #"<<counter+1<<": Yes"<<endl;
					found=true;
				}
				if(found)
					break;
			}
			if(found)
				break;
		}

		if(!found)
			out<<"Case #"<<counter+1<<": No"<<endl;
		for(counter2=0;counter2<numberOfClasses;counter2++)
		{
			nodes[counter2].inheritFrom.clear();
			nodes[counter2].inheritTo.clear();
		}
	}

	return 0;
}