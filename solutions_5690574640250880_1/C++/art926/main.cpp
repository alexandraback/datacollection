#include <QFile>
#include <QTextStream>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam2014-0C/test.txt");
QFile outFile("C:/CodeJam2014-0C/output.txt");

char matrix[50][50];
int R,C, M;
bool transposed;

void transpose()
{
	char c;
	for(int i=0; i<50; i++)
	{
		for(int j=i; j<50; j++)
		{
			c = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = c;
		}
	}

	int temp = R;
	R = C;
	C = temp;
	transposed = !transposed;
}

void setAllMines()
{
	for(int i=0; i<50; i++)
		for(int j=0; j<50; j++) matrix[i][j] = '*';
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
		inData >> R;
		inData >> C;
		inData >> M;
		int notM = R*C-M;

		bool impossible = 0;
		setAllMines();
		transposed = 0;
		if(R<C)  transpose();
			
		if( notM==1 )  //don't do anything, there is only one empty cell
		{
		}
		else if(C==1)  //special case
		{
			for(int i=0; i<R; i++)
			{
				matrix[i][0] = '.';
				if( (R-i-1) == M ) break;
			}
		}
		else if(C==2)  //special case
		{
			if( (M%2) || (notM<4)  )  impossible = 1;
			else
			{
				for(int i=0; i<(notM/2); i++)
				{
					matrix[i][0] = '.';
					matrix[i][1] = '.';
				}
			}
		}
		else  // R>=3 and C>=3
		{
			if( (notM<4) || (notM==5) || (notM==7) )  impossible = 1;
			else
			{
				matrix[0][0] = '.';
				matrix[0][1] = '.';
				matrix[1][0] = '.';
				matrix[1][1] = '.';
				int tNotM = notM - 4;
				if(tNotM>0)   //let's try to fill out 2 first rows and 2 columns
				{
					for(int i=2; i<R; i++)
					{
						matrix[i][0] = '.';
						matrix[i][1] = '.';
						tNotM -= 2;
						if(tNotM<2) break;

						if(i<C)
						{
							matrix[0][i] = '.';
							matrix[1][i] = '.';
							tNotM -= 2;
							if(tNotM<2) break;
						}
					}

					if(tNotM>0)  //now fill out the rest, we can go by one cell now
					{
						for(int i=2; (i<R) && (tNotM>0); i++)
						{
							for(int j=2; (j<C) && (tNotM>0); j++)
							{
								matrix[i][j] = '.';
								tNotM--;
							}
						}
					}
				}
			}
		}

		matrix[0][0] = 'c';

		outData << QString("Case #%1:\r\n").arg(t+1);
		if(impossible)  outData << QString("Impossible\r\n");
		else
		{
			if(transposed)  transpose();
			for(int i=0; i<R; i++)
			{
				for(int j=0; j<C; j++)  outData << matrix[i][j];
				outData << "\r\n";
			}
		}
	}
}