#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

using namespace std;

class problem
{
public:
    static void init();
    void read(FILE* inf);
    int solve();
private:
    int d;
    vector<int> p;
    int ma;

    static vector<int> s;   // number of splits for optimal result for i-th
    static vector<int> m;   // maximum after splits for optimal result for i-th
    // total price for a single stack: s[i] + m[i]
    // total price: sum(s[size[i]]) + max(m[size[i]])   where size[] is the size of the individual stacks
};

vector<int> problem::s;
vector<int> problem::m;

void problem::init()
{
    //static vector<int> s;
    //static vector<int> m;
    s.resize(1001);
    m.resize(1001);
    for (int i = 1; i < 1001; ++i)
    {
        int mi = i;
        for (int j = 1; j < i; ++j)
        {
            mi = min(mi, (j+ (i - 1) / j));
            int tot = j + (i - 1) / j;
            if (tot < mi)
            {
                mi = tot;
            }
        }
        if (i < 35)
        {
            cout << "i:\t" << i << "\t" << mi << endl;
        }
    }
}

void problem::read(FILE* inf)
{
    //scanf("%d",&d);
    fscanf(inf, "%d",&d);
    p.resize(d);
    ma = 0;
    for (int i = 0; i < d; ++i)
    {
        //scanf("%d", &(p[i]));
        fscanf(inf, "%d",&p[i]);
        cout << p[i] << " ";
        ma = max(ma, p[i]);
    }
    cout << "\tmax: " << ma << endl;
}

int problem::solve()
{
    // looking for a split (addition) of all numbers where the total number of splits + the highest number afterwards is minimal
    int mi = ma;
    for (int j = 1; j < ma; ++j)
    {
        int tot = 0;
        for (int i = 0; i < d; ++i)
        {
            tot += (p[i] - 1) / j;
            //cout << tot << "\t";
        }
        tot = tot + j;
        //cout << endl;
        mi = min(mi, tot);
    }
    return mi;    // worst case scenario
}

int main()
{
    //problem::init();

    FILE* infile = fopen("B-small-attempt1.in","r");
    int t;
    //scanf("%d", &t);
    fscanf(infile, "%d", &t);
    ofstream outf("out.txt");
    for (int i = 0; i < t; ++i)
    {
        problem p;
        p.read(infile);
        int s = p.solve();
        cout << "Case #" << i + 1 << ": " << s << endl;
        outf << "Case #" << i + 1 << ": " << s << endl;
    }
    fclose(infile);
    outf.close();
    return 0;
}
