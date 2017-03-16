#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int minlevels(int stars, int beg, const vector<int>& a, const vector<int>& b, vector<int>& complete, int current, int& best)
{
    bool done = true;
    if(current+a.size()-beg>best)
    {
        return 999999;
    }

    for(int i=beg; i<a.size(); ++i)
    {
        if(complete[i]!=2)
        {
            done = false;
            beg = i;
            break;
        }
    }
    if(done)
    {
        best = min(current, best);
        return 0;
    }
            
    int ml = 99999999;
    for(int i=beg; i<a.size(); ++i)
    {
        if(complete[i]==0 && stars>=b[i])
        {
            complete[i] = 2;
            int levels = minlevels(stars+2, beg, a, b, complete, current+1, best) + 1;
            ml = min(levels, ml);
            complete[i] = 0;
        }
        if(complete[i]==1 && stars>=b[i])
        {
            complete[i] = 2;
            int levels = minlevels(stars+1, beg, a, b, complete, current+1, best) + 1;
            ml = min(levels, ml);
            complete[i] = 1;
        }
        if(complete[i]==0 && stars>=a[i])
        {
            complete[i] = 1;
            int levels = minlevels(stars+1, beg, a, b, complete, current+1, best) + 1;
            ml = min(levels, ml);
            complete[i] = 0;
        }
    }
    return ml;
}

int main(int argc, char* argv[])
{
    ifstream infile;
    ofstream outfile;
    
//    infile.open( "/Users/Guy/Downloads/C-small-attempt0.in");
    infile.open( "/Users/Guy/Downloads/B-small-attempt3.in");
//    infile.open( "/Users/Guy/Downloads/A-small-attempt2.in");
//    infile.open( "/Users/Guy/Downloads/C-large.in");
//    infile.open( "/gcjam/input.txt");
//    infile.open( "/Users/Guy/Downloads/A-large.in");
    outfile.open( "/gcjam/output.txt");

    int ntestcases;
    infile >> ntestcases;
    infile.ignore(1, '\n');

    for(int i=0; i<ntestcases; ++i)
    {
        int N;
        infile >> N;

        vector<int> a, b, completed;
        for(int j=0; j<N; ++j)
        {
            int ai, bi;
            infile >> ai;
            infile >> bi;
            a.push_back(ai);
            b.push_back(bi);
            completed.push_back(0);
        }
        int best = 9999999999;
        int ml = minlevels(0, 0, a, b, completed, 0, best);
        if(ml < 100000)
        {
            outfile << "Case #" << i+1 << ": " << ml << endl;
            cout << "Case #" << i+1 << ": " << ml << endl;
        }
        else
        {
            outfile << "Case #" << i+1 << ": Too Bad" << endl;
            cout << "Case #" << i+1 << ": Too Bad" << endl;
        }
    }
	return 0;
}