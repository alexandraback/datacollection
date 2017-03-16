//Christopher Mueller
//Made for Google Code Jam 2012

#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Level
{
    int earned;
    int first;
    int second;

    Level()
    : earned(0), first(0), second(0)
    {}

    Level(int e, int f, int s)
    : earned(e), first(f), second(s)
    {}
};

//str initially contains the line of input for the test case.
//When the function returns, str must contain the output line for that case.
string solve(istream& infile)
{
    int N;
    infile >> N;

    vector <Level> v(N);
    for(int i = 0; i < N; ++i)
    {
        int a, b;
        infile >> a >>b;
        v[i] = Level(0, a, b);
    }

    int stars = 0;
    int moves = 0;
    while(!v.empty())
    {
        ++moves;

        vector <Level>::iterator hardest;
        int hardestDifficulty = -1;

        for(vector<Level>::iterator it = v.begin(); it != v.end(); ++it)
        {
            if(it->earned == 0 && stars >= it->second)
            {
                stars += 2;
                v.erase(it);
                goto while_end;
            }
        }

        for(vector<Level>::iterator it = v.begin(); it != v.end(); ++it)
        {
            if(it->earned == 1 && stars >= it->second)
            {
                stars += 1;
                v.erase(it);
                goto while_end;
            }
        }

        for(vector<Level>::iterator it = v.begin(); it != v.end(); ++it)
        {
            if(it->earned == 0 && stars >= it->first && it->second > hardestDifficulty)
            {
                hardest = it;
                hardestDifficulty = it->second;
            }
        }

        if(hardestDifficulty == -1)
        {
            return "Too Bad";
        }

        stars += 1;
        hardest->earned = 1;
        //v.erase(hardest);

        while_end:
        ;
    }

    stringstream ss;
    ss << moves;
    return ss.str();
}

int main()
{
    string str;

    ifstream infile("B-small-attempt0.in");
    int T;
    infile >> T;
    getline(infile, str);

    ofstream outfile("output.txt");
    for(int i = 0; i < T; ++i)
    {
        outfile << "Case #" << i + 1 << ": ";

        str = solve(infile);

        outfile << str << endl;
    }

    return 0;
}
