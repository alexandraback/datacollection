using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCaseCount = int.Parse(Console.ReadLine());
            for (int i = 0; i < testCaseCount; ++i)
            {
                DoWork(i);
            }
        }

        static void DoWork(int testCaseNumber)
        {
            int N = int.Parse(Console.ReadLine());

            string[] friends = Console.ReadLine().Split(' ');
            Student[] students = new Student[N];
            for (int i = 0; i < friends.Length; ++i)
            {
                students[i] = new Student()
                {
                    outIndex = int.Parse(friends[i]) - 1,
                    color = 0
                };
            }
            for (int i = 0; i < students.Length; ++i)
            {
                students[students[i].outIndex].inIndexes.Add(i);
            }

            int maxCount = -1;
            int currentColor = 2;
            foreach (Student s in students)
            {
                ++currentColor;
                if (s.color == 0)
                {
                    Student t = s;
                    do
                    {
                        t.color = currentColor;
                        t = students[t.outIndex];
                    }
                    while (t.color == 0);

                    if (t.color == currentColor)
                    {
                        int count = 0;
                        do
                        {
                            t.color = 1;
                            ++count;
                            t = students[t.outIndex];
                        }
                        while (t.color == currentColor);

                        if (count == 2)
                        {
                            t.inIndexes.Remove(t.outIndex);
                            students[t.outIndex].inIndexes.Remove(students[t.outIndex].outIndex);
                            count = count + CountDepth(t, students, 0) + CountDepth(students[t.outIndex], students, 0);
                        }

                        if (count > maxCount)
                        {
                            maxCount = count;
                        }
                    }
                }
            }
            
            Console.WriteLine("Case #{0}: {1}", testCaseNumber + 1, maxCount);
        }

        private static int CountDepth(Student start, Student[] students, int depth)
        {
            if (start.inIndexes.Count == 0)
            {
                return depth;
            }

            int max = -1;
            foreach (int inIndex in start.inIndexes)
            {
                students[inIndex].color = 2;
                int t = CountDepth(students[inIndex], students, depth + 1);
                if (t > max)
                {
                    max = t;
                }
            }

            return max;
        }

        private class Student
        {
            public List<int> inIndexes = new List<int>();
            public int outIndex;
            public int color;
        }
    }
}
