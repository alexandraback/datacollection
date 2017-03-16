/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author cs1080171
 */
import java.io.*;
import java.util.*;

public class NewClass1 {

    public static void main(String args []) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        BufferedWriter brw = new BufferedWriter(new FileWriter("output"));
        int t = Integer.parseInt(br.readLine());

        for (int j = 1 ; j <= t ; j++)
        {

            int n = Integer.parseInt(br.readLine());
            boolean visited [] = new boolean [n+1];
            Vector<Vector<Integer>> input = new Vector<Vector<Integer>>();
            input.add(new Vector<Integer>());
            for(int i = 0; i < n ; i++)
            {
                String [] inp = br.readLine().split(" ");
                Vector <Integer> temp = new Vector <Integer>();
                for (int k = 1 ; k < inp.length; k ++)
                {
                    temp.add(Integer.parseInt(inp[k]));
                }
                input.add(temp);
            }

            boolean pre = false;

            for (int c = 1 ; c <=n ; c++ )
            {
                boolean [] visit =  new boolean [n+1];
                if (visited[c]==false)
                {
                    if (DFS(input, visit, visited, c))
                    {
                        pre = true;
                        break;
                    }
                }
            }

            if (pre)
                brw.append("Case #"+j +": " + "Yes \n");
            else
                brw.append("Case #"+j +": " + "No \n");


        }
        brw.close();


    }

    static boolean DFS(Vector<Vector<Integer>> input, boolean [] visit,boolean [] visited, int c)
    {
        if (visit[c] == true)
            return true;
        visit[c] = true;
        visited[c] = true;

        Vector<Integer> temp = input.elementAt(c);

        for (int i = 0 ; i < temp.size() ; i++)
        {
            if (DFS(input, visit, visited, temp.elementAt(i)))
                return true;
        }
        return false;
    }

}
