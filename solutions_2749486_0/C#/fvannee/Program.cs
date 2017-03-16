using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using TrainAlgorithms.CodeJam;

namespace TrainAlgorithms
{
   internal class Program
   {
      private static void Main(string[] args)
      {
         System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

         var p = new R20131CB();
         p.Run();
      }
   }

   class R20131CA : Problem
   {
      public override void ProcessOne()
      {
         var list = this.ReadStringList();
         var str = list[0];
         var n = Int32.Parse(list[1]);

         int consrow = 0;
         int total = 0;
         int last = 0;
         for (int i = 0; i < str.Length; i++)
         {
            if (str[i] != 'e' && str[i] != 'a' && str[i] != 'u' && str[i] != 'i' && str[i] != 'o')
            {
               consrow++;
               if (consrow >= n)
               {
                  int start = i - consrow + 1;
                  int end = i;
                  int before = Math.Max(start, 0) + 1 - last;
                  int after = Math.Max(str.Length - end - 1, 0) + 1;
                  total += before*after;
                  last = start + 1;
                  consrow--;
               }
            }
            else
            {
               consrow = 0;
            }
         }
         this.WriteLine(total.ToString());
      }
   }

   internal class R20131CB : Problem
   {
      private Dictionary<KeyValuePair<int, int>, SortedSet<int>> memo;

      public override void ProcessOne()
      {
         var list = this.ReadIntList();
         int x = list[0];
         int y = list[1];
         memo = new Dictionary<KeyValuePair<int, int>, SortedSet<int>>();
         System.Collections.Generic.Queue<KeyValuePair<int, int>> queue = new System.Collections.Generic.Queue<KeyValuePair<int, int>>();
         System.Collections.Generic.Queue<int> queuen = new System.Collections.Generic.Queue<int>();
         System.Collections.Generic.Queue<string> queues = new System.Collections.Generic.Queue<string>();
         queue.Enqueue(new KeyValuePair<int, int>(0, 0));
         queues.Enqueue("");
         queuen.Enqueue(1);
         while (queue.Count > 0)
         {
            int n = queuen.Dequeue();
            var kv = queue.Dequeue();
            var s = queues.Dequeue();
            int dist = Math.Abs(kv.Key - x) + Math.Abs(kv.Value - y);
            int restsum = (n)*(n-1)/2;
            double n2 = -0.5 + 0.5*Math.Sqrt(1 + 8*(dist-restsum));
            if (kv.Key == x && kv.Value == y)
            {
               this.WriteLine(s);
               break;
            }
            if (false && Math.Abs(n2 - (int) n2) < 0.000001)
            {
               //direct path
            }
            else
            {
               int diffx = Math.Abs(x - kv.Key);
               int diffy = Math.Abs(y - kv.Value);
               int dx = x - kv.Key;
               int dy = y - kv.Value;
               if (diffx < diffy && diffx != 0 || diffy == 0)
               {
                  if (dx >= n || (dx < 0 && dx > -n))
                  {
                     queue.Enqueue(new KeyValuePair<int, int>(kv.Key + n, kv.Value));
                     queues.Enqueue(s + "E");
                  }
                  else
                  {
                     queue.Enqueue(new KeyValuePair<int, int>(kv.Key - n, kv.Value));
                     queues.Enqueue(s + "W");
                  }
               }
               else
               {
                  if (dy >= n || (dy < 0 && dy > -n))
                  {
                     queue.Enqueue(new KeyValuePair<int, int>(kv.Key, kv.Value + n));
                     queues.Enqueue(s + "N");
                  }
                  else
                  {
                     queue.Enqueue(new KeyValuePair<int, int>(kv.Key, kv.Value - n));
                     queues.Enqueue(s + "S");

                  }
               }
               queuen.Enqueue(n + 1);

            }
         }
      }

      public List<char> SolveGreedy()
      {
         return null;
      }
   }

   class R20131CB2 : Problem
   {
      private Dictionary<KeyValuePair<int, int>, SortedSet<int>> memo;

      public override void ProcessOne()
      {
         var list = this.ReadIntList();
         int x = list[0];
         int y = list[1];
         memo = new Dictionary<KeyValuePair<int, int>, SortedSet<int>>();

         int low = 1;
         int high = 500;
         while (low <= high)
         {
            int mid = (low + high)/2+1;
            var s = Solve(x, y, mid, new List<char>());
            if (s != null)
            {
               high = mid;
            }
            else
            {
               low = mid + 1;
            }
         }
         this.WriteLine(high.ToString());
      }

