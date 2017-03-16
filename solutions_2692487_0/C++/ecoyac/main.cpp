#include <QtCore>
#include <iostream>
//#include "utilities.h"

using namespace std;

int minimumMote(int size, QLinkedList<int> motes) {
    if (motes.size() == 0) {
        return 0;
    }
    if (size > motes.front()) {
        int x = size + motes.takeFirst();
        return minimumMote(x, motes);
    }

    int min = -1;
    if (size > 1) {
        min = 1 + minimumMote(size+size-1, motes);
    }
    motes.takeFirst();
    int min2 = 1+minimumMote(size, motes);

    if (min == -1) {
        min = min2;
    }

    return std::min(min, min2);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Q_UNUSED(a);

    QTextStream s(stdin);

    int n;
    s >> n;

    for (int i = 0; i < n; i++) {
        int size, others;
        s >> size >> others;

        QVector<int> motes;

        for (int j = 0; j < others; j++) {
            int x;
            s >> x;
            motes.push_back(x);
        }

        qSort(motes);

        QLinkedList<int> copy;
        for (int j = 0; j < motes.size(); j++) {
            copy.push_back(motes[j]);
        }

        int count = minimumMote(size, copy);

        cout << "Case #" << (i+1) << ": " << count << endl;
    }

    return 0;
}
