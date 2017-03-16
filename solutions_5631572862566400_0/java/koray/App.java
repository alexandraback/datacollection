package com.koray.codejam;

import java.io.File;
import java.io.FileWriter;
import java.util.*;

/**
 * Hello world!
 * 
 */
public class App 
{
    
    
    public static void questionA()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String res = "";
                String input  = sc.next();
                for (int j = 0 ; j < input.length() ; j ++ )
                {
                    if((res+input.charAt(j)).compareTo(input.charAt(j) + res) > 0)
                        res += input.charAt(j);
                    else
                        res = input.charAt(j) + res;
                }

    
                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    
    public static void questionB()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                int N = sc.nextInt();
                int []  all = new int [2900];
                int [] ret = new int [N];
                for(int j = 0 ; j < 2*N-1 ; j++)
                {
                    for (int k = 0 ; k < N ; k ++)
                    {
                        all[sc.nextInt()]++;
                    }
                }
                int index = 0 ;
                for (int j = 0 ; j < 2600 ; j ++)
                {
                    if(all[j] % 2 ==1)
                    {
                        ret[index] = j;
                        index ++;
                    }
                }


                Arrays.sort(ret);





                String res = "";
                for(int j = 0 ; j < N ; j ++)
                    res+=" " + ret[j];
                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }



    static List<List<Integer>> scchains = new ArrayList<List<Integer>>() ;
    static int biggestloop = 0;
    public static void questionC()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                scchains = new ArrayList<List<Integer>>() ;
                biggestloop = 0;
                int ret = 0 ;
                int N = sc.nextInt();
                int[] arr = new int [N];
                for (int j = 0 ; j < N ; j ++){
                    arr[j]=sc.nextInt()-1;
                }

                for (int j = 0 ; j < N ;j ++){
                    List<Integer> chain = new ArrayList<Integer>();
                    chain.add(j);
                    searchFor(arr , chain);
                }
                Set<Integer> set = new HashSet<Integer>();
                for(List<Integer > l : scchains)
                {
                    for(Integer z : l)
                        set.add(z);
                }
                int res = Math.max(biggestloop , set.size());
                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }

            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }

    private static void searchFor(int[] arr, List<Integer> chain) {
        int lastelement = chain.get(chain.size()-1);
        if(arr[arr[lastelement]] == lastelement)
        {
            chain.add(arr[lastelement]);
            boolean found = false;
            boolean replace = false;
            List tobereplaced = null;
            for(List l : scchains)
            {

                if (l.lastIndexOf(arr[lastelement]) == l.size()-1){
                    found = true;
                    if(l.size() < chain.size()) {
                        replace = true;
                        tobereplaced = l;
                    }
                }

            }
            if(replace)
            {
                scchains.remove(tobereplaced);
                scchains.add(chain);
            }
            if(!found)
            {
                scchains.add(chain);
            }


        }
        else if(chain.contains(arr[lastelement]))
        {
            int index = chain.indexOf(arr[lastelement]);
            int size  = chain.size() - index;
            biggestloop = Math.max(biggestloop , size);

        }
        else {
            chain.add(arr[lastelement]);
            searchFor(arr,chain);
        }
    }


    public static void questionD()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String  res = "";
                int X = new Integer(sc.nextInt());


                System.out.println("Case #" + i + ": " + res);
                out.write("Case #" + i + ": " + res + "\n");
                try {
                    sc.nextLine();
                } catch (Exception e) {
                }


            }
            out.flush();
            sc.close();
            out.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }


}
