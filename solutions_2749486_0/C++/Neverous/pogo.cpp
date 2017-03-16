/* 2013
 * Maciej Szeptuch
 * II UWr
 */
#include <cstdio>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

typedef std::pair<int, int> Heuristic;
typedef std::pair<Heuristic, std::string> Path;
typedef std::pair<int, int> Point;
typedef std::pair<Path, Point> State;
typedef std::pair<Point, int> Visited;
#define _heuristic first.first.first
#define _steps first.first.second
#define _word first.second
#define _point second
#define _x first
#define _y second

int tests,
    x, y;
State act;

std::string solve(const int &x, const int &y);

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %d", &x, &y);
        printf("Case #%d: %s\n", t + 1, solve(x, y).c_str());
    }

    return 0;
}

std::string solve(const int &X, const int &Y)
{
    std::map<Visited, bool> visited;
    std::priority_queue<State> que;
    que.push(State(Path(Heuristic(-std::abs(X)-std::abs(Y), 0), ""), Point(0, 0)));

    while(!que.empty())
    {
        act = que.top();
        que.pop();

        if(act._point == std::make_pair(X, Y))
            return act._word;

        if(visited[Visited(act._point, act._steps)])
            continue;

        visited[Visited(act._point, act._steps)] = true;
        State next = act;
        /* UP */
        next._steps -= 1;
        next._word += 'N';
        next._point._y += 1 - act._steps;
        next._heuristic = next._steps - std::abs(X - next._point._x) - std::abs(Y - next._point._y);
        que.push(next);

        /* DOWN */
        next = act;
        next._steps -= 1;
        next._word += 'S';
        next._point._y -= 1 - act._steps;
        next._heuristic = next._steps - std::abs(X - next._point._x) - std::abs(Y - next._point._y);
        que.push(next);

        /* RIGHT */
        next = act;
        next._steps -= 1;
        next._word += 'E';
        next._point._x += 1 - act._steps;
        next._heuristic = next._steps - std::abs(X - next._point._x) - std::abs(Y - next._point._y);
        que.push(next);

        /* LEFT */
        next = act;
        next._steps -= 1;
        next._word += 'W';
        next._point._x -= 1 - act._steps;
        next._heuristic = next._steps - std::abs(X - next._point._x) - std::abs(Y - next._point._y);
        que.push(next);
    }

    return "";
}
