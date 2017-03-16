using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P_C
{
    class Program
    {
        static void Main(string[] args)
        {
            var local = false;

            var input = new Input();
            var output = new Output();

            if (local)
            {
                input.loadString(
                    @"5
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
");
            }
            else
            {
                input.loadFile(@"C:\Users\talal\Downloads\C-small-attempt1.in");
                output.setSaveFile(@"C:\Users\talal\Downloads\C-Small.out");
            }
        
            var testCaseCount = input.readInt();
            for (int testCaseIdx = 0; testCaseIdx < testCaseCount; testCaseIdx++)
            {
                //load info
                var controlArr = input.readIntArr();
                var inputDataLen = controlArr[0];
                var inputDataRepeatCount = controlArr[1];

                var inputData = input.readLine();

                string dataStr = "";
                for (int inputDataIdx = 0; inputDataIdx < inputDataRepeatCount; inputDataIdx++)
                {
                    dataStr += inputData;
                }
                
                List<Quaternion> qList = new List<Quaternion>();
                for (int dataIdx = 0; dataIdx < dataStr.Length; dataIdx++)
                {
                    qList.Add(new Quaternion(1, dataStr.Substring(dataIdx, 1)));
                }

                //solution
                Multiplicative multiplicative = new Multiplicative();

                while (qList.Count > 1)
                {
                    var newVal = multiplicative.multiply(qList[0], qList[1]);
                    qList.RemoveAt(0);
                    qList.RemoveAt(0);
                    qList.Insert(0, newVal);
                }
             
                output.writeLine((qList[0].sign == -1 && qList[0].symbol == _.SymbolEnum.o) ? "YES" : "NO");
            }
            output.end();
        }
    }
}
