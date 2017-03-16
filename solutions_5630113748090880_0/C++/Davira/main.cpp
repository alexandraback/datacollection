/**
  First of all, I LOVE GOOGLE JAM, thanks you make us learn a lot.
  This main.cpp is for executing using Qt FrameWork.

  Round 1C.

  Problem A.

  */

#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <math.h>
#include <QApplication>
#include <QApplication>
#include <QTextStream>

void removeOneOfEachPair(QList<int> &totalNumbers)
{

    int i = 1;

    while(i < totalNumbers.size()){
//        qDebug() << "===============";
//        qDebug() << "i" << i;
//        qDebug() << "totalNumbers" << totalNumbers;
//        qDebug() << "totalNumbers.at(i-1)" << totalNumbers.at(i-1);
//        qDebug() << "totalNumbers.at(i)" << totalNumbers.at(i);

        if(totalNumbers.at(i) == totalNumbers.at(i-1)){
//            qDebug() << "The numbers are the same, so remove pair";
            totalNumbers.removeAt(i);
            totalNumbers.removeAt(i-1);
        }else {
            i++;
        }

    }

//    qDebug() << "totalNumbers" << totalNumbers;


}

int main(int argc, char *argv[])
{

    qDebug() << "Starting Problem 1";

    QFile reading("/Users/davidsanchezplaza/Downloads/B-small-attempt0 (1).in");
//    QFile reading("/Users/davidsanchezplaza/Downloads/solution.in");
//    QFile file("/Users/davidsanchezplaza/Downloads/A-large-practice-1.in.text");

    QFile destiny("/Users/davidsanchezplaza/Downloads/solution.txt");

    //Making sure we can open the files!
    if (!reading.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Can not open reading file";
    }
    if (!destiny.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Can not open destiny file";
    }

    QTextStream in(&reading);
    QTextStream out(&destiny);

    QString line = in.readLine();

    //Read T cases
    int T = line.toInt();
    qDebug() << "We have T cases " << T;

    for(int z = 0; z < T; z++){
        //Each case line:

        int N = in.readLine().toInt();
        qDebug() << "N" << N;

        QList<int> totalNumbers;

        qDebug() << "=============";

        for(int i = 0; i < 2* N -1; ++i){
            QStringList row = in.readLine().split(" ", QString::SkipEmptyParts);
            qDebug() << "row" << row;
            for(int j =0; j < row.size(); ++j){
                totalNumbers.append(row.at(j).toInt());
            }
        }

        qDebug() << "totalNumbers" << totalNumbers;
        qSort(totalNumbers);
        qDebug() << "totalNumbers" << totalNumbers;


        removeOneOfEachPair(totalNumbers);

        //Generate string solution;
        QString partialSol = "";
        foreach(int i, totalNumbers){
            partialSol.append(QString::number(i));
            partialSol.append(" ");
        }

        partialSol.chop(1);

        qDebug() << "partialSol" << partialSol;



//        QList<int> row = in.readLine().split("", QString::SkipEmptyParts);






        //        QString solution ("Case #" + QString::number((z+1)) + ": " + QString::number(currentNumber));

        QString solution ("Case #" + QString::number((z+1)) + ": " + partialSol);
        qDebug() << solution;
        out << solution << endl;

    }

    //Closing the files.
    reading.close();
    destiny.close();

    qDebug() << "DONE, dont forget to submit your code and solution :D";
}
