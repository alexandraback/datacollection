#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>

using namespace std;
int R,C,W;

int compare(const void* one, const void* two)
{
	return *(int *)one < *(int *)two;
}


int main()
{
	ifstream OpenFile("A-large.txt");
	ofstream SaveFile("ex_out.txt");

	int T;
	OpenFile>>T;

	for (int t = 0; t < T; t++)
	{		
		OpenFile>>R>>C>>W;
		int res=0;
		res=(C/W)*R;

		int rest=(C%W);
		if(rest!=0)
			res += W;
		else
			res += (W-1);
		SaveFile<<"Case #"<<t+1<<": "<<res<<endl;
	}
	
	OpenFile.close();
	SaveFile.close();

	return 0;
}
