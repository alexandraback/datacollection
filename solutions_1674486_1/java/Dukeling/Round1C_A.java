import java.util.ArrayList;
import java.util.Iterator;
import java.util.TreeSet;

public class Round1C_A
{
   static boolean debug = false;

   static void print(String str) { if (debug) System.out.print(str); }
   static void println(String str) { if (debug) System.out.println(str); }
   static void println(int str) { if (debug) System.out.println(str); }
   static void println() { if (debug) System.out.println(); }

   public static void main(String[] args)
   {
      Utils.openInFile("A-large.in");
      Utils.openOutFile("out.txt", debug);
      String input = Utils.readFromFile();
      String[] split1 = input.split(" ");
      int lineCount = Integer.parseInt(split1[0]);

      //while ((input = Utils.readFromFile()) != null)
      for (int i = 1; i <= lineCount; i++)
      {
         input = Utils.readFromFile();

         boolean success = false;
         int N = Integer.parseInt(input);
         Node[] nodes = new Node[N];
         for (int j = 1; j <= N; j++)
            nodes[j-1] = new Node(j);

         for (int j = 1; j <= N; j++)
         {
            input = Utils.readFromFile();
            if (!success)
            {
               String[] split = input.split(" ");
               for (int k = 1; k < split.length; k++)
               {
                  int val = Integer.parseInt(split[k]);
                  if (nodes[j-1].addParent(nodes[val-1], true))
                  {
                     success = true;
                     break;
                  }
               }
            }
         }

         println("input="+input);

         String output = "Case #" + i + ": ";
         if (success)
            output += "Yes";
         else
            output += "No";

         Utils.writeToFile(output);
      }
      Utils.closeInFile();
      Utils.closeOutFile();
   }

   static class Node implements Comparable
   {
      TreeSet<Node> parents;
      TreeSet<Node> children;
      boolean hasDualInheritance = false;
      int value;

      Node(int val)
      {
         parents = new TreeSet<Node>();
         children = new TreeSet<Node>();
         value = val;
      }

      ArrayList<Node> getParents(boolean primary)
      {
         println("    getParents 1 - "+value+" - "+parents);
         ArrayList<Node> returns = new ArrayList<Node>();
         returns.add(this);
         if (primary)
         {
            Iterator<Node> iter = parents.iterator();
            while (iter.hasNext())
            {
               Node n = iter.next();
               returns.add(n);
               //returns.addAll(n.getParents(primary));
            }
         }
         println("    getParents 2 - "+value+" - "+returns);
         return returns;
      }

      @Override
      public String toString()
      {
         return "" + value;
      }

      boolean addParent(Node n, boolean primary)
      {
         println("Adding "+n+" to "+value);
         parents.addAll(new ArrayList<Node>());
         //if (!parents.add(n)) return true;
         ArrayList<Node> ps = n.getParents(primary);
         println(value+" - "+parents+" - "+children + " - " + ps);
         for (Node p: ps)
            if (!parents.add(p))
            {
               println("returning true");
               return true;
            }

         for (Node child: children)
         {
            println("  doing child "+child);
            //if (!child.addParent(n)) return true;
            for (Node p: ps)
               if (child.addParent(p, false))
                  return true;
         }
         if (primary) n.children.add(this);
         return false;
      }

      @Override
      public int compareTo(Object o)
      {
         return new Integer(value).compareTo(new Integer(((Node)o).value));
      }
   }
}
