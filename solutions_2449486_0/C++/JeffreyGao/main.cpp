#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
using namespace std;
void main()
{
	ifstream in("B-small-attempt0.in",ios::in);
	ofstream out("small.txt",ios::out);
	int grassland[100][100];
	int testCase;
	in>>testCase;
	for(int index=0;index<testCase;index++)
	{
		vector<map<int,int>> rowvec;
		vector<map<int,int>> columnvec;
		vector<map<int,int>> rowdatamap;
		vector<map<int,int>> columndatamap;
		int numofrow;
		int numofcolumn;
		in>>numofrow;
		in>>numofcolumn;
		for(int row=0;row<numofrow;row++)
		{
			for(int column=0;column<numofcolumn;column++)
			{
				in>>grassland[row][column];
			}
		}
		for(int indexY=0;indexY<numofrow;indexY++)
		{
			map<int,int> newmap;
			rowvec.push_back(newmap);
			for(int indexX=0;indexX<numofcolumn;indexX++)
			{
				rowvec[indexY][grassland[indexY][indexX]]++;
			}
		}
		for(int indexX=0;indexX<numofcolumn;indexX++)
		{		
			map<int,int> newmap;
			columnvec.push_back(newmap);
			for(int indexY=0;indexY<numofrow;indexY++)
			{
				columnvec[indexX][grassland[indexY][indexX]]++;
			}
		}
		for(int indexY=0;indexY<numofrow;indexY++)
		{
			map<int,int> newmap;
			int index=0;
			for(map<int,int>::iterator it=rowvec[indexY].begin();it!=rowvec[indexY].end();it++)
			{
				newmap[it->first]=index;
				index++;
			}
			rowdatamap.push_back(newmap);
		}
		for(int indexX=0;indexX<numofcolumn;indexX++)
		{
			map<int,int> newmap;
			int index=0;
			for(map<int,int>::iterator it=columnvec[indexX].begin();it!=columnvec[indexX].end();it++)
			{
				newmap[it->first]=index;
				index++;
			}
			columndatamap.push_back(newmap);
		}
		bool finished=false;
		for(int indexY=0;indexY<numofrow;indexY++)
		{
			bool verified=false;
			int a;
			int b;
			for(int indexX=0;indexX<numofcolumn;indexX++)
			{
				a=rowdatamap[indexY][grassland[indexY][indexX]];
				b=columndatamap[indexX][grassland[indexY][indexX]];
				if((rowdatamap[indexY][grassland[indexY][indexX]]<(rowvec[indexY].size()-1))&&(columndatamap[indexX][grassland[indexY][indexX]]<(columnvec[indexX].size()-1)))
				{
					finished=true;
				}
			}
			if(finished==true)
			{
				out<<"Case #"<<index+1<<": NO"<<endl;
				break;
			}
		}
		if(finished==false)
		{
			out<<"Case #"<<index+1<<": YES"<<endl;
		}
	}
}