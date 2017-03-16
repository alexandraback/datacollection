
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author David
 */
public class Train2 {
    public static boolean[] used;
    public static String[] train;
    public static ArrayList<Integer>[] begin;
    public static ArrayList<Integer>[] end;
    public static int count;
    public static int t;
    public static void main (String[] args) throws IOException
    {
        Scanner in = new Scanner(new BufferedReader(new FileReader("input.in")));
        PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
        int cases = Integer.parseInt(in.next());
        for(int i = 1; i <= cases; i++)
        {
            t = Integer.parseInt(in.next());
            used = new boolean[t];
            train = new String[t];
            begin = new ArrayList[26];
            end = new ArrayList[26];
            count = 0;
            for (int j = 0; j < 26; j++)
            {
                begin[j] = new ArrayList<Integer>();
                end[j] = new ArrayList<Integer>();
            }
            for (int j = 0; j < t; j++)
            {
                train[j] = strip(in.next());
                begin[train[j].charAt(0)-'a'].add(j);
                end[train[j].charAt(train[j].length()-1)-'a'].add(j);
            }
            //System.out.println(Arrays.toString(train));
            //System.out.println(Arrays.toString(begin));
            //System.out.println(Arrays.toString(end));
            out.printf("Case #%d: ", i);
            for(int j = 0; j < t; j++)
            {
                boolean[] done = new boolean[26];
                used[j] = true;
                for(int k = 0; k < train[j].length(); k++)
                {
                    done[train[j].charAt(k)-'a'] = true;
                }
                recurse(train[j], 1, done);
                used[j] = false;
            }
            out.println(count);
        }
        out.close();
    }
   public static void recurse(String curr, int size, boolean[] done)
   {
       //System.out.println(size+" "+curr);
       //System.out.println(Arrays.toString(done));
       if(size == t)
       {
           //System.out.println("valid");
           count++;
           return;
       }
       
       for(int i = 0; i < t; i++)
       {
           if(!used[i])
           {
                String currtrain = train[i];
                int stopper = currtrain.length();
                
                for(int j = 0; j < currtrain.length(); j++)
                {
                    if(done[currtrain.charAt(j)-'a'] && !(j==0 && curr.charAt(curr.length()-1)==currtrain.charAt(0)))
                    {
                        stopper = j;
                        break;
                    }
                    done[currtrain.charAt(j)-'a'] = true;
                }
                if(stopper==currtrain.length())
                {
                    used[i] = true;
                    recurse(currtrain, size+1, done);
                    used[i] = false;
                    
                }
                for(int j = 0; j < stopper; j++)
                {
                    done[currtrain.charAt(j)-'a'] = false;
                }
                done[curr.charAt(curr.length()-1)-'a'] = true;
           }
       }
   }
   public static String strip(String word)
   {
       String result = "";
       for(int i = 0; i < word.length(); i++)
       {
           if(!result.contains(""+word.charAt(i)))
           {
               result+=word.charAt(i);
           }
       }
       return result;
   }
}
