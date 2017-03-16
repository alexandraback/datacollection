#include <QtCore>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream in(stdin, QIODevice::ReadOnly);

    int n;
    in >> n;

    for (int i = 0; i < n; i++) {
        string res;

        int x,y;

        in >> x >> y;

        int curx = 0;
        int cury = 0;
        int j = 0;

        while (! (curx == x && cury == y) && j < 200) {
            j++;
            bool east, north;

            int curx2 = curx;
            int cury2 = cury;

            if (curx < x && (curx+j) <= x) {
                east = true;
                curx2 += j;
            } else {
                east = false;
                curx2 -= j;
            }

            if (cury < y && (cury+j) <= y) {
                north = true;
                cury2 += j;
            } else {
                north = false;
                cury2 -= j;
            }

            if ( (std::abs(curx2-x) < std::abs(cury2-y) && curx!=x) || cury==y) {
                curx = curx2;
                res.push_back(east ? 'E' : 'W');
            } else {
                cury = cury2;
                res.push_back(north ? 'N' : 'S');
            }

            //cout << "(" << curx << ", " << cury << ")" << endl;
        }
        //cout << "(" << curx << ", " << cury << ")" << endl;

        cout << "Case #" << (i+1) << ": " << res << endl;
    }
    
    return 0;
}
