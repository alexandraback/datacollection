/**
 * Created by kronenthaler on 08/04/16.
 */

import sun.security.util.BitArray;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(new FileInputStream("B-small-attempt0.in"));
        System.setOut(new PrintStream(new FileOutputStream("B.out")));

        int T = in.nextInt();
        for (int cases = 1; cases <= T; cases++) {
            System.out.printf("Case #%d: ", cases);
            doit(in);
        }
    }

    static void doit(Scanner in) throws IOException{
        String line = in.nextLine();
        if(line.length() == 0)
            line = in.nextLine();

        String toks[] = line.split(" ");
        String C = toks[0];
        String J = toks[1];

        int min=Integer.MAX_VALUE,minc=Integer.MAX_VALUE,minj=Integer.MAX_VALUE;
        int ci = Integer.parseInt(C.replace('?','0'));
        int ji = Integer.parseInt(J.replace('?','0'));
        HashSet<Integer> cl = cand(C, ci, 0);
        HashSet<Integer> jl = cand(J, ji, 0);

        for(int c : cl){
            for(int j : jl){
                if(Math.abs(c-j) < min){
                    min = Math.abs(c-j);
                    minc = c;
                    minj = j;
                }else if(Math.abs(c-j) == min){
                    if(c < minc) {
                        minc = c;
                        minj = j;
                    }else if(c == minc){
                        if(j < minj){
                            minj = j;
                        }
                    }
                }
            }
        }

        System.out.printf(String.format("%%0%dd %%0%dd\n", C.length(), C.length()), minc,minj);
    }

    static HashSet<Integer> cand(String C, int ci, int current){
        HashSet<Integer> ret = new HashSet<>();
        if(current >= C.length())
            ret.add(ci);

        for(int i=current,n=C.length();i<n;i++){
            if(C.charAt(i) == '?') {
                for(int k=0;k<10;k++) {
                    ret.addAll(cand(C, ci + (k * (int) Math.pow(10, (n-i-1))), i + 1));
                }
            }else{
                ret.addAll(cand(C, ci, i + 1));
            }
        }
        return ret;
    }
}