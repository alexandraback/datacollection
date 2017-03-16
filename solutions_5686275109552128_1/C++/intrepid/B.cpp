//
//  B.cpp
//  codejam2015
//  zintrepid
//
#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

#if defined(CJ_INDIRECT_COMPILE)
#  define ENTRY_POINT B
#else
#  define ENTRY_POINT main
#endif

#define CASE_LABEL(i) "Case #" << to_string(i) << ": "

struct Diner
{
    Diner(int num_cakes) : initial_cakes(num_cakes), num_splits(0), cur_value(num_cakes) {}
    
    void Split()
    {
        ++num_splits;
        cur_value = ( initial_cakes + num_splits ) / ( num_splits + 1 );
    }
    
    bool operator<(const Diner& other) const
    {
        return cur_value < other.cur_value;
    }
    
    int initial_cakes;
    int num_splits;
    int cur_value;
};

void make_move(vector<Diner>& p, vector<Diner>::iterator& max_it)
{
    max_it->Split();
}

int ENTRY_POINT(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int test_num = 1; test_num <= T; ++test_num)
    {
        int D;
        cin >> D;
        vector<Diner> p;
        for (int i=0; i<D; ++i)
        {
            int cakes;
            cin >> cakes;
            p.emplace_back(cakes);
        }
        vector<int> e;
        int cur_moves = 0;
        auto max_elem = max_element(p.begin(), p.end());
        e.push_back(max_elem->cur_value);
        while( max_elem->cur_value > 3 )
        {
            make_move(p, max_elem);
            ++cur_moves;
            max_elem = max_element(p.begin(), p.end());
            e.push_back(max_elem->cur_value + cur_moves);
            //cerr << "From " << (&e.back())[-1] << " to " << e.back() << "\n";
        }
        cout << CASE_LABEL(test_num) << *min_element(e.begin(), e.end()) << "\n";
    }
    return 0;
}
