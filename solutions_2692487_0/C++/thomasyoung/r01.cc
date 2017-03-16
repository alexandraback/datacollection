#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#define NMAX 100

static unsigned int mylog2 (unsigned int val) {
    unsigned int ret = -1;
    while (val != 0) {
        val >>= 1;
        ret++;
    }
    return ret;
}

int numMoteAndVal(int start, int end, int &nmotes, int &val)
{
    if (start>end)
    {
        nmotes = 0;
        val = start + end;
        return 0;
    }
    nmotes = mylog2(static_cast<unsigned int>(end/start));
    val = start * (1<<nmotes) - (1<<nmotes) + 1;
    while ( val  <= end )
    {
        nmotes ++;
        val = start * (1<<nmotes) - (1<<nmotes) + 1;
    }
    return nmotes;
}

int minEffort(std::vector<int> &motes, int curidx, int curval)
{
    int N = motes.size(), oidx = curidx;
    while ( (curval > motes[curidx]) && (curidx < N) )
    {
        curval += motes[curidx];
        curidx ++;
    }
    int todel = motes.size() - curidx;

    if (todel == 0) 
    {
        return 0;
    }
    else
    {
        if ( (oidx == curidx) && (curval == 1) ) return todel;
        int toadd, valadd;
        numMoteAndVal(curval, motes[curidx], toadd, valadd);
        return std::min( todel, toadd+minEffort(motes, curidx, valadd) );
    }
}


int main(int argc, char** argv) {
    if (argc<3) {
        printf("not enough parameters: %d\n", argc);
        return 0;
    }
    FILE *fp;
    printf("%s\n", argv[1]);

    if ( (fp = fopen( (const char*) argv[1], "r" )) == NULL ) {
        printf("Open Input File ERROR!\n"); 
        return 0;
    }

    std::ofstream ofs(argv[2]);

    int ncases;
    fscanf(fp, "%d\n", &ncases);

    printf("#Cases: %d\n", ncases);
    if (ncases<=0) return -1;

    int A, N;
    std::vector<int> motes;
    motes.reserve(NMAX);

    for (auto i=0; i<ncases; ++i) 
    { 
        motes.clear();
        printf("Case #%d\n", i+1);
        fscanf(fp, "%d %d\n", &A, &N );
        printf("%d %d\n", A, N);

        int val;
        for (auto j=0; j<N; ++j) 
        {
            fscanf(fp, "%d ", &val );
            motes.push_back( val );
        }
        fscanf(fp, "\n");

        std::sort(motes.begin(), motes.end(), [](int x, int y){ return x<y;} );

        int sum = A, cnt = 0;

        for (auto v = motes.begin(); v != motes.end(); ++v )
        {
            printf("%d ", *v);
        }
        printf("\n");
        int effort = minEffort(motes, 0, A);
        printf("%d \n", effort);
//int minEffort(std::vector<int> &motes, int curidx, int curval)
        ofs<<"Case #"<<i+1<<": "<<effort<<std::endl;
    }


    ofs.close();

    fclose(fp);
}

