using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace MinesweeperMaster
{
    public enum Result
    {
        Possible,
        Impossible
    }

    public enum sq
    {
        Empty,
        Mine,
        Click,  
        Number
    }

    class TestCase
    {
        int number;
        int rows;
        int columns;
        int mines;
        int size;
        int spaces;
        int spaceSofar;

        int? mineCol;
        int? mineRow;

        Result? result;
        sq[,] board;

        public List<string> GetResult()
        {
            var msg = new List<string>();
            if (result == null)
                Calc();

            var sb = new StringBuilder();

            msg.Add(string.Format("Case #{0}:", number));
            if (result == Result.Impossible)
                msg.Add("Impossible");
            else
            {   
                for (int r = 0; r < rows; r++)
                {
                    sb.Clear();
                    for (int c = 0; c < columns; c++)
                    {
                        switch (board[r,c])
                        {
                            case sq.Click:
                                sb.Append("c");
                                break;
                            case sq.Empty:
                            case sq.Number:
                                sb.Append(".");
                                break;
                            case sq.Mine:
                                sb.Append("*");
                                break;
                        }
                    }
                    msg.Add(sb.ToString());
                        
                }
            }
            return msg;
        }

        public TestCase(int _number, int _rows, int _columns, int _mines)
        {
            number = _number;
            rows = _rows;
            columns = _columns;
            mines = _mines;
            size = rows * columns;
            spaces = size - mines;
         

        }

        private void Calc()
        {   
            result = Result.Possible;
            board = new sq[rows,columns];
            //board[0, 0] = sq.Click;

            //for (int i = 0; i < mines; i++)
            //{
            //    placeMine();
                
            //}
            //if (!boardIsValid())
            //{

            //    result = Result.Impossible;
            //    return;
            //}

            //try2
            //if (!placeMinesV2(mines))
            //    result = Result.Impossible;

            //try3




            int i=0;
            foreach (int[] p in MyIterator(size,mines))
            {
                //Console.WriteLine("Tst {0} perm {1}", number, i++);
                //var flat = new sq[size];
                //for (int i = 0; i < size; i++)
                //    flat[i] = sq.Empty;
                //for (int i = 0; i < mines; i++)
                //    flat[p[i]] = sq.Mine;

             //   int i = 0;
           
                if (validateBoard(p))
                    return;
            }
            result = Result.Impossible;
        }

      

        public static System.Collections.IEnumerable MyIterator(int size, int sel)
        {
            var r = new List<int[]>();
            var ps = new int[sel];
//            var a = new int[sel];
            bool more = true;
            for (int i = 0; i < sel; i++)
            {
                ps[i] = i;
            }
            int offset = 1;
            while (more)
            {                
                yield return ps;

                //int lvl = sel - 1;
                //bool done = false;

                //while (lvl>=0 && !done)
                //{
                //    ps[lvl]++;
                //    if (ps[lvl] != size)
                //    {
                //        done = true;
                //    }
                //    else
                //    {
                //        if (ps[0] < size - sel)
                //        {
                //            for (int i = lvl; i >= 0; i--)
                //                ps[i] = i + offset;
                //            offset++;
                //            done = true;
                //        }
                //        else
                //        {
                //            break;
                //        }
                //    }
                //}
                //if (!done)
                //    more = false;

                int lvl = sel - 1;
                if (ps[lvl] != size - 1)
                    ps[lvl]++;
                else
                {
                    bool done = false;
                    while (lvl > 0)
                    {
                        lvl--;
                        if (ps[lvl] != size - sel + lvl)
                        {
                            ps[lvl]++;
                            for (int i = lvl + 1; i < sel; i++)
                                ps[i] = ps[i - 1] + 1;
                            done = true;
                            break;
                        }
                    }
                    if (!done)
                        more = false;
                }
                

            }

            
        }

        

        private bool validateBoard(int[] p)
        {
            for (int r = 0; r < rows; r++)
            {
                for (int c =0;c<columns ; c++)
                {
                    redrawboard(p);
                    spaceSofar = 0;
                    if (board[r, c] == sq.Mine) 
                    {
                        //boom
                        break;
                    }
                    else if (board[r,c] == sq.Empty)
                    {
                        board[r, c] = sq.Click;
                        spaceSofar++;
                        check(surround(new coord(r,c)));
                    }
                    if (spaceSofar == spaces)
                    {
                        //solution found
                        return true;
                    }
                }
            }
            return false; ;
        }

        private void redrawboard(int[] p)
        {
            //Console.WriteLine("-------------------------------------------------------");
            for (int r1 = 0; r1 < rows; r1++)
            {
                for (int c1 = 0; c1 < columns; c1++)
                {
                    board[r1, c1] = (p.Contains(r1 * columns + c1)) ? sq.Mine : sq.Empty;
                    //Console.Write(board[r1, c1]==sq.Mine?"*":".");
                }
                //Console.WriteLine();
            }
        }

        public class coord
        {
            public int r;
            public int c;
            public coord(int _r, int _c)
            {
                r = _r;
                c = _c;
            }
        }

        private bool check(List<coord> list)
        {
            foreach (var c in list)
            {
                if (board[c.r, c.c] == sq.Empty)
                {
                    board[c.r, c.c] = sq.Number;
                    spaceSofar++;
                    check(surround(new coord(c.r,c.c)));

                }
            }
            return false;
        }

        private List<coord> surround(coord co)
        {
            var list = new List<coord>();
            if (co.r > 0)
                list.Add(new coord(co.r-1,co.c));
            if (co.r > 0 && co.c > 0)
                list.Add(new coord(co.r-1,co.c-1));
            if (co.r > 0 && co.c < columns - 1)
                list.Add(new coord(co.r-1,co.c+1));

            if (co.c > 0)
                list.Add(new coord(co.r, co.c - 1));
            if (co.c < columns - 1)
                list.Add(new coord(co.r, co.c + 1));

            if (co.r  < rows - 1)
                list.Add(new coord(co.r + 1, co.c));
            if (co.r < rows -1 && co.c > 0)
                list.Add(new coord(co.r + 1, co.c - 1));
            if (co.r < rows -1 && co.c < columns - 1)
                list.Add(new coord(co.r + 1, co.c + 1));

            foreach (var x in list)
            {
                if (board[x.r, x.c] == sq.Mine)
                    return new List<coord>();
            }


            return list;
        }

        private bool placeMine()
        {
            if (mineCol == null)
            {
                mineCol = columns - 1;
                mineRow = rows - 1;
            }
            else
            {
                mineCol--;
                if (mineCol == -1)
                {
                    mineCol = columns - 1;
                    mineRow--;
                }

            }
            if (mineRow == 1 && mineCol < columns-1 && rows > 1)
            {
                if (board[0, mineCol.Value + 1] == sq.Empty)
                {
                    mineRow = 0;
                    mineCol = mineCol.Value + 1;
                }

            }
            //if (board[mineRow.Value, mineCol.Value] == sq.Mine)
            //    Console.WriteLine("ERROR");
            board[mineRow.Value, mineCol.Value] = sq.Mine;

            if (mineRow == 0 && rows > 1)
                mineRow = 1;

            return true;
        }

        private bool placeMinesV2(int mines)
        {
            for (int c = columns -1; c >= 0; c--)
            {
                for (int r = rows - 1; r >= 0; r++)
                {
                    if (valid(r,c))
                    {
                        board[r,c] = sq.Mine;
                        mines--;
                        if (mines == 0)
                            return true;
                    }

                }
            }
            return false;
            
        }

        private bool valid(int r,int c)
        {

            return true;
        }

        private bool boardIsValid()
        {
            //assumes click 0,0
            if (columns > 1 && board[0, 1] == sq.Mine)
                return false;
            if (rows > 1 && board[1, 0] == sq.Mine)
                return false;
            if (columns > 1 && rows > 1 && board[1, 1] == sq.Mine)
                return false;
            //if (columns > 3 && rows > 1)
            //{
            //    for (int i = 1; i<columns-2; i++)
            //    {
            //        if (board[0, i] == sq.Empty &&
            //            board[0, i + 1] == sq.Empty &&
            //            board[0, i + 2] == sq.Mine &&
            //            board[1, i + 1] == sq.Mine)
            //            return false;
            //    }
            //}

            //if (rows > 3 && columns > 1)
            //{
            //    for (int i = 1; i < rows - 2; i++)
            //    {
            //        if (board[i,0] == sq.Empty &&
            //            board[i+1,0] == sq.Empty &&
            //            board[i+2,0] == sq.Mine &&
            //            board[i + 1,1] == sq.Mine)
            //            return false;
            //    }
            //}
            for (int i = 0; i < rows - 1; i++)
            {
                for (int j = 0; j < columns - 1; j++)
                {
                    if (board[i, j] == sq.Empty &&
                        board[i + 1, j + 1] == sq.Mine)
                    {
                        //if (i == rows - 2 || j == columns - 2)
                        //    return false;
                        //if (i < rows - 3 &&
                        //    board[i + 1, j] == sq.Empty &&
                        //    board[i+2, j] == sq.Mine)
                        //    return false;
                        //if (j < columns - 3 &&
                        //   board[i, j + 1] == sq.Empty &&
                        //   board[i, j + 2] == sq.Mine)
                        //    return false;
                    }
                }


            }

            return true;
        }


    }
    class MineSweepMaster
    {
        static void Main(string[] args)
        {
            try
            {
                using (StreamReader sr = new StreamReader(string.Format("c:\\codejam\\{0}", args[0])))
                {
                    System.IO.StreamWriter file = new System.IO.StreamWriter(string.Format("c:\\codejam\\out_{0}", args[0]));
                    int numberOfTest = Int32.Parse(sr.ReadLine());
                    TestCase test;
                    Console.WriteLine(string.Format("{0} Test cases", numberOfTest));
                    for (int i = 0; i < numberOfTest; i++)
                    {
                        var line = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();


                        //could check prices.Count() == noItems;
                        test = new TestCase(i + 1, line[0], line[1], line[2]);
                        var results = test.GetResult();
                        foreach (var res in results)
                            file.WriteLine(res);
                        //if (i % 10 == 0)
                        Console.WriteLine(string.Format("wrote test {0}", i + 1));
                    }
                    file.Close();
                    //Console.WriteLine(string.Format("Done {0} Tests", numberOfTest));

                }
                //Console.WriteLine("Local");
                //Console.WriteLine(string.Join("\n", new TestCase(1, 5, 5, 23).GetResult()));
                //Console.WriteLine(string.Join("\n", new TestCase(2, 3, 1, 1).GetResult()));
                //Console.WriteLine(string.Join("\n", new TestCase(3, 2, 2, 1).GetResult()));
                //Console.WriteLine(string.Join("\n", new TestCase(4, 4, 7, 3).GetResult()));
                //Console.WriteLine(string.Join("\n", new TestCase(5, 10, 10, 82).GetResult()));
                //Console.WriteLine("it");
                //foreach (int[] x in TestCase.MyIterator(5, 3))
                //{

                //    Console.WriteLine(string.Join(",", x));
                //}

                //foreach (int[] x in TestCase.MyIterator(3, 1))
                //{

                //    Console.WriteLine(string.Join(",", x));
                //}

                //foreach (int[] x in TestCase.MyIterator(4, 1))
                //{

                //    Console.WriteLine(string.Join(",", x));
                //}
                
                Console.ReadKey();

            }
            catch (Exception e)
            {
                Console.WriteLine("Something bad:");
                Console.WriteLine(e.Message);
                return;
            }
        }


    }
}
