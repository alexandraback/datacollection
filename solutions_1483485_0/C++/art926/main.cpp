#include <QFile>
#include <QTextStream>
#include <QStringList>

//Artem Klimov's solution
//soved using Qt Framework 4.7.1


QFile inFile("C:/CodeJamQLanguage/A-small-attempt4.in");
QFile outFile("C:/CodeJamQLanguage/output.txt");

QString excample = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv yeqz";
QString excampleOrig = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up aozq";

QList<QChar> origLangLetters;
QList<QChar> translatedLangLetters;

int main(int argc, char *argv[])
{
	inFile.open(QFile::ReadOnly);
	outFile.open(QFile::WriteOnly);
	QTextStream inData(&inFile);
	QTextStream outData(&outFile);

	int T;
	inData >> T;
	inData.readLine();

	for(int t=0; t<T; t++)
	{
		QString inStr = inData.readLine();

		for(int i=0; i<inStr.count(); i++)  
		{
			if(excample.indexOf(inStr[i])<0) continue;
			inStr[i] = excampleOrig[ excample.indexOf(inStr[i]) ];
		}

		outData << QString("Case #%1: %2\r\n").arg(t+1).arg(inStr);
	}
}