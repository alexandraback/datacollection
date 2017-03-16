#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QDebug>

int main(int, char *[])
{
    QTextStream in(stdin);
    QTextStream out(stdout);

    int T;
    in >> T;

    for (int c = 0; c < T; ++c) {
        int N;
        in >> N;

        QList<int> values;
        int total = 0;

        for (int i = 0; i < N; ++i) {
            int val;
            in >> val;
            values.append(val);
            total += val;
        }

        out << "Case #" << c+1 << ":";
        for (int i = 0; i < N; ++i) {
            int current = values[i];
            QList<int> others = values;
            others.removeAt(i);
            qSort(others);
            double min = 1.0;
            for (int x = 1; x <= others.size(); ++x) {
                QList<int> worsts = others.mid(0, x);

                qDebug() << worsts;
                double A = 1.0 + x;

                double SOL = 1.0;
                for (int j = 0; j < worsts.size(); ++j) {
                    SOL += double(worsts[j] - current) / double(total);
                }

                if ((SOL / A) < min)
                    min = SOL / A;
            }
            if (min > 0.0)
                out << " " << min * 100.0;
            else
                out << " 0";


        }
        out << endl;
    }
    
    return 0;
}
