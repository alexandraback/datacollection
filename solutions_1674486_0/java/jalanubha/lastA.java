/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package contests.googleJam;

import java.io.*;
import java.util.LinkedList;

/**
 *
 * @author
 * Kisna
 */
public class lastA 
{
    static int[][] classes = null;
    static int exit = 0;
    static  int N;
    static LinkedList<Integer> end = null;
    public static void check(int j,int[] a)
    {
        if(exit == 0)
        for (int i = 0; i < a.length; i++) 
        {
            if(a[0] == -1)
            {
                if(end.contains(j+1))
                {
                    exit = 1;
                    break;
                }
                end.add(j+1);
            }
            else
                check(a[i]-1,classes[a[i]-1]);
        }
    }
    public static void main(String[] args) 
    {
       BufferedReader br = null;
       
 
		try {
                        FileWriter fstream = new FileWriter("output.out");
                        BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader("A-small-attempt1.in"));
			//br = new BufferedReader(new FileReader("textfile.in"));
                        sCurrentLine = br.readLine();
                        int i = 1;
                        while ((sCurrentLine = br.readLine()) != null) 
                        {    
                            out.write("Case #" + i++ + ": "); 
                            N = Integer.parseInt(sCurrentLine);
                            
                            System.out.println(sCurrentLine);
                            classes = new int[N][];
                            int t = 0;
                            for (int j = 0; j < N; j++) 
                            {
                                String[] mi = br.readLine().split(" ");
                                if("0".equals(mi[0]))
                                {
                                    classes[j] = new int[1];
                                    classes[j][0] = -1;
                                }
                                else
                                {
                                    classes[j] = new int[Integer.parseInt(mi[0])];
                                }
                                for (int k = 1; k < mi.length; k++) 
                                {
                                    classes[j][k-1] = Integer.parseInt(mi[k]);
                                }
                            }
                            
                            for (int j = 0; j < N; j++) 
                            {
                                end = new LinkedList<Integer>();
                                exit = 0;
                                check(j,classes[j]);
                                if(exit == 1)
                                {
                                    out.write("Yes");
                                    t = 1;
                                    break;
                                }
                                
                            }
                            if(t == 0)
                                out.write("No");
                            out.write("\n");
                        }
                        out.close();
 
		} catch (IOException e) {
		} finally {
			try {
				if (br != null)
                                    br.close();
			} catch (IOException ex) {
			}
		} 
    }
}
