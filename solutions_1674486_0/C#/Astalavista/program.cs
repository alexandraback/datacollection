using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamFirst
{
    class Program
    {
        static List<tempClass> listOfAllClasses;

        static void Main(string[] args)
        {
            int NoOfTestCases = int.Parse(Console.ReadLine());

            for (int T = 0;T  < NoOfTestCases; T++)
            {
                int N = int.Parse(Console.ReadLine());

                listOfAllClasses = new List<tempClass>();

                for (int i = 0; i < N; i++)
                {
                    string classInfo = Console.ReadLine();

                    string[] parts = classInfo.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                    tempClass newClass = new tempClass();
                    newClass.ClassName = i+1;
                    newClass.NoOfInheritedClasses = int.Parse(parts[0]);
                    newClass.listOfInheritedClass = new List<int>();

                    for (int j = 0; j < newClass.NoOfInheritedClasses; j++)
                    {
                        newClass.listOfInheritedClass.Add(int.Parse (parts[j + 1]));
                    }

                    listOfAllClasses.Add(newClass);

                }

                //GiveOutput(listOfAllClasses,T);

                List<int> roots = new List<int>();

                bool breakstatus = false;
            
                for (int i = 0; i < listOfAllClasses.Count; i++)
                {
                    roots = FindRoots(listOfAllClasses[i]);
                    
                    for(int j=0; j<roots.Count; j++)
                        if(IsDouble(roots,roots[j]))
                        {
                            Console.WriteLine("Case #{0}: {1}", (T + 1).ToString(), "Yes");
                            breakstatus = true;
                            break;
            
                        }

                    if (breakstatus)
                    {
                        break;
                    }
                }

                if(!breakstatus)
                    Console.WriteLine("Case #{0}: {1}", (T + 1).ToString(), "No");
            }

            
        }

        private static bool IsDouble(List<int> roots,int value)
        {
            int count = 0;

            for (int i = 0; i < roots.Count; i++)
                if (roots[i] == value)
                    ++count;

            if (count > 1) return true;

            else return false;
        }

        private static List<int> FindRoots(tempClass child)
        {           
            List<int> roots = new List<int>();

            for (int i = 0; i < child.listOfInheritedClass.Count; i++)
            {
                roots.Add(child.listOfInheritedClass[i]);
                tempClass parent = GetClassFromName(child.listOfInheritedClass[i]);
                roots.AddRange(FindRoots(parent));                
            }

            return roots;
        }

        //private static void GiveOutput(List<tempClass> listOfAllClasses, int TestCase)
        //{
           

        //    for (int i = 0; i < listOfAllClasses.Count; i++)
        //    {
        //        int successPath = 0;

        //        for (int j = 0; j < listOfAllClasses.Count; j++)
        //        {
        //            successPath += CanReachFromOneToAnother(listOfAllClasses[i].ClassName, listOfAllClasses[j].ClassName);

        //            if (successPath >= 2)
        //            {
        //                Console.WriteLine("Case #{0}: {1}", (TestCase + 1).ToString(), "Yes");
        //                return;
        //            }
        //        }
        //    }

        //    Console.WriteLine("Case #{0}: {1}", (TestCase + 1).ToString(), "No");
        //}

        //private static int CanReachFromOneToAnother(int p, int p_2)
        //{
            
        //}

        private static tempClass GetClassFromName(int className)
        {
            for (int i = 0; i < listOfAllClasses.Count; i++)
                if (listOfAllClasses[i].ClassName == className)
                    return listOfAllClasses[i];

            return null;
        }
    }

    class tempClass
    {
        public int ClassName { get; set; }
        public int NoOfInheritedClasses { get; set; }
        public List<int> listOfInheritedClass { get; set; }
    }
}
