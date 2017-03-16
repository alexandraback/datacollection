#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int xf,yf;


struct dir
{
    int x, y, dis;
    string ans;
    dir(){}
    dir(int a, int b, int c, string d)
    {
        x = a, y = b, dis = c, ans = d;
    }
};
int main ()
{
    int T;
    freopen ("B-small-attempt2.in","r",stdin);
    freopen ("b.out","w",stdout);
    cin >> T;

    for (int tc = 0; tc < T; tc ++)
    {
        cin >> xf >> yf;
        map <pair <int,int>, int > m;

        queue <dir> q;
        q.push (dir (0,0,1,""));

        m [make_pair (0,0)] = 1;

        while (!q.empty())
        {
            dir aux = q.front();
            q.pop();
            if (aux.x == xf && aux.y == yf)
            {
                cout << "Case #" << tc + 1 << ": " << aux.ans << endl;
                break;
            }

            if (m.count (make_pair (aux.x + aux.dis , aux.y)) <= 0){
                q.push (dir (aux.x + aux.dis , aux.y, aux.dis + 1, aux.ans + "E"));
                m [make_pair (aux.x + aux.dis , aux.y)] = 1;
            }
            if (m.count (make_pair (aux.x - aux.dis , aux.y)) <= 0){
                q.push (dir (aux.x - aux.dis , aux.y, aux.dis + 1, aux.ans + "W"));
                m [make_pair (aux.x - aux.dis , aux.y)] = 1;
            }
            if (m.count (make_pair (aux.x , aux.y - aux.dis)) <= 0)
            {
                q.push (dir (aux.x , aux.y - aux.dis , aux.dis + 1, aux.ans + "S"));
                m [make_pair (aux.x , aux.y - aux.dis)] = 1;
            }
            if (m.count (make_pair (aux.x , aux.y + aux.dis)) <= 0)
            {
                q.push (dir (aux.x, aux.y + aux.dis , aux.dis + 1, aux.ans + "N"));
                m [make_pair (aux.x , aux.y + aux.dis)] = 1;
            }
        }



    }

    return 0;
}










