using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace _1C_A.Diamond_Inheritance
{
    class SimpleClass
    {
        public SimpleClass(Int32 num)
        {
            ClassNum = num;
            Parents = new List<Int32>();
        }
        public Int32 ClassNum { get; private set; }
        public List<Int32> Parents { get; set; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            SimpleClass[] classes = null;

            String fileName = "N:/Users/Spidy/Downloads/" + Console.ReadLine();
            StreamReader fileStream = new StreamReader(fileName);
            StreamWriter output = new StreamWriter("N:/Users/Spidy/Downloads/A-large-attempt0-out.txt");
            int numTestCases = Int32.Parse(fileStream.ReadLine());
            for (int testCase = 0; testCase < numTestCases; ++testCase)
            {
                int numClasses = Int32.Parse(fileStream.ReadLine());
                classes = new SimpleClass[numClasses];
                for (int classNum = 0; classNum < numClasses; ++classNum)
                {
                    String[] testCaseInput = fileStream.ReadLine().Split(' ');
                    int classInheritCount = Int32.Parse(testCaseInput[0]);
                    SimpleClass sClass = new SimpleClass(classNum);
                    for (int parentNum = 0; parentNum < classInheritCount; ++parentNum)
                    {
                        sClass.Parents.Add(Int32.Parse(testCaseInput[parentNum + 1]) - 1);
                    }

                    classes[classNum] = sClass;
                }

                Stack<Int32> pathQueue = new Stack<int>();
                bool hasDiamond = false;
                try
                {
                    for (int classNum = 0; classNum < numClasses; ++classNum)
                    {
                        SimpleClass curClass = classes[classNum];
                        pathQueue.Push(curClass.ClassNum);

                        List<Int32> parentList = new List<int>();
                        while (pathQueue.Count > 0)
                        {
                            SimpleClass node = classes[pathQueue.Pop()];
                            if (parentList.Contains(node.ClassNum))
                            {
                                throw new Exception("Diamond");
                            }
                            parentList.Add(node.ClassNum);

                            for( int i = 0; i < node.Parents.Count; ++i )
                            {
                                if (pathQueue.Contains(node.Parents[i]))
                                {
                                    throw new Exception("Diamond");
                                }
                                pathQueue.Push(node.Parents[i]);
                            }
                        }
                    }
                }
                catch (Exception)
                {
                    hasDiamond = true;
                }

                output.WriteLine("Case #" + (testCase + 1) + ": " + (hasDiamond ? "Yes" : "No"));
                Console.WriteLine("Case #" + (testCase + 1) + ": " + (hasDiamond ? "Yes" : "No"));
            }

            fileStream.Close();
            output.Close();
            Console.ReadKey();
        }
    }
}