      public List<char> Solve(int x, int y, int n, List<char> res )
      {
         int dist = x + y;
         double n2 = -0.5 + 0.5 * Math.Sqrt(1 + 8 * dist);
         if (Math.Abs(n2 - (int) n2) < 0.000001 && (int) n2 == n)
            return res;

         if (n == 0 && x == 0 && y == 0)
            return res;
         if (n == 0)
            return null;
         var kv = new KeyValuePair<int, int>(x, y);
         if (memo.ContainsKey(kv) && memo[kv].Contains(n))
            return null;
         int newx;
         int newy;
         char xap, yap;
         if (x < 0)
         {
            newx = x + n;
            xap = 'E';
         }
         else
         {
            newx = x - n;
            xap = 'W';
         }
         if (y < 0)
         {
            newy = y + n;
            yap = 'N';
         }
         else
         {
            newy = y - n;
            yap = 'S';
         }

         res.Add(xap);
         var r1 = Solve(newx, y, n - 1, res);
         if (r1 != null)
            return r1;

         res[res.Count - 1] = yap;
         var r2 = Solve(x, newy, n - 1, res);
         if (r2 != null)
            return r2;
         res.RemoveAt(res.Count - 1);
         if (!memo.ContainsKey(kv))
            memo[kv] = new SortedSet<int>();
         memo[kv].Add(n);
         return null;
      }
   }

   class R20131CC : Problem
   {
      public override void ProcessOne()
      {

      }
   }

   public class FitwickTree
   {
      private int[] tree;
      
      public FitwickTree(int length)
      {
         this.tree = new int[length + 1];
      }

      public void BuildTree(int[] array)
      {
         for (int i = 0; i < array.Length; i++)
         {
            Modify(i, array[i]);
         }
      }

      public void Modify(int index, int difference)
      {
         index += 1; // offset
         while (index < tree.Length)
         {
            tree[index] += difference;
            index += BitManipulation.GetFirstBit(index);
         }
      }

      public int GetCumulative(int left, int right)
      {
         if (left == 0)
            return GetCumulative(right);
         else
            return GetCumulative(right) - GetCumulative(left - 1);
      }

      public int GetCumulative(int right)
      {
         right += 1; // offset
         int sum = 0;
         while (right > 0)
         {
            sum += tree[right];
            right = right - BitManipulation.GetFirstBit(right);
         }
         return sum;
      }

      /// <summary>
      /// Gets the first index for which the cumulative frequency is greater than or equal to parameter cumulative.
      /// Only works for increasing arrays
      /// </summary>
      /// <param name="cumulative"></param>
      /// <returns></returns>
      public int GetFirstIndexWithCumulative(int cumulative)
      {
         int low = 0;
         int diff = 1;
         int next = -1;
         while (true)
         {
            next = low + diff;
            if (next >= tree.Length || tree[next] >= cumulative)
            {
               if (diff == 1)
                  break;
               low += diff/2;
               diff = 1;
            }
            else
            {
               diff *= 2;
            }
         }
         return next >= tree.Length ? -1 : next - 1; // offset
      }
   }

   public class SegmentTree<T>
   {
      private int[] tree;
      private T[] array;
      private int depth;
      private Func<T, T, T> f;
 
      public T[] Values
      {
         get { return array; }
      }

      public SegmentTree(T[] array, Func<T, T, T> f )
      {
         this.f = f;
         this.depth = (int)(Math.Floor(Math.Log(array.Length, 2)) + 1);
         int size = 1 << depth;
         this.array = array;
         this.tree = new int[size];
         this.BuildTree(1, 0, array.Length - 1);
      }

      private int BuildTree(int index, int left, int right)
      {
         if (left == right)
         {
            this.tree[index] = left;
         }
         else
         {
            int lc = 2*index;
            int rc = 2*index + 1;
            int mid = (left + right)/2;
            int l = BuildTree(lc, left, mid);
            int r = BuildTree(rc, mid + 1, right);
            this.tree[index] = Compare(r, l);
         }
         return this.tree[index];
      }

      public int FindIndex(int left, int right)
      {
         return FindIndex(1, left, right, 0, this.array.Length - 1);
      }

