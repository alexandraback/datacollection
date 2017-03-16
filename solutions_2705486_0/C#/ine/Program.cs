using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace email
{
  class Node
  {
    public Node[] children = new Node[26];
    public bool terminal = false;

    public Node Next(char x)
    {
      int code = x - 'a';
      if (children[code] == null)
        children[code] = new Node();

      return children[code];
    }
  }

  class Program
  {
    static Node root = new Node();
    static string cipher;
    static Dictionary<Node, int>[] explored;

    static void Main(string[] args)
    {
      var words = File.ReadAllLines("garbled_email_dictionary.txt");
      foreach (var word in words)
      {
        var cur = root;
        for (int i = 0; i < word.Length; ++i)
          cur = cur.Next(word[i]);

        cur.terminal = true;
      }

      var lines = File.ReadAllLines(args[0]);
      int T = int.Parse(lines[0]);
      for (int i = 1; i <= T; ++i)
      {
        cipher = lines[i];
        explored = new Dictionary<Node, int>[cipher.Length];
        for (int j = 0; j < cipher.Length; ++j)
          explored[j] = new Dictionary<Node, int>();

        var minReplacements = Search(0, -100, root, int.MaxValue);

        Console.WriteLine("Case #{0}: {1}", i, minReplacements);
      }
    }

    private static int Search(int pos, int lastReplace, Node cur, int best)
    {
      if(pos == cipher.Length)
        return cur.terminal ? 0 : int.MaxValue;

      int code = cipher[pos] - 'a';
      bool canReplace = pos - lastReplace > 4;

      if (canReplace && explored[pos].ContainsKey(cur))
        return explored[pos][cur];

      if (cur.children[code] != null)
        best = Math.Min(best, Search(pos + 1, lastReplace, cur.children[code], best));

      if (best == 0)
      {
        if(canReplace)
          explored[pos][cur] = best;
        return best;
      }

      if (cur.terminal)
        best = Math.Min(best, Search(pos, lastReplace, root, best));

      if (best == 0)
      {
        if (canReplace)
          explored[pos][cur] = best;
        return best;
      }

      if(canReplace && best > 1)
        for(int i = 0; i < 26 && best > 1; ++i)
          if (i != code && cur.children[i] != null)
          {
            var res = Search(pos + 1, pos, cur.children[i], best == int.MaxValue ? best : best - 1);

            if(res != int.MaxValue)
              best = Math.Min(best, res + 1);

            if (best == 1)
            {
              explored[pos][cur] = best;
              return best;
            }
          }

      if (canReplace)
        explored[pos][cur] = best;

      return best;
    }
  }
}
