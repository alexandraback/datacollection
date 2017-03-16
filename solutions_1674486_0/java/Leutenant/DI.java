import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.Stack;

/**
 * Created by IntelliJ IDEA.
 * User: Pavel Bulanov
 * Date: 06.05.12
 * Time: 11:06
 * To change this template use File | Settings | File Templates.
 */
public class DI {


    public static boolean solve (int[][] inheritance)
    {
        int[] search = new int[inheritance.length];

        for (int start = 0; start < search.length; start++)
        {
            if (0 == inheritance[start].length) continue;

            int[] parents = inheritance[start];
            Arrays.fill(search, -1);
            Stack<Integer> stack  =new Stack<Integer>();

            for (int i=0; i<parents.length; i++)
            {
                int parent = parents[i];
                search[parent] = i;

                stack.push (parent);
            }


            while (stack.size() > 0)
            {
                Integer cur = stack.pop();

                parents = inheritance[cur];
                int pathIndex = search[cur];

                for (int i=0; i<parents.length; i++)
                {
                    int parent = parents[i];

                    if (search[parent] < 0)
                    {
                        search[parent] = pathIndex;
                        stack.push(parent);
                    }
                    else
                    {
                        return true;
                    }

                }
            }
        }

        return false;
    }



    public static void main (String[] args) throws Exception
    {

		BufferedReader sr = new BufferedReader(new FileReader("c:\\Projects\\DI.txt"));

		int total = Integer.parseInt(sr.readLine());

        for (int c=0; c<total; c++)
        {
            int N = Integer.parseInt (sr.readLine());

            int[][] inheritance = new int[N][];

            for (int i=0; i<N; i++)
            {
                String[] tokens = sr.readLine().split(" ");

                int cnt = Integer.parseInt (tokens[0]);
                inheritance[i] = new int[cnt];

                for (int j=0; j<cnt; j++)
                {
                    inheritance[i][j] = Integer.parseInt (tokens[j+1]) - 1;
                }
            }

            boolean isOk = solve (inheritance);

            System.out.printf("Case #%d: %s\n", c+1, isOk? "Yes" : "No");
        }
    }
}
