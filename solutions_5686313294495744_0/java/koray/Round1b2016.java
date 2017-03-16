package com.koray.codejam;

import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.*;


public class Round1b2016
{
    
    
    public static void questionA()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String ret = "";
                String input  = sc.next();
                int[] arr = new int[150];
                for ( int j = 0 ; j < input.length() ; j ++)
                    arr[input.charAt(j)] ++;

                List<Integer> res  = new ArrayList<Integer>();
                for(int j = 0 ; j < arr['Z'] ; j ++)
                    res.add(0);
                for(int j = 0 ; j < arr['W'] ; j ++)
                    res.add(2);
                for(int j = 0 ; j < arr['U'] ; j ++)
                    res.add(4);
                for(int j = 0 ; j < arr['G'] ; j ++)
                    res.add(8);
                for(int j = 0 ; j < arr['X'] ; j ++)
                    res.add(6);
                for(int j = 0 ; j < arr['T'] - arr['G'] - arr['W']; j ++)
                    res.add(3);
                for(int j = 0 ; j < arr['O'] -arr['U'] -arr['W'] -arr['Z'] ; j ++)
                    res.add(1);
                for(int j = 0 ; j < arr['F'] - arr['U'] ; j ++)
                    res.add(5);
                for(int j = 0 ; j < arr['S'] - arr['X'] ; j ++)
                    res.add(7);
                for(int j = 0 ; j < arr['I'] - arr['G'] - arr['X'] -arr['F'] + arr['U'] ; j ++)
                    res.add(9);
                Collections.sort(res);
                for(Integer k: res)
                    ret += k;
                System.out.println("Case #" + i + ": " + ret);
                out.write("Case #" + i + ": " + ret + "\n");
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
                String ret = "";
                String first  = sc.next();
                String second= sc.next();
                String [] rr = search(first, second , 0);
                ret = rr[0] + " " + rr[1];
                System.out.println("Case #" + i + ": " + ret);
                out.write("Case #" + i + ": " + ret + "\n");
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

    static Comparator<String []> comp = new stringcomp();

    public static String[] search(String first, String second, int bigger){
        if(first.length() == 0)
            return new String[]{first , second};
        if(bigger > 0)
            return new String[]{ first.replace('?' , '0') , second.replace('?' , '9')};
        else if(bigger < 0)
            return new String[]{ first.replace('?' , '9') , second.replace('?' , '0')};
        if(first.charAt(0 ) == '?'  && second.charAt(0) == '?')
        {
            String [][] res = new String [3][];
            String [] dummy = search(first.substring(1) , second.substring(1) , 1);
            res[0] = new String[]{'1' + dummy[0] , '0' + dummy[1]};
            dummy = search(first.substring(1) , second.substring(1) , -1);
            res[1] = new String[]{'0' + dummy[0] , '1' + dummy[1]};
            dummy = search(first.substring(1) , second.substring(1) , 0);
            res[2] = new String[]{'0' + dummy[0] , '0' + dummy[1]};
            Arrays.sort(res , comp);
            return res[0];

        }
        else if(first.charAt(0) == '?')
        {
            String [][] res;
            if(second.charAt(0) != '9'  && second.charAt(0) != '0' )
                res = new String[3][];
            else
                res = new String[2][];
            int index =0;
            if(second.charAt(0) != '0'  ) {
                String[] dummy = search(first.substring(1), second.substring(1), -1);
                res[index] = new String[]{(char)(second.charAt(0)-1) + dummy[0] , second.charAt(0) + dummy[1]};
                index++;
            }
            if(second.charAt(0) != '9'  ) {
                String[] dummy = search(first.substring(1), second.substring(1), 1);
                res[index] = new String[]{(char)(second.charAt(0)+1) + dummy[0] , second.charAt(0) + dummy[1]};
                index++;
            }
            String[] dummy = search(first.substring(1), second.substring(1), 0);
            res[index] = new String[]{ (second.charAt(0)) + dummy[0] , second.charAt(0) + dummy[1]};
            Arrays.sort(res , comp);
            return res[0];
        }
        else if(second.charAt(0) == '?')
        {
            String [][] res;
            if(first.charAt(0) != '9'  && first.charAt(0) != '0' )
                res = new String[3][];
            else
                res = new String[2][];
            int index =0;
            if(first.charAt(0) != '0'  ) {
                String[] dummy = search(first.substring(1), second.substring(1), 1);
                res[index] = new String[]{ first.charAt(0) + dummy[0] ,   (char)(first.charAt(0)-1)+ dummy[1]};
                index++;
            }
            if(first.charAt(0) != '9'  ) {
                String[] dummy = search(first.substring(1), second.substring(1), -1);
                res[index] = new String[]{ first.charAt(0) + dummy[0] ,   (char)(first.charAt(0)+1)+ dummy[1]};
                index++;
            }
                String[] dummy = search(first.substring(1), second.substring(1), 0);
            try {
                res[index] = new String[]{first.charAt(0) + dummy[0], (first.charAt(0)) + dummy[1]};
                Arrays.sort(res, comp);
            }
            catch (Exception e){
                e.printStackTrace();
            }
            return res[0];
        }
        else {
            String [] ret = search(first.substring(1) , second.substring(1) , first.charAt(0) - second.charAt(0));
            return   new String[]{first.charAt(0) + ret[0] , second.charAt(0) + ret[1]};
        }
    }


    public static class stringcomp implements  Comparator<String[]>{

        @Override
        public int compare(String[] o1, String[] o2) {
            BigInteger ff = new BigInteger(o1[0]);
            BigInteger fs = new BigInteger(o1[1]);
            BigInteger sf = new BigInteger(o2[0]);
            BigInteger ss = new BigInteger(o2[1]);
            BigInteger diff1 =fs.subtract(ff).abs();
            BigInteger diff2 =ss.subtract(sf).abs();

            if(diff1.compareTo(diff2) != 0 )
                return diff1.compareTo(diff2);
            else if(ff.compareTo(sf) !=0)
                return ff.compareTo(sf);
            else
                return fs.compareTo(ss);
        }


    }


    static int [] powersoftwo = new int[31];
    public static void questionC()
    {
        for (int i = 0 ; i < powersoftwo .length ; i ++)
        {
            powersoftwo [i] = 1 << i;
        }
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                int ret = 0;
                int N =   sc.nextInt();
                String [][] words = new String [N][2];

                for ( int j = 0 ; j < N ; j ++)
                {
                    words [j][0] = sc.next();
                    words [j][1] = sc.next();
                }
                int max = 0;
                for (int x = 0 ; x < N ; x++ )
                    System.out.println(x + "  " +Arrays.toString(  words[x]));
                Arrays.deepToString(words);
                for (int j = 0 ; j <  ((1 << N) +200 ) ; j ++ )
                {
                    boolean possible =true;
                    int size = 0;
                    for(int z = 0 ; z < N ; z++)
                    {
                        if( (powersoftwo [z] & j) > 0  ) {
                            size ++;
                            boolean foundfirst = false;
                            boolean foundsecond = false;

                            for (int m = 0; m < N; m++) {
                                if ( z!=m  && words[z][0].equals(words[m][0]))
                                    foundfirst = true;
                                if ( z!=m  &&  words[z][1].equals(words[m][1]))
                                    foundsecond = true;
                            }
                            possible &= foundfirst &foundsecond;

                        }
                    }
                    if(possible)
                        max = Math.max(max , size);



                }

                ret = max;

                System.out.println("Case #" + i + ": " + ret);
                out.write("Case #" + i + ": " + ret + "\n");
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
