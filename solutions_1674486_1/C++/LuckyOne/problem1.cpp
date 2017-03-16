#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "QString"
#include "qalgorithms.h"
#include "QList"
#include <iomanip>
#include "QDebug"

using namespace std;

bool find(int classNr, QList<int>* reachable, QList<QList<int>*>* listOfClasses){
    //cout << "find for class:" << classNr << endl;
    bool found = false;
    QList<int>* classTargets = listOfClasses->at(classNr);

    //cout << "1" << endl;
    foreach(int target, *classTargets){
        //cout << "2" << " " << target << endl;
        //qDebug() << *reachable;
        if(!reachable->contains(target)) reachable->append(target);
        else{
            found = true;
            break;
        }
    }
    //cout << "3" << endl;
    if(!found){
        foreach(int target, *classTargets){
            //cout << "4" << endl;
            bool tmp = find(target, reachable, listOfClasses);
            if(tmp){
                found = true;
                break;
            }
        }
    }
    //cout << "5" << endl;
    return found;

}

int main(){
    ifstream problemFile;
    ofstream resultFile;
    string line;
    int cases;

    problemFile.open("A-large.in");
    getline(problemFile, line);
    cases = atoi(line.c_str());
    cout << cases << " cases found." << endl;
    resultFile.open ("result_A.txt");

    for(int i = 1; i < cases+1; i++){
        cout << "Case " << i << endl;
        stringstream sstream;

        // Code goes here
        int classes;
        problemFile >> classes;
        QList<QList<int>*> listOfClasses;
        QList<int>* platz = new QList<int>;
        listOfClasses.append(platz);

        for(int j = 0; j < classes; j++){
            int numberInh;
            problemFile >> numberInh;
            QList<int>* listOfInh = new QList<int>();
            for(int k = 0; k < numberInh; k++){
                int read;
                problemFile >> read;
                listOfInh->append(read);
            }
            listOfClasses.append(listOfInh);
        }
        //cout << "#classes: " << listOfClasses.size() << endl;

        bool found = false;
        for(int x = 1; x < listOfClasses.size(); x++){
            QList<int>* reachable = new QList<int>();
            found = find(x, reachable, &listOfClasses);
            if(found) break;
        }


        sstream << "Case #" << i << ":";
        if(found) sstream << " Yes";
        else sstream << " No";
        // Code ends here

        resultFile << sstream.str();
        if(i != cases) resultFile << endl;
    }

    resultFile.close();
    problemFile.close();

    return 0;
}
