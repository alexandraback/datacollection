#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

class problem
{
public:
    void read(FILE* inf);
    string solve();
private:
    int x;
    int r;
    int c;
};

void problem::read(FILE* inf)
{
    /*
    scanf("%d", &x);
    scanf("%d", &r);
    scanf("%d", &c);
    */
    fscanf(inf, "%d", &x);
    fscanf(inf, "%d", &r);
    fscanf(inf, "%d", &c);

}

string problem::solve()
{
    bool ri = false;
    int ma = max(r,c);
    int mi = min(r,c);
    /*
    if (((r * c) % x != 0) || (x > r && x > c) || ((x + 1) / 2 > r ) || ((x + 1) / 2 > c ) || (x >= 7))
    {
        ri = true;
    }
    */
    if ((r * c) % x != 0)
    {
        ri = true;
    } else
    {
        ri = (ma < x) || (mi < ((x + 1) / 2));
    }
    // 2,3 are solved by these
    if (x == 4)
    {
        ri = ri || (mi == 2);    //block 121 doesn't fit into n * 2
    }
    if (x == 5)
    {
        ri = ri || (mi == 3 && ma == 5);   // block 12-2 doesn't fit into 5 * 3, but it does into 10 * 3
        // something something relative primes
    }
    if (x == 6)
    {
        // block -22-2 doesn't fit n * 3
        ri = ri || (mi == 3);
    }
    if (x >= 7)
    {
        ri = true;
    }
    return ri? "RICHARD" : "GABRIEL";
}

int main()
{
    int t;
    FILE* infile = fopen("D-small-attempt0.in", "r");
    //scanf("%d", &t);
    fscanf(infile, "%i", &t);
    ofstream outfile("out.txt");
    for (int i = 0; i < t; ++i)
    {
        problem p;
        p.read(infile);
        cout << "Case #" << i + 1 << ": " << p.solve() << endl;
        outfile << "Case #" << i + 1 << ": " << p.solve() << endl;
    }
    fclose(infile);
    outfile.close();
    return 0;
}
