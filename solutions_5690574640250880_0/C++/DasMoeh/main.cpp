#include <QTextStream>
#include <QFile>
#include <QStringList>
#include <QGenericMatrix>

#include <QDebug>

#include <cmath>

bool findSolution(QVector<QVector<char> >& matrix, int posRow, int posColumn, int maxRows, int maxColumns, int minesLeft, bool cSet);
bool checkMatrix(QVector<QVector<char> > matrix);
void solveMatrix(QVector<QVector<char> >& matrix, int cx, int cy);
void printMatrix(QVector< QVector< char > > matrix);
void printMatrix(QVector< QVector< char > >& matrix, QTextStream& out);

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
    QStringList parameters = in.readLine().split(" ");
    const int R = parameters[0].toInt();
    const int C = parameters[1].toInt();
    int M = parameters[2].toInt();
    qDebug() << "[R C M]" << R << C << M;
    QVector<QVector<char> > matrix(R);
    for (int i = 0; i < matrix.size(); ++i)
    {
      matrix[i] = QVector<char>(C);
    }
    out << "Case #" << c << ":" << endl;
    if (!findSolution(matrix, 0, 0, R, C, M, false))
    {
      out << "Impossible" << endl;
    }
    else
    {
      printMatrix(matrix, out);
    }
  }
  inFile.close();
  outFile.close();
  return 0;
}

bool findSolution(QVector< QVector< char > >& matrix, int posRow, int posColumn, int maxRows, int maxColumns, int minesLeft, bool cSet)
{
  if ((posRow < maxRows) && (posColumn < maxColumns))
  {
    if (minesLeft > 0)
    {
      matrix[posRow][posColumn] = '*';
      if (findSolution(matrix, posRow, posColumn + 1, maxRows, maxColumns, minesLeft - 1, cSet))
      {
	return true;
      }
    }
    if (!cSet)
    {
      matrix[posRow][posColumn] = 'c';
      if (findSolution(matrix, posRow, posColumn + 1, maxRows, maxColumns, minesLeft, true))
      {
	return true;
      }
    }
    matrix[posRow][posColumn] = '.';
    return findSolution(matrix, posRow, posColumn + 1, maxRows, maxColumns, minesLeft, cSet);
  }
  else if ((posRow < maxRows) && (posColumn == posColumn))
  {
    return findSolution(matrix, posRow + 1, 0, maxRows, maxColumns, minesLeft, cSet);
  }
  else
  {
    Q_ASSERT((posRow == maxRows) && (posColumn == 0));
    if ((minesLeft > 0) || (cSet == false))
    {
      return false;
    }
    return checkMatrix(matrix);
  }
  return false;
}

bool checkMatrix(QVector< QVector< char > > matrix)
{
  //find c
  int cx = 0;
  int cy = 0;
  for (; cx < matrix.size(); ++cx)
  {
    bool found = false;
    for (; cy < matrix[cx].size(); ++cy)
    {
      if (matrix[cx][cy] == 'c')
      {
	found = true;
	break;
      }
    }
    if (found)
    {
      break;
    }
    cy = 0;
  }
  Q_ASSERT((cx < matrix.size()) && (cy < matrix[0].size()));
  solveMatrix(matrix, cx, cy);
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[i].size(); ++j)
    {
      if (matrix[i][j] == '.')
      {
	return false;
      }
    }
  }
  return true;
}

void solveMatrix(QVector< QVector< char > >& matrix, int cx, int cy)
{
  int mines = 0;
  if (((cx - 1) >= 0) && (matrix[cx - 1][cy] == '*'))
  {
    mines++;
  }
  if (((cx - 1) >= 0) && ((cy - 1) >= 0) && (matrix[cx - 1][cy - 1] == '*'))
  {
    mines++;
  }
  if (((cx - 1) >= 0) && ((cy + 1) < matrix[cx - 1].size()) && (matrix[cx - 1][cy + 1] == '*'))
  {
    mines++;
  }
  if (((cx + 1) < matrix.size()) && (matrix[cx + 1][cy] == '*'))
  {
    mines++;
  }
  if (((cx + 1) < matrix.size()) && ((cy - 1) >= 0) && (matrix[cx + 1][cy - 1] == '*'))
  {
    mines++;
  }
  if (((cx + 1) < matrix.size()) && ((cy + 1) < matrix[cx + 1].size()) && (matrix[cx + 1][cy + 1] == '*'))
  {
    mines++;
  }
  if (((cy - 1) >= 0) && (matrix[cx][cy - 1] == '*'))
  {
    mines++;
  }
  if (((cy + 1) < matrix[cx].size()) && (matrix[cx][cy + 1] == '*'))
  {
    mines++;
  }
  matrix[cx][cy] = mines;
  if (mines == 0)
  {
    if (((cx - 1) >= 0) && (matrix[cx - 1][cy] == '.'))
    {
      solveMatrix(matrix, cx - 1, cy);
    }
    if (((cx - 1) >= 0) && ((cy - 1) >= 0) && (matrix[cx - 1][cy - 1] == '.'))
    {
      solveMatrix(matrix, cx - 1, cy - 1);
    }
    if (((cx - 1) >= 0) && ((cy + 1) < matrix[cx - 1].size()) && (matrix[cx - 1][cy + 1] == '.'))
    {
      solveMatrix(matrix, cx - 1, cy + 1);
    }
    if (((cx + 1) < matrix.size()) && (matrix[cx + 1][cy] == '.'))
    {
      solveMatrix(matrix, cx + 1, cy);
    }
    if (((cx + 1) < matrix.size()) && ((cy - 1) >= 0) && (matrix[cx + 1][cy - 1] == '.'))
    {
      solveMatrix(matrix, cx + 1, cy - 1);
    }
    if (((cx + 1) < matrix.size()) && ((cy + 1) < matrix[cx + 1].size()) && (matrix[cx + 1][cy + 1] == '.'))
    {
      solveMatrix(matrix, cx + 1, cy + 1);
    }
    if (((cy - 1) >= 0) && (matrix[cx][cy - 1] == '.'))
    {
      solveMatrix(matrix, cx, cy - 1);
    }
    if (((cy + 1) < matrix[cx].size()) && (matrix[cx][cy + 1] == '.'))
    {
      solveMatrix(matrix, cx, cy + 1);
    }
  }
}

void printMatrix(QVector< QVector< char > > matrix)
{
  for (int i = 0; i < matrix.size(); ++i)
  {
    qDebug() << matrix[i];
  }
}

void printMatrix(QVector< QVector< char > >& matrix, QTextStream& out)
{
  for (int i = 0; i < matrix.size(); ++i)
  {
    for (int j = 0; j < matrix[i].size(); ++j)
    {
      out << matrix[i][j];
    }
    out << endl;
  }
}