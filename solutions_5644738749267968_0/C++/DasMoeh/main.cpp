#include <QTextStream>
#include <QFile>
#include <QStringList>

#include <QDebug>

#include <cmath>

int playWar(QList<double> naomiBlocks, QList<double> kenBlocks);
int playDeceitfulWar(QList<double> naomiBlocks, QList<double> kenBlocks);

int main(int argc, char** argv)
{
  QFile inFile("/home/alex/projects/GoogleCodeJam/input/input.txt");
  if(!inFile.open(QIODevice::ReadOnly)) {
    qDebug() <<  "ReadError:" << inFile.errorString();
    return -1;
  }
  QTextStream in(&inFile);
  QFile outFile("/home/alex/projects/GoogleCodeJam/input/output.txt");
  if(!outFile.open(QIODevice::WriteOnly)) {
    qDebug() <<  "WriteError:" << outFile.errorString();
    return -1;
  }
  QTextStream out(&outFile);
  out.setRealNumberNotation(QTextStream::FixedNotation);
  out.setRealNumberPrecision(7);
  int numberOfCases = in.readLine().toInt();
  qDebug() << "Cases:" << numberOfCases;
  for (int c = 1; c <= numberOfCases; ++c)
  {
    int nBlocks = in.readLine().toInt();
    qDebug() << "Blocks:" << nBlocks;
    //Naomi Blocks
    QStringList inNaomiBlocks = in.readLine().split(" ");
    //qDebug() << "Naomi Block List:" << inNaomiBlocks;
    Q_ASSERT(inNaomiBlocks.size() == nBlocks);
    QList<double> naomiBlocks;
    for (int i = 0; i < inNaomiBlocks.size(); ++i)
    {
      naomiBlocks.append(inNaomiBlocks[i].toDouble());
    }
    qSort(naomiBlocks);
    qDebug() << "Naomi Blocks:" << naomiBlocks;
    //Ken Blocks
    QStringList inKenBlocks = in.readLine().split(" ");
    //qDebug() << "Ken Block List:" << inKenBlocks;
    Q_ASSERT(inKenBlocks.size() == nBlocks);
    QList<double> kenBlocks;
    for (int i = 0; i < inKenBlocks.size(); ++i)
    {
      kenBlocks.append(inKenBlocks[i].toDouble());
    }
    qSort(kenBlocks);
    qDebug() << "Ken Blocks:" << kenBlocks;
    out << "Case #" << c << ": " << playDeceitfulWar(naomiBlocks, kenBlocks) << " " << playWar(naomiBlocks, kenBlocks) << endl;
  }
  inFile.close();
  outFile.close();
  return 0;
}

int playWar(QList<double> naomiBlocks, QList<double> kenBlocks)
{
  int naomiPoints = 0;
  for(int i = 0; i < naomiBlocks.size(); ++i)
  {
    int j = 0;
    for (; j < kenBlocks.size(); ++j)
    {
      if (naomiBlocks[i] < kenBlocks[j])
      {
	break;
      }
    }
    if (j < kenBlocks.size())
    {
      kenBlocks.removeAt(j);
    }
    else
    {
      naomiPoints++;
      kenBlocks.removeFirst();
    }
  }
  return naomiPoints;
}

int playDeceitfulWar(QList<double> naomiBlocks, QList<double> kenBlocks)
{
  int naomiPoints = 0;
  for(int i = 0; i < naomiBlocks.size(); ++i)
  {
    if (naomiBlocks[i] < kenBlocks.first())
    {
      kenBlocks.removeLast();
    }
    else
    {
      naomiPoints++;
      kenBlocks.removeFirst();
    }
  }
  return naomiPoints;
}