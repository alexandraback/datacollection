#include <iostream>
using namespace std;

int R, N, M, K;
int Dig[1000];

bool checkzzz(int a, int b, int c, int dig)
{

    for (int x=1;x<=a;x+=a-1)
        for (int y=1;y<=b;y+=b-1)
            for (int z=1;z<=c;z+=c-1)
                if (x*y*z == dig)
                    return true;
    return false;
}

bool check(int a, int b, int c)
{
    for (int i=1;i<=K;i++)
        if (!checkzzz(a,b,c,Dig[i]))
                return false;
    return true;
}

int main()
{
    cin >>R; // Dummy
    cin >> R>>N>>M>>K;
    cout<<"Case #1:"<<endl;
    for (int i=1;i<=R;i++)
    {
        for (int j=1; j<=K; j++)
            cin>> Dig[j];
        bool q = true;
        for (int a = 2; a <=M && q; a++)
            for (int b =2; b<=M && q; b++)
                for (int c =2;c<=M && q; c++)
                {
                    if (check(a,b,c))
                    {
                        cout<<a<<b<<c<<endl;
                        q = false;
                    }
                }
    }
    return 0;
}
