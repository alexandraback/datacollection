#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
using namespace std;
char mapping[200];
ifstream fin("1.in");
ifstream fans("1.out");
ofstream fout("mapping.out");
int main()
{
    string stra, strb;
    while (fin >> stra)
    {
          fans >> strb;
          for (int i=0; i<stra.length(); i++) mapping[stra[i]] = strb[i];
    }
    for (char i='a'; i<='z'; i++)
    {
        fout << i << "-->" << mapping[i] << endl;
    }
    return 0;
}
