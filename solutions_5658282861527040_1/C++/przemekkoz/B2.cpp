//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
typedef long long LL;
const int W = 31;

void dodaj(const LL PREF[4], char A, char B, char znak, LL ret[4]);

int t;
LL Ar,Br,Kr;
LL Z[2][W+7], K[W+7];
LL ZP[2][W+7];
LL PREF[W+7][4];
LL TMP[4];

int main()
{
    scanf("%d", &t);
    for(int ti = 1;ti <= t;ti++)
    {
        scanf("%lld%lld%lld", &Ar, &Br, &Kr);
        Kr--;Ar--;Br--;
        for(int i = 1;i <= W;i++)
        {
            Z[0][i] = ( (Ar&(1<<(W-i))) ? 1 : 0);
            Z[1][i] = ( (Br&(1<<(W-i))) ? 1 : 0);
            K[i] =    ( (Kr&(1<<(W-i))) ? 1 : 0);
        }
        for(int i = W;i >= 1;i--)
            for(int j = 0;j <= 1;j++)
                ZP[j][i] = ZP[j][i+1]+(1<<(W-i))*(int)Z[j][i];

        /*for(int j = 0;j <= 1;j++)
        {
            cerr << "Z J: " << j << " : " << endl;
            for(int i = 1;i <= W;i++)
                cerr << (int)Z[j][i];
            cerr << endl;
        }

        cerr << "K : " << endl;
        for(int i = 1;i <= W;i++)
            cerr << (int)K[i];
        cerr << endl;*/

        PREF[0][0] = PREF[0][1] = PREF[0][2] = 0;
        PREF[0][3] = 1;
        for(int i = 1;i <= W;i++)
        {
            dodaj(PREF[i-1], Z[0][i], Z[1][i], K[i], PREF[i]);
            //cerr << "I: " << i << " PREF[i]: " << PREF[i][0] << " " << PREF[i][1] << " " << PREF[i][2] << " " << PREF[i][3] << endl;
        }

        //cerr << "B" << endl;
        LL wyn = (LL)(Ar+1)*(Br+1);
        //cerr << Ar << " " << Kr << " " << Br << endl;
        if(Kr < Ar && Kr < Br)
        {
            //cerr << "A" << endl;
            for(int i = 1;i <= W;i++)
                if(K[i] == 0)
                {
                    dodaj(PREF[i-1], Z[0][i], Z[1][i], 1, TMP);
                    LL twyn = 0;
                    twyn += TMP[0]*(1<<(W-i))*(1LL<<(W-i));
                    twyn += TMP[1]*(ZP[1][i+1]+1)*(1LL<<(W-i));
                    twyn += TMP[2]*(ZP[0][i+1]+1)*(1LL<<(W-i));
                    twyn += TMP[3]*(ZP[0][i+1]+1)*(ZP[1][i+1]+1);
                    //cerr << "(W-i): " << (W-i) << " twyn: " << twyn << endl;
                    wyn -= twyn;
                }
        }

        printf("Case #%d: %lld\n", ti, wyn);
    }
    return 0;
}


void dodaj(const LL PREF[4], char Az, char Bz, char znak, LL ret[4])
{
    ret[0] = ret[1] = ret[2] = ret[3] = 0;
    if(znak == 1) // Nowe muszą być jedynkami
    {
        // Jeśli oba nie były maksymalne
        ret[0] += PREF[0];
        // Jeśli tylko A był maksem
        if(Az == 1) ret[2] += PREF[2];
        // Jeśli tylko B był maksem
        if(Bz == 1) ret[1] += PREF[1];
        // Jeśli oba były maksami
        if(Az == 1 && Bz == 1) ret[3] += PREF[3];
    }
    else
    {
        // Jeśli oba nie były maksymalne
        ret[0] += PREF[0]*3LL;
        // Jeśli tylko A był maksem
        {
            // (0, cos)
            if(Az == 1) ret[0] += PREF[2]*2;
            else ret[2] += PREF[2]*2;
            // (1, 0)
            if(Az == 1) ret[2] += PREF[2];
        }
        // Jeśli tylko B był maksem
        {
            // (cos, 0)
            if(Bz == 1) ret[0] += PREF[1]*2;
            else ret[1] += PREF[1]*2;
            // (0, 1)
            if(Bz == 1) ret[1] += PREF[1];
        }
        // Jeśli oba były maksami
        {
            // (0, 0)
            if(Az == 1 && Bz == 1) ret[0] += PREF[3];
            if(Az == 1 && Bz == 0) ret[1] += PREF[3];
            if(Az == 0 && Bz == 1) ret[2] += PREF[3];
            if(Az == 0 && Bz == 0) ret[3] += PREF[3];
            // (0, 1)
            if(Az == 1 && Bz == 1) ret[1] += PREF[3];
            if(Az == 0 && Bz == 1) ret[3] += PREF[3];
            // (1, 0)
            if(Az == 1 && Bz == 1) ret[2] += PREF[3];
            if(Az == 1 && Bz == 0) ret[3] += PREF[3];
            // (1, 1)
            //if(Az == 1 && Bz == 1) ret[3] += PREF[3];
        }
    }
}
