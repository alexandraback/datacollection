/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg20161b.a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;

/**
 *
 * @author Juli
 */
public class A {
    
    public void solve() throws FileNotFoundException, IOException
    {
        BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0.in"));
	// input file name goes above
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
	//PrintWriter out = new PrintWriter(System.out);
	Scanner in = new Scanner(f);
	int T = in.nextInt();
	for(int c = 0; c < T; c++)
	{
            out.print("Case #" + (c+1) + ": ");
            String numbers = in.next();
            int[] cq = new int['Z'-'A'+1];
            for(int i = 0; i < numbers.length(); i++)
            {
                cq[numbers.charAt(i)-'A']++;
            }
            int[] nq = new int[10];
            while(cq['Z'-'A'] > 0)
            {
                cq['Z'-'A']--;
                cq['E'-'A']--;
                cq['R'-'A']--;
                cq['O'-'A']--;
                nq[0]++;
            }
            while(cq['W'-'A'] > 0)
            {
                cq['T'-'A']--;
                cq['W'-'A']--;
                cq['O'-'A']--;
                nq[2]++;
            }
            while(cq['G'-'A'] > 0)
            {
                cq['E'-'A']--;
                cq['I'-'A']--;
                cq['G'-'A']--;
                cq['H'-'A']--;
                cq['T'-'A']--;
                nq[8]++;
            }           
            while(cq['X'-'A'] > 0)
            {
                cq['S'-'A']--;
                cq['I'-'A']--;
                cq['X'-'A']--;
                nq[6]++;
            }
            while(cq['T'-'A'] > 0)
            {
                cq['T'-'A']--;
                cq['H'-'A']--;
                cq['R'-'A']--;
                cq['E'-'A']--;
                cq['E'-'A']--;
                nq[3]++;
            }            
            while(cq['S'-'A'] > 0)
            {
                cq['S'-'A']--;
                cq['E'-'A']--;
                cq['V'-'A']--;
                cq['E'-'A']--;
                cq['N'-'A']--;
                nq[7]++;
            }            
            while(cq['R'-'A'] > 0)
            {
                cq['F'-'A']--;
                cq['O'-'A']--;
                cq['U'-'A']--;
                cq['R'-'A']--;
                nq[4]++;
            }
            while(cq['F'-'A'] > 0)
            {
                cq['F'-'A']--;
                cq['I'-'A']--;
                cq['V'-'A']--;
                cq['E'-'A']--;
                nq[5]++;
            }
            while(cq['O'-'A'] > 0)
            {
                cq['O'-'A']--;
                cq['N'-'A']--;
                cq['E'-'A']--;
                nq[1]++;
            }
            nq[9] = cq['I'-'A'];
            for(int i = 0; i < 10; i++)
            {
                while(nq[i]>0)
                {
                    nq[i]--;
                    out.print(i);
                }
            }
            out.println();
            out.flush();
	}
	
        out.close();
	in.close();
    }
    
        	public static void main(String ... args) throws IOException
	{
		A solver = new A();
		solver.solve();
		System.exit(0);
	}
}