      public int FindIndex(int node, int left, int right, int curLeft, int curRight)
      {
         if (curLeft > right || curRight < left)
            return -1;
         if (curLeft >= left && curRight <= right)
            return tree[node];

         int mid = (curLeft + curRight) / 2;
         var l = FindIndex(2*node, left, right, curLeft, mid);
         var r = FindIndex(2*node + 1, left, right, mid + 1, curRight);
         if (l == -1) return r;
         if (r == -1) return l;
         return Compare(l, r);
      }

      private int Compare(int l, int r)
      {
         if (this.f(array[l], array[r]).Equals(array[r]))
         {
            return r;
         }
         else
         {
            return l;
         }
      }

      private int FindTreeIndex(int node, int left, int right, int curLeft, int curRight)
      {
         if (curLeft > right || curRight < left)
            return -1;
         if (curLeft >= left && curRight <= right)
            return node;

         int mid = (curLeft + curRight) / 2;
         var l = FindIndex(2 * node, left, right, curLeft, mid);
         var r = FindIndex(2 * node + 1, left, right, mid + 1, curRight);
         if (l == -1) return r;
         if (r == -1) return l;
         return -1;
      }

      public void Update(int index, T value)
      {
         this.array[index] = value;
         int treeIndex = FindTreeIndex(1, index, index, 0, this.array.Length - 1);
         int parent = treeIndex/2;
         while (parent >= 1)
         {
            int min = Compare(2*parent, 2*parent + 1);
            this.tree[parent] = min;
            treeIndex = parent;
            parent = treeIndex/2;
         }
      }
   }

   public class UnionFindDisjoint
   {
      private int[] parents;
      private int[] counts;
      private int[] ranks;
      private int numDisjoint;

      public UnionFindDisjoint(int size)
      {
         this.numDisjoint = size;
         this.parents = new int[size];
         this.counts = new int[size];
         this.ranks = new int[size];
         for (int i = 0; i < size; i++)
         {
            this.parents[i] = i;
            this.counts[i] = 1;
         }
      }

      public int FindSet(int i)
      {
         return parents[i] == i ? i : parents[i] = FindSet(parents[i]);
      }

      public bool IsSameSet(int i, int j)
      {
         return FindSet(i) == FindSet(j);
      }

      public void UnionSet(int i, int j)
      {
         int pi = FindSet(i);
         int pj = FindSet(j);
         if (pi != pj)
         {
            if (ranks[pi] > ranks[pj])
            {
               parents[pj] = pi;
               counts[pi] += counts[pj];
            }
            else if (ranks[pi] < ranks[pj])
            {
               parents[pi] = pj;
               counts[pj] += counts[pi];
            }
            else
            {
               parents[pi] = pj;
               counts[pj] += counts[pi];
               ranks[pj]++;
            }
            this.numDisjoint--;
         }
      }

      public int NumDisjointSets()
      {
         return this.numDisjoint;
      }

      public int SizeOfSet(int i)
      {
         return this.counts[FindSet(i)];
      }

      public Dictionary<int, List<int>> CopyToDictionary()
      {
         var ret = new Dictionary<int, List<int>>();
         for (int i = 0; i < this.parents.Length; i++)
         {
            int p = FindSet(i);
            if (!ret.ContainsKey(p))
               ret[p] = new List<int>();
            ret[p].Add(i);
         }
         return ret;
      }
   }

   internal class TwoDimNode<T>
   {
      public TwoDimNode(TwoDimNode<T>[,] twoDims)
      {
         this.Squares = twoDims;
      }

      /// <summary>
      /// The row this square is in. This square is twoDims[X,Y]
      /// In the input, every input on the same line has the same value of X
      /// </summary>
      public int X { get; set; }

      /// <summary>
      /// The column this square is in. This square is twoDims[X,Y]
      /// In the input, every input on the same line has a different Y value
      /// </summary>
      public int Y { get; set; }

      public T Data { get; set; }

      public TwoDimNode<T>[,] Squares { get; private set; }

      public TwoDimNode<T> Down()
      {
         return X + 1 < this.Squares.GetLength(0) ? this.Squares[X + 1, Y] : null;
      }

      public TwoDimNode<T> Up()
      {
         return X - 1 >= 0 ? this.Squares[X - 1, Y] : null;
      }

      public TwoDimNode<T> Left()
      {
         return Y - 1 >= 0 ? this.Squares[X, Y - 1] : null;
      }

      public TwoDimNode<T> Right()
      {
         return Y + 1 < this.Squares.GetLength(1) ? this.Squares[X, Y + 1] : null;
      }
   }

   internal abstract class Problem
   {
      private readonly TextWriter writer;

