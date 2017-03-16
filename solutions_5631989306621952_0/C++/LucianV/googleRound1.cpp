
#include <iostream>
#include <deque>
#include <fstream>
#include <map>

using namespace std;
ofstream out("googleR.out");
ifstream in("googleR.in");

int main()
{
    int T;
    in >> T;
    for(int test = 1; test <=T; ++test)
    {
        string sir;
        in >> sir;
        deque<char> deq;
        deq.push_back(sir[0]);
        for(int i = 1; i < sir.length(); ++i)
        {
            if(sir[i] >= deq.front())
            {
                deq.push_front(sir[i]);
            }
            else
            {
                deq.push_back(sir[i]);
            }
        }

        out <<"Case #" <<test << ": ";
        while(!deq.empty())
        {
            out << deq.front();
            deq.pop_front();
        }

        out << '\n';

    }

    return 0;
}

