#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MoteState
{
    int size;
    int ops;
};

void doCase()
{
    int A;
    cin >> A;
    int N;
    cin >> N;
    vector<int> sizes;
    for(int i=0; i<N; i++)
    {
        int size;
        cin >> size;
        sizes.push_back(size);
    }
    sort(sizes.begin(), sizes.end());

    MoteState start = {A, 0};
    vector<MoteState> cands;
    cands.push_back(start);
    for(int ind=0; ind < N; ind++)
    {
        vector<MoteState> newcands;
        int nextsize = sizes[ind];

        for(int i=0; i<(int)cands.size(); i++)
        {
            MoteState curstate = cands[i];
            if(nextsize < curstate.size)
            {
                curstate.size += nextsize;
                newcands.push_back(curstate);
            }
            else
            {
                // two options: delete
                MoteState deletestate = curstate;
                deletestate.ops++;
                newcands.push_back(deletestate);

                // or absorb
                if(curstate.size > 1)
                {
                    MoteState absorbstate = curstate;
                    while(absorbstate.size <= nextsize)
                    {
                        absorbstate.size += absorbstate.size-1;
                        absorbstate.ops++;
                    }
                    absorbstate.size += nextsize;
                    newcands.push_back(absorbstate);
                }
            }
        }
        cands = newcands;
    }
    int bestop = std::numeric_limits<int>::max();
    for(int i=0; i<(int)cands.size(); i++)
        bestop = std::min(bestop, cands[i].ops);
    std::cout << bestop << std::endl;
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


