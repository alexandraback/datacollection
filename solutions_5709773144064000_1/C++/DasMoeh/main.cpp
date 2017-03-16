#include <QTextStream>
#include <QFile>
#include <QStringList>

#include <QDebug>

#include <cmath>

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
  //qDebug() << "Cases:" << numberOfCases;
  for (int c = 1; c <= numberOfCases; ++c)
  {
    QStringList parameters = in.readLine().split(" ");
    //qDebug() << "C F X" << parameters;
    Q_ASSERT(parameters.size() == 3);
    double base = 2;
    double C = parameters[0].toDouble();
    double F = parameters[1].toDouble();
    double X = parameters[2].toDouble();
    //qDebug() << "C =" << C << "F =" << F << "X =" << X;
    double time = 0;
    double secToWin = X/base;
    double secToFarm = C/base;
    double secToWinWithFarm = X/(base + F);
    while ((secToFarm+secToWinWithFarm) < secToWin)
    {
      time = time + secToFarm;
      base = base + F;
      secToWin = X/base;
      secToFarm = C/base;
      secToWinWithFarm = X/(base + F);
    }
    time = time + secToWin;
    out << "Case #" << c << ": " << time << endl;
  }
  inFile.close();
  outFile.close();
  return 0;
}
