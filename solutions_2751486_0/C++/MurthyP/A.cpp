#include <QFileInfo>
#include <QFile>
#include <QString>
#include "QStringList"
#include <iostream>
#include <QTextStream>
#include <QList>
#include <QMap>
#include <QSet>
#include "QVector"
#include <cmath>
#include <QtAlgorithms>
#include <qmath.h>
using namespace std;
typedef long long LongInt;

int main() {
	QFile smallIn("D:/murthy/1B/inout/A-small-attempt0.in");
	if (!smallIn.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return 1;
	}

	QFile smallOut("D:/murthy/1B/inout/A-small-out.txt");
	if ( ! smallOut.open(QIODevice::WriteOnly | QIODevice::Text)) {
		return 1;
	}

	QTextStream in(&smallIn);
	QTextStream out(&smallOut);
	QStringList inputStrList;
	while (!in.atEnd()) {
		QString line = in.readLine();
		inputStrList.push_back(line);
	}

	int currentLineNo = 0;
	int T = inputStrList.at(currentLineNo).toInt();
	currentLineNo++;

	for(int testCaseNo = 0; testCaseNo < T; testCaseNo++) {
		QString rowStr = inputStrList.at(currentLineNo++);
		QStringList strList = rowStr.split(" ");
		QString name = strList.first();
		int n = strList.at(1).toInt();

		QList<bool> consoBool;
		for(int i = 0; i < name.size(); i++) {
			QChar ch = name.at(i);
			if ( (ch == 'a') || (ch == 'e')|| (ch == 'i')|| (ch == 'o')|| (ch == 'u') || (ch == 'A') || (ch == 'E')|| (ch == 'I')|| (ch == 'O')|| (ch == 'U')) {
				consoBool.push_back(false);
			} else {
				consoBool.push_back(true);
			}
		}
		
		int count = 0;

		for (int substrsize = name.size(); substrsize >= n; substrsize--) {
			for(int i = 0; i+substrsize-1 < name.size(); i++) {
				//strings of size n-i
				int consecCount = 0;
				for (int j = i; j < substrsize+i; j++) {
					if ( consoBool[j] ) {
						consecCount++;
					} else {
						consecCount = 0;
					}
					if ( consecCount == n ) {
						count++;
						break;
					}
				}
			}
		}
		
		if ( 1 ) {
			out << "Case #" << testCaseNo+1  << ": " << count << "\n";
		}
	}

	return 0;
}

