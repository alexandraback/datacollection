package com.koray.codejam;

import com.google.common.collect.TreeMultiset;

import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Scanner;

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
                int res = 0;
                int length = new Integer(sc.nextInt()) +1;
                int []  numbers  =   new int[length];
                String line = sc.next();
                for(int j = 0 ; j < length ; j++)
                    numbers[j] = line.charAt(j) - 48;
                int need = 0;
                for(int j = 1 ; j < numbers.length ; j++) {
                    if (j > numbers[j - 1] + need)
                        need += j - numbers[j - 1]-need;
                    numbers[j]+=numbers[j-1];
                }
                res=need;

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
                int res = 0;
                int length = new Integer(sc.nextInt());
                sc.nextLine();
                TreeMultiset<Integer> numbers  = TreeMultiset.create();
                for(int j = 0 ; j < length; j ++)
                    numbers.add( sc.nextInt());
                int besttimepassed  = 9999999;
                for(int j = 0 ; j < 30000 ;j ++)
                {
                    int max =  numbers.lastEntry().getElement();
                    numbers.remove(max);
                    besttimepassed = Math.min(besttimepassed, j+ max);
                    int dual =max % 2 == 0 ? max/ 2 :max / 2;
                    max = max % 2 == 0 ? max/ 2 :max / 2 + 1;
                    numbers.add(max);
                    if(dual > 2)
                        numbers.add(dual);
                }
                res=besttimepassed;

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


static class Res
{
    char value;
    int sign;
    public Res(char value , int sign){
        this.value = value;
        this.sign = sign;
    }
}


    public static HashMap<String , Res> map = new HashMap<String, Res>();
    static
    {
        map.put("ij" , new Res('k',1));
        map.put("jk" , new Res('i',1));
        map.put("ki" , new Res('j',1));
        map.put("ji" , new Res('k',-1));
        map.put("ik" , new Res('j',-1));
        map.put("kj" , new Res('i',-1));
        map.put("ii" , new Res('x',-1));
        map.put("jj" , new Res('x',-1));
        map.put("kk" , new Res('x',-1));
        map.put("xk" , new Res('k',1));
        map.put("xj" , new Res('j',1));
        map.put("xi" , new Res('i',1));
    }

    public static void questionC()
    {
        try {
            Scanner sc = new Scanner(new File("in.txt"));
            FileWriter out = new FileWriter(new File("out.txt"));
            int T = new Integer(sc.nextLine());
            for (int i = 1; i < T + 1; i++) {
                String res = "NO";
                int length = new Integer(sc.nextInt());
                int repetition = new Integer(sc.nextInt());//%64;
                sc.nextLine();
                String string = sc.next();
                String st = "";
//                if(repetition !=0 )
                {
                    int signi = 1;
                    for (int j = 0; j < repetition; j++)st+=string;
                    char currenti  = st.charAt(0);
                    boolean found = false;
                    for(int j = 1 ; j < st.length() ; j ++ )
                    {
                        if(currenti == 'i' && signi ==1)
                        {
                            int signj = 1;
                            char currentj = st.charAt(j);
                            for(int z = j+1 ; z < st.length() ; z++)
                            {
                                if(currentj == 'j' && signj==1)
                                {
                                    int signk = 1;
                                    char currentk = st.charAt(z);
                                    for(int t = z+1 ; t < st.length() ; t++)
                                    {
                                        Res resk = map.get("" + currentk+st.charAt(t));
                                        currentk = resk.value;
                                        signk *=resk.sign;
                                    }
                                    if(signk == 1 && currentk == 'k')
                                        found =true;

                                    break;
                                }
                                Res resj = map.get("" + currentj+st.charAt(z));
                                currentj = resj.value;
                                signj *=resj.sign;

                            }
                            break;
                        }
                        Res resi = map.get("" + currenti+st.charAt(j));
                        currenti = resi.value;
                        signi *=resi.sign;
                    }
                    if(found )
                        res = "YES";

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

}
