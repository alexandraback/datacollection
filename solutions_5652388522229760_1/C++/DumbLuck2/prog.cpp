#include <iostream>
#include <fstream>
#include <algorithm>
//#include <iomanip>
using namespace std;

template <class X>
void printArray(X a[], int len);



void getDigits(int N, int num[], int& n)
{
    int x;

    for(; N != 0; N /= 10)
    {
        x = N%10;
        if(num[x] == 0)
        {
            n--;
            num[x] = 1;
        }
    }
}

int main()
{
    //fstream fin("ABtest.in", ios::in);

    //fstream fin("A-small-attempt0.in", ios::in);
    fstream fin("A-large.in", ios::in);

    fstream fout("Output.out", ios:: out);

    int T;
    fin >> T;
    for(int TC = 1; TC <= T; TC++)
    {
        fout << "Case #" << TC << ": ";
        int N;

        fin >> N;
        int num[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int n = 10;

        if(N == 0)
            fout << "INSOMNIA";
        else
        {
            int i;
            for(i = 1; n != 0; i++)
                getDigits(N*i, num, n);
            fout << N*(i-1);
        }
        fout << endl;

    }
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
