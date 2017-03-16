#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct s_bfs
{
    int dist;
    int x, y;
    string path;

    s_bfs () {}
    s_bfs(int a, int b, int c)
    {
        dist = a;
        x = b;
        y = c;
    }
};



void solution(int deltaX, int deltaY)
{
    while (deltaX > 0)
    {
        putchar('W');
        putchar('E');
        deltaX--;
    }

    while (deltaX < 0)
    {
        putchar('E');
        putchar('W');
        deltaX++;
    }

    while (deltaY > 0)
    {
        putchar('S');
        putchar('N');
        deltaY--;
    }

    while (deltaY < 0)
    {
        putchar('N');
        putchar('S');
        deltaY++;
    }
}



int n, strSize;
string str;

int main()
{
    freopen("small.in", "r", stdin);
    freopen("small.out", "w", stdout);
    int t = 1, nbT;


    cin >> nbT;
    while (t <= nbT)
    {
        int xDest, yDest;
        cin >> xDest >> yDest;





        cout << "Case #" << t << ": ";
        solution(xDest, yDest);
        cout << "\n";
        t++;
    }






    return 0;
}
