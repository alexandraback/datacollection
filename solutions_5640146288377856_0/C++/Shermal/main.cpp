#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QList>
#include <QtCore/qmath.h>
#include <math.h>
#include <iostream>
#include <float.h>
#include <intsafe.h>
#include <cstdlib>

//I use Qt 5.2.0 that can be downloaded from http://www.qt.io/download-open-source/

QFile go_InFile("Input.in");
QFile go_OutFile("Output.txt");
QTextStream out(&go_OutFile);

char zTmp[20];

char* Rev(char* pzNum)
{
	int iSize = strlen(pzNum);

	for (int i = 0; i < iSize; ++i)
	{
		zTmp[i] = pzNum[iSize - i - 1];
	}

	zTmp[iSize] = '\0';

	return zTmp;
}
int main(int argc, char *argv[])
{
	
 	QCoreApplication a(argc, argv);
 
	if (go_InFile.open(QIODevice::ReadOnly | QIODevice::Text) == false)
		return -1;

	if (go_OutFile.open(QIODevice::WriteOnly | QIODevice::Text) == false)
		return -1;

	QTextStream oTextStream(&go_InFile);

	QString sLine = oTextStream.readLine();
	int iNoOftestCases = sLine.toInt();

	//////////////
	//out.setRealNumberPrecision(7);
	//out.setRealNumberNotation(QTextStream::FixedNotation);
	//////////////

	for (int iCaseNo = 1; iCaseNo <= iNoOftestCases; ++iCaseNo)
	{
		out << "Case #" << iCaseNo << ": ";
		qDebug() << "Case " << iCaseNo;

 		sLine = oTextStream.readLine();
 		QStringList lstTmp = sLine.split(" ");

		int iR = lstTmp.at(0).toInt();
		int iC = lstTmp.at(1).toInt();
		int iW = lstTmp.at(2).toInt();

		int iCount = (iC / iW) * iR;

		if (iW > 1 && iC % iW != 0)
			++iCount;

		iCount = iCount + iW - 1;

		out << iCount << "\n";
		
	}

	go_OutFile.close();
	go_InFile.close();

	qDebug() << "Completed";

	return a.exec();
}