      protected Problem(String output = "test.out")
      {
         this.writer = new StreamWriter(output);
      }

      public int CurrentCase { get; private set; }

      public virtual void Run()
      {
         var firstline = Console.ReadLine();
         if (firstline == null)
            throw new Exception("No integer found");
         var testcases = Int32.Parse(firstline);
         for (int i = 1; i <= testcases; i++)
         {
            this.CurrentCase = i;
            this.ProcessOne();
         }
      }

      public string ReadLine()
      {
         var ret = Console.ReadLine();
         if (ret == null)
            throw new Exception("No line found");
         return ret;
      }

      public T[] ReadList<T>(Func<String, T> f, char seperator = ' ')
      {
         var line = Console.ReadLine();
         if (line == null)
            throw new Exception("No list found");
         var split = line.Split(new char[] {seperator});
         var ret = new T[split.Length];
         for (int i = 0; i < split.Length; i++)
         {
            ret[i] = f(split[i]);
         }
         return ret;
      }

      public int ReadInt()
      {
         var line = Console.ReadLine();
         if (line == null)
            throw new Exception("No integer found");
         return Int32.Parse(line);
      }

      public int[] ReadIntList(char seperator = ' ')
      {
         return ReadList(Int32.Parse, seperator);
      }

      public char[,] ReadMultiCharArray(int x, int y)
      {
         var ret = new char[x,y];
         for (int j = 0; j < x; j++)
         {
            var line = Console.ReadLine();
            if (line == null)
               throw new Exception("No list found");
            for (int i = 0; i < line.Length; i++)
            {
               ret[j, i] = line[i];
            }
         }
         return ret;
      }
      
      public TwoDimNode<T>[,] ReadTwoDimMaze<T, T2>(Func<string, T2> f, Action<T2, TwoDimNode<T>> f2, int x, int y, TwoDimNode<T>[,] squares = null, char seperator = ' ')
      {
         var ret = squares ?? new TwoDimNode<T>[x, y];

         for (int j = 0; j < x; j++)
         {
            var line = Console.ReadLine();
            if (line == null)
               throw new Exception("No list found");
            var split = line.Split(new char[] { seperator });
            for (int i = 0; i < split.Length; i++)
            {
               if (ret[j,i] == null)
                  ret[j,i] = new TwoDimNode<T>(ret);
               f2(f(split[i]), ret[j,i]);
            }
         }
         return ret;
      }

      public T[,] ReadMultiArray<T>(Func<string, T> f, int x, int y, T[,] ret = null, char seperator = ' ')
      {
         if (ret == null)
            ret = new T[x, y];
         for (int j = 0; j < x; j++)
         {
            var line = Console.ReadLine();
            if (line == null)
               throw new Exception("No list found");
            var split = line.Split(new char[] { seperator });
            for (int i = 0; i < split.Length; i++)
            {
               ret[j, i] = f(split[i]);
            }
         }
         return ret;
      }

      public double[] ReadDoubleList(char seperator = ' ')
      {
         return ReadList(Double.Parse, seperator);
      }

      public string[] ReadStringList(char seperator = ' ')
      {
         var line = Console.ReadLine();
         if (line == null)
            throw new Exception("No list found");
         var split = line.Split(new char[] {seperator});
         return split;
      }

      public void WriteLine(string value)
      {
         string val = "Case #" + this.CurrentCase + ": " + value;
         Console.WriteLine(val);
         this.writer.WriteLine(val);
         this.writer.Flush();
      }

      public void WriteLineNoCase(string value)
      {
         Console.WriteLine(value);
         this.writer.WriteLine(value);
         this.writer.Flush();
      }

      public abstract void ProcessOne();
   }

   public static class BitManipulation
   {
      public static bool TestBit(int value, int bit)
      {
         return (value & (1 << bit)) != 0;
      }

      public static int SetBit(int value, int bit)
      {
         return value | (1 << bit);
      }

      public static int ClearBit(int value, int bit)
      {
         return value | ~(1 << bit);
      }

      public static int ToggleBit(int value, int bit)
      {
         return value ^ (1 << bit);
      }

      public static int GetFirstBit(int value)
      {
         return value & (-value);
      }

      /// <summary>
      /// Start inclusive, End exclusive
      /// </summary>
      /// <param name="start"></param>
      /// <param name="end"></param>
      /// <returns></returns>
      public static int GetBitMask(int start, int end)
      {
         return ((1 << end) - 1) ^ ((1 << start) - 1);
      }
   }
}
