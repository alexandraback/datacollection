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
        QString s2;
        int nv;
        long long int res = 0;

        in >> s2 >> nv;

        string s = s2.toStdString();

        int begin=0;
        int nc=0;

        for (int j = 0; j < s.length(); j++) {
            //qDebug() << "index " << j;
            if (s[j] != 'a' && s[j] != 'e' && s[j] != 'o' && s[j] != 'i' && s[j] != 'u') {
                nc++;
                //qDebug() << "hitting jackpot";

                if (nc == nv) {
                    /* middle */
                    res += 1;
                    /* before */
                    res += (j+1-nc-begin);
                    /* after */
                    res += (s.length() - j-1);
                    /* before + after */
                    res += (j+1-nc-begin)*(s.length() - j-1);

                    //qDebug() << " new subs, new res is " << res;

                    nc -= 1;
                    begin = j-nv+2;

                    //qDebug() << "new begin is " << begin;
                }
            } else {
                nc = 0;
            }
        }

        cout << "Case #" << (i+1) << ": " << res << endl;
    }
    
    return 0;
}
