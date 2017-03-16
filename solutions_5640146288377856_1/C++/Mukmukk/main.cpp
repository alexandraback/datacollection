#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fbe("A-large.in");
    ofstream fki("ki.txt");
    int t;
    fbe>>t;
    for (int i=0; i<t; i++)
    {
        int r,c,w;
        fbe>>r>>c>>w;
        fki<<"Case #"<<i+1<<": "<<c/w*(r-1)+(c-1)/w+w<<endl;
    }
    fbe.close();
    fki.close();

    return 0;
}
