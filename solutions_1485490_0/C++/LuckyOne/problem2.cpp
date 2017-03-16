#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "QString"
#include "qalgorithms.h"
#include "QList"
#include "qdebug"

using namespace std;

quint64 min(quint64 a, quint64 b){
    if(a>b) return b;
    return a;
}

quint64 max(quint64 a, quint64 b){
    if(a>b) return a;
    return b;
}

quint64 calc(QList<quint64> listA, QList<quint64> listB){
    if(listA.size() == 0 || listB.size() == 0) return 0;

    //cout << "1" << endl;

    quint64 verpackt = 0;
    quint64 anzahlA = listA.at(0);
    quint64 typA = listA.at(1);
    quint64 anzahlB = listB.at(0);
    quint64 typB = listB.at(1);

    while(typA == typB){
        quint64 tmp = min(anzahlA, anzahlB);
        //qdebug() << " min: " << min(anzahlA, anzahlB);
        verpackt += tmp;
        if(anzahlA - tmp == 0){
            listA.pop_front();
            listA.pop_front();
            //qdebug() << "verpackt " << verpackt << " von typ " << typA << endl;
            typA = -1;
            if(listA.size() != 0){
                anzahlA = listA.at(0);
                typA = listA.at(1);
            }
        }else{
            listA[0] = anzahlA - tmp;
        }
        if(anzahlB - tmp == 0){
            listB.pop_front();
            listB.pop_front();
            //qdebug() << "verpackt " << verpackt << " von typ " << typB << endl;
            typB = -2;
            if(listB.size() != 0){
                anzahlB = listB.at(0);
                typB = listB.at(1);
            }
        }
        else{
            listB[0] = anzahlB - tmp;
        }
    }

    //cout << "2" << endl;



    quint64 ergebnis1 = 0, ergebnis2 = 0;

    if(listA.size() != 0 && listB.size() != 0){
        QList<quint64> tmpA(listA);
        tmpA.pop_front();
        tmpA.pop_front();
        ergebnis1 += calc(tmpA, listB);
    }

    if(listB.size() != 0 && listA.size() != 0){
        QList<quint64> tmpB(listB);
        tmpB.pop_front();
        tmpB.pop_front();
        ergebnis2 += calc(listA, tmpB);
    }

    //cout << "3" << endl;
    //qdebug() << "listA: " << listA;
    //qdebug() << "listB: " << listB;
    //qdebug() << " max: " << max(ergebnis1, ergebnis2) << endl;
    return max(ergebnis1, ergebnis2) + verpackt;
}

int main(){
    ifstream problemFile;
    ofstream resultFile;
    string line;
    quint64 cases;

    problemFile.open("C-small-attempt2.in");
    getline(problemFile, line);
    cases = atoi(line.c_str());
    //qdebug() << cases << " cases found." << endl;
    resultFile.open ("result_B.txt");

    for(quint64 i = 1; i < cases+1; i++){
        //qdebug() << "Case " << i << endl;
        stringstream sstream;

        quint64 as, bs;
        problemFile >> as;
        problemFile >> bs;
        QList<quint64> listA;
        QList<quint64> listB;


        for(quint64 a = 0; a < 2*as; a++){
            quint64 tmp;
            problemFile >> tmp;
            listA.append(tmp);
        }
        for(quint64 b = 0; b < 2*bs; b++){
            quint64 tmp;
            problemFile >> tmp;
            listB.append(tmp);
        }

        //qdebug() << "sizes " << listA.size() << " " << listB.size() << endl;

        quint64 result = calc(listA, listB);

        sstream << "Case #" << i << ": " << result;
        resultFile << sstream.str();
        if(i != cases) resultFile << endl;
    }

    resultFile.close();
    problemFile.close();

    return 0;
}
