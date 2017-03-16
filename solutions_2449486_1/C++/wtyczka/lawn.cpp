#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <cassert>
#include <algorithm>
using namespace std;

struct Point {
    Point(int x, int y, int height)
        : x(x), y(y), altHeight(height), height(height), possible(false) {}
    int x, y, altHeight, height;
    bool possible, joker;
};

enum Direction {
    HORIZONTAL,
    VERTICAL
};

struct Line {
    vector<shared_ptr<Point> > points;
    Direction dir;
    bool processed;
    int maxHeight;

    void updateMaxHeight() {
        maxHeight = 0;
        for (auto &p : points) {
            if (p->height > maxHeight)
                maxHeight = p->height;
        }
    }
};

bool are_alt_heights_equal(const Line &line)
{
    assert(line.points.size() > 0);

    int maxJoker = -1;

    for (int i = 0; i < line.points.size(); i++) {
        int altHeight = line.points[i]->altHeight;

        if (! line.points[i]->joker)
            continue;

        if (maxJoker == -1 || altHeight > maxJoker)
            maxJoker = altHeight;
    }    

    int prevNonjoker = -1;

    for (int i = 0; i < line.points.size(); i++) {
        int altHeight = line.points[i]->altHeight;

        if (! line.points[i]->joker) {
            if (prevNonjoker == -1) {
                prevNonjoker = altHeight;
            } else
            if (prevNonjoker != altHeight) {
                return false;
            }

            if (altHeight < maxJoker)
                return false;
        }
    }

    return true;
#if 0
    find_if_not(line.points.begin(), line.points.end(),
                [=] (shared_ptr<Point> p) { return p->altHeight == h; });
#endif
}

void alg(vector<Line> &h_lines, vector<Line> &v_lines)
{
    queue<Line*> q;

    for (auto &l : h_lines) {
        if (are_alt_heights_equal(l))
            q.push(&l);
    }

    for (auto &l : v_lines) {
        if (are_alt_heights_equal(l))
            q.push(&l);
    }

    while (!q.empty()) {
        Line *l = q.front();
        q.pop();

        if (l->processed) continue;
        l->processed = true;

        //cout << "processing line starting with " << l->points[0]->x << ", " << l->points[0]->y << "  " << l->dir << endl;

        for (auto &p : l->points) {
            p->joker = true;

            Line *altLine;

            if (l->dir == HORIZONTAL) {
                altLine = &v_lines[p->x];
            } else /* VERTICAL */ {
                altLine = &h_lines[p->y];
            }

            if (are_alt_heights_equal(*altLine)) {
                q.push(altLine);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<Line> h_lines(n), v_lines(m);
        vector<shared_ptr<Point> > all_points;

        for_each(h_lines.begin(), h_lines.end(), [](Line &l) { l.dir = HORIZONTAL; });
        for_each(v_lines.begin(), v_lines.end(), [](Line &l) { l.dir = VERTICAL; });

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                int tmpHeight;
                cin >> tmpHeight;

                shared_ptr<Point> point = make_shared<Point>(k, j, tmpHeight);

                all_points.push_back(point);
                h_lines[j].points.push_back(point);
                v_lines[k].points.push_back(point);
            }
        }

        auto maxHeightUpdater = [](Line &l) { l.updateMaxHeight(); };
        for_each(h_lines.begin(), h_lines.end(), maxHeightUpdater);
        for_each(v_lines.begin(), v_lines.end(), maxHeightUpdater);

        alg(h_lines, v_lines);

        bool possible = true;

        for (auto &p : all_points) {
            //cout << "(" << p->x << ", " << p->y << ") = " << p->altHeight << ", j: " << p->joker << endl;
            if (!p->joker && p->altHeight != 100) {
                possible = false;
                break;
            }
        }

        cout << "Case #" << i + 1 << ": " << (possible ? "YES" : "NO") << endl;
    }
}

