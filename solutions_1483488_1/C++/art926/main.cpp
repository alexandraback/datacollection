#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QSet>

//Artem Klimov's solution
//soved using Qt Framework 4.7.1


QFile inFile("C:/CodeJamQPairs/test.in");
QFile outFile("C:/CodeJamQPairs/output.txt");


int main(int argc, char *argv[])
{
	inFile.open(QFile::ReadOnly);
	outFile.open(QFile::WriteOnly);
	QTextStream inData(&inFile);
	QTextStream outData(&outFile);

	int T;
	inData >> T;

	for(int t=0; t<T; t++)
	{
		int A, B;
		inData >> A;
		inData >> B;

		int res=0;
		int tNumb;
		for(int i=A; i<=B; i++)
		{

			QString intStr = QString("%1").arg(i);
			int strL = intStr.count();
			QSet<int> usedNumbers;
			for(int j=1; j<strL; j++)
			{
				intStr.push_back(intStr[0]);
				intStr = intStr.remove(0,1);
				tNumb = intStr.toInt();
				if(tNumb<=i) continue;
				if( (tNumb>=A) && (tNumb<=B) )
				{
					if(usedNumbers.contains(tNumb)==0)
					{
						usedNumbers.insert(tNumb);
						res ++;
					}
				}
			}
		}

		outData << QString("Case #%1: %2\r\n").arg(t+1).arg(res);
	}
