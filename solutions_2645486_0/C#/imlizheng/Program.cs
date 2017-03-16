using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Numerics;

namespace Codejam_2013Round1A
{
    class Program
    {
        static uint orin_E = 0;
        static void Main(string[] args)
        {

            FileStream fs = new FileStream("output.out", FileMode.Create);
            StreamWriter sw = new StreamWriter(fs);

            StreamReader sr = new StreamReader("B-small-attempt0.in");

            String line;
            line = sr.ReadLine(); //Number of cases
            int case_num = int.Parse(line.Trim());

            for (int case_id = 0; case_id < case_num; case_id++)
            {
                line = sr.ReadLine(); //Case title information
                string[] strERN;
                strERN = line.Split(' ');
                uint E = uint.Parse(strERN[0].ToString().Trim()), R = uint.Parse(strERN[1].ToString().Trim()), N = uint.Parse(strERN[2].ToString().Trim());
                
                uint[] values = new uint[N];
                line = sr.ReadLine(); // values of activities
                string[] strValues = line.Split(' ');
                for (int i = 0; i < N; i++)
                    values[i] = uint.Parse(strValues[i].Trim());
                orin_E = E;
                string caseResult=CaseSolver(E,R,values).ToString();
                Console.WriteLine("Case #" + (case_id + 1).ToString() + ": "+caseResult);
                sw.WriteLine("Case #" + (case_id + 1).ToString() + ": "+caseResult);
            }//for case_id ...

            sw.Flush();
            sr.Close();
            sw.Close();
            fs.Close();
            Console.WriteLine("Done!");
        }// Main


        static uint CaseSolver(uint E, uint R, uint[] values)
        {
            uint account=0;
            uint positionOfBiggestValue = 0, tmpBiggestValue = 0;
            bool isFound = false;
            
            for (uint i=0; i < values.Length; i++)
            {
                if (values[i] > tmpBiggestValue)
                {
                    tmpBiggestValue = values[i];
                    positionOfBiggestValue = i;
                    isFound = true;
                }
            }
            if (!isFound)
                return 0;

            E = E + R > orin_E ? orin_E : E + R;
            account += E * values[positionOfBiggestValue];

            uint[] leftValues, rightValues;
            if (positionOfBiggestValue > 0)
            {
                leftValues = new uint[positionOfBiggestValue];
                for (uint l = 0; l < positionOfBiggestValue; l++)
                    leftValues[l] = values[l];
                account += CaseSolver(0, R, leftValues);
            }
            if (positionOfBiggestValue < values.Length - 1)
            {
                rightValues = new uint[values.Length - positionOfBiggestValue - 1];
                for (uint r = 0; r < rightValues.Length; r++)
                    rightValues[r] = values[positionOfBiggestValue + r + 1];
                account += CaseSolver(0, R, rightValues);
            }

            return account;
        }//CaseSolver

    }
}
