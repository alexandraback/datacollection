using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount;

            using (StreamReader file = new StreamReader("C-large.in"))
            {
                using (StreamWriter output = new StreamWriter("output.txt"))
                {
                    int[,] lookup = { { 0, 1, 2, 3 }, { 1, 4, 3, 6 }, { 2, 7, 4, 1 }, { 3, 2, 5, 4 }, { 4, 5, 6, 7 }, { 5, 0, 7, 2 }, { 6, 3, 0, 5 }, { 7, 6, 1, 0 } };
                    testCaseCount = int.Parse(file.ReadLine());
                    for (int testCaseIndex = 0; testCaseIndex < testCaseCount; ++testCaseIndex)
                    {
                        string[] splitLine = file.ReadLine().Split(new char[] { ' ' });
                        int lineLength = int.Parse(splitLine[0]);
                        long totalLoops = long.Parse(splitLine[1]);
                        char[] lineDataStr = file.ReadLine().ToCharArray();
                        int[] lineData = new int[lineDataStr.Length];
                        for (int index = 0; index < lineData.Length; ++index)
                        {
                            if (lineDataStr[index] == 'i')
                            {
                                lineData[index] = 1;
                            }
                            else if (lineDataStr[index] == 'j')
                            {
                                lineData[index] = 2;
                            }
                            else if (lineDataStr[index] == 'k')
                            {
                                lineData[index] = 3;
                            }
                        }
                        int currLoop = 0;
                        const int totalAllowedLoops = 5;
                        int allowLoops = totalAllowedLoops;
                        
                        bool foundI = false;
                        bool foundJ = false;
                        bool foundK = false;
                        bool success = false;
                        int currChar = 0;
                        // 0 1
                        // 1 i
                        // 2 j
                        // 3 k
                        // 4 -1
                        // 5 -i
                        // 6 -j
                        // 7 -k
                        
                        while (allowLoops > 0 && currLoop < totalLoops)
                        {
                            ++currLoop;
                            --allowLoops;
                            for (int charIndex = 0; charIndex < lineData.Length; ++charIndex)
                            {
                                currChar = lookup[currChar,lineData[charIndex]];
                                if (!foundI)
                                {
                                    if (currChar == 1)
                                    {
                                        foundI = true;
                                        currChar = 0;
                                        allowLoops = totalAllowedLoops;
                                    }
                                }
                                else if (!foundJ)
                                {
                                    if (currChar == 2)
                                    {
                                        foundJ = true;
                                        currChar = 0;
                                        allowLoops = totalAllowedLoops;
                                    }
                                }
                                else if (!foundK)
                                {
                                    if (currChar == 3)
                                    {
                                        foundK = true;
                                        currChar = 0;
                                        allowLoops = 0;
                                    }
                                }
                            }
                        }

                        if (foundK)
                        {
                            if (currLoop < totalLoops)
                            {
                                int newChar = 0;
                                for (int charIndex = 0; charIndex < lineData.Length; ++charIndex)
                                {
                                    newChar = lookup[newChar, lineData[charIndex]];
                                }
                                switch ((totalLoops - currLoop) % 4)
                                {
                                    case 0:
                                        if (currChar == 0)
                                        {
                                            success = true;
                                        }
                                        break;
                                    case 1:
                                        if (currChar == 0 || currChar == 4)
                                        {
                                            if (currChar == newChar)
                                            {
                                                success = true;
                                            }
                                        }
                                        else
                                        {
                                            if (currChar - newChar == 4 || currChar - newChar == -4)
                                            {
                                                success = true;
                                            }
                                        }
                                        break;
                                    case 2:
                                        if (currChar == 0)
                                        {
                                            if (newChar == 0 || newChar == 4)
                                            {
                                                success = true;
                                            }
                                        }
                                        else if (currChar == 4)
                                        {
                                            if (newChar != 0 && newChar != 4)
                                            {
                                                success = true;
                                            }
                                        }
                                        break;
                                    case 3:
                                        if (currChar == newChar)
                                        {
                                            success = true;
                                        }
                                        break;
                                }
                            }
                            else if (currChar == 0)
                            {
                                success = true;
                            }
                        }

                        if (success)
                        {
                            output.WriteLine("Case #" + (testCaseIndex + 1) + ": " + "YES");
                            Console.WriteLine("Case #" + (testCaseIndex + 1) + ": " + "YES");
                        }
                        else
                        {
                            output.WriteLine("Case #" + (testCaseIndex + 1) + ": " + "NO");
                            Console.WriteLine("Case #" + (testCaseIndex + 1) + ": " + "NO");
                        }
                        
                    }
                }
            }
        }
    }
}
