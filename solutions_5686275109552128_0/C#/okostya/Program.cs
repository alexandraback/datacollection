using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Infinite_House_of_Pancakes
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\B-small-attempt4.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            int D = int.Parse(reader.ReadLine());
            string sss = reader.ReadLine();
            string[] ss = sss.Split(' ');

            var heap = new MaxBinaryHeap();
            for (int i = 0; i < D; i++)
            {
                heap.Add(int.Parse(ss[i]));
            }

            int time = heap.Max();

            for (int i = 1;; i++)
            {
                if (i >= time)
                    break;

                int max = heap.GetMax();
                if (max == 1)
                    break;

                if (max == 9 && (heap.HeapSize==0 || heap.Max() == 6 || heap.Max() < 4))
                {
                    int b = 6;
                    int l = max - b;

                    heap.Add(b);
                    heap.Add(l);
                }
                else
                {
                    int b = max/2;
                    int l = max - b;

                    heap.Add(b);
                    heap.Add(l);
                }

                max = heap.Max();

                if (time > i + max)
                    time = i + max;
            }

            Console.WriteLine("Case #{0}: {1} - {2}", Case, time, sss);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }

    public class MaxBinaryHeap
    {
        private readonly List<int> _list;

        public MaxBinaryHeap()
        {
            _list = new List<int>();
        }

        public int HeapSize
        {
            get { return _list.Count; }
        }

        public void Add(int value)
        {
            _list.Add(value);
            int i = HeapSize - 1;
            int parent = (i - 1)/2;

            while (i > 0 && _list[parent] < _list[i])
            {
                int temp = _list[i];
                _list[i] = _list[parent];
                _list[parent] = temp;

                i = parent;
                parent = (i - 1)/2;
            }
        }

        public void Heapify(int i)
        {
            for (;;)
            {
                int leftChild = 2*i + 1;
                int rightChild = 2*i + 2;
                int largestChild = i;

                if (leftChild < HeapSize && _list[leftChild] > _list[largestChild])
                {
                    largestChild = leftChild;
                }

                if (rightChild < HeapSize && _list[rightChild] > _list[largestChild])
                {
                    largestChild = rightChild;
                }

                if (largestChild == i)
                {
                    break;
                }

                int temp = _list[i];
                _list[i] = _list[largestChild];
                _list[largestChild] = temp;
                i = largestChild;
            }
        }


        public int Max()
        {
            return _list[0];
        }

        public int GetMax()
        {
            int result = _list[0];
            _list[0] = _list[HeapSize - 1];
            _list.RemoveAt(HeapSize - 1);
            Heapify(0);
            return result;
        }
    }
}