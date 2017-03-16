#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;
int main ()
{
    char mymap['z' + 1];
    mymap['a']='y';
	mymap['b']='h';
	mymap['c']='e';
	mymap['d']='s';
	mymap['e']='o';
	mymap['f']='c';
	mymap['g']='v';
	mymap['h']='x';
	mymap['i']='d';
	mymap['j']='u';
	mymap['k']='i';
	mymap['l']='g';
	mymap['m']='l';
	mymap['n']='b';
	mymap['o']='k';
	mymap['p']='r';
	mymap['q']='z';
	mymap['r']='t';
	mymap['s']='n';
	mymap['t']='w';
	mymap['u']='j';
	mymap['v']='p';
	mymap['w']='f';
	mymap['x']='m';
	mymap['y']='a';
	mymap['z']='q';
	mymap[' ']=' ';
    ifstream R("A-small-attempt0.in");
    ofstream W("a.out");
    int t;
    string space;
    R>>t;
    getline(R,space);
    for (int i=1;i<=t;++i)
    {
        string google;
        getline(R,google);
        for(int i=0;i<google.size();i++)
        {
            google[i]=mymap[google[i]];
        }
        W<<"Case #"<<i<<": "<<google<<endl;
    }
    system("pause");
}
