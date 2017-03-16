using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

class Set<T>
{
    public List<T> l = new List<T>();

    public void Insert(T t)
    {
        if (!l.Contains(t))
            l.Add(t);
    }
}

class Vert
{
    public bool visited = false;
    public List<Vert> nv = new List<Vert>();
}

class Graph
{
    Set<Vert> verts = new Set<Vert>();

    public void DefineEdge(Vert v, Vert u)
    {
        v.nv.Add(u);
        verts.Insert(v);
        verts.Insert(u);
    }

    public bool SolveViaBFS(Vert s)
    {
        foreach (Vert v in verts.l)
        {
            v.visited = false;
        }

        s.visited = true;

        Queue<Vert> q = new Queue<Vert>();
        q.Enqueue(s);
        while (q.Count > 0)
        {
            Vert v = q.Dequeue();

            foreach (Vert u in v.nv)
            {
                if (!u.visited)
                {
                    q.Enqueue(u);
                    u.visited = true;
                }
                else
                    return true;
            }
        }

        return false;
    }
}


class Program
{
    static int ncase, N;
    static Graph g;
    static Vert[] v;

    static void Main(string[] args)
    {
        Console.Write(args.Length != 1 ? "args?" : ProcessInput(fileToString(args[0])));
    }

    public static String fileToString(String filePath)
    {
        using (StreamReader re = File.OpenText(filePath)) { return re.ReadToEnd(); }
    }

    public static String ProcessInput(String input)
    {
        string tline, output = "";
        int lineNumber = 0;

        input = input.Replace("\r", "");
        string []lines = input.Split(new char[] { '\n' });

        int NUM_TESTS = int.Parse(lines[lineNumber++]);
        for (ncase = 1; ncase <= NUM_TESTS; ncase++)
        {
            tline = lines[lineNumber++];
            N = int.Parse(tline);

            g = new Graph();
            v = new Vert[N];
            for (int i=0; i<N; i++)
                v[i] = new Vert();

            for (int i = 0; i < N; i++)
            {
                tline = lines[lineNumber++];
                String[] parts = tline.Split(new char[] { ' ' });
                int Mi = int.Parse(parts[0]);
                for (int j = 0; j < Mi; j++)
                {
                    int x = int.Parse(parts[1 + j]);
                    g.DefineEdge(v[i], v[x - 1]); // zero based
                }

            }

            output += ("Case #" + ncase + ": " + Solve("_") + "\n");
        }

        return output;
    }

    public static string Solve(String paramx)
    {
        for (int i = 0; i < N; i++)
        {
            // check if class i contains a loop
            bool loop = g.SolveViaBFS(v[i]);
            if (loop)
                return "Yes";
        }        

        return "No";
    }

}    



