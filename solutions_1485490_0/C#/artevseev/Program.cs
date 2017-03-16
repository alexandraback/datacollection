using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _2012C1Toys
{
  public class Item
  {
    public int Type;
    public UInt64 Count;
  }

  class Program
  {
    public static List<Item> Boxes;
    public static List<Item> Toys;

    public static UInt64 GetCount(int boxNo, int toyNo)
    {
      if (boxNo >= Boxes.Count || toyNo >= Toys.Count)
        return 0;

      UInt64 matchResult = 0;
      if (Boxes[boxNo].Type == Toys[toyNo].Type)
      {
        UInt64 amount = Math.Min(Boxes[boxNo].Count, Toys[toyNo].Count);
        UInt64 matchA = 0;
        UInt64 matchB = 0;
        UInt64 matchC = 0;
        if (Boxes[boxNo].Count < Toys[toyNo].Count)
        {
          UInt64 boxes = Boxes[boxNo].Count;
          Toys[toyNo].Count -= boxes;
          matchA = GetCount(boxNo + 1, toyNo);
          Toys[toyNo].Count += boxes;
        }
        if (Toys[toyNo].Count < Boxes[boxNo].Count)
        {
          UInt64 toys = Toys[toyNo].Count;
          Boxes[boxNo].Count -= toys;
          matchB = GetCount(boxNo, toyNo + 1);
          Boxes[boxNo].Count += toys;
        }
        if (Toys[toyNo].Count == Boxes[boxNo].Count)
        {
          UInt64 toys = Toys[toyNo].Count;
          UInt64 boxes = Boxes[boxNo].Count;
          Toys[toyNo].Count -= boxes;
          Boxes[boxNo].Count -= toys;

          matchC = GetCount(boxNo + 1, toyNo + 1);

          Toys[toyNo].Count += boxes;
          Boxes[boxNo].Count += toys;

        }
        matchResult = Math.Max(Math.Max(matchA, matchB), matchC) + amount;
      }
      UInt64 a = 0;
      UInt64 b = 0;
      if (matchResult == 0)
      {
        a = GetCount(boxNo + 1, toyNo);
        b = GetCount(boxNo, toyNo + 1);
      }
      return Math.Max(Math.Max(a, b), matchResult);
    }

    static void Main(string[] args)
    {
      int tests = int.Parse(Console.ReadLine());
      for (int test = 0; test < tests; test++)
      {
        string[] line = Console.ReadLine().Split(' ');
        int n = int.Parse(line[0]);
        int m = int.Parse(line[1]);
        List<Item> boxes = new List<Item>();
        List<Item> toys = new List<Item>();
        string[] boxLine = Console.ReadLine().Split(' ');
        string[] toyLine = Console.ReadLine().Split(' ');

        for (int i = 0; i < n; i++)
        {
          Item box = new Item();
          box.Count = UInt64.Parse(boxLine[i * 2]);
          box.Type = int.Parse(boxLine[i * 2 + 1]);
          boxes.Add(box);
        }

        for (int i = 0; i < m; i++)
        {
          Item toy = new Item();
          toy.Count = UInt64.Parse(toyLine[i * 2]);
          toy.Type = int.Parse(toyLine[i * 2 + 1]);
          toys.Add(toy);
        }
        Boxes = boxes;
        Toys = toys;
        Console.WriteLine(string.Format("Case #{0}: {1}", test+1, GetCount(0, 0)));
      }
    }
  }
}
