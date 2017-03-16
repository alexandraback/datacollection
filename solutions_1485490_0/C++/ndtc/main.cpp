#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

typedef long long int64;

int n , m;
int64 a[110] , b[110], cuong, vu, thanh;
int A[110] , B[110];
int64 ketqua;

void doit(int i , int j , int64 res)
{
    if (i > n || j > m)
    {
        ketqua = max(ketqua , res);
        return ;
    }
    if (A[i] == B[j])
    {
    if (a[i] > b[j])
    {
    int64 tmp = a[i];
    a[i] -= b[j];
    doit(i , j + 1 , res + b[j]);
    a[i] = tmp;
    }
    else if (a[i] < b[j])
    {
    int64 tmp = b[j];
    b[j] -= a[i];
    doit(i + 1 , j , res + a[i]);
    b[j] = tmp;
    }
    else
    doit(i + 1 , j + 1 , res + a[i]);
    }
    else
    {
    doit(i + 1 , j , res);
    doit(i , j + 1 , res);
    }


}

int main()
{
    freopen("C-small.in" , "r" , stdin);
    freopen("Out.txt" , "w" , stdout);
    int ctest;
    cin >> ctest;
    for (int test = 1 ; test <= ctest ; test ++)
    {
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i ++)
    cin >> a[i] >> A[i];
    for (int i = 1 ; i <= m ; i ++)
    cin >> b[i] >> B[i];
    ketqua = 0;
    doit(1 , 1 , 0);
    cout << "Case #" << test << ": " << ketqua << endl;
    }
}
