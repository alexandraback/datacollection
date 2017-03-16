#include <QFile>
#include <QTextStream>
#include <QStringList>

//Artem Klimov's solution
//soved using Qt Framework 4.7.1


QFile inFile("C:/CodeJamQDancers/test.in");
QFile outFile("C:/CodeJamQDancers/output.txt");


bool CanBeMoreThanPWithSurprise(int tSum, int p, int &S)
{
	int restTwoRes = tSum - p;
	if(restTwoRes<0) return 0;
	float averRest = restTwoRes*0.5;
	if(averRest>=(p-1.0001)) return 1;
	if(S==0) return 0;
	if(averRest>=(p-2.0001))
	{
		S--;
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	inFile.open(QFile::ReadOnly);
	outFile.open(QFile::WriteOnly);
	QTextStream inData(&inFile);
	QTextStream outData(&outFile);

	int T;
	inData >> T;

	int totals[100];

	for(int t=0; t<T; t++)
	{
		int N, S, p;
		inData >> N;
		inData >> S;
		inData >> p;

		int res=0;
		for(int i=0; i<N; i++)
		{
			int tSum;
			inData >> tSum;
			res += CanBeMoreThanPWithSurprise(tSum, p, S);
		}

		outData << QString("Case #%1: %2\r\n").arg(t+1).arg(res);
	}
}