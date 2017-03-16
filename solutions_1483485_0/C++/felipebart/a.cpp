#include <vector>
#include <string>
#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXL = 100;

void set_mapping(const string& from, const string& to, vector<char>& mapping)
{
    assert(from.size() == to.size());
    for(int i=0;i<from.size();++i)
    {
        if(from[i] == ' ')
        {
            assert(to[i] == ' ');
        }
        else
        {
            int ind = from[i] - 'a';
            assert((mapping[ind] == 0) || (mapping[ind] == to[i]));
            mapping[ind] = to[i];
        }
    }
}

void complete_mapping(vector<char>& mapping)
{
    int numUnset = 0;
    for(int i=0;i<mapping.size();++i)
    {
        if(mapping[i] == 0)
        {
            ++numUnset;
            for(char c='a';c<='z';++c)
            {
                if (mapping.end() == find(mapping.begin(), mapping.end(), c))
                {
                    mapping[i] = c;
                }
            }
        }
    }
    assert(numUnset <= 1);
}

void assert_mappingisok(const vector<char>& mapping)
{
    for(int i=0;i<mapping.size();++i)
    {
        assert(mapping[i] != 0);
        for(int j=1+i;j<mapping.size();++j)
        {
            assert(mapping[i] != mapping[j]);
        }
    }
}

string translate(const string& inp, const vector<char>& mapping)
{
    string ret(inp.size(), ' ');
    for(int i=0;i<inp.size();++i)
    {
        if(inp[i] != ' ')
        {
            ret[i] = mapping[inp[i] - 'a'];
        }
    }
    
    return ret;
}

int main()
{
    vector<char> mapping(26, 0);
    set_mapping("yeq", "aoz", mapping);
    set_mapping("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand", mapping);
    set_mapping("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities", mapping);
    set_mapping("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up", mapping);
    complete_mapping(mapping);
    assert_mappingisok(mapping);
    
    int t;
    scanf(" %d ", &t);
    for(int lp=1;lp<=t;++lp)
    {
        char line[1+MAXL];
        scanf("%[^\n]\n", line);
        auto resp = translate(line, mapping);
        printf("Case #%d: %s\n", lp, resp.c_str());
    }
    
    return 0;
}