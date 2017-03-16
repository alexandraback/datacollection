#include <iostream>
#include <string>
using namespace std;

int*Narr;
int E, R, N;
int maxG;
void goNext(int i, int gain, int cE)
{
    if(i>=N)
    {
        if(maxG<0 || maxG<gain)
        {
            maxG = gain;
        }
        return;
    }
    int cGain = 0;
    for(int j=cE; j>=0; --j)
    {
        cGain = gain + Narr[i]*j;
        int nCE = cE-j+R;
        if(nCE>E) nCE = E;
        goNext(i+1, cGain, nCE);
    }
    //cGain = gain + Narr[i]*cE;
    //goNext(i+1, cGain, R);

    //if(cE>(E-R))
    //{
    //    cGain = gain + Narr[i]*(cE-(E-R));
    //    goNext(i+1, cGain, E);
    //}

    //cGain = gain;
    //int nextCE = cE+R;
    //if(cE+R>E)
    //{
    //    nextCE = E;
    //}
    //goNext(i+1, cGain, nextCE);
}
void main()
{

    int T;
    cin >> T;
    for(int C=0; C<T; ++C)
    {
        cin >> E >> R >> N;
        Narr = new int[N];
        for(int pn = 0; pn<N; ++pn)
        {
            int ni;
            cin >> Narr[pn];
        }
        maxG = -1;
        goNext(0, 0, E);

        delete[] Narr;        
        printf("Case #%d: %d\n", C+1, maxG);
    }

}