#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
//#include <iomanip>
using namespace std;

template <class X>
void printArray(X a[], int len);

int COUNT;

void flip(char s[], int N)
{
    reverse(s, s+N);
    for(int i = 0; i < N; i++)
        s[i] = '+' + '-' - s[i];
}

void minFlips(char s[], int N, char pos)
{
    if(N == 1)
    {
        if(s[0] != pos)
        {
            s[0] = '+' + '-' - s[0];
            COUNT++;
        }
        return;
    }

    if(s[N-1] == pos)
        minFlips(s, N-1, pos);
    else
    {
        minFlips(s, N-1, '+' + '-' - pos);
        flip(s, N);
        COUNT++;
    }
}


int main()
{
    //fstream fin("ABtest.in", ios::in);

    fstream fin("B-small-attempt0.in", ios::in);
    //fstream fin("A-large.in", ios::in);

    fstream fout("Output.out", ios:: out);

    int T;
    fin >> T;
    for(int TC = 1; TC <= T; TC++)
    {
        fout << "Case #" << TC << ": ";

        char s[100];
        fin >> s;
        int N = strlen(s);

        COUNT = 0;

        minFlips(s, N, '+');


        fout << COUNT << endl;

    }

    fout.close();
    fin.close();

    return 0;
}


template <class X>
void printArray(X a[], int len)
{
    cout << "Array = ";
    for(int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout <<  endl;
}
