
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author adam
 */


public class A
{
    public static void main(String[] args) throws Exception
    {
        Scanner s=new Scanner(new FileInputStream(args[0]) );
        int t=s.nextInt();
        TreeSet<Long> keresettek=new TreeSet<Long>();
        LinkedList<Long> keresettek2=new LinkedList<Long>();
        for (int i=1;i<=t;i++)
        {
             //System.out.print("Case #"+i+": ");
             long l=s.nextLong();
             keresettek2.add(l);
             keresettek.add(l);
        }
        TreeMap<Long,Long> sol=solve(keresettek);
        for (int i=1;i<=t;i++)
        {
             System.out.println("Case #"+i+": "+sol.get(keresettek2.get(i-1)) );
        }
    }

    //TreeSet<Long> solu=new TreeSet<Long>();
    //static int[] solu=new int[1000000000];
    private static TreeMap<Long,Long>  solve(TreeSet<Long> l ) {
        TreeMap<Long,Long> ret=new TreeMap<Long, Long>();
        
        TreeSet<Long> voltmar=new TreeSet<Long>();
        TreeSet<Long> elements=new TreeSet<Long>();
        TreeSet<Long> nextelements=new TreeSet<Long>();
        elements.add((long)1);
        int kellmeg=l.size();
        int lepesek=1;
        if (l.contains((long)1))
            ret.put((long)1, (long)1);
        //int max=l.last();
        //while(kellmeg!=0)
        while (ret.size()!=l.size())
        {
            //if (elements.contains(l)) break;
        for (Long i:elements)
        {
           if (
                   //i+1<=max && 
                   voltmar.contains(i+1)==false)
           {
               if (l.contains(i+1) && ret.containsKey(i+1)==false )
               {
                   System.err.println("betesz hozzaadassal:"+(i+1) );
                   ret.put(i+1, (long)(lepesek+1) );
               }
           nextelements.add(i+1); 
           }
           //if (voltmar.contains(i)) continue;
           Long newertek=Long.parseLong(new StringBuilder(i.toString()).reverse().toString() );
           //System.err.println(i+"->"+newertek);
           //if (newertek<=l && new)
           if (
                   //newertek<=l && 
                   voltmar.contains(newertek)==false )
           {
               if (l.contains(newertek) && ret.containsKey(newertek)==false)
               {
                   System.err.println("betesz forditassal:"+newertek);
                   ret.put(newertek, (long)(lepesek+1) );
               }
               
           nextelements.add(newertek);
           }
           //voltmar.add(newertek);
           voltmar.add(i);
        }
        elements=new TreeSet<Long>(nextelements);
        nextelements.clear();
        lepesek++;
        System.err.println(lepesek);
        //if (elements.contains(l)) break;
        }
        return ret;
        //System.out.println(lepesek);
        
    }
}