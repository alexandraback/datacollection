#include <stdio.h>
#include <stdint.h>
#include <math.h>
//#include <string.h>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define U8  uint8_t
#define U16 uint16_t
#define U32 uint32_t
#define U64 uint64_t

#define S8  int8_t
#define S16 int16_t
#define S32 int32_t
#define S64 int64_t


bool isconst(char c)
{
    bool ans = true;
    if (c == 'a') ans = false;
    if (c == 'e') ans = false;
    if (c == 'i') ans = false;
    if (c == 'o') ans = false;
    if (c == 'u') ans = false;

    return ans;
}


int main()
{
    S32 C, Z;

  cin >> Z;
//    fprintf(stderr, "Count: %I32u\n", Z);
    for (C = 1;C <= Z;C++)
    {
        U32 N;
        string NAME;
        U32 count;
        U32 a, b;

        cin >> NAME >> N;
        count = 0;

        //now we start at 0 - n, and increase n till end and check if it is good name
        a = 0;
        b = 1;
//        cout << NAME.size() << ":" << NAME << endl;
        while (a  <= NAME.size())
        {
//            cout << "a=" << a << ":";
            b = a+1;
            while (b  <= NAME.size())
            {
                //now we loop from begin to end
                //count the consecutive constants
                U32 consonant = 0;
                for (U32 q = 0;(a+q) < b;q++)
                {
                    if (isconst(NAME.c_str()[a+q]))
                    {
//                        cout << "a=" << a << ":b=" << b << ":" << NAME.c_str()[a+q] << endl;
                        consonant++;
                        if (consonant >= N)
                        {
                            count++;
//                            cout << "*\n";
                            break;
                        }
                    } else consonant = 0;
                }
                b++;
            }
            a++;
        }


        cout << "Case #" << C << ": " << count << endl;
    }


    return 0;
}
