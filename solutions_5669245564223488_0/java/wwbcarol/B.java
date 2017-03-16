package C2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

/**
 * Created by wenbin on 11/5/14.
 */
public class B {

    static final String TYPE = "B";
    static String inputFile;
    static String outputFile;

    private static void Name(String s) {
        inputFile = s + ".in";
        outputFile = s + ".out";
    }

    public static ArrayList<ArrayList<Integer>> permute(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
        if(num.length==0) return list;
        if(num.length==1){
            ArrayList<Integer> a = new ArrayList<Integer>();
            a.add(num[0]);
            list.add(a);
            return list;
        }

        for(int i=0;i<num.length;i++){
            int[] sub = new int[num.length-1];
            for(int j=0;j<num.length;j++){
                if(j<i)sub[j] = num[j];
                if(j>i)sub[j-1] = num[j];
            }

            ArrayList<ArrayList<Integer>> sublist = permute(sub);
            for(int j=0;j<sublist.size();j++){
                ArrayList<Integer> subsub = sublist.get(j);
                subsub.add(num[i]);
                list.add(subsub);
            }
        }

        return list;
    }

    public static boolean isValid(String s){
        System.out.println("Start:" + s);
        HashSet<Character> hash = new HashSet<Character>();
        Character last = '-';
        for(int i=0;i<s.length();i++){
            Character c = s.charAt(i);
            if(c.compareTo(last)==0){
                continue;
            }else{
                if(hash.contains(c)){
                    return false;
                }
                else{
                    hash.add(c);
                }
                last = c;
            }
        }
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {

        String root = "data/C2014";

        // Test
//        Name(TYPE + "-test");
        Name(TYPE);

        Scanner in = new Scanner(new File(root, inputFile));
        PrintWriter out = new PrintWriter(new File(root, outputFile));

        int T = in.nextInt();

        for (int i = 0; i < T; i++) {
            int N = in.nextInt();
            in.nextLine();
            String input_s = in.nextLine();
            String[] cars = input_s.split(" ");
            int[] init = new int[N];
            for(int t = 0; t < N; t++){
                init[t] = t;
            }

            ArrayList<ArrayList<Integer>> permu = B.permute(init);

            int count=0;
            for(int t = 0; t < permu.size(); t++){
                ArrayList<Integer> list = permu.get(t);
                StringBuilder sb = new StringBuilder();

                for(int tt = 0; tt<list.size();tt++){
                    sb.append(cars[list.get(tt)]);
                }

                if(B.isValid(sb.toString())) count++;
            }
            out.println("Case #" + (i + 1) + ": " + count);
//            HashSet<Character> inside_set = new HashSet<Character>();
//            HashSet<Character> side_set = new HashSet<Character>();
//
//            for(int t = 0; t < N; t++){
//                String car = cars[t];
//                HashSet<Character> one = new HashSet<Character>();
//                if(car.length()==1){
//                    inside_set.add(car.charAt(0));
//                    continue;
//                }
//                for(int inx = 0; inx < car.length();inx++){
//                    if(inx==0||inx==car.length()-1){
//                        side_set.add(car.charAt(inx));
//                    }else{
//
//                    }
//                }
//            }


        }

        in.close();
        out.close();

    }
}
