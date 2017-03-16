#include <iostream>
#include <string>
#include <vector>

using namespace std;



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

class test_solver
{
public:
    test_solver(istream& is_)  :_possibles()
    {
        int N = 0, s = 0, p = 0;
        is_ >> N >> s >> p;
        vector<int> totals;
        for (int i = 0; i < N; ++i)
        {
            int temp = 0;
            is_ >> temp;
            totals.push_back(temp);
        }
        string endline;
        getline(is_,endline);

        vector<int> base;
        for (int i = 0; i < N; ++i)
        {
            base.push_back(totals[i] / 3);
        }

        vector<int> remainder;

        for (int i = 0; i < N; ++i)
        {
            remainder.push_back(totals[i] - 3*base[i]);
        }

        int remaining_surprises = s;
        for (int i = 0; i < N; ++i)
        {
            int n = base[i];
            int r = remainder[i];
            switch (r)
            {
            case 0:
                if (n >= p)
                {
                    ++_possibles;
                }
                else if (n == p-1 && n > 0 && remaining_surprises)
                {
                    ++_possibles;
                    --remaining_surprises;
                }
                break;
            case 1:
                if (n+1 >= p)
                {
                    ++_possibles;
                }
                break;
            case 2:
                if (n+1 >= p)
                {
                    ++_possibles;
                }
                else if (n+2 == p && remaining_surprises)
                {
                    ++_possibles;
                    --remaining_surprises;
                }
            }
        }
    }

    void output(ostream& os_)
    {
        os_ << _possibles << endl;
    }

private:
    int _possibles;
};


int main (int argc, char *argv[])
{
    test_marshall<test_solver> tm(cin,cout);
    
    return 0;
}

