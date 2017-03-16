#include <fstream>
#include <iostream>
using namespace std;
bool vowel[256];

int tren;
void displej(int stat,int uk)
{
    int perc=(double)stat/(double)uk*100.0;
    for (int i=tren;i<perc/10;i++)
        cout << ".";
    tren=perc/10;
}

int main()
{
    vowel['a']=true;
    vowel['e']=true;
    vowel['i']=true;
    vowel['o']=true;
    vowel['u']=true;
    string str;
    getline(cin,str);
    ifstream in(str.c_str());
    //ifstream in("in.txt");
    ofstream out("izlaz.txt");
    int tests;
    in >> tests;
    cout << "working ";
    tren=0;
    for (int t=0;t<tests;t++)
    {
        int res=0;
        string s;
        int n;
        in >> s >> n;
        int con=0;
        for (int i=0;i<s.length();i++)
        {
            con=!vowel[s[i]];
            int mCon=con;
            if (con>=n) res++;
            for (int j=i+1;j<s.length();j++)
            {
                if (vowel[s[j]]) con=0; else con++;
                if (con>mCon) mCon=con;
                if (mCon>=n)
                {
                    res++;
                    //out << i << "-" << j << endl;
                }
            }
        }
        out << "Case #" << t+1 << ": " << res << endl;
        displej(t,tests);
    }

    return 0;
}
