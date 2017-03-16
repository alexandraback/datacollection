#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

const int NA = static_cast<int>('z') - static_cast<int>('a') + 1;

class mapping
{
public:
    mapping() : _codebook()
    {
    }
    void add(const string& cleartext_, const string& coded_)
    {
        for (int i = 0; i < cleartext_.size(); ++i)
        {
            char cl = cleartext_[i];
            char cd = coded_[i];
            if (cl >= 'a' && cl <= 'z')
            {
                _codebook[cd] = cl;
            }
        }
    }

    bool complete()
    {
        if (_codebook.size() == NA)
        {
            return true;
        }
        set<char> onto;
        set<char> from;
        for (map<char,char>::iterator i = _codebook.begin(); i != _codebook.end(); ++i)
        {
            from.insert(i->first);
            onto.insert(i->second);
        }

        set<char> not_from;

        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (from.count(c) == 0)
            {
                not_from.insert(c);
            }
        }

        set<char> not_onto;

        for (char c = 'a'; c <= 'z'; ++c)
        {
            if (onto.count(c) == 0)
            {
                not_onto.insert(c);
            }
        }

        for (set<char>::iterator i = not_from.begin(); i != not_from.end(); ++i)
        {
            for (set<char>::iterator j = not_onto.begin(); j != not_onto.end(); ++j)
            {
                if (*i != *j)
                {
                    _codebook[*i] = *j;
                    not_onto.erase(*j);
                    break;
                }
            }
        }

        return _codebook.size() == NA;
    }

    char cleartext(char coded_) const
    {
        map<char,char>::const_iterator i = _codebook.find(coded_);
        return i == _codebook.end() ? ' ' : i->second;
    }

private:

    map<char,char> _codebook;

};

class test_solver
{
public:
    test_solver() : _language()
    {
        _language.add("a zoo","y qee");
        _language.add("our language is impossible to understand","ejp mysljylc kd kxveddknmc re jsicpdrysi");
        _language.add("there are twenty six factorial possibilities","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
        _language.add("so it is okay if you want to just give up","de kr kd eoya kw aej tysr re ujdr lkgc jv");
        _language.complete();
    }

    void output(istream& is_, ostream& os_)
    {
        string coded;
        getline(is_,coded);
        string translated;
        for (int i = 0; i < coded.size(); ++i)
        {
            translated += _language.cleartext(coded[i]);
        }
        os_ << translated << endl;
    }

private:
    mapping _language;
};


template <class S>
class test_marshall
{
public:
    test_marshall(istream& is_, ostream& os_)
    {
        int N = 0;
        string endline;
        
        is_ >> N;
        getline(is_,endline);

        S solver;

        for (int i = 0; i < N; ++i)
        {
            os_ << "Case #" << (i+1) << ": "; 
            solver.output(is_, os_);
        }
    }
};

int main (int argc, char *argv[])
{
    test_marshall<test_solver> tm(cin,cout);
    
    return 0;
}

