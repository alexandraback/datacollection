#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    fstream input;
    int n;
    input.open(argv[1], fstream::in);
    input >> n;
    list<double> n_blocks, n_tmp, k_blocks, k_tmp;
    for(int i = 1; i<=n; i++)
    {   
        int nb, nscore = 0, dscore = 0;
        cout << "Case #" << i << ": ";
        input >> nb;
        n_blocks.clear();
        k_blocks.clear();
        for(int j = 0; j<nb; j++)
        {
            double d;
            input >> d;
            n_blocks.push_back(d);
        }
        for(int j = 0; j<nb; j++)
        {
            double d;
            input >> d;
            k_blocks.push_back(d);
        }
        n_tmp = list<double>(n_blocks);
        k_tmp = list<double>(k_blocks);
        n_tmp.sort(greater<double>());
        k_tmp.sort(greater<double>());
        // compute normal score
        while(n_tmp.empty() == false)
        {
            if(n_tmp.front() > k_tmp.front())
            {
                nscore++;
                k_tmp.pop_back();
                n_tmp.pop_front();
            }
            else
            {
                k_tmp.pop_front();
                n_tmp.pop_front();
            }
        }
        n_tmp = list<double>(n_blocks);
        k_tmp = list<double>(k_blocks);
        n_tmp.sort();
        k_tmp.sort();
        while(n_tmp.empty() == false)
        {
            if(n_tmp.front() > k_tmp.front())
            {
                dscore++;
                k_tmp.pop_front();
                n_tmp.pop_front();
            }
            else
            {
                k_tmp.pop_back();
                n_tmp.pop_front();
            }
        }
        cout << dscore << " " << nscore << endl;
    }
}
