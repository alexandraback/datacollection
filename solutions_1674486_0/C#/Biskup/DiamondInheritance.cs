using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace Round1C
{
    public class DiamondInheritance
    {
        [STAThread]
        public static void Main(string[] args)
        {
            var sr = new StreamReader("input.txt");
            var sw = new StreamWriter("output.txt");
            var srd = new StreamDataRead(sr);

            int _case = Convert.ToInt32(srd.GetNext());

            for (int tc = 0; tc < _case; tc++)
            {
                Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();
                Dictionary<int, List<int>> dicB = new Dictionary<int, List<int>>();
                int N = Convert.ToInt32(srd.GetNext());
                bool[] bA = new bool[N];
                int[] qA = new int[N];

                for (int i = 0; i < N; i++)
                {
                    dic[i] = new List<int>();
                    dicB[i] = new List<int>();
                }
                for (int i = 0; i < N; i++)
                {
                    int M = Convert.ToInt32(srd.GetNext());
                    for (int j = 0; j < M; j++)
                    {
                        int t = Convert.ToInt32(srd.GetNext()) - 1;
                        dic[i].Add(t);
                        dicB[t].Add(i);
                    }
                }

                /*int p = 0;
                for (int i = 0; i < N; i++)
                    if(!bA[i])
                    {
                        p++;
                        Queue queue = new Queue();
                        queue.Enqueue(i);
                        while(queue.Count!=0)
                        {
                            int cur = (int)queue.Dequeue();
                            if (bA[cur]) continue;
                            bA[cur] = true;
                            qA[cur] = p;
                            foreach (int ne in dic[cur])
                                queue.Enqueue(ne);
                            foreach (int ne in dicB[cur])
                                queue.Enqueue(ne);
                        }
                    }

                bool y = false;
                for (int i = 1; i <= p; i++)
                {*/
                    bool y = false;
                    for (int j = 0; j < N; j++)
                        if(dicB[j].Count==0)
                        {
                            int[] nn = new int[N];
                            nn[j] = 1;
                            Queue queue = new Queue();
                            queue.Enqueue(j);
                            while (queue.Count != 0)
                            {
                                int cur = (int)queue.Dequeue();
                                foreach (int ne in dic[cur])
                                {
                                    queue.Enqueue(ne);
                                    nn[ne] += nn[cur];
                                    if (nn[ne] > 1) y = true;
                                }
                            }
                        }
                //}
                sw.Write(String.Format("Case #{0:G}: {1:G}\n", tc + 1, (y ? "Yes" : "No")));
            }

            sr.Close();
            sw.Close();
        }
    }

    public class StreamDataRead
    {
        private readonly Queue _queue;
        private readonly Queue _queueLine;

        public StreamDataRead(StreamReader sr)
        {
            _queue = new Queue();
            _queueLine = new Queue();

            while (sr.Peek() >= 0)
            {
                string readLine = sr.ReadLine();
                _queueLine.Enqueue(readLine);
                if (readLine != null)
                {
                    string[] strTmp = readLine.Trim().Split(new[] { ' ' });
                    foreach (string str in strTmp)
                        if (str.Length > 0)
                            _queue.Enqueue(str);
                }
            }
        }

        public object GetNext()
        {
            return _queue.Dequeue();
        }

        public object GetNextLine()
        {
            return _queueLine.Dequeue();
        }
    }
}