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
using namespace std;

int x, y;
QString minPath;

void findPath(int currentX, int currentY, int stepSize, QString currentPath) {
	if ( !minPath.isEmpty() && (minPath.size() < 500) ) return;
	if ( (!minPath.isEmpty()) && (minPath.size() < currentPath.size() ) ) return;

	if ( (currentX == x) && (currentY == y)) {
		if ( (minPath.isEmpty()) || minPath.size() > currentPath.size() ) {
			minPath = currentPath;
			return;
		}
	}

	if ( currentX != x ) {
		//Try E and W
		if ( stepSize > (x - currentX ) ) {
			findPath(currentX-stepSize, currentY, stepSize+1, currentPath+"W");
		} else {
			findPath(currentX+stepSize, currentY, stepSize+1, currentPath+"E");
		}
	}

	if ( currentY != y) {
		//Try N & S
		if ( stepSize > (y - currentY ) ) {
			findPath(currentX, currentY-stepSize,  stepSize+1, currentPath+"S");
		} else {
			findPath(currentX, currentY+stepSize, stepSize+1, currentPath+"N");
		}
	}
}

int main() {
	QFile smallIn("D:/murthy/1B/inout/B-small-attempt0.in");
	if (!smallIn.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return 1;
	}

	QFile smallOut("D:/murthy/1B/inout/B-small-out.txt");
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
	int t = inputStrList.at(currentLineNo).toInt();
	currentLineNo++;

	for(int testCaseNo = 0; testCaseNo < t; testCaseNo++) {
		minPath.clear();
		QString rowStr = inputStrList.at(currentLineNo++);
		QStringList strList = rowStr.split(" ");
		x = strList.first().toInt();
		y = strList.last().toInt();

		int currentX = 0, currentY = 0;
		QString path;

		findPath(currentX, currentY, 1, path);


		out << "Case #" << testCaseNo+1 << ": " << minPath << "\n";

	}

	return 0;
}