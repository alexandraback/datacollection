
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */
public class ProblemB {
     public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int casenum=s.nextInt();
        for (int i=1;i<=casenum;i++)
        {
            System.out.print("Case #"+i+": ");
            solve(s);
            System.out.println();
        }
    }
     static class pont implements Comparable<pont>
     {
         public int v,pos;
public int usedenergy=0;
public int availenergy;
        @Override
        public int compareTo(pont o) {
         return new Integer(v).compareTo(o.v);
        }
         
     }
       private static void solve(Scanner s) {
           int maxenergy,regain,nnum;
           maxenergy=s.nextInt();
           regain=s.nextInt();
           nnum=s.nextInt();
           List<pont> values=new ArrayList<pont>();
           List<pont> sortedvalues=new ArrayList<pont>();
           for (int i=0;i<nnum;i++)
           {
               
               pont p=new pont();
               p.v=s.nextInt();
               p.pos=i;
               p.availenergy=maxenergy;
               values.add(p );
               sortedvalues.add(p);
           }
           Collections.sort(sortedvalues);
           Collections.reverse(sortedvalues);
           int valuesum=0;
           TreeMap<Integer,pont> v=new TreeMap<Integer, pont>();
           for (pont p:sortedvalues)
           {
               
                       int k;
                       for (k=p.pos;k<values.size() && values.get(k).usedenergy==0;k++);
                      // System.err.println("k:"+p.pos+" "+k+" "+values.size());
                if (k<values.size())
                {
                    //System.err.println("67:"+k+" "+values.get(k).usedenergy);
                    int nextvaluedist=k-p.pos;
                    //System.err.println(71+" "+p.availenergy+" "+nextvaluedist+" "+values.get(k).usedenergy);
                    int maxlose=Math.min(maxenergy,p.availenergy+nextvaluedist*regain-(values.get(k).usedenergy+values.get(k).availenergy));
                    //int maxlose=Math.max(0,Math.min(p.availenergy,Math.min(nextvaluedist*regain,(nextvaluedist*regain+p.availenergy)-values.get(k).usedenergy)));
                //    System.out.println("69 "+nextvaluedist+" "+maxlose) ;
                 //   System.out.println("68:"+p.availenergy+" "+(Math.min(nextvaluedist*regain,maxenergy))+" "+nextvaluedist);
                    p.usedenergy+=maxlose;
                    p.availenergy-=maxlose;
                    for (int k2=p.pos+1;k2<k;k2++)
                    {
                        pont o=values.get(k2);
                        o.availenergy=Math.min(values.get(k2-1).availenergy+regain,maxenergy);
                        
                    }
                    
                }
                else
                {//uccsó elem, ő nullazhat
                    p.usedenergy=p.availenergy;
                    p.availenergy=0;
             //       System.err.println("86:"+p.pos+" "+p.v);
                    for (int k2=p.pos+1;k2<values.size();k2++)
                    {
                        pont o=values.get(k2);
                        o.availenergy=Math.min(values.get(k2-1).availenergy+regain,maxenergy);
                    }
                }
            //    System.out.println("--------------");
                //System.out.println(p.usedenergy+" "+p.pos);
              //  for (int i=0;i<values.size();i++)
                //    System.out.println(values.get(i).pos+" "+values.get(i).usedenergy+" "+values.get(i).availenergy);
                
                valuesum+=p.usedenergy*p.v;
           }
           System.out.print(valuesum);
       }
}
