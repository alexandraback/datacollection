using System;
using System.Collections.Generic;
using System.IO;
using GCJ_base;
using System.Linq;

namespace GCJ_1BB
{
    class Program
    {
        static void Main()
        {
            new Gcj1BB().Run();
        }
    }

    class Gcj1BB : Gcj
    {
        private Map<int> m_ceiling;
        private Map<int> m_floor;
        private int m_startHeight;
        private SortedList<double, List<Point>> m_queue;
        private Map<double> m_times;
        private int m_m;
        private int m_n;

        public Gcj1BB()
        {
            Problem = 'B';
            Small = true;
            Attempt = 1;
        }

        protected override string ComputeCase(TextReader reader)
        {
            var line = reader.ReadLine().Split(' ');
            m_startHeight = int.Parse(line[0]);
            m_m = int.Parse(line[2]);
            m_n = int.Parse(line[1]);

            m_ceiling = Map.Create(m_m, m_n, reader);
            m_floor = Map.Create(m_m, m_n, reader);

            m_times = new Map<double>(m_m, m_n, double.PositiveInfinity);
            m_queue = new SortedList<double, List<Point>>();

            m_times[0, 0] = 0;
            Enqueue(0, new Point(0, 0));

            var target = new Point(m_n - 1, m_m - 1);

            while (m_queue.Count > 0)
            {
                var tuple = Dequeue();
                double time = tuple.Item1;
                Point from = tuple.Item2;

                if (time >= m_times[target])
                    continue;

                foreach (var to in GetMoves(from))
                {
                    double accessibleAt = Math.Max(time, WillBeAccessibleAt(from, to));
                    if (double.IsPositiveInfinity(accessibleAt))
                        continue;

                    double waterWhenAccessible = m_startHeight - 10 * accessibleAt - m_floor[from];

                    double movedAt;
                    if (accessibleAt == 0)
                        movedAt = 0;
                    else if (waterWhenAccessible >= 20)
                        movedAt = accessibleAt + 1;
                    else
                        movedAt = accessibleAt + 10;

                    if (movedAt < m_times[to])
                    {
                        for (int i = 0; i < m_queue.Count; i++)
                        {
                            var list = m_queue.Values[i];
                            if (list.Remove(to))
                            {
                                if (list.Count == 0)
                                    m_queue.RemoveAt(i);
                                break;
                            }
                        }

                        Enqueue(movedAt, to);
                        m_times[to] = movedAt;
                    }
                }
            }

            return m_times[target].ToString();
        }

        private double WillBeAccessibleAt(Point from, Point to)
        {
            int belowToCeiling = m_ceiling[to] - 50;
            int belowFromCeiluing = m_ceiling[from] - 50;

            if (m_floor[to] > belowToCeiling || m_floor[to] > belowFromCeiluing || m_floor[from] > belowToCeiling)
                return double.PositiveInfinity;

            return Math.Max(m_startHeight - belowToCeiling, 0) / 10.0;
        }

        private void Enqueue(double time, Point position)
        {
            List<Point> list;
            if (!m_queue.TryGetValue(time, out list))
            {
                list = new List<Point>();
                m_queue.Add(time, list);
            }
            list.Add(position);
        }

        private Tuple<double, Point> Dequeue()
        {
            int i = m_queue.Count - 1;
            double time = m_queue.Keys[i];
            var list = m_queue.Values[i];
            int j = list.Count - 1;
            var point = list[j];
            list.RemoveAt(j);

            if (list.Count == 0)
                m_queue.RemoveAt(i);

            return Tuple.Create(time, point);
        }

        private IEnumerable<Point> GetMoves(Point p)
        {
            if (p.X > 0)
                yield return new Point(p.X - 1, p.Y);
            if (p.Y > 0)
                yield return new Point(p.X, p.Y - 1);
            if (p.X < m_n - 1)
                yield return new Point(p.X + 1, p.Y);
            if (p.Y < m_m - 1)
                yield return new Point(p.X, p.Y + 1);
        }
    }

    struct Point : IEquatable<Point>
    {
        public Point(int x, int y)
        {
            X = x;
            Y = y;
        }

        public readonly int X;
        public readonly int Y;

        public bool Equals(Point other)
        {
            return other.X == X && other.Y == Y;
        }

        public override bool Equals(object obj)
        {
            if (ReferenceEquals(null, obj))
                return false;
            if (obj.GetType() != typeof(Point))
                return false;
            return Equals((Point)obj);
        }

        public override int GetHashCode()
        {
            unchecked
            {
                return (X * 397) ^ Y;
            }
        }

        public override string ToString()
        {
            return string.Format("({0}, {1})", X, Y);
        }
    }

    class Map<T>
    {
        public Map(T[][] values)
        {
            Values = values;
        }

        public Map(int m, int n, T value)
        {
            Values = new T[n][];

            for (int i = 0; i < n; i++)
            {
                Values[i] = new T[m];
                for (int j = 0; j < m; j++)
                {
                    Values[i][j] = value;
                }
            }
        }

        public T[][] Values { get; private set; }

        public T this[Point p]
        {
            get { return this[p.X, p.Y]; }
            set { this[p.X, p.Y] = value; }
        }

        public T this[int x, int y]
        {
            get { return Values[x][y]; }
            set { Values[x][y] = value; }
        }
    }

    static class Map
    {
        public static Map<int> Create(int m, int n, TextReader reader)
        {
            var values = new int[n][];
            for (int i = 0; i < n; i++)
            {
                var line = reader.ReadLine().Split(' ');
                values[i] = line.Select(Int32.Parse).ToArray();
            }
            return new Map<int>(values);
        }
    }

}