#include <fstream>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int n;
deque<float> warN, warK;
deque<float> dwarN, dwarK;

int WarNaomi()
{
	int nao=0;
    for(int i=n-1; i>=0; i--)
    {
		if(warN.back()>warK.back())
		{
			warK.pop_front();
			nao++;
		}
		else
		{
			warK.pop_back();
		}
		warN.pop_back();
	}
	return nao;
}

int deceitfulWarNaomi()
{
	int nao=0;
    for(int i=n-1; i>=0; i--)
    {
		if(dwarK.back()>dwarN.back())
		{
			dwarN.pop_front();
		}
		else
		{
			dwarN.pop_back();
			nao++;
		}
		dwarK.pop_back();
	}
	return nao;
}

int main()
{
int t;
float temp;
in >> t;
for(int i=1; i<=t; i++)
{
	warN.clear();
	warK.clear();
     out << "Case #" << i << ": ";
     in >> n;
     for(int j=0; j<n; j++)
     {
          in >> temp;   
          warN.push_back(temp);
     }
     
     for(int j=0; j<n; j++)
     {
          in >> temp;   
          warK.push_back(temp);
     }
     sort(warN.begin(), warN.end());
     sort(warK.begin(), warK.end());
     dwarN=warN;
     dwarK=warK;
     out << deceitfulWarNaomi() << " " << WarNaomi();
     out << endl;   
}

}
