#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string orig =
"abcdefghijklmnopqrstuvwxyz ";
string next = 
"yhesocvxduiglbkrztnwjpfmaq ";

ifstream fin ("a.in");
ofstream fout ("a.out");

int main()
{
    int t; fin >> t;
    string s;
    getline (fin, s);
    for (int test = 0; test < t; test++)
    {
        getline (fin, s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ') continue;
            s[i] = next[s[i]-'a'];
        }
        fout << "Case #" << test + 1 << ": ";
        fout << s << "\n";
    }
    return 0;
}
