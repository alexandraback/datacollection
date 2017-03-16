#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
ifstream fin;
ofstream fout;
int x;
int y;
string process();
int main(int argc,char* argv[])
{
	int counter;
	fin.open(argv[1]);
	fout.open("test.out");
	fin>>counter;
	for (int i = 0; i < counter; ++i)
	{
		string result;
        fin>>x>>y;
        result=process();
		fout<<"Case #"<<(i+1)<<": "<<result<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

string process()
{
    string answer;
    int stepx=abs(x);
    int stepy=abs(y);
    if(x>0)
    {
        for(int i=0;i<stepx;i++)
        {
            answer.append("WE");
        }
    }
    else
    {
        for(int i=0;i<stepx;i++)
        {
            answer.append("EW");
        }
    }
    if(y>0)
    {
        for(int i=0;i<stepy;i++)
        {
            answer.append("SN");
        }
    }
    else
    {
        for(int i=0;i<stepy;i++)
        {
            answer.append("NS");
        }
    }
    return answer;
}
