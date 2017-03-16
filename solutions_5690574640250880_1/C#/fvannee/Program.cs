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

         var p = new R2014_C();
         p.Run();
      }
   }

   internal class R2014_C : Problem
   {
      public override void ProcessOne()
      {
         var vars = this.ReadList(Int32.Parse);
         int c, r, m;
         r = vars[0];
         c = vars[1];
         m = vars[2];
         var board = new char[r][];
         for (int i = 0; i < r; i++)
         {
            board[i] = new char[c];
            for (int j = 0; j < c; j++)
            {
               board[i][j] = 'x';
            }
         }
         int curC = 0;
         int curR = 0;
         while (m >= Math.Min(r, c))
         {
            if (r < c || (r == c && curC > 0))
            //if (r < c)
            {
               for (int i = curR; i < board.Length; i++)
               {
                  board[i][curC] = '*';
               }
               curC++;
               c--;
               m -= r;
            }
            else
            {
               for (int i = curC; i < board[curR].Length; i++)
               {
                  board[curR][i] = '*';
               }
               curR++;
               r--;
               m -= c;
            }
         }
         int newr = curR + 1;
         int newc = curC + 1;
         if (m > 0)
         {
            board[curR][curC] = '*';
            m--;
         }
         while (m > 0)
         {
            if (board.Length - newr > board[0].Length - newc)
            {
               board[newr][curC] = '*';
               newr++;
            }
            else
            {
               board[curR][newc] = '*';
               newc++;
            }
            m--;
         }
         Check(board, board.Length - 1, board[0].Length - 1);
         board[board.Length - 1][board[0].Length - 1] = 'c';

         bool good = true;
         for (int i = 0; i < board.Length && good; i++)
         {
            for (int j = 0; j < board[i].Length && good; j++)
            {
               if (board[i][j] == 'x')
               {
                  good = false;
               }
            }
         }
         if (good)
         {
            this.WriteLine("");
            for (int i = 0; i < board.Length; i++)
            {
               string s = "";
               for (int j = 0; j < board[i].Length; j++)
               {
                  s += board[i][j];
               }
               this.WriteLineNoCase(s);
            }
         }
         else
         {
            this.WriteLine("");
            this.WriteLineNoCase("Impossible");

            /*for (int i = 0; i < board.Length; i++)
            {
               string s = "";
               for (int j = 0; j < board[i].Length; j++)
               {
                  s += board[i][j];
               }
               this.WriteLineNoCase(s);
            }*/
         }
      }

      private int[,] neighbours = {{-1, 0}, {-1, -1}, {0, -1}};

      void Check(char[][] board, int r, int c)
      {
         int n = 0;
         board[r][c] = '.';
         for (int i = 0; i < neighbours.GetLength(0); i++)
         {
            int nr = r + neighbours[i, 0];
            int nc = c + neighbours[i, 1];
            if (nr >= 0 && nc >= 0 && board[nr][nc] == '*')
            {
               n++;
            }
         }
         if (n == 0)
         {
            for (int i = 0; i < neighbours.GetLength(0); i++)
            {
               int nr = r + neighbours[i, 0];
               int nc = c + neighbours[i, 1];
               if (nr >= 0 && nc >= 0 && board[nr][nc] == 'x')
               {
                  Check(board, nr, nc);
               }
            }
         }
      }

   }

   public class IntervalTree<T> where T : IComparable<T>
   {
      public class TreeNode<T> where T : IComparable<T>
      {
         public TreeNode(int left, int right, int data)
         {
            this.Left = left;
            this.Right = right;
            this.Data = data;
         }

         public TreeNode<T> LeftChild, RightChild;
         public int Left, Right;
         public int Data;
      }

      private TreeNode<T> head;
 
      public IntervalTree(int start, int end, int init)
      {
         this.head = new TreeNode<T>(start, end, init);
      }

      public int MinValue(int start, int end)
      {
         return MinValue(head, start, end);
      }

      public int MinValue(TreeNode<T> node, int start, int end)
      {
         if (start > node.Right || end < node.Left)
            return Int32.MaxValue;
         if (node.Left >= start && node.Right <= end || node.LeftChild == null)
         {
            return node.Data;
         }

         return Math.Max(node.Data,
                         Math.Min(MinValue(node.LeftChild, start, end), MinValue(node.RightChild, start, end)));
      }

      public void AddInterval(int start, int end, int value)
      {
         AddInterval(head, start, end, value, head.Data);
      }

      private void AddInterval(TreeNode<T> node, int start, int end, int value, int maxSoFar)
      {
         maxSoFar = (maxSoFar.CompareTo(node.Data) < 0) ? node.Data : maxSoFar;
         node.Data = maxSoFar;
         if (node.Left >= start && node.Right <= end)
         {
            node.Data = Math.Max(value, node.Data);
            //node.LeftChild = null;
            //node.RightChild = null;
            return;
         }
         if (start > node.Right || end < node.Left)
            return;
         if (node.LeftChild == null)
         {
            if (node.Right <= end)
            {
               var newd = (value.CompareTo(node.Data) < 0) ? node.Data : value;
               node.LeftChild = new TreeNode<T>(node.Left, start - 1, node.Data);
               node.RightChild = new TreeNode<T>(start, node.Right, newd);
               
            }
            else if (node.Left >= start)
            {
               var newd = (value.CompareTo(node.Data) < 0) ? node.Data : value;
               node.LeftChild = new TreeNode<T>(node.Left, end, newd);
               node.RightChild = new TreeNode<T>(end + 1, node.Right, node.Data);
               //if (value.CompareTo(node.Data) < 0)
               //   node.Data = value;
            }
            else
            {
               node.LeftChild = new TreeNode<T>(node.Left, end, node.Data);
               node.RightChild = new TreeNode<T>(end + 1, node.Right, node.Data);
               AddInterval(node.LeftChild, start, end, value, node.Data);
            }
         }
         else
         {
            AddInterval(node.LeftChild, start, end, value, node.Data);
            AddInterval(node.RightChild, start, end, value, node.Data);
            var newd = (node.LeftChild.Data.CompareTo(node.RightChild.Data) < 0) ? node.LeftChild.Data : node.RightChild.Data;
            node.Data = newd;
         }
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
         return value & ~(1 << bit);
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
