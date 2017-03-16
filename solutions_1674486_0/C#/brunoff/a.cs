using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace codejam._2012.rnd1c.a
{
    class a
    {
        const string _INPUT_FILE_PATH = @"J:\codejam.2012.rnd1c.a\A-small-attempt1.in";
        const string _OUTUT_FILE_PATH = @"J:\codejam.2012.rnd1c.a\A-small-attempt1.out";

        static int testCase, testCaseTotal;
        StringBuilder tempString;

        static void Main(string[] args) { new a().run(); }

        int[] string2intarray(string inputString) {
            int[] outputArray = null;
            int arraySize = 0;
            int decimalPlace = 0, arrayPosition = -1;
            foreach (char inputChar in inputString) {
                if (inputChar != ' ') {
                    if (arrayPosition == -1) {
                        if (decimalPlace == 0) arraySize = (int)(inputChar - '0');
                        else arraySize = (10 * arraySize + (int)(inputChar - '0'));
                        decimalPlace++;
                    }
                    else {
                        if (decimalPlace == 0) outputArray[arrayPosition] = (int)(inputChar - '0');
                        else outputArray[arrayPosition] = (10 * outputArray[arrayPosition] + (int)(inputChar - '0'));
                        decimalPlace++;
                    }
                } else {
                    arrayPosition++;
                    if (arrayPosition == 0)
                        outputArray = new int[arraySize];
                    decimalPlace = 0;
                }
            }
            for (arrayPosition = 0; arrayPosition < arraySize; arrayPosition++)
                outputArray[arrayPosition]--;
            return outputArray;
        }

        void run()
        {
            StreamReader inputstream = new StreamReader(_INPUT_FILE_PATH);
            StreamWriter outputstream = new StreamWriter(_OUTUT_FILE_PATH);
            tempString = new StringBuilder();
            testCaseTotal = Int32.Parse(inputstream.ReadLine());
            for (testCase = 1; testCase <= testCaseTotal; testCase++, tempString.Clear()) {
                int classesCount = Int32.Parse(inputstream.ReadLine());
                List<int[]> classesInheritance = new List<int[]>();
                for (int classNumber = 0; classNumber < classesCount; classNumber++)
                    classesInheritance.Add(string2intarray(inputstream.ReadLine()));
                solve(classesInheritance, classesCount);
                outputstream.Write(tempString.ToString());
            }
            inputstream.Close();
            outputstream.Close();
        }

        void solve(List<int[]> classesInheritance, int classesCount) {
            tempString.Append("Case #").Append(testCase).Append(": ");
            tempString.Append(solveClass(classesInheritance, classesCount)?"Yes":"No").Append('\n');
        }

        bool solveClass(List<int[]> classesInheritance, int classesCount) {
            List<HashSet<int>> parentsSet = new List<HashSet<int>>();
            for (int classNumber = 0; classNumber < classesCount; classNumber++) {
                parentsSet.Add(new HashSet<int>());
                if (classesInheritance[classNumber] != null) {
                    //parentsSet.Add(new HashSet<int>(classesInheritance[classNumber]));
                    foreach (int parentClass in classesInheritance[classNumber])
                        if (parentsFill(parentsSet[classNumber], parentClass, classesInheritance))
                            return true;
                }
                //parentsSet.Add(new HashSet<int>());
                
                //foreach (int parentClass in classesInheritance[classNumber])
                    //    if (classesInheritance[parentClass] != null)
                    //        foreach (int grandParentClass in classesInheritance[parentClass])
                    //            if (grandparentsFill(grandparents[classNumber], grandParentClass, classesInheritance))
                    //                return true;
            }
            return false;
        }

        bool parentsFill(HashSet<int> parentsSet, int parentClass, List<int[]> classInheritance) {
            if (parentsSet.Contains(parentClass))
                return true;
            else {
                parentsSet.Add(parentClass);
                if (classInheritance[parentClass] != null)
                    foreach (int grandparentClass in classInheritance[parentClass])
                        if (parentsFill(parentsSet, grandparentClass, classInheritance))
                            return true;
            }
            return false;
        }
    }
}
