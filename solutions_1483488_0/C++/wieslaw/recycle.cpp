
// g++ dancing.cpp -o dancing

#include <iostream>
#include <string>
#include <set>

using namespace std;

const int P10[7] = {1,10,100,1000,10000,100000,1000000};

// only good for 1..9999999
int numlen(int n_)
{
    if (n_ < 10000)
    {
        if (n_ < 100)
        {
            return n_ < 10 ? 1 : 2;
        }
        else
        {
            return n_ < 1000 ? 3 : 4;
        }
    }
    else
    {
        if (n_ < 1000000)
        {
            return n_ < 100000 ? 5 : 6;
        }
        else
        {
            return n_ < 10000000 ? 7 : 8;
        }
    }
}

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

        for (int i = 0; i < N; ++i)
        {
            S solver(is_);
            os_ << "Case #" << (i+1) << ": "; 
            solver.output(os_);
        }
    }

private:

};

class number
{
public:
    number(int n_) : _value(n_), _len(numlen(_value)), _highexp(P10[_len-1])
    {
    }

    // Important to keep it as the same object so that the original length is not lost
    void cycle()
    {
        _value = _value / 10 + _highexp * (_value % 10);
    }

    int value() const
    {
        return _value;
    }

    int len() const
    {
        return _len;
    }

    int highexp() const
    {
        return _highexp;
    }

private:
    int _value;
    int _len;
    int _highexp;
};

ostream& operator<<(ostream& os_, const number& n_)
{
    return os_ << "V=" << n_.value() << " L=" << n_.len() << "H=" << n_.highexp();

}

struct npair
{
    npair(int n1_=0, int n2_=0) : _n1(n1_),_n2(n2_)
    {
    }
    number _n1;
    number _n2;
};

bool operator <(const npair& p1, const npair& p2)
{
    return p1._n1.value() < p2._n1.value() 
    || p1._n1.value() == p2._n1.value() && p1._n2.value() < p2._n2.value();
}

class test_solver
{
public:
    test_solver(istream& is_)  :_count()
    {
        int A = 0, B = 0;
        is_ >> A >> B;
        string endline;
        getline(is_,endline);

        set<npair> pairs;

        for (int n = A; n < B; ++n)
        {
            number nn(n);
            number mm = nn;
            for (int i = 1; i < nn.len(); ++i)
            {
                mm.cycle();
                if (mm.value() > nn.value() && mm.len() == nn.len() && mm.value() <= B)
                {
                    pairs.insert(npair(nn.value(),mm.value()));
                }
            }
        }
        _count = pairs.size();
    }

    void output(ostream& os_)
    {
        os_ << _count << endl;
    }

private:
    int _count;
};


int main (int argc, char *argv[])
{
    test_marshall<test_solver> tm(cin,cout);
    
    return 0;
}


