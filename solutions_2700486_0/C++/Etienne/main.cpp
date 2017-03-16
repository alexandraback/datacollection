#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;

class Prob
{
public:
    long long num;
    long long denom;

    Prob() : num(0), denom(1) {}
    Prob(long long num, long long denom) : num(num), denom(denom) {}

    Prob operator*(const Prob &other)
    {
        Prob result;
        result.num = num*other.num;
        result.denom = denom*other.denom;
        return result;
    }

    Prob operator+(const Prob &other)
    {
        Prob result;
        result.num = num*other.denom + other.num*denom;
        result.denom = denom*other.denom;
        while(result.num % 2 == 0 && result.denom % 2 ==0)
        {
            result.num /= 2;
            result.denom /= 2;
        }
        return result;
    }
};

typedef set<pair<int, int> > DiamondState;
typedef map<DiamondState, Prob > SimState;

void simulate(DiamondState state, Prob p, int x, int y, SimState &newstate)
{
    // sinks in the ground
    if(y == 0)
    {
        state.insert( make_pair(x, y));
        newstate[state] = newstate[state] + p;
    }
    else
    {
        if(state.find(make_pair(x-1, y-1)) != state.end())
        {
            if(state.find(make_pair(x+1,y-1)) != state.end())
            {
                // stuck
                state.insert(make_pair(x,y));
                newstate[state] = newstate[state] + p;
            }
            else
            {
                //slides
                simulate(state, p, x+1, y-1, newstate);
            }
        }
        else if(state.find(make_pair(x+1,y-1)) != state.end())
        {
            //slides
            simulate(state, p, x-1, y-1, newstate);
        }
        else if(state.find(make_pair(x, y-2)) != state.end())
        {
            //choice
            Prob half(1,2);
            simulate(state, half*p, x-1, y-1, newstate);
            simulate(state, half*p, x+1, y-1, newstate);
        }
        else
        {
            //falls
            simulate(state, p, x, y-1, newstate);
        }
    }
}

void doCase()
{
    int N;
    cin >> N;
    int X;
    int Y;
    cin >> X >> Y;

    // Find biggest odd triangular number less than N

    int base = 1;

    while( ((base+3)*(base+2))/2 <= N)
        base += 2;

    int start = ((base+1)*base)/2;
    DiamondState startstate;
    int startx = 0;
    for(int h=base-1; h>=0; h--)
    {
        int numdiamonds = base-h;
        for(int i=0; i<numdiamonds; i++)
            startstate.insert(make_pair(startx+2*i, h));
        assert(startx+2*(numdiamonds-1) == -startx);
        startx--;
    }

    SimState probs;
    probs[startstate] = Prob(1,1);

    // simulate the rest
    for(int i = start; i<N; i++)
    {
        SimState newprobs;

        for(SimState::iterator it = probs.begin(); it != probs.end(); ++it)
        {
            int top = 0;
            for(DiamondState::iterator dit = it->first.begin(); dit != it->first.end(); ++dit)
            {
                top = max(top, dit->second);
            }
            simulate(it->first, it->second, 0, top+2, newprobs);
        }

        probs = newprobs;
        /*for(SimState::iterator it = probs.begin(); it != probs.end(); ++it)
        {
            cout << it->second.num << "/" << it->second.denom << ":" << endl;
            for(DiamondState::iterator dit = it->first.begin(); dit != it->first.end(); ++dit)
            {
                cout << "D " << dit->first << " " << dit->second << endl;
            }
        }
        cout << endl;*/
    }

    Prob targetprob;
    for(SimState::iterator it = probs.begin(); it != probs.end(); ++it)
    {
        if(it->first.find(make_pair(X,Y)) != it->first.end())
        {
            targetprob = targetprob + it->second;
        }
    }
    double prob = double(targetprob.num)/double(targetprob.denom);
    cout << prob << endl;
}


int main()
{
    int sets;
    cin >> sets;
    for(int i=0; i<sets; i++)
    {
        cout << "Case #" << i+1 << ": ";
        doCase();
    }
}


