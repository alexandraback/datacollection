using namespace std;
#include<iostream>

int B[9][9];

int func(int a, int b)
{
    if (a == 1) return b;
    if (b == 1) return a;
    if (a == 0 || b == 0) return 0;
    if (a < 0 || b < 0)
    {
        int aa = a, bb = b;
        if (a < 0) aa = -a;
        if (b < 0) bb = -b;
        return func(aa, bb) * (a == aa? 1 : -1) * (b == bb? 1 : -1);
    }
    if (a == b) return -1;
    if (a == 2 && b == 3) return 4;
    if (a == 3 && b == 4) return 2;
    if (a == 4 && b == 2) return 3;
    return -func(b, a);
}

void computeB()
{
    for(int i = 0; i <= 8; i++)
    {
        for(int j = 0; j <= 8; j++)
            //cout << " " << 
            (B[i][j] = func(i - 4, j - 4));
        //cout << endl;
    }
}

inline int ask(int a, int b)
{
    return B[a+4][b+4];
}

inline int trans(int s)
{
    return s - 'i' + 2;
}

void prod(int L, char* S, int* Z, int* A)
{
    Z[L] = 1;
    for (int i = L-1; i >= 0; i--)
        Z[i] =  ask(trans(S[i]), Z[i+1]);
    A[0] = 1;
    for (int i = 0; i < L; i++)
        A[i+1] =  ask(A[i], trans(S[i]));
}

int main()
{
    int T;
    char S[11000];
    int Z[11000];
    int A[11000];
    int PW[4];
    computeB();
    cin >> T;
    for (int tt = 1; tt <= T; tt++)
    {
        int L;
        long long X;
        cin >> L >> X;
        cin >> S;
        prod(L, S, Z, A);
        PW[0] = 1;
        PW[1] = Z[0];
        PW[2] = ask(Z[0], Z[0]);
        PW[3] = ask(Z[0], PW[2]);
        bool find = false;
        int first = 1;
        for (int i = 0; i < L && !find; i++)
        {
            int second = 1;
            int Pi[4];
            Pi[0] = 1; Pi[1] = ask(Z[i], A[i]);
            Pi[2] = ask(Pi[1], Pi[1]); Pi[3] = ask(Pi[1], Pi[2]);
//            for (int kk = 0; kk < 4; kk++)
//                cout << kk << ": " << Pi[kk] << endl;
            for (int j = i; j < L + i && !find; j++)
            {
                int used = 1;
                int jj = (j < L ? j : j - L);
                if (jj < i) used = 2;
                int n1, n2, n3;
                for (n1 = 0; n1 < 4; n1++)
                    if (ask(PW[n1], first) == 2)
                        break;
//                if (i == 1 && j == 1) cout << "n1: " << n1 << endl;
                if (n1 < 4)
                {
                    for (n2 = 0; n2 < 4; n2++)
                        if (ask(Pi[n2], second) == 3)
                            break;
 //                   if (i == 1 && j == 1) cout << "n2: " << n2 << endl;
                    if (n2 < 4)
                    {
                        for (n3 = 0; n3 < 4; n3++)
                            if (ask(Z[jj], PW[n3]) == 4)
                                break;
  //                      if (i == 1 && j == 1) cout << "n3: " << n3 << endl;
                        if (n3 < 4)
                            if (!(X - n1 - n2 - n3 - used < 0 ||
                                        ((X - n1 - n2 - n3 - used)&3) != 0))
                            {
                                find = true;
//                                cout << n1 << " " << i << " " << n2 << " " << jj << " " << n3 << endl;
                            }
                    }
                }

                second = ask(second, trans(S[jj]));
            }
            first = ask(first, trans(S[i]));
        }
        cout << "Case #" << tt << ": " << (find? "YES" : "NO") << endl;
    }
    return 0;
}
