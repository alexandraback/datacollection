using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections.Concurrent;
using System.Threading;
using System.Threading.Tasks;

namespace GoogleCodeJam2012_Stage2_1
{
    class Program
    {
        static void Main(string[] args)
        {
            HashSet<ClassDef> testCaseClasses = new HashSet<ClassDef>();
            using (StreamReader strR = new StreamReader("input.txt"))
            {
                using (StreamWriter strW = new StreamWriter("output.txt", false))
                {
                    int i = 0;
                    int classLeft = 0;
                    int classIndex = 0;
                    int casesLeft = 0;
                    int caseIndex = 1;
                    bool isFirstRun = true;
                    while (!strR.EndOfStream)
                    {
                        if (i == 0)
                        {
                            casesLeft = int.Parse(strR.ReadLine());
                            i++;
                            continue;
                        }
                        else if (classLeft == 0)
                        {
                            if (!isFirstRun)
                            {
                                WriteResultForTestCase(strW, caseIndex, casesLeft, testCaseClasses);
                                caseIndex++;
                            }
                            else
                                isFirstRun = false;
                            classIndex = 1;
                            testCaseClasses = new HashSet<ClassDef>();
                            classLeft = int.Parse(strR.ReadLine());
                            for (int k = 1; k <= classLeft; k++)
                            {
                                testCaseClasses.Add(new ClassDef(k));
                            }
                        }
                        else
                        {
                            testCaseClasses.FillTestClass(classIndex++, strR.ReadLine());
                            classLeft--;
                        }
                    }
                    //WriteLastResult
                    WriteResultForTestCase(strW, caseIndex, casesLeft, testCaseClasses);
                }
                strR.Close();
            }
        }

        private static void WriteResultForTestCase(StreamWriter strW, int caseIndex, int casesLeft, HashSet<ClassDef> testCaseClasses)
        {
            strW.Write(String.Format("Case #{0}: ", caseIndex));
            if (caseIndex == casesLeft)
                strW.Write(CheckIfDiamonExist(testCaseClasses));
            else
                strW.WriteLine(CheckIfDiamonExist(testCaseClasses));
        }

        private static ConcurrentDictionary<int,int> indexes;
        private static int existSecondPath=0; 
        private static string CheckIfDiamonExist(HashSet<ClassDef> testCaseClasses)
        {
            HashSet<int> indexElements = new HashSet<int>();
            
            foreach (var classRef in testCaseClasses)
            {
                existSecondPath = 0;
                indexes = new ConcurrentDictionary<int, int>();
                HashSet<Task> tasks = new HashSet<Task>();
                {
                    ClassDef fclassRef = classRef;
                    tasks.Add(Task.Factory.StartNew(()=>FillAllRefClasses(fclassRef), TaskCreationOptions.LongRunning));
                }
                Task.WaitAll(tasks.ToArray());                
                //foreach (var referencedClass in classRef.ClassRef)
                //    if (indexElements.Contains(referencedClass.Index))
                //        return "Yes";
                //    else
                //        indexElements.Add(referencedClass.Index);
                if (existSecondPath > 0) return "Yes";
            }
            return "No";
        }
        private static void FillAllRefClasses(ClassDef def)
        {
            if(def.ClassRef== null || def.ClassRef.Count==0) return;
            foreach (var el in def.ClassRef)
            {
                if (indexes.Keys.Contains((el.Index)))
                {
                    Interlocked.Increment(ref existSecondPath);
                }
                else
                {
                    indexes.TryAdd(el.Index, el.Index);
                    FillAllRefClasses(el);
                }
            }
        }
    }
    public static class Extensions
    {
        public static void FillTestClass(this HashSet<ClassDef> testCaseClasses, int index, string p)
        {
            ClassDef def = testCaseClasses.ElementAt(index - 1);
            List<string> parameters = p.Split(' ').ToList();
            bool FirstEl = true;
            foreach (var el in parameters)
            {
                if (FirstEl)
                {
                    FirstEl = false;
                    continue;
                }

                ClassDef ClassDefToReferrence = testCaseClasses.FirstOrDefault(t => t.Index == int.Parse(el));
                def.ClassRef.Add(ClassDefToReferrence);
            }
        }
    }
    public class ClassDef
    {
        public ClassDef(int index)
        {
            Index = index;
        }
        public int Index { get; private set; }
        private HashSet<ClassDef> _classRef;
        public HashSet<ClassDef> ClassRef
        {
            get
            {
                if (_classRef == null)
                    _classRef = new HashSet<ClassDef>();
                return _classRef;
            }
            set
            {
                _classRef = value;
            }
        }
    }
}
