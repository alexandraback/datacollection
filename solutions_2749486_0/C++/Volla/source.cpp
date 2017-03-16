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

int main()
{
    S32 C, Z;

  cin >> Z;
//    fprintf(stderr, "Count: %I32u\n", Z);

    for (C = 1;C <= Z;C++)
    {
        S64 X, Y, count, x, y;
        vector<char> steps;

        //read x and y
        cin >> X >> Y;
        count = 1;
        x = 0;
        y = 0;
//        cout << "X="<< X <<" Y=" << Y << endl;
        //repeat until we get there
        //jump towards if it moves us closer, jump away if it moves us further
        while ((x != X) || (y != Y))
        {
            if (x != X)
            {
                if ((x + count) <= X)
                {
                    x += count;
                    count++;
                    steps.push_back('E');
//                    cout << 'E'<< x <<','<< y <<endl;
//                    continue;
                } else
                {
                    x  -= count;
                    count++;
                    steps.push_back('W');
//                    cout << 'W'<< x <<','<< y <<endl;

//                    continue;
                }
            }
            if (y != Y)
            {
                if ((y + count) <= Y)
                {
                    y += count;
                    count++;
                    steps.push_back('N');
//                    cout << 'N'<< x <<','<< y <<endl;

                } else
                {
                    y -= count;
                    count++;
                    steps.push_back('S');
//                    cout << 'S'<< x <<','<< y <<endl;

                }
            }

        }


//        cerr << endl;
        cout << "Case #" << C << ": " ;
        vector<char>::iterator it=steps.begin();
        while(it != steps.end())
        {
            cout << *it;
            it++;
        }

        cout << endl;
    }


    return 0;
}
