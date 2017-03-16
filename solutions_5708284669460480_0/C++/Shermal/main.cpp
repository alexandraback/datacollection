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


int CheckOverlap(QString& sWord, const int iStartingPost, int iL)
{
	int iSecondStart = iStartingPost;

	for (int i = 0; i < iL; ++i)
	{
		if (iSecondStart >= iL)
			break;

		if (sWord.at(i) == sWord.at(iSecondStart))
		{
			++iSecondStart;
		}
		else
			return -1;
	}

	return iStartingPost;
}

QList<QChar> lstKeys;
QMap<QChar, int> mapKeys;
int iS;
int iK;
int iL;
QString sTargetWord;
double dExpectedUsed;

double FindProbability(QString& sWord)
{
	double dProb = 1;

	for (int i = 0; i < iS; ++i)
	{
		dProb = dProb * mapKeys[sWord.at(i)] / (double)iK;
	}

	return dProb;
}

bool IsWord(QString& sWord, int iCount)
{

	for (int i = iCount, iNo = 0; iNo < iL; ++i, ++iNo)
	{
		if (i >= iS)
			return false;

		if (sWord.at(i) != sTargetWord.at(iNo))
			return false;
		
	}

	return true;
}


int FindCount(QString& sWord)
{
	int iCount = 0;

	for (int i = 0; i < iS; ++i)
	{
		if (IsWord(sWord, i))
			++iCount;
	}

	return iCount;
}

void CreateWords(QString sWord)
{
	if (sWord.size() == iS)
	{
		double dProb = FindProbability(sWord);
		int iCount = FindCount(sWord);

		dExpectedUsed = dExpectedUsed + iCount * dProb;
		return;
	}

	int iKeyPadSize = lstKeys.size();

	for (int i = 0; i < iKeyPadSize; ++i)
	{
		QString sNewWord = QString("%1%2").arg(sWord).arg(lstKeys.at(i));
		CreateWords(sNewWord);
	}
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
	out.setRealNumberPrecision(7);
	out.setRealNumberNotation(QTextStream::FixedNotation);
	//////////////

	for (int iCaseNo = 1; iCaseNo <= iNoOftestCases; ++iCaseNo)
	{
		lstKeys.clear();
		mapKeys.clear();
		dExpectedUsed = 0;
		sTargetWord = "";

		out << "Case #" << iCaseNo << ": ";
		qDebug() << "Case " << iCaseNo;

 		sLine = oTextStream.readLine();
 		QStringList lstTmp = sLine.split(" ");

		iK = lstTmp.at(0).toInt();
		iL = lstTmp.at(1).toInt();
		iS = lstTmp.at(2).toInt();

		

		sLine = oTextStream.readLine();
		for (int i = 0; i < iK; ++i)
		{
			if (mapKeys.contains(sLine.at(i)))
			{
				mapKeys[sLine.at(i)] = mapKeys[sLine.at(i)] + 1;
			}
			else
			{
				mapKeys[sLine.at(i)] = 1;
			}
			
		}

		sLine = oTextStream.readLine();
		sTargetWord = sLine;
		bool bFoundAll = true;
		for (int i = 0; i < iL; ++i)
		{
			if ( mapKeys.contains(sLine.at(i)) == false )
			{
				bFoundAll = false;
				break;
			}
		}

		if (bFoundAll == false)
		{
			out << "0\n";
			continue;
		}

		/////////////////////////////

		lstKeys = mapKeys.keys();

		int iOverlapedPos = -1;

		for (int i = 1; i < iL; ++i)
		{
			iOverlapedPos = CheckOverlap(sLine, i, iL);
			if ( iOverlapedPos != -1 )
			{
				break;
			}
		}

		

		if (iOverlapedPos == -1)
		{
			CreateWords("");
			double dAns = iS / iL - dExpectedUsed;
			if (dAns < 0)
				qDebug() << "errorrr...";

			out << dAns << "\n";

			continue;
		}

		

		int iRemain = iS - iL;

		if (iRemain > 0)
		{
			int iTotalbanas = 1 + iRemain / iOverlapedPos; 
			CreateWords("");
			double dAns = iTotalbanas - dExpectedUsed;

			out << dAns << "\n";
			continue;
		}
		else
		{
			out << "0\n";
			continue;
		}
	}

	go_OutFile.close();
	go_InFile.close();

	qDebug() << "Completed";

	return a.exec();
}

