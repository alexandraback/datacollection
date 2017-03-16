#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fbe("A-small-attempt1.in");
    ofstream fki("ki.out");
    int t;
    fbe>>t;
    for (int i=0; i<t; i++)
    {
        int r,c,w;
        fbe>>r>>c>>w;
        fki<<"Case #"<<i+1<<": "<<(c-1)/w+w<<endl;
    }
    fbe.close();
    fki.close();

    return 0;
}
