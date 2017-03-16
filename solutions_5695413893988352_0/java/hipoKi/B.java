/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg20161b.b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import pkg20161b.a.A;

/**
 *
 * @author Juli
 */
public class B {
    
    public void solve() throws FileNotFoundException, IOException
    {
        BufferedReader f = new BufferedReader(new FileReader("B-small-attempt0.in"));
	// input file name goes above
	PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
	//PrintWriter out = new PrintWriter(System.out);
	Scanner in = new Scanner(f);
	int T = in.nextInt();
	for(int c = 0; c < T; c++)
	{
            out.print("Case #" + (c+1) + ": ");
            
            String a = in.next();
            String b = in.next();
            
            boolean tie = true;
            boolean aWins = false;
            boolean bWins = false;
            
            StringBuffer na = new StringBuffer();
            StringBuffer nb = new StringBuffer();
            
            for(int i = 0; i < a.length(); i++)
            {
                char nexta = a.charAt(i);
                char nextb = b.charAt(i);
                boolean nt = tie && (nexta == nextb || nexta == '?' || nextb == '?');
                if(!nt && tie)
                {
                    aWins = nexta >  nextb;
                    bWins = nextb > nexta;
                }
                tie = nt;
                this.act(na, nexta, nextb, aWins, tie);
                this.act(nb, nextb, nexta, bWins, tie);
            }
            out.println(na.toString() + ' ' + nb.toString());
            out.flush();
	}
	
        out.close();
	in.close();
    }
    
    private void act(StringBuffer b, char c, char oc, boolean wins, boolean tie)
    {
        char nc = '*';
        if(c == '?')
        {
            if(tie)
            {
                if(oc == '?')
                {
                    nc = '0';
                } else {
                    nc = oc;
                }
            } else if(wins) {
                nc = '0';
            } else {
                nc = '9';
            }
        } else {
            nc = c;
        }
        b.append(nc);
    }
    
            	public static void main(String ... args) throws IOException
	{
		B solver = new B();
		solver.solve();
		System.exit(0);
	}
}
