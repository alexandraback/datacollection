
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProbA {
          public static void main(String[] args) 
    {
        
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
                for (int i=1;i<=casenum;i++)
                {System.out.print("Case #"+i+": ");
                solve(s);
                System.out.println();
                }
    }

    private static void solve(Scanner s) {
        String g=s.next();
        long n=s.nextLong();
        Set<Character> vow=new TreeSet<Character>();
        vow.add('a');
        vow.add('e');
        vow.add('i');
        vow.add('o');
        vow.add('u');
        List<Integer> poz=new LinkedList<Integer>();
        for (int i=0;i<g.length();i++)
        {
            boolean ok=true;
            if (i+n<=g.length())
            {
            for (long j=0;j<n && ok;j++)
                if (vow.contains(g.charAt((int)(i+j) )) ) ok=false;
            if (ok)
            {
             //   System.err.println("add"+i);
                poz.add(i);
            }
            }
        }
        BigInteger ret=new BigInteger("0");
        
        for (int i=0;i<poz.size();i++)
        {
            
            long elotte=0;
            if (i==0)
                elotte=0;
            else
                elotte=poz.get(i-1)+1;
            long elsointervall=poz.get(i)-elotte+1;
            long utana=0;
            //if (i==poz.size()-1)
                utana=g.length();
            //else
              //  utana=poz.get(i+1);
            
            long masodikintervall=utana-(poz.get(i)+n)+1;
         //   System.err.println("ret"+ret+" "+elsointervall+" "+masodikintervall);
            ret=ret.add(new BigInteger(new Long(elsointervall).toString()).multiply(new BigInteger(new Long(masodikintervall).toString())));
        }
        System.out.print(ret.toString());
    }
    
        /*static BigInteger combinations( n, long k) {
		long coeff = 1;
		for (long i = n - k + 1; i <= n; i++) {
			coeff *= i;
		}
		for (long i = 1; i <= k; i++) {
			coeff /= i;
		}
		return coeff;
	}*/
    
}
