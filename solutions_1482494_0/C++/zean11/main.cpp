#include <QtCore/QCoreApplication>
#include <QFile>

#include <QList>
#include <QDebug>

#include <QMultiMap>

#include <QStringList>

struct Game {
    int levelNumber;
    int oneStar;
    int twoStar;
    bool oneCompleted;
    bool twoCompleted;
};

int main(int argc, char *argv[])
{
    QFile debug("debug.txt");
    debug.open(QIODevice::WriteOnly);

    QFile tests("test.txt");
    tests.open(QIODevice::ReadOnly);

    QFile results("results.txt");

    results.open(QIODevice::ReadWrite);

    //    QString helloThere = QString::fromAscii("HelloThere\nHow are you today?\n I am fine. \n Yes!  CodeJAM!#@!$&^*%");
    //    results.write(helloThere.toUtf8());

    QString numberOfCases = tests.readLine();
    int numc = numberOfCases.toInt();
    int i=1;
    while(i <= numc && !tests.atEnd()) {

        QString buffer = "Too Bad";

        bool fail = false;

        qDebug() << "Game" << i;

        QString SnumLevels = tests.readLine();
        int levs = SnumLevels.toInt();


        Q_ASSERT(levs != 0);

        debug.write(QString("Game ").toUtf8());
        debug.write(QString::number(i).toUtf8());
        debug.write(QString::fromAscii("\n").toUtf8());
        QMultiMap<int, Game*> games1;
        QMultiMap<int, Game*> games2;
        for (int x=0; x<levs; x++) {
            QString Sints = tests.readLine();
            QStringList Splints = Sints.split(' ');
            Game *a = new Game;
            a->levelNumber = x;
            a->oneStar = Splints.at(0).toInt();
            a->twoStar = Splints.at(1).toInt();
            a->oneCompleted = false;
            a->twoCompleted = false;

            games1.insert(a->oneStar, a);
            games2.insert(a->twoStar, a);

            QString aaa="%1. ";
            Sints.prepend(aaa.arg(x));
            debug.write(Sints.toUtf8());

        }
        debug.write(QString::fromAscii("\n").toUtf8());


        int iterations=0;
        int stars = 0;
        while (!games2.isEmpty()) {
            //qDebug() << iterations;
            //qDebug() << games2.keys() << games2.keys().front();
            if (games2.keys().front() <= stars) {
                QList<Game*> gas = games2.values(games2.keys().front());
                Game* candidate = 0;
                foreach(Game* ga, gas) {
                    if (!ga->oneCompleted) {
                        candidate = ga;
                        break;
                    }
                }
                if (candidate != 0) {

                    candidate->oneCompleted = true;
                    candidate->twoCompleted = true;
                    stars += 2;

                    qDebug() << "2 Star Removed" << candidate->levelNumber << stars;
                    games2.remove(candidate->twoStar,candidate);
                    games1.remove(candidate->oneStar,candidate);
                }
                else {
                    Game* gaba = gas.front();

                    gaba->oneCompleted = true;
                    gaba->twoCompleted = true;

                    stars += 1;

                    qDebug() << "2-1 STar removed" << gaba->levelNumber << stars;
                    games2.remove(gaba->twoStar, gaba);
                    games1.remove(gaba->oneStar, gaba);
                }

                iterations++;
                continue;
            }

            QMultiMap<int, Game*> temp;
            foreach(int k, games1.keys()) {
                if (k > stars) {
                    break;
                }

                foreach(Game* ap, games1.values(k)) {
                    temp.insert(ap->twoStar, ap);
                }
            }

            if (temp.isEmpty()) {

                qDebug() << "Can't be done!";
                fail = true;
                break;

            }

            temp.keys().back(); // largest 2 weight


            QList<Game*> gas = temp.values(temp.keys().back());
            Game* maxWeight = gas.front();
            stars += 1;
            maxWeight->oneCompleted = true;
            Q_ASSERT(!maxWeight->twoCompleted);

            qDebug() << "1 Star completed" << maxWeight->levelNumber << stars;

            games1.remove(maxWeight->oneStar, maxWeight);

            iterations++;
            continue;

        }

        QString res = "Case #%1: %2\n";

        if (fail) {
            buffer = "Too Bad";
        }
        else {
            buffer = QString::number(iterations);
        }

        res = res.arg(i++).arg(buffer);
        results.write(res.toUtf8());
    }

    results.close();
    debug.close();
    tests.close();

    return 0;
}
