#include<iostream>
#include<fstream>

using namespace std;

int solve(int a, int b, int c)
{
    int res = 0;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; j++) 
            if ((i&j) < c) 
                ++res;
    return res;
}

int main()
{
    int t;
    ifstream in("input");
    ofstream out("output");
    in >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c;
        in >> a >> b >> c;
        out << "Case #" << i + 1 << ": " << solve(a, b, c) << endl;
    }
    in.close();
    out.close();
}


