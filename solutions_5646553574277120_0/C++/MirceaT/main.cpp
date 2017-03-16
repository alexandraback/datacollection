#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int viz[1000];

int main()
{
    ifstream f ("input.txt");
    ofstream g ("output.txt");
    int nr_tests;
    f >> nr_tests;
    for (int test = 1; test <= nr_tests; ++ test)
    {
        //cout << test << " ";
        int C, D, V;
        f >> C >> D >> V;
        int nr = 0;
        memset(viz, 0, sizeof(viz));
        viz[0] = 1;
        int pas = 2;
        for (int i = 1; i <= D; ++ i)
        {
            int x;
            f >> x;
            for (int j = 0; j + x <= V; ++ j)
            {
                if (viz[j] != pas && viz[j] != 0 && viz[j + x] == 0)
                {
                    ++nr;
                    viz[j+x] = pas;
                }
            }
            ++ pas;
        }
        int ret = 0;

        while (nr < V)
        {
            for (int i = 0; i <= V; ++ i)
            {
                if (viz[i] == 0)
                {
                    ++ ret;
                    ++ pas;
                    int x = i;
                    for (int j = 0; j + x <= V; ++ j)
                    {
                        if (viz[j] != pas && viz[j] != 0 && viz[j + x] == 0)
                        {
                            ++ nr;
                            viz[j+x] = pas;
                        }
                    }
                }
            }
        }
        g << "Case #" << test << ": " << ret << "\n";
    }
    f.close();
    g.close();
    return 0;
}
