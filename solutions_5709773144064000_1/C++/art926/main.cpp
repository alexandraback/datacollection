#include <QFile>
#include <QTextStream>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam2014-0B/B-large.in");
QFile outFile("C:/CodeJam2014-0B/output.txt");


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
		double C,F,X;

		inData >> C;
		inData >> F;
		inData >> X;

		double currentRate = 2;
		double STime = 0;
		double timeForNextFarm, timeToWinWithCurrentRate;

		for(;;)
		{
			timeForNextFarm = C / currentRate;
			timeToWinWithCurrentRate = X / currentRate;
			
			if( timeToWinWithCurrentRate < (timeForNextFarm + X/(currentRate+F)) )
			{
				STime += timeToWinWithCurrentRate;
				break;
			}
			else
			{
				STime += timeForNextFarm;
				currentRate += F;
			}
		}

		outData << QString("Case #%1: %2\r\n").arg(t+1).arg(STime,0,'f',7);
	}
}