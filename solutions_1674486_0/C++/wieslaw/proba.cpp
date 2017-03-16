#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long int64;

const int NA = static_cast<int>('z') - static_cast<int>('a') + 1;

template <class S>
class test_marshall
{
public:
    test_marshall(istream& is_, ostream& os_)
    {
        string endline;
        
        int N = 0;
        is_ >> N;
        getline(is_,endline);

        for (int i = 0; i < N; ++i)
        {
            S solver(is_);
            os_ << "Case #" << (i+1) << ": "; 
            solver.output(os_);
        }
    }

private:

};

class node
{
public:
    node(int id_=0) : _id(id_),_ancestors(),_descendants(),_mark()
    {
    }
    void add_anc(int id_)
    {
        _ancestors.insert(id_);
    }
    void add_des(int id_)
    {
        _descendants.insert(id_);
    }

    int _id;
    set<int> _ancestors;
    set<int> _descendants;
    bool _mark;
};

class test_solver
{
public:

    bool connected(node* from_, node* to_)
    {
        if (from_->_ancestors.count(to_->_id))
        {
            return true;
        }

        if (from_->_ancestors.size() == 0)
        {
            return false;
        }

        for (set<int>::iterator i = from_->_ancestors.begin();
              i != from_->_ancestors.end();
              ++i)
        {
            node& n = _nodes[*i];
            if (connected(&n,to_))
            {
                return true;
            }
        }

        return false;

    }

    test_solver(istream& is_)  : _n(),_nodes(),_yes()
    {
        string endline;
        is_ >> _n;
        getline(is_,endline);

        for (int i = 1; i <= _n; ++i)
        {
            _nodes[i] = node(i);
        }

        for (int i = 1; i <= _n; ++i)
        {
            node& d = _nodes[i];;
            int nanc = 0;
            is_ >> nanc;
            for (int j = 1; j <= nanc; ++j)
            {
                int aid = 0;
                is_ >> aid;
                d.add_anc(aid);
                _nodes[aid].add_des(i);
            }
            getline(is_,endline);
        }


        vector<node*> mulanc;
        vector<node*> muldes;
        for (map<int,node>::iterator i = _nodes.begin(); i != _nodes.end(); ++i)
        {
            node* n = &i->second;
            if (n->_ancestors.size() > 1)
            {
                mulanc.push_back(n);
            }
            if (n->_descendants.size() > 1)
            {
                muldes.push_back(n);
            }
        }

        for (vector<node*>::iterator from = mulanc.begin(); from != mulanc.end(); ++from)
        {
            if (_yes)
            {
                break;
            }
            for (vector<node*>::iterator to = muldes.begin(); to != muldes.end(); ++to)
            {
                if (_yes)
                {
                    break;
                }
                if (*from == *to)
                {
                    continue;
                }


                int numcon = 0;
                for (set<int>::iterator i = (*from)->_ancestors.begin();
                      i != (*from)->_ancestors.end();
                      ++i
                          )
                {
                    if (&_nodes[*i] == *to 
                        || 
                        connected(&_nodes[*i], *to))
                    {
                        ++numcon;
                        if (numcon > 1)
                        {
                            _yes = true;
                        }
                    }
                }
            }
        }
    }

    void output(ostream& os_)
    {
        os_ << (_yes ? "Yes":"No") << endl;
    }

private:
    int _n;
    map<int,node>   _nodes;
    bool    _yes;
};


int main (int argc, char *argv[])
{
    test_marshall<test_solver> tm(cin,cout);
    
    return 0;
}

