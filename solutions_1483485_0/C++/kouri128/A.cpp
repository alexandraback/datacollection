#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <cassert>
using namespace std;

int main()
{
    pair<string, string> hint(
        "ejp mysljylc kd kxveddknmc re jsicpdrysi"
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
        "de kr kd eoya kw aej tysr re ujdr lkgc jv"
        "qz",
        "our language is impossible to understand"
        "there are twenty six factorial possibilities"
        "so it is okay if you want to just give up"
        "zq"
        );
    map<char, char> mapping;

    for (int i = 0; i < hint.first.size(); ++i)
    {
        char k = hint.first[i];
        char v = hint.second[i];

        if (mapping.find(k) == mapping.end())
        {
            mapping[k] = v;
        }
        else
        {
            assert(mapping[k] == v);
        }
    }
    assert(mapping.size() == 'z' - 'a' + 2);

    string s;
    int N;
    getline(cin, s);
    istringstream is(s);
    is>>N;

    for (int i = 0; i < N; ++i)
    {
        getline(cin, s);

        for (int j = 0; j < s.size(); ++j)
        {
            s[j] = mapping[s[j]];
        }

        cout<<"Case #"<<i + 1<<": "<<s<<endl;
    }

    return 0;
}
