#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

int N;
vector <vector<int> > M;
vector <int>  Hash;


bool Next(int n)
{
    for(int j=0;j<10;j++)
    {
        int NextPoint = M[n][j];
        if(NextPoint==0) return false;
        if(Hash[NextPoint]!=0) return true;
        Hash[NextPoint]=1;
        if(Next(NextPoint)) return true;
    }
    return false;
}

int main()
{

    ifstream is;
    ofstream rs;
    FILE *pfile = NULL;
    is.open("../../../../Downloads/A-large.in");
    //pfile = fopen("./res.out", "w");
    rs.open("./res.out");
    int num_of_test;
    is >>  num_of_test;
    for(int n_t=0; n_t<num_of_test; n_t++)
    {
        bool res;
        is >> N;
        M=vector <vector<int> > (N+1, vector<int>(10, 0));

        for(int i=1;i<=N;i++)
        {
            int num;
            is >> num;
            for(int j=0;j<num;j++)
                is >> M[i][j];
        }

        for(int i=1;i<=N;i++)
        {
            Hash=vector <int>  (N+1, 0);
            res = Next(i);
            if(res)break;
        }

        //fprintf(pfile,"Case #%d: %.6f\n",n_t+1, A);
        if(res)
            rs << "Case #" << n_t+1 << ": Yes" << endl;
        else
            rs << "Case #" << n_t+1 << ": No" << endl;
    }
    return 0;
}


