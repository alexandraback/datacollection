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
        QList<int> S;
        for (int i = 0; i < N; ++i) {
            int s;
            in >> s;
            S.append(s);
        }

        bool ok = false;
        for (int combination1 = 1; combination1 < (1 << N); ++combination1) {
            int sum1 = 0;
            QList<int> O;
            for (int i = 0; i < N; ++i) {
                if ((combination1 & (1 << i)) != 0)
                    sum1 += S[i];
                else
                    O.append(S[i]);
            }

            for (int combination2 = 1; combination2 < (1 << O.size()); ++combination2) {
                int sum2 = 0;
                for (int i = 0; i < O.size(); ++i) {
                    if ((combination2 & (1 << i)) != 0)
                        sum2 += O[i];
                }

                if (sum1 == sum2) {
                    out << "Case #" << c+1 << ":" << endl;
                    for (int i = 0; i < N; ++i) {
                        if ((combination1 & (1 << i)) != 0)
                            out << S[i] << " ";
                    } out << endl;
                    for (int i = 0; i < O.size(); ++i) {
                        if ((combination2 & (1 << i)) != 0)
                            out << O[i] << " ";
                    } out << endl;
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }
        if (ok == false) {
            out << "Case #" << c+1 << ":" << endl;
            out << "Impossible" << endl;
        }


    }
    
    return 0;
}
