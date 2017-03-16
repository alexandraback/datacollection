/*
 * reordering
 * Girish Venkat
 */

import java.io.*;
import java.util.*;

public class reordering {
    public static int T;
    public static int N;
    public static long mod=1000000007L;
    public static String[] arr;
    public static boolean[] isSame;
    
    public static String compress(String s) {
        String ret="";
        int start=0;
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(start)!=s.charAt(i)) {
                ret+=s.charAt(start);
                start=i;
            }
        }
        ret+=s.charAt(start);
        return ret;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner in=new Scanner(new File("reordering.in"));
        PrintStream out=new PrintStream(new File("reordering.out"));
        T=in.nextInt();
        boolean found;
        for (int i=1; i<=T; i++) {
            out.print("Case #"+i+": ");
            N=in.nextInt();
            found=false;
            long ret=1L;
            arr=new String[N];
            isSame=new boolean[N];
            for (int j=0; j<N; j++) {
                arr[j]=compress(in.next());
                for (int k=0; k<arr[j].length() && !found; k++) {
                    if (arr[j].substring(0,k).contains(arr[j].charAt(k)+"")) {
                        out.println(0);
                        found=true;
                    }
                }
                isSame[j]=(arr[j].length()==1);
            }
            String letters="qwertyuioplkjhgfdsazxcvbnm";
            for (int j=0; j<letters.length() && !found; j++) {
                char c=letters.charAt(j);
                int numb=0, nume=0, ib, ie, nums=0;
                ArrayList<Integer> arr1=new ArrayList<Integer>();
                for (int k=0; k<N && !found; k++) {
                    if (arr[k].charAt(arr[k].length()-1)==c) {
                        if (!isSame[k]) {
                            nume++;
                            ie=k;
                        }
                        else {
                            nums++;
                            arr1.add(k);
                        }
                    }
                    else if (arr[k].charAt(0)==c) {
                        if (!isSame[k]) {
                            numb++;
                            ib=k;
                        }
                        else {
                            nums++;
                            arr1.add(k);
                        }
                    }
                    else if (arr[k].contains(c+"")) {
                        out.println(0);
                        found=true;
                    }
                    if (nume>1 || numb>1) {
                        out.println(0);
                        found=true;
                    }
                }
                if (!found) {
                    if (nums!=0 && i==2) System.out.println(nums);
                    for (int k=1; k<=nums; k++) {
                        ret*=i;
                        ret=ret % mod;
                    }
                }
            }
            if (!found) out.println(ret);
        }
    }
}