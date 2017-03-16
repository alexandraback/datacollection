#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <list>
#include <complex>
#include <sstream>

using namespace std;

struct position{
    int x, y, t;
    bool operator <(const position &other) const
    {
        if(x != other.x)
            return x < other.x;
        else if(y != other.y)
            return y < other.y;
        else
            return t < other.t;
    }
    position(int a, int b, int c):x(a),y(b),t(c){}
};


map<position, int> Positions;

int dx[] = {-1, 0, +1, 0};
int dy[] = {0, +1, 0, -1};
char dn[] = "WNES";

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.out","w",stdout);
    int TestNumbers;
    scanf("%d",&TestNumbers);
    for(int test = 0; test < TestNumbers; test++)
    {
        printf("Case #%d: ", test + 1);

        Positions.clear();
        queue<position> Q;

        Positions.insert(make_pair(position(0,0,0),0));
        Q.push(position(0,0,0));

        int X, Y;
        scanf("%d%d",&X,&Y);
        int successTime;
        while(true){
            position top = Q.front();
            Q.pop();
            if(top.x == X && top.y == Y)
            {
                successTime = top.t;
                break;
            }
            else
            {
                for(int i = 0; i < 4; i++){
                    position next = top;
                    next.x += (top.t + 1) * dx[i];
                    next.y += (top.t + 1) * dy[i];
                    next.t++;
                    if(Positions.count(next) == 1)
                        continue;
                    else{
                        Q.push(next);
                        Positions.insert(make_pair(next,i));
                    }
                }
            }
        }
        string result;
        while(X != 0 || Y != 0){
            int direction = (*Positions.find(position(X,Y,successTime))).second ;
            result.push_back(dn[direction]);
            X -= successTime * dx[direction];
            Y -= successTime * dy[direction];
            successTime--;
        }
        reverse(result.begin(), result.end());

        cout << result;
        //printf("%d",successTime);
        printf("\n");
    }
    return 0;
}

