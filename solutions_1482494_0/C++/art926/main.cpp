#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QVector>

//Artem Klimov's solution
//soved using Qt Framework 4.7.1


QFile inFile("C:/CodeJam-R1-Task2/B-small-attempt4.in");
QFile outFile("C:/CodeJam-R1-Task2/output.txt");


int main(int argc, char *argv[])
{
	inFile.open(QFile::ReadOnly);
	outFile.open(QFile::WriteOnly);
	QTextStream inData(&inFile);
	QTextStream outData(&outFile);

	int T;
	inData >> T;

	QVector<int> oneStarRequir(1000);
	QVector<int> twoStarRequir(1000);

	QVector<bool> oneStarsFlag(1000);
	QVector<bool> twoStarsFlag(1000);

	for(int t=0; t<T; t++)
	{
		int N;
		inData >> N;
		for(int i=0; i<N; i++)
		{
			inData >> oneStarRequir[i];
			inData >> twoStarRequir[i];
			oneStarsFlag[i] = 0;
			twoStarsFlag[i] = 0;
		}

		int tAllMyStars = 0;
		int sumTimesOfPlays = 0;

		for(;;)
		{
			//check if can get two stars from some level
			bool justGotTwoStarsFromClearLevel = 0;
			for(int i=0; i<N; i++)
			{
				if(oneStarsFlag[i]||twoStarsFlag[i]) continue;	//already played

				if(twoStarRequir[i]<=tAllMyStars)
				{
					twoStarsFlag[i] = 1;
					tAllMyStars += 2;
					sumTimesOfPlays++;
					justGotTwoStarsFromClearLevel = 1;
				}
			}
			if(justGotTwoStarsFromClearLevel) continue;

			//try to pass some one-star level or replay old one with two-star raiting
			bool justGotOneStar = 0;
			for(int i=0; i<N; i++)
			{
				if(twoStarsFlag[i]) continue;  //already got two stars here

				if( (oneStarRequir[i]<=tAllMyStars) && (oneStarsFlag[i]==0) )  //play with one-star
				{
					oneStarsFlag[i] = 1;
					tAllMyStars ++;
					sumTimesOfPlays++;
					justGotOneStar = 1;
					break;  //don't play anymore one-star raiting
				}

				if(twoStarRequir[i]<=tAllMyStars)  //replay with two-star
				{
					twoStarsFlag[i] = 1;
					tAllMyStars ++;
					sumTimesOfPlays++;
					justGotOneStar = 1;
					break;  //don't play anymore one-star raiting
				}
			}
			if(justGotOneStar) continue;

			break; //can't get anymore stars
		}		

		bool gotAllTwoStars = 1;
		for(int i=0; i<N; i++)
		{
			if(twoStarsFlag[i]==0)
			{
				gotAllTwoStars = 0;
				break;
			}
		}

		if(!gotAllTwoStars)	outData << QString("Case #%1: %2\r\n").arg(t+1).arg("Too Bad");
		else				outData << QString("Case #%1: %2\r\n").arg(t+1).arg(sumTimesOfPlays);
	}
}