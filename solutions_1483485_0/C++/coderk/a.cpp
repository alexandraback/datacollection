#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

const string s0 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
const string s1 = "our language is impossible to understand";
const string s2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
const string s3 = "there are twenty six factorial possibilities";
const string s4 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
const string s5 = "so it is okay if you want to just give up";

int main()
{
    int c[30], count = 0;
    for (int i = 0; i < 26; i++)
        c[i] = -1;
    for (int i = 0; i < s0.size(); i++)
        if (s0[i] >= 'a' && s0[i] <= 'z')
        {
            int a = int(s0[i] - 'a'), b = int(s1[i] - 'a');
            if (c[a] < 0)
                count++;
            c[a] = b;
        }
    for (int i = 0; i < s2.size(); i++)
        if (s2[i] >= 'a' && s2[i] <= 'z')
        {
            int a = int(s2[i] - 'a'), b = int(s3[i] - 'a');
            if (c[a] < 0)
                count++;
            c[a] = b;
        }
    for (int i = 0; i < s4.size(); i++)
        if (s4[i] >= 'a' && s4[i] <= 'z')
        {
            int a = int(s4[i] - 'a'), b = int(s5[i] - 'a');
            if (c[a] < 0)
                count++;
            c[a] = b;
        }
    c[int('q' - 'a')] = int('z' - 'a');
    c[int('z' - 'a')] = int('q' - 'a');

    ifstream fin("a.in", ios::in);
    ofstream fout("a.out", ios::out);
    int t;
    string s;
    fin >> t;
    for (int i = 1; i <= t; i++)
    {
        getline(fin, s);
        if (i == 1)
            getline(fin, s);
        fout << "Case #" << i << ": ";
        for (int j = 0; j < s.size(); j++)
            if (s[j] == ' ')
                fout << ' ';
            else
                fout << char(c[int(s[j] - 'a')] + 'a');
        fout << endl;
    }
    fin.close();
    fout.close();
}

