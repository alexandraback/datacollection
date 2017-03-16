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

int main(int argc, char *argv[])
{

    qDebug() << "Starting Problem 1";

    QFile reading("/Users/davidsanchezplaza/Downloads/A-large (1).in");
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

        qDebug() << "=============";

        QString word = in.readLine();

        qDebug() << "word" << word;

        QStringList splitWord = word.split("", QString::SkipEmptyParts);

        qDebug() << "splitWord" << splitWord;


        QString lastWord = "";
        lastWord.append(splitWord.at(0));

        for(int i = 1; i< splitWord.size(); ++i){

//            qDebug() << "=========";
//            qDebug() << "lastWord" << lastWord;
//            qDebug() << "lastWord.at(0)" << lastWord.at(0);
//            qDebug() << "splitWord.at(i)" << splitWord.at(i);

            if(lastWord.at(0) <= splitWord.at(i)){
//                qDebug() << "Put it first";
                lastWord.prepend(splitWord.at(i));
            }else{
                lastWord.append(splitWord.at(i));
            }


        }

//        qDebug() << "lastWord" << lastWord;




//        QString solution ("Case #" + QString::number((z+1)) + ": " + QString::number(currentNumber));

        QString solution ("Case #" + QString::number((z+1)) + ": " + lastWord);
        qDebug() << solution;
        out << solution << endl;

    }

    //Closing the files.
    reading.close();
    destiny.close();

    qDebug() << "DONE, dont forget to submit your code and solution :D";
}
