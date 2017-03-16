#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
    ifstream f("AS.in");
    ofstream of("AS.out");
    int T;
    f >> T;
    int TT = T;
    while(T--)
    {
        of<<"Case #"<<TT - T <<": ";

        int n;
        f >> n;

        n++;

        vector<vector<bool> > ih(n, vector<bool>(n, false));

        vector<vector<bool> > aj(n, vector<bool>(n, false));

        for(int i = 1; i < n; ++i)
        {
            int m;

            f >> m;

            for(int k = 0; k < m; ++k)
            {
                int j;
                f >> j;
                ih[i][j] = true;
                aj[i][j] = true;
            }
        }

        // F something
        for(int k = 1; k < n; ++k)
        for(int i = 1; i < n; ++i)
        {

            for(int j = 1; j < n; ++j)
            {


                    if(aj[i][k] && aj[k][j])
                    {
                        aj[i][j] = true;
                    }

            }
        }

        for(int i = 1; i < n; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                int count = 0;
                if(ih[i][j]) count++;

                for(int k = 1; k < n; ++k)
                {

                    if(k != i && ih[k][j] && aj[i][k])
                    {
                        count++;
                        if( count == 2)
                        {
                            of <<"Yes"<<endl;
                           // cout <<TT - T <<" "<< i<<" "<<j;
                            goto Yes;
                        }

                    }

                }
            }
        }

        of <<"No"<<endl;

        Yes: cout<<endl<<endl;
    }

    f.close();
    of.close();
    return 0;
}
