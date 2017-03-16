#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

fstream fin,fout;
int T;

int R,N,M,K;
int a[20];
int b[20];
int cnt;



struct xxx{
    int a[3];
};

xxx now;
xxx c[1000];

bool yes(int tot, xxx h)
{
    bool can = true;
    int b[3];
    b[0] = b[1] = b[2] = 1;
    while (can)
    {
        can = false;
        if (tot == 1) return true;
        for (int i = 0; i < 3; i++)
            if (tot % h.a[i] == 0 && b[i] == 1)
            {
                tot = tot / h.a[i]; b[i] = 0;
                can = true;
            }
    }
    return false;
}

bool check(xxx h)
{
    for (int i = 0; i < K; i++)
        if (!yes(a[i],h)) return false;
    return true;
}

int main()
{
    fin.open("C-small-1-attempt0.in",ios::in);
    fout.open("c-small.txt",ios::out);
    fin >> T;
    fin >> R >> N >> M >> K;
    srand(time(NULL));
    fout << "Case #1:" << endl;
    for (int k = 0; k < R; k++){
        for (int i = 0; i < K; i++)
            fin >> a[i];
        cnt = 0;
        for (int i1 = 2; i1 <= 5; i1++)
            for (int i2 = 2; i2 <= 5; i2++)
            for (int i3 = 2; i3 <= 5; i3++)
            {
                now.a[0] = i1; now.a[1] = i2; now.a[2] = i3;
                if (check(now))
                {
                    c[cnt] = now;
                    cnt ++;
                }
            }
        int ans = rand()%(cnt);
        fout << c[ans].a[0] << c[ans].a[1] << c[ans].a[2] << endl;
    }

    fout.close();
    return 0;
}
