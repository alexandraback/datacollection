#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

#define U8  uint8_t
#define U16 uint16_t
#define U32 uint32_t
#define U64 uint64_t

#define S8  int8_t
#define S16 int16_t
#define S32 int32_t
#define S64 int64_t

typedef struct
{
    S64 d, n, w, e, s, dd, dp, ds;
} tribe;

int main()
{
    S32 C, Z;

  cin >> Z;
//    fprintf(stderr, "Count: %I32u\n", Z);
    for (C = 1;C <= Z;C++)
    {
        U64 N;
        U64 ans = 0;
        S64 wall[500] = {0};
        tribe T[50];
        S64 totalattacks = 0, day = 0;


        cin >> N;

        for (U32 c = 0;c < N;c++)
        {
            cin >> T[c].d;
            cin >> T[c].n;
            cin >> T[c].w;
            cin >> T[c].e;
            cin >> T[c].s;
            cin >> T[c].dd;
            cin >> T[c].dp;
            cin >> T[c].ds;

            totalattacks += T[c].n;
        }

        //ok, now we go through the attacks
        while (totalattacks > 0)
        {
            //find the earliest attack
            U32 nextday = -1;//day is current day
            for (U32 c = 0;c < N;c++)
            {
                if ((T[c].d < nextday)&&(T[c].n != 0)) nextday = T[c].d;
            }

            //ok, now we know the day of attack
            for (U32 c = 0;c < N;c++)
            {
                U32 breach;
                if ((T[c].d == nextday)&&(T[c].n != 0))
                {
                    breach = 0;//start with no breaches
                    //this attack we should check
//                    cout << "wall:\n";
//                        for (int c = 0;c < 20;c++)
//                            cout << wall[100+c] << ',';
//                    cout << endl;
                    for (U32 q = T[c].w;q <= T[c].e;q++)
                    {
                        if (wall[100+q] < T[c].s) breach++;
                    }
                    //end of this tribe fighting, if it breached
                    if (breach > 0)
                    {
                        ans++;//add to answer
//                        cout << "day=" << nextday << endl;
                    }

                }//end of all this days fighting, now to build a wall
            }
            for (U32 c = 0;c < N;c++)
            {
                if ((T[c].d == nextday)&&(T[c].n != 0))
                {
                    //this attack we should check and build wall
                    for (U32 q = T[c].w;q <= T[c].e;q++)
                    {
                        if (wall[100+q] < T[c].s) wall[100+q] = T[c].s;
                    }
                    //remove from attack counter
                    totalattacks--;
                    //and update this tribes stuff
                    if (T[c].n == 1) //end of fighting
                    {
                        T[c].n = 0;
                    } else
                    {
                        T[c].n--;
                        T[c].d += T[c].dd;
                        T[c].s += T[c].ds;
                        T[c].w += T[c].dp;
                        T[c].e += T[c].dp;
                    }
                }
            }
        }



        cout << "Case #" << C << ": " << ans << endl;
    }


    return 0;
}
