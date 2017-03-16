#include <QtCore>
#include <iostream>
#include <string>

using namespace std;

struct Tribe {
    int nextDay;
    int attacks;
    int west, east;
    int strength;
    int dayPause;
    int velocity;
    int strengthDiff;

    Tribe(QTextStream &in) {
        in >> nextDay >> attacks >> west >> east >> strength >> dayPause >> velocity >> strengthDiff;
    }

    bool operator < (const Tribe &other) const {
        return nextDay < other.nextDay;
    }

    void move() {
        attacks -= 1;
        nextDay += dayPause;
        east += velocity;
        west += velocity;
        strength += strengthDiff;
    }

    int attack(const QHash<int,int> &wall, QHash<int,int> &wall2) {
        bool succ = false;
        for (int i = 2*west+1; i <= 2*east-1; i++) {
            if (wall[i] < strength) {
                succ = true;
                wall2[i] = strength;
            }
        }
        //qDebug() << "attack at [" << west << ", " << east << "] height " << strength << ": " << succ;

        return succ;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream in(stdin, QIODevice::ReadOnly);

    int n;
    in >> n;

    for (int i = 0; i < n; i++) {
        int T;
        in >> T;

        QList<Tribe> tribes;
        tribes.reserve(T);

        for (int i = 0; i < T; i++) {
            tribes.push_back(Tribe(in));
        }

        QHash<int,int> wall;
        int nsuccess = 0;

        while (tribes.size() > 0) {
            qSort(tribes);

            QHash<int, int> wall2 = wall;

            //qDebug() << "day " << tribes[0].nextDay;
            int nmax = 0;
            for (int i = 0; i < tribes.size(); i++) {
                if (tribes[i].nextDay == tribes[0].nextDay) {
                    nmax += 1;
                    nsuccess += tribes[i].attack(wall, wall2);
                }
            }
            for (int i = 0; i < nmax; i++) {
                tribes[i].move();
            }
            for (int i = 0; i < nmax; i++) {
                if (tribes[i].attacks == 0) {
                    tribes.removeAt(i);
                    nmax --;
                    i--;
                }
            }

            //qDebug() << "success so far: " << nsuccess;

            wall2.swap(wall);
        }

        cout << "Case #" << (i+1) << ": " << nsuccess << endl;
    }
    
    return 0;
}
