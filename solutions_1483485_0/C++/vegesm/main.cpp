#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

char mapping[26]=
{
    'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b',	'k', 'u', 'o', 'm',	'x', 's', 'e', 'v',	'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'
};

char decode(char c)
{
    for(int i=0; i<26; i++)
    {
        if(mapping[i]==c)
        {
            return 'a'+i;
        }
    }
    return ' ';
}

int main()
{
    /*cout << "Hello world!" << endl;
    vector<char> abc;
    for(int i=0;i<26;i++)
    {
        abc.push_back(mapping[i]);
    }
    sort(abc.begin(), abc.end());
    for(int i=0;i<26;i++)
    {
        cout<<abc[i]<<' ';
    }*/
    ifstream in("A-small-attempt0.in");
    ofstream out("ki.txt");
    int n;
    in>>n;
    string s;
    getline(in, s);
    for(int i=1; i<=n; i++)
    {
        out<<"Case #"<<i<<": ";
        //string s;
        getline(in, s);
        for(int j=0;j<s.size(); j++)
        {
            char c=s[j];
            if(c==' ') out<<' ';
            else out<<decode(c);
        }
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
