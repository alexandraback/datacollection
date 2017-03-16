#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void main()
{
	ifstream in("A-large.in",ios::in);
	int numofTest;
	in>>numofTest;
	char pattern[4][4];
	int testNum=0;
	ofstream out("finallarge.out",ios::out);
	for(int times=0;times<numofTest;times++)
	{
		bool dotFind=false;
		testNum++;
		for(int y=0;y<=3;y++)
		{
			for(int x=0;x<=3;x++)
			{
				char data=0;
				in>>data;
				pattern[y][x]=data;
				if(pattern[y][x]=='.')
					dotFind=true;
			}
		}
		bool finished=false;
		for(int index=0;index<=3;index++)
		{
			char start='w';
			bool rowfinished=true;
			for(int index2=0;index2<=3;index2++)
			{
				if(start=='w'&&((pattern[index][index2]=='O')||(pattern[index][index2]=='X')))
				{
					start=pattern[index][index2];
					break;
				}
			}
			if(start=='X'||start=='O')
			{
				for(int index2=0;index2<=3;index2++)
				{
					if(!(pattern[index][index2]==start||pattern[index][index2]=='T'))
					{
						rowfinished=false;
						break;
					}
				}
			}
			else
			{
				rowfinished=false;
			}
			if(rowfinished==true)
			{
				out<<"Case #"<<testNum<<": "<<start<<" won"<<endl;
				finished=true;
				break;
			}
		}
		if(finished==false)
		{
			for(int index=0;index<=3;index++)
			{
				char start='w';
				bool rowfinished=true;
				bool charfind=false;
				for(int index2=0;index2<=3;index2++)
				{
					if(start=='w'&&((pattern[index2][index]=='O')||(pattern[index2][index]=='X')))
					{
						start=pattern[index2][index];
						break;
					}
				}
				if(start=='X'||start=='O')
				{
					for(int index2=0;index2<=3;index2++)
					{
						if(!(pattern[index2][index]==start||pattern[index2][index]=='T'))
						{
							rowfinished=false;
							break;
						}
					}
				}
				else
				{
					rowfinished=false;
				}
				if(rowfinished==true)
				{
					out<<"Case #"<<testNum<<": "<<start<<" won"<<endl;
					finished=true;
					break;
				}
			}
		}		
		if(finished==false)
		{
			char start='w';
			bool rowfinished=true;
			bool charfind=false;
			for(int index=0;index<=3;index++)
			{
				if(start=='w'&&((pattern[index][index]=='O')||(pattern[index][index]=='X')))
				{
					start=pattern[index][index];
					break;
				}
			}
			if(start=='X'||start=='O')
			{
				for(int index=0;index<=3;index++)
				{
					if(!(pattern[index][index]==start||pattern[index][index]=='T'))
					{
						rowfinished=false;
						break;
					}
				}
			}
			else
			{
				rowfinished=false;
			}
			if(rowfinished==true)
			{
				out<<"Case #"<<testNum<<": "<<start<<" won"<<endl;
				finished=true;
			}
		}
		if(finished==false)
		{
			char start='w';
			bool rowfinished=true;
			bool charfind=false;
			for(int index=0;index<=3;index++)
			{
				if(start=='w'&&((pattern[index][3-index]=='O')||(pattern[index][3-index]=='X')))
				{
					start=pattern[index][3-index];
					break;
				}
			}
			if(start=='X'||start=='O')
			{
				for(int index=0;index<=3;index++)
				{
					if(!(pattern[index][3-index]==start||pattern[index][3-index]=='T'))
					{
						rowfinished=false;
						break;
					}
				}
			}
			else
				rowfinished=false;
			if(rowfinished==true)
			{
				out<<"Case #"<<testNum<<": "<<start<<" won"<<endl;
				finished=true;
			}
		}
		if(finished==false&&dotFind==false)
		{
			out<<"Case #"<<testNum<<": "<<"Draw"<<endl;
		}
		if(finished==false&&dotFind==true)
		{
			out<<"Case #"<<testNum<<": "<<"Game has not completed"<<endl;
		}
	}
	int data;
	in>>data;
}