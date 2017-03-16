using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cj2013qrb
{
    class Program
    {
        static void Main(string[] args)
        {
            var fn = "B-small-attempt0.in";
            using (var strIn = File.OpenText("c:\\Users\\zoli\\Downloads\\cj2013\\" + fn))
            using (var strOut = new StreamWriter("c:\\Users\\zoli\\Downloads\\cj2013\\" + fn + ".out"))
            {
                var cCase = int.Parse(strIn.ReadLine());
                for (int iCase = 0; iCase < cCase; iCase++)
                {
                    var rgstLine = new string[4];
                    var rgstNM = strIn.ReadLine().Split(' ');
                    var dimRow = int.Parse(rgstNM[0]);
                    var dimCol = int.Parse(rgstNM[1]);
                    var matHeight = new int[dimRow,dimCol];
                    for (var iRow = 0; iRow < dimRow; iRow++)
                    {
                        var rgstHeight = strIn.ReadLine().Split(' ');
                        for (var iCol = 0; iCol < dimCol; iCol++)
                            matHeight[iRow, iCol] = int.Parse(rgstHeight[iCol]);
                    }
                    var cjqrb = new Cjqrb(matHeight);
                    
                    Console.WriteLine("Case #{0}: {1}", iCase + 1, cjqrb.fSolvable()?"YES":"NO");
                    strOut.WriteLine("Case #{0}: {1}", iCase + 1, cjqrb.fSolvable() ? "YES" : "NO");
                }
            }
            Console.ReadLine();
        }
    }

    internal class Cjqrb
    {
        private int[,] matHeight;
        private bool[,] matFSolv;
        private Matidx matidxDim;
        public Cjqrb(int[,] matHeight)
        {
            matidxDim = new Matidx {Irow = matHeight.GetLength(0), Icol = matHeight.GetLength(1)};
            this.matHeight = matHeight;
            matFSolv = new bool[matHeight.GetLength(0), matHeight.GetLength(1)];
            for (var iRow = 0; iRow < matHeight.GetLength(0); iRow++)
                for (var iCol = 0; iCol < matHeight.GetLength(1); iCol++)
                    matFSolv[iRow, iCol] = false;
        }

        public bool fSolvable()
        {
            while (true)
            {
                var matidxMin = matidxMinUnsolved();
                if (matidxMin == null)
                    return true;

                if (!(fSolvedSolveInDir(matidxMin, Kdir.Col) || fSolvedSolveInDir(matidxMin, Kdir.Row)))
                    return false;
            }
        }

        private bool fSolvedSolveInDir(Matidx matidx, Kdir kdir)
        {
            var idx = matidx.iInDir(kdir);
            for (var i = 0; i < matidxDim.iInOpDir(kdir); i++)
            {
                var fsolv = kdir == Kdir.Row ? matFSolv[idx, i] : matFSolv[i, idx];
                if (!fsolv)
                {
                    var height = kdir == Kdir.Row ? matHeight[idx, i] : matHeight[i, idx];
                    if (height > matHeight[matidx.Irow, matidx.Icol])
                        return false;
                }
            }

            for (var i = 0; i < matidxDim.iInOpDir(kdir); i++)
            {
                if (kdir == Kdir.Row) matFSolv[idx, i] = true;
                else matFSolv[i, idx] = true;
            }
            return true;
        }

        private Matidx matidxMinUnsolved()
        {
            var minHeight = int.MaxValue;
            Matidx matidxMix = null;
            for (var iRow = 0; iRow < matHeight.GetLength(0); iRow++)
                for (var iCol = 0; iCol < matHeight.GetLength(1); iCol++)
                    if (!matFSolv[iRow, iCol] && matHeight[iRow, iCol] < minHeight)
                    {
                        minHeight = matHeight[iRow, iCol];
                        matidxMix = new Matidx {Irow = iRow, Icol = iCol};
                    }

            return matidxMix;
        }
    }

    class Matidx
    {
        public int Irow { get; set; }
        public int Icol { get; set; }

        public int iInDir(Kdir kdir)
        {
            return kdir == Kdir.Col ? Icol : Irow;
        }

        public int iInOpDir(Kdir kdir)
        {
            return kdir != Kdir.Col ? Icol : Irow;
        }
    }

    enum Kdir {Col, Row}
}
