#include <iostream>
#include <fstream>

using namespace std;

int map[] = {	25,8,5,19,15,
		3,22,24,4,21,
		9,7,12,2,11,
		18,26,20,14,23,
		10,16,6,13,1,17	};

string s;
char del[200];

ifstream fin;
ofstream fout;

int main()
{
    int n;
    fin.open("in.txt");
    fout.open("out.txt");

    fin>>n;
    fin.getline(del,200);
    for (int i=1;i<=n;++i)
    {
        fin.getline(del,200);
        s = string(del);
        for (int j=0;j<s.size();++j)
            if (s[j] != ' ')
            {
                s[j] = (char)(map[s[j]-97]+96);
            }
        fout<<"Case #"<<i<<": "<<s<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
