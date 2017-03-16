#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QVector>

//Artem Klimov's solution
//soved using Qt Framework 4.7.1


QFile inFile("C:/CodeJam-R1-Task1/test.in");
QFile outFile("C:/CodeJam-R1-Task1/output.txt");


int main(int argc, char *argv[])
{
	inFile.open(QFile::ReadOnly);
	outFile.open(QFile::WriteOnly);
	QTextStream inData(&inFile);
	QTextStream outData(&outFile);

	int T;
	inData >> T;

	QVector<double> P(99999);

	for(int t=0; t<T; t++)
	{
		int A, B;
		inData >> A;
		inData >> B;
		for(int i=0; i<A; i++)  inData >> P[i];

		double probOfAllCorrectTyping = 1;
		for(int i=0; i<A; i++) probOfAllCorrectTyping *= P[i];
		double probOfSomeIncorrectTyping = 1 - probOfAllCorrectTyping;

		double keystrIfKeepTyping = probOfAllCorrectTyping*(B-A+1) + probOfSomeIncorrectTyping * (B-A+1 + B+1);
		double keystrIfPressEnterRightAway = 1 + B + 1;
		double tMinKeystr = qMin(keystrIfKeepTyping, keystrIfPressEnterRightAway);

		//for backspaces
		for(int i=1; i<=A; i++)
		{
			double probThatThereIsNoErrorOnLeft = 1; 
			for(int j=0; j<A-i; j++) probThatThereIsNoErrorOnLeft *= P[j];
			double probThatThereIsSomeErrorOnLeft = 1 - probThatThereIsNoErrorOnLeft; 

			double keystrForThisNumbOfBacksp = probThatThereIsNoErrorOnLeft*(i+B-(A-i)+1) + probThatThereIsSomeErrorOnLeft*(i+B-(A-i)+1 +B+1);
			tMinKeystr = qMin(tMinKeystr, keystrForThisNumbOfBacksp);
		}

		outData << QString("Case #%1: %2\r\n").arg(t+1).arg(tMinKeystr,0,'f',6);
	}
}