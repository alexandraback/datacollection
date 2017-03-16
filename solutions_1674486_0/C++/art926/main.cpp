#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QVector>

//Artem Klimov's solution
//soved using Qt Framework 4.7.1


QFile inFile("C:/CodeJam-R1v3-Task1/test.in");
QFile outFile("C:/CodeJam-R1v3-Task1/output.txt");


class MyNode
{
public:
	QList<int> connections;
	bool colored;
	bool used;
};

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
		inData >> N;

		QVector<MyNode> nodes(N);

		int i,j,k,c;
		for(i=0; i<N; i++)
		{
			int M;
			inData >> M;
		
			for(j=0; j<M; j++)
			{
				int tConnect;
				inData >> tConnect;
				tConnect--; //to 0-base
				nodes[i].connections.append(tConnect);
			}
			nodes[i].colored = 0;
			nodes[i].used = 0;
		}

		bool diamondFound = 0;

		for(i=0; (i<N) && !diamondFound; i++)  //let's try to start coloring from different nodes
		{
			if( nodes[i].connections.count() < 2 ) continue;  //better to choose its ancestor in this case

			nodes[i].colored = 1;
			bool anyChanges = 1;
			while( anyChanges && !diamondFound )
			{
				anyChanges = 0;
				for(j=0; (j<N) && !diamondFound; j++)
				{
					if(nodes[j].colored==0) continue;  //doesn't have color
					if(nodes[j].used) continue;  //was already used to broadcast color
					nodes[j].used = 1;
					for(k=0; (k<nodes[j].connections.count()) && !diamondFound; k++)
					{
						c = nodes[j].connections[k];
						if( nodes[c].colored )  //already colored?
						{
							diamondFound = 1;
							break;
						}
						else
						{
							nodes[c].colored = 1;
							anyChanges = 1;
						}
					}
				}
			}

			for(j=0; j<N; j++)
			{
				nodes[j].colored = 0;
				nodes[j].used = 0;
			}
		}

		if(diamondFound)	outData << QString("Case #%1: Yes\r\n").arg(t+1);
		else				outData << QString("Case #%1: No\r\n").arg(t+1);		
	}
}