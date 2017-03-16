#include <iostream>
#include <string>

using namespace std;

static const short C1 = 1;
static const short CI = 2;
static const short CJ = 3;
static const short CK = 4;

short code(char a)
{
    switch (a)
    {
        case 'i': return CI;
        case 'j': return CJ;
        case 'k': return CK;
    }
    return 0; // error
}

short mult_codes(short c1, short c2) // c2 * c2
{
    static short tab[5][5] =
    {
        { 0, 0, 0, 0, 0  },
        { 0, 1, 2, 3, 4  },
        { 0, 2, -1, 4, -3 },
        { 0, 3, -4, -1, 2 },
        { 0, 4, 3, -2, -1 },
    };

    short c1sign = c1 < 0 ? -1 : 1;
    short c2sign = c2 < 0 ? -1 : 1;
    return tab[abs(c1)][abs(c2)] * c1sign * c2sign;
}

//short divide_codes(short c1, short c2) // c1 * x = c2 => x = c2/c1
//{
//    if (abs(c1) == C1) return mult_codes(c1, c2);
//    return -mult_codes(c1, c2);
//}

int main()
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int64_t L;
        int64_t X;
        string str;
        cin >> L >> X;
        cin >> str;

        short bucket_mult = 1;
        for (int64_t i = 0; i < L; ++i)
        {
            bucket_mult = mult_codes(bucket_mult, code(str[i]));
        }
        //cout << "bucket_mult=" << bucket_mult << endl;

        // bucket_mult^2 = +-1
        // bucket_mult^4 = 1
        // so exclude unnecessary number of buckets that is multiple of 12 (for 3 slices)
        if (X > 12)
        {
            X = X%12 + 12;
        }
        //cout << "X=" << X << endl;

        short total_mult = 1;
        for (int64_t i = 0; i < X; ++i)
        {
            total_mult = mult_codes(total_mult, bucket_mult);
        }
        //cout << "total_mult=" << total_mult << endl;

        if (total_mult != -1) // eventually i*j*k should be -1
        {
            cout << "Case #" << t << ": NO" <<  endl;
            continue;
        }

        bool found_i = false;
        bool found_j = false; // actually k since i*j=k
        total_mult = 1;
        for (int64_t i = 0; i < X*L; ++i)
        {
            total_mult = mult_codes(total_mult, code(str[i%L]));
            if (total_mult == CI)
            {
                //cout << "i=" << i << endl;
                found_i = true;
            }
            if (found_i && total_mult == CK) // we found j as soon as total_mult == CK since i*j=k
            {
                //cout << "j=" << i << endl;
                found_j = true;
                break;
            }
        }

        if (found_i && found_j)
        {
            cout << "Case #" << t << ": YES" <<  endl;
        }
        else
        {
            cout << "Case #" << t << ": NO" <<  endl;
        }
    }

    return 0;
}
