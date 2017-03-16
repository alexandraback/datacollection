
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Charles
 */
public class CodeJamA
{
    //input/output file name

    static final String FILE_NAME = "A";

    /**
     * @param args the command line arguments
     * @throws FileNotFoundException  
     */
    public static void main(String[] args) throws FileNotFoundException
    {
        ArrayList<Graph> values = readFile(FILE_NAME + ".in");
        int count = 1;

        PrintWriter outFile = new PrintWriter(new File(FILE_NAME + ".out"));
        for (Graph g : values)
        {
            String output = processAlgorithm(g, count++);
            System.out.println(output);
            outFile.println(output);
        }
        outFile.close();
    }

    /**
     * Reads the CodeJam files and returns the input as a List of String. Should
     * be adjusted for each individual file inputs.
     *
     * @param fileName The name of the file to be read
     * @return the list containing the contents of the file.
     */
    public static ArrayList<Graph> readFile(String fileName)
    {
        ArrayList<Graph> results = new ArrayList<Graph>();
        try
        {
            Scanner inFile = new Scanner(new File(fileName));
            int numberOfLines = Integer.parseInt(inFile.nextLine());
            for (int count = 0; count < numberOfLines; count++)
            {
                int vCount = inFile.nextInt();
                Graph g = new Graph();
                results.add(g);
                for (int v = 0; v < vCount; v++)
                {
                    V child = new V(v + 1);
                    g.vertices.add(child);

                }
                for (int v = 0; v < vCount; v++)
                {
                    V child = g.vertices.get(v);
                    int parentCount = inFile.nextInt();
                    for (int p = 0; p < parentCount; p++)
                    {
                        int pId = inFile.nextInt();
                        V parent = g.vertices.get(pId - 1);
                        E e = new E();
                        e.child = child;
                        e.parent = parent;
                        child.parrents.add(e);
                    }
                }
            }

            if (numberOfLines != results.size())
            {
                System.err.println("File size does not match...");
                System.exit(0);
            }

        }
        catch (FileNotFoundException ex)
        {
            System.err.println("File not found...");
            System.exit(0);
        }
        return results;
    }

    /**
     * Work the magic here.
     * @param line
     * @param count
     * @return 
     */
    private static String processAlgorithm(Graph g, int count)
    {
        StringBuilder result = new StringBuilder("Case #" + count + ": ");

        if (g.hasDiamond())
        {
            result.append("Yes");
        }
        else
        {
            result.append("No");
        }


        return result.toString();
    }
}

class Graph
{

    ArrayList<V> vertices = new ArrayList<V>();

    boolean hasDiamond()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            V a = vertices.get(i);
            for (int j = 0; j < vertices.size(); j++)
            {
                V b = vertices.get(j);
                if (a.id != b.id)
                {
                    if (countPaths(a, b) > 1)
                    {
                        return true;
                    }
                }
            }

        }

        return false;
    }

    int countPaths(V a, V b)
    {
        int count = 0;

        ArrayList<V> queue = new ArrayList<V>();
        for (E parent : a.parrents)
        {
            queue.add(parent.parent);
        }

        while (!queue.isEmpty())
        {
            V current = queue.remove(0);
            if (current.id == b.id)
            {
                count++;
            }
            else
            {
                for (E parent : current.parrents)
                {
                    queue.add(parent.parent);
                }
            }
        }

        return count;
    }
}

class E
{

    V child, parent;
}

class V
{

    ArrayList<E> parrents = new ArrayList<E>();
    int id;

    public V(int id)
    {
        this.id = id;
    }

    @Override
    public boolean equals(Object obj)
    {
        return ((V) obj).id == this.id;
    }
}
