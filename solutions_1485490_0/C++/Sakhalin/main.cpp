#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

vector <vector<int64_t> > A, B;
int64_t N, M;
ifstream is;
ofstream rs;

int64_t Go(int64_t Sn, int64_t Sm, int64_t minusA,  int64_t minusB)
{
int64_t res=0;
    if(A[Sn][1]==B[Sm][1])
    {
        if( (A[Sn][0]-minusA)<(B[Sm][0]-minusB) )
        {
            res = A[Sn][0]-minusA;
            minusB=A[Sn][0]-minusA;
            minusA=0;
            Sn=Sn+1;
            if(Sn<N) res=res+ Go(Sn, Sm, minusA, minusB);
        }
        else if( (A[Sn][0]-minusA)>(B[Sm][0]-minusB) )
        {
            res = B[Sm][0]-minusB;
            minusA=B[Sm][0]-minusB;
            minusB=0;
            Sm=Sm+1;
            if(Sm<M) res=res+ Go(Sn, Sm, minusA, minusB);
        }
        else
        {
            res = B[Sm][0]-minusB;
            minusA=0;
            minusB=0;
            Sm=Sm+1;
            Sn=Sn+1;
            if((Sn<N)&&(Sm<M)) res=res+ Go(Sn, Sm, minusA, minusB);
        }
    }
    else
    {
        int64_t res1, res2;
        if (Sn<N-1) res1 = Go(Sn+1, Sm, 0, minusB); else res1=0;
        if (Sm<M-1) res2 = Go(Sn, Sm+1, minusA, 0); else res2=0;
        if(res1>res2) res = res+res1;  else res = res+res2;
    }
    //rs << Sn << " " << Sm << " " << res << endl;
    return res;
}

int main()
{

    FILE *pfile = NULL;
    is.open("../../../../Downloads/C-small-attempt1.in");
    //pfile = fopen("./res.out", "w");
    rs.open("./res.out");
    int num_of_test;
    is >>  num_of_test;
    for(int n_t=0; n_t<num_of_test; n_t++)
    {
        is >> N >> M;
        A=vector <vector<int64_t> > (N, vector<int64_t>(2, 0));
        B=vector <vector<int64_t> > (M, vector<int64_t>(2, 0));

        for(int64_t i=0; i<N; i++)
        {
            int64_t num, type;
            is >> A[i][0] >> A[i][1];
        }
        for(int64_t i=0; i<M; i++)
        {
            int64_t num, type;
            is >> B[i][0] >> B[i][1];
        }
        int64_t res = Go(0, 0, 0, 0);
        //fprintf(pfile,"Case #%d: %.6f\n",n_t+1, A);
        rs << "Case #" << n_t+1 << ": " << res << endl;
    }
    return 0;
}


