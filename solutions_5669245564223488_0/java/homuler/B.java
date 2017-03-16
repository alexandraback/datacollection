/**
 * Created by homulerdora on 3/31/14.
 */
import java.util.*;
import java.io.*;

public class B {
    public static void swap(int[] p, int x, int y){
        int temp = p[x];
        p[x] = p[y];
        p[y] = temp;
    }
    public static void swap(char[] p, int x, int y){
        char temp = p[x];
        p[x] = p[y];
        p[y] = temp;
    }

    public static int[] next_permutation(int[] p){
        int x = -1;
        for(int i = p.length-1; i > 0; i--){
            if( p[i-1] < p[i] ){
                x = i-1;
                break;
            }
        }
        if( x == - 1 ){
            return p;
        }
        int next = -1;
        for(int i = p.length-1; i > x; i--){
            if( p[i] > p[x] ){
                next = i;
                break;
            }
        }
        swap(p, x, next);
        List<Integer> min = new ArrayList<Integer>();
        for(int i = x+1; i < p.length; i++){
            min.add(p[i]);
        }
        Collections.sort(min);
        for(int i = x+1; i < p.length; i++){
            p[i] = min.get(i-x-1);
        }
        return p;
    }
    public static char[] next_permutation(char[] p){
        int x = -1;
        for(int i = p.length-1; i > 0; i--){
            if( p[i-1] < p[i] ){
                x = i-1;
                break;
            }
        }
        if( x == - 1 ){
            return p;
        }
        int next = -1;
        for(int i = p.length-1; i > x; i--){
            if( p[i] > p[x] ){
                next = i;
                break;
            }
        }
        swap(p, x, next);
        List<Character> min = new ArrayList<Character>();
        for(int i = x+1; i < p.length; i++){
            min.add(p[i]);
        }
        Collections.sort(min);
        for(int i = x+1; i < p.length; i++){
            p[i] = min.get(i-x-1);
        }
        return p;
    }
    public static String next_permutation(String p){
        char[] temp = p.toCharArray();
        char[] result = next_permutation(temp);
        return new String(result);
    }
    public static void main(String[] args){
        try {
            new B().solve();
        } catch (IOException e){
            e.printStackTrace();
            System.exit(1);
        }
    }

    public int factorial(int n){
        return n == 0 ? 1 : n * factorial(n-1);
    }

    public boolean isValid(String[] str){
        /*for(String s : str){
            System.out.print(s + " ");
        }
        System.out.println();*/

        for(char ch = 'a'; ch <= 'z'; ch++){
            boolean in = false;
            boolean passed = false;
            for(int i = 0; i < str.length; i++){
                for(char x : str[i].toCharArray()){
          //          System.out.println(ch + ", " + x);
                    if(x == ch){
                        in = true;
                        if(passed){
                            return false;
                        }
                    } else if(in){
                        in = false;
                        passed = true;
                    }
                }
            }
        }
        return true;
    }
    public void solve() throws IOException {
        try(BufferedReader br = new BufferedReader(new FileReader("B.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("B-output.txt"))
        ){
            int T = Integer.parseInt(br.readLine());
            for(int i = 1; i <= T; i++){
                int n = Integer.parseInt(br.readLine());
                String[] strs = br.readLine().split(" ");
                int[] px = new int[n];
                for(int j = 0; j < n; j++){
                    px[j] = j;
                }
                int rep = factorial(n);
                int count = 0;
                while(rep-- > 0) {
                    String[] temp = new String[n];
                    for(int j = 0; j < n; j++){
                        temp[j] = strs[px[j]];
                    }
                    if(isValid(temp)){
                        count++;
                    }
                    px = next_permutation(px);
                }
                bw.write("Case #" + i + ": " + count + "\n");
            }
        }
    }

    public int[] nextInts(BufferedReader br) throws IOException {
        String[] strs = br.readLine().split(" ");
        int[] ret = new int[strs.length];
        for(int i = 0; i < ret.length; i++){
            ret[i] = Integer.parseInt(strs[i]);
        }
        return ret;
    }
}

