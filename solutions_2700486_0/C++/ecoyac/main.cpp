#include <QtCore>
#include <iostream>
#include <iomanip>
//#include "utilities.h"

using namespace std;

struct point {
    qint16 x, y;

    point (int x= 0, int y =0):x(x), y(y) {

    }

    bool operator == (const point &other) const {
        return int(*this) == int(other);
    }

    operator int() const {
        return x + (y << 16);
    }

    bool operator < (const point &other) const {
        return int (*this) < int(other);
    }
};

int qHash(const point &p) {
    return qHash(int(p));
}

struct grid {
    QSet<point> points;
    int bottom;

    grid() {
        bottom = 0;
        points.insert(point(0,0));
    }

    bool operator == (const grid &other) const {
        return points == other.points;
    }

    void addDiamond();
    void addDiamond(int x, int y, double p);

    void addPoint(int x, int y, double p);
};

int qHash(const grid &g) {
    int total = 0;
    foreach(point x, g.points) {
        total += qHash(QPair<int,int>(x,0));
    }

    return qHash(total);
}

QHash<grid, double> grids;

void grid::addDiamond()
{
    int y = bottom+2;
    int x = 0;

    addDiamond(x, y, grids.take(*this));
}

void grid::addDiamond(int x, int y, double p) {
    if (y == 0) {
        addPoint(x, y, p);
        return;
    }

    if (x == 0) {
        bool left = points.contains(point(x-1, y-1));
        bool right = points.contains(point(x+1, y-1));
        if (left || right) {
            if (left && right) {
                addPoint(x,y,p);
            } else if (left) {
                addDiamond(x+1, y-1, p);
            } else { // right
                addDiamond(x-1, y-1, p);
            }
        } else {
            addDiamond(x-1, y-1, p/2);
            addDiamond(x+1, y-1, p/2);
        }

        return;
    }

    if (x < 0) {
        while (y > 0 && !points.contains(point(x-1, y-1))) {
            x -= 1;
            y -= 1;
        }
        addPoint(x, y, p);
    } else { // x > 0
        while (y > 0 && !points.contains(point(x+1, y-1))) {
            x += 1;
            y -= 1;
        }
        addPoint(x, y, p);
    }
}

void grid::addPoint(int x, int y, double p)
{
    //qDebug() << "adding point at " << x << y << " with p " << p;
    grid g2 = *this;
    g2.points.insert(point(x,y));

    if (x == 0) {
        g2.bottom = y;
    }

    grids[g2] += p;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Q_UNUSED(a);

    QTextStream s(stdin);

    int n;
    s >> n;

    cout << setiosflags(ios::fixed) << std::setprecision(6);

    for (int i = 0; i < n; i++) {
        grids.clear();

        int size, x, y;
        s >> size >> x >> y;

        point us (x,y);

        grids.insert(grid(), 1);

        for (int j = 1; j < size; j++) {
            //qDebug() << "j: " <<  j << ", " << grids.size();
            foreach(grid g, grids.keys()) {
                //qDebug() << "adding a diamond";
                g.addDiamond();
            }
            double t = 0;
            foreach(double y, grids) {
                //qDebug() << y;
                t += y ;
            }
            //qDebug() << "total amount: " << t;
        }

        double count = 0;
        QHashIterator<grid, double> it(grids);

        while (it.hasNext()) {
             it.next();

            if (it.key().points.contains(us)) {
                count += it.value();
            }
        }

        cout << "Case #" << (i+1) << ": " << count << endl;
    }

    return 0;
}
