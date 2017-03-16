#include <QFile>
#include <QTextStream>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam2014-0D/test.txt");
QFile outFile("C:/CodeJam2014-0D/output.txt");

int findALittleBitBiggerInList(const QList<double> &list, double value)
{
	for(int i=0; i<list.count(); i++)
	{
		if(list[i]>value) return i;
	}
	return -1;
}

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
		int N;
		QList<double> naomiList, kenList, naomiListOriginal, kenListOriginal;
		double c;

		inData >> N;
		for(int i=0; i<N; i++)
		{
			inData >> c;
			naomiListOriginal << c;
		}
		for(int i=0; i<N; i++)
		{
			inData >> c;
			kenListOriginal << c;
		}

		qSort(naomiListOriginal);
		qSort(kenListOriginal);
		
		//honest strategy
		int honestNaomiPoints = 0;
		naomiList = naomiListOriginal;
		kenList = kenListOriginal;
		while(naomiList.count())
		{
			int aLittleBitBiggerValueIndex = findALittleBitBiggerInList(kenList, naomiList[0]);
			if(aLittleBitBiggerValueIndex<0)  //Ken can't find such block, each player plays a smallest block
			{
				naomiList.removeFirst();
				kenList.removeFirst();
				honestNaomiPoints++;
			}
			else  //Ken uses smallest possible block to win
			{
				naomiList.removeFirst();
				kenList.removeAt(aLittleBitBiggerValueIndex);
			}
		}

		//deceitful strategy is simple - Naomi always says 0.999.... when she has a block, bigger than a smallest Ken's block
		//'cause Ken should play smallest block when he knows he can't win
		int deceitfulNaomiPoints = 0;
		naomiList = naomiListOriginal;
		kenList = kenListOriginal;
		while(naomiList.count())
		{
			int aLittleBitBiggerValueIndex = findALittleBitBiggerInList(naomiList, kenList[0]);
			if(aLittleBitBiggerValueIndex<0)  //Naomi can't win this round, she shouldn't lie
			{
				naomiList.removeFirst();   //she uses her smallers block and tells the true
				kenList.removeFirst();		//Ken's smallest block is bigger than Naomi's smallest, he uses it
			}
			else   //she says she has 0.9999..., Ken spends his smallest block, Naomi spends a little bit bigger to win
			{
				naomiList.removeAt(aLittleBitBiggerValueIndex);
				kenList.removeFirst();
				deceitfulNaomiPoints++;
			}
		}


		outData << QString("Case #%1: %2 %3\r\n").arg(t+1).arg(deceitfulNaomiPoints).arg(honestNaomiPoints);
	}
}