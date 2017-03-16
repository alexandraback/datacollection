using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MinesweeperMaster
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                string[] lines = File.ReadAllLines("data_in.txt");
                int nCases = int.Parse(lines[0]);
                int cLine = 1;
                List<string> result = new List<string>();
                for (int c = 0; c < nCases; ++c)
                {
                    var vals = lines[c + 1].Split(' ').Select(i => int.Parse(i)).ToList();
                    int nRows = vals[0];
                    int nColumns = vals[1];
                    int nMines = vals[2];
                    IEnumerable<string> solution = Solve(nRows, nColumns, nMines);
                    result.Add("Case #" + (c + 1) + ":");
                    result.AddRange(solution);
                }
                File.WriteAllLines("data_out.txt", result);
            }
            catch (Exception exc)
            {
                Console.WriteLine("Error: " + exc);
                Console.ReadLine();
            }
        }

        private static IEnumerable<string> Solve(int nRows, int nColumns, int nMines)
        {
            List<string> impossibleResult = new List<string>(new string[] { "Impossible" });
            char[] board = new char[nRows * nColumns];
            for (int c = 0; c < board.Length; ++c)
                board[c] = '.';
            board[0] = 'c';
            int usedMines = 0;
            if (nMines >= nRows * nColumns)
                return impossibleResult;
            if (nMines == nRows * nColumns-1)
            {
                // full
                for (int c = 1; c < board.Length; ++c)
                    board[c] = '*';
            }
            else if (nRows==1)
            {
                if (nMines >= nColumns)
                    return impossibleResult;
                for (int cCol = nColumns - nMines; cCol < nColumns; ++cCol)
                    board[cCol] = '*';
            } 
            else if (nColumns==1)
            {
                if (nMines >= nRows)
                    return impossibleResult;
                for (int cRow = nRows - nMines; cRow < nRows; ++cRow)
                    board[cRow] = '*';
            }
            else
            {
                // fill in board with mines
                for (int cRow = nRows - 1; cRow >= 0; --cRow)
                {
                    if (usedMines == nMines)
                        break;
                    for (int cCol = nColumns - 1; cCol >= 0; --cCol)
                    {
                        if (usedMines == nMines)
                            break;
                        // skip if it is too close to the 'c'
                        if ((cCol == 0 || cCol == 1) || (cRow == 0 || cRow == 1))
                            continue;
                        board[cRow * nColumns + cCol] = '*';
                        ++usedMines;
                    }
                }
                // kombinuj...
                if (usedMines<nMines)
                {
                    bool cornerRemoved = false;
                    if ((nMines-usedMines)%2 == 1)
                    {
                        // usuń mine z rogu
                        if ((nColumns == 2) || (nRows == 2))
                            return impossibleResult;
                        board[2 * nColumns + 2] = '.';
                        --usedMines;
                        cornerRemoved = true;
                    }
                    // wypełnij kolumny na prawo
                    for (int cCol=nColumns-1;cCol>1;--cCol)
                    {
                        if (usedMines >= nMines)
                            break;
                        if (cornerRemoved && cCol == 2)
                            break;
                        // pierwszy i drugi rząd
                        board[cCol] = '*';
                        board[nColumns + cCol] = '*';
                        usedMines += 2;
                    }
                    // wupełnij rzędy od dołu
                    for (int cRow=nRows-1;cRow>1;--cRow)
                    {
                        if (usedMines >= nMines)
                            break;
                        if (cornerRemoved && cRow == 2)
                            break;
                        board[cRow * nColumns] = '*';
                        board[cRow * nColumns + 1] = '*';
                        usedMines += 2;
                    }
                    if (usedMines < nMines)
                    {
                        // przypadek pełnego zapełnienia już rozpatrzony, więc wywalamy błąd...
                        return impossibleResult;
                    }
                }
            }
            // wypluj
            if (usedMines > nMines)
                throw new Exception("usedMines = " + usedMines + "; nMines = " + nMines);
            
            List<string> res = new List<string>();
            for (int cRow=0;cRow<nRows;++cRow)
            {
                String line = String.Empty;
                for (int cCol = 0; cCol < nColumns; ++cCol)
                        line += board[cRow * nColumns + cCol];
                    res.Add(line);
            }
            return res;
        }
    }
}
