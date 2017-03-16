#include <iostream>
#include <fstream>

using namespace std;

int nbTour(int r, int c, int w)
{
    int tmp = 0;
    while(((tmp*w)+w) <= c)
        tmp ++;
    tmp *= r;
    tmp += w;
    if(c%w == 0)
        tmp -= 1;
    return tmp;
}

int main()
{
    ifstream input("input.txt", ios::in);
    ofstream output("output.txt", ios::out | ios::trunc);

    if(input && output)
    {
        int nbTest;

        input >> nbTest;

        cout << "nombre de tests : " << nbTest << endl;


        for(int i(0); i < nbTest; i++)
        {
            int r, c, w;

            input >> r;
            input >> c;
            input >> w;

            int res = nbTour(r, c, w);

            output << "Case #" << i+1 << ": " << res << endl;
        }
    }
    return 0;
}
