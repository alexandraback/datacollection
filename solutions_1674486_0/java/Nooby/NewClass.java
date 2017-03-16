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

public class NewClass {

    public static void main(String args []) throws IOException
    {
        BufferedReader br = new BufferedReader(new FileReader("A-small-attempt2.in"));
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
                    if (DFS(input, visit, c))
                    {
                        pre = true;
                        break;
                    }
                }
                for (int z = 1 ; z <=n ; z++)
                {
                    if (visit[z])
                        visited[z] = true;
                }
            }

            if (pre)
                brw.append("Case #"+j +": " + "Yes \n");
            else
                brw.append("Case #"+j +": " + "No \n");


        }
        brw.close();


    }

    static boolean DFS(Vector<Vector<Integer>> input, boolean [] visited, int c)
    {
        if (visited[c] == true)
            return true;
        else
            visited[c] = true;

        Vector<Integer> temp = input.elementAt(c);

        for (int i = 0 ; i < temp.size() ; i++)
        {
            if (DFS(input, visited, temp.elementAt(i)))
                return true;
        }
        return false;
    }

}
