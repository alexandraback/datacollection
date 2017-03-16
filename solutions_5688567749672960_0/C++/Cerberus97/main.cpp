#include <iostream>
#include <fstream>

using namespace std;

int a[1000001];

int reverseNum(int n)
{
    int ans = 0;

    while (n)
    {
        ans = (ans * 10) + (n % 10);
        n /= 10;
    }

    return ans;

}



void initialize()
{
    for (int i = 0; i < 1000001; ++i)
        a[i] = i;
}

void build()
{
    int temp;

    for (int i = 10; i <= 1000000; ++i)
    {
        a[i] = min(a[i], a[i - 1] + 1);

        temp = reverseNum(i);

        a[temp] = min(a[temp], a[i] + 1);

    }
}

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");

    initialize();
    build();

    int t, n;

    in >> t;

    for (int j = 1; j <= t; ++j)
    {
        in >> n;

        out << "Case #" << j << ": " << a[n] << '\n';
    }

    return 0;
}
