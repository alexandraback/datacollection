#include<iostream>

using namespace std;

int main()
{
    int Ntests, testnum;
    long double P[100005], Pok;
    long double Answer, tmpAnswer;
    cin >> Ntests;
    int A, B, i, q;
    for(testnum = 1; testnum <= Ntests; ++testnum)
    {
        cin >> A >> B;
        for (i = 0; i < A; ++i)
            cin >> P[i];
        Pok = 1;
        for(i = 0; i < A; ++i)
            Pok *= P[i];
        Answer = (B - A + 1) + (1 - Pok) * (B + 1);
        for(q = 1; q < A; ++q)
        {
            // Erase q characters strategy
            // Live along A - q characters
            Pok = 1;
            for (i = 0; i < A - q; ++i)
                Pok *= P[i];
            tmpAnswer = (B - A + 1 + 2 * q) + (1 - Pok) * (B + 1);
            if (tmpAnswer < Answer)
                Answer = tmpAnswer;
        }
        if (Answer > B + 2)
            Answer = B + 2;
        cout.precision(20);
        cout << "Case #" << testnum << ": " << Answer << endl;
    }
    return 0;
}
