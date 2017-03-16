import java.io.*;
import java.util.*;


public class Match{
    public static void main(String[] args) throws Exception{
        MyScanner sc = new MyScanner();
        File outFile = new File("./out.txt").getAbsoluteFile();
        outFile.createNewFile();
        FileWriter fw = new FileWriter(outFile.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int t = sc.nextInt();
        for(int cases = 0; cases < t; cases++){
            String[] lines = sc.nextLine().split(" ");
            int[] num1 = new int[lines[0].length()];
            int[] num2 = new int[num1.length];
            boolean[] fixed1 = new boolean[num1.length];
            boolean[] fixed2 = new boolean[num1.length];
            for(int i = 0; i < num1.length; i++){
                num1[i] = (lines[0].charAt(i) == '?') ? -1 : Character.getNumericValue(lines[0].charAt(i));
                fixed1[i] = (num1[i] == -1) ? false : true;
                num2[i] = (lines[1].charAt(i) == '?') ? -1 : Character.getNumericValue(lines[1].charAt(i));
                fixed2[i] = (num2[i] == -1) ? false : true;
            }
            match(num1, num2, fixed1, fixed2);
            
            /*boolean n1High = false;
            boolean n2High = false;
            for(int i = 0; i < num1.length; i++){
                if(num1[i] == -1 && num2[i] == -1){
                    if(n1High){
                        num1[i] = 0;
                        num2[i] = 9;
                    } else if (n2High){
                        num1[i] = 9;
                        num2[i] = 0;
                    } else {
                        num1[i] = 0;
                        num2[i] = 0;
                    }
                } else if(num1[i] == -1) {
                    if(n1High){
                        num1[i] = 0;
                    } else if (n2High){
                        num1[i] = 9;
                    } else {
                        num1[i] = num2[i];
                    }
                } else if (num2[i] == -1) {
                    if(n1High){
                        num2[i] = 9;
                    } else if (n2High){
                        num2[i] = 0;
                    } else {
                        num2[i] = num1[i];
                    }
                } else if(!n1High && !n2High){
                    boolean reverse = false;
                    if(Math.abs(num1[i] - num2[i]) > 5){
                        if(num1[i] > num2[i]){
                            if(canAdd(num2, fixed2, i - 1)){
                                reverse = true;
                                add(num2, i - 1);
                            }
                        }
                        if(num2[i] > num1[i]){
                            if(canAdd(num1, fixed1, i - 1)){
                                reverse = true;
                                add(num1, i - 1);
                            }
                        }
                    }
                    
                    if(num1[i] > num2[i]){
                        n1High = true;
                    } else if (num2[i] > num1[i]) {
                        n2High = true;
                    }
                    if(reverse){
                        n1High = !n1High;
                        n2High = !n2High;
                    }
                }
            }*/
            
            String str1 = "";
            String str2 = "";
            for(int i = 0; i < num1.length; i++){
                str1 += num1[i];
                str2 += num2[i];
            }
            //out.println("Case #" + (cases+1) + ": " + str1 + " " + str2);
            bw.write("Case #" + (cases+1) + ": " + str1 + " " + str2 + "\n");
        }
        
        bw.close();
        out.close();
    }
    
    public static void match(int[] num1, int[] num2, boolean[] fixed1, boolean[] fixed2){
        boolean n1High = false;
        boolean n2High = false;
        boolean isDone = false;
        for(int i = 0; i < num1.length && !isDone; i++){
            if(num1[i] == -1 && num2[i] == -1){
                if(n1High){
                    num1[i] = 0;
                    num2[i] = 9;
                } else if (n2High){
                    num1[i] = 9;
                    num2[i] = 0;
                } else {
                    num1[i] = 0;
                    num2[i] = 0;
                }
            } else if(num1[i] == -1) {
                if(n1High){
                    num1[i] = 0;
                } else if (n2High){
                    num1[i] = 9;
                } else {
                    num1[i] = num2[i];
                }
            } else if (num2[i] == -1) {
                if(n1High){
                    num2[i] = 9;
                } else if (n2High){
                    num2[i] = 0;
                } else {
                    num2[i] = num1[i];
                }
            } else if(!n1High && !n2High){
                //boolean reverse = false;
                if(Math.abs(num1[i] - num2[i]) > 4){
                    int j = i - 1;
                    if(num1[i] > num2[i]){
                        while(j >= 0 && fixed2[j]){
                            j--;
                        }
                        if((Math.abs(num1[i] - num2[i]) > 5  || greater(num1, num2, i + 1)) && canAdd(num2, fixed2, j)){
                            add(num2, j);
                            fixed2[j] = true;
                            reset(num1,num2,fixed1, fixed2);
                            match(num1,num2,fixed1, fixed2);
                            isDone = true;
                        } else if (canSub(num1, fixed1, i - 1)){
                            sub(num1, i - 1);
                            fixed1[i - 1] = true;
                            reset(num1,num2,fixed1, fixed2);
                            match(num1,num2,fixed1, fixed2);
                            isDone = true;
                        }
                    }
                    if(num2[i] > num1[i]){
                        while(j >= 0 && fixed1[j]){
                            j--;
                        }
                        if((Math.abs(num1[i] - num2[i]) > 5 || greater(num2, num1, i + 1)) && canAdd(num1, fixed1, j)){
                            add(num1, j);
                            fixed1[j] = true;
                            reset(num1,num2,fixed1, fixed2);
                            match(num1,num2,fixed1, fixed2);
                            isDone = true;
                        } else if (canSub(num2, fixed2, i - 1)){
                            sub(num2, i - 1);
                            fixed2[i - 1] = true;
                            reset(num1,num2,fixed1, fixed2);
                            match(num1,num2,fixed1, fixed2);
                            isDone = true;
                        }
                    }
                }
                if(num1[i] > num2[i]){
                    n1High = true;
                } else if (num2[i] > num1[i]) {
                    n2High = true;
                }
            }
        }
    }
    
    public static boolean greater(int[] num1, int[] num2, int i){
        while(i < num1.length){
            if(num1[i] != -1 && num1[i] != 9){
                if(num2[i] == -1 || num2[i] > num1[i]){
                    return false;
                } else if(num2[i] == num1[i]){
                    return greater(num1, num2, i + 1);
                }
            }
            if(num2[i] != -1 && num2[i] != 9){
                return true;
            }
            i++;
        }
        return false;
    }
    public static void reset(int[] num1, int[] num2, boolean[] fixed1, boolean[] fixed2){
        for(int i = 0; i < num1.length; i++){
            if(!fixed1[i]){
                num1[i] = -1;
            }
            if(!fixed2[i]){
                num2[i] = -1;
            }
        }
    }
    public static boolean canAdd(int[] param, boolean[] fixed, int i){
        if(i < 0 || fixed[i]){
            return false;
        }
        if(param[i] < 9){
            return true;
        }
        return canAdd(param, fixed, i - 1);
    }
    
    public static void add(int[] param, int i){
        if(param[i] == 9){
            param[i] = 0;
            add(param, i - 1);
        } else {
            param[i]++;
        }
    }
    
    public static boolean canSub(int[] param, boolean[] fixed, int i){
        if(i < 0 || fixed[i]){
            return false;
        }
        if(param[i] > 0){
            return true;
        }
        return canSub(param, fixed, i - 1);
    }
    
    public static void sub(int[] param, int i){
        if(param[i] == 0){
            param[i] = 9;
            sub(param, i - 1);
        } else {
            param[i]--;
        }
    }
    
    public static PrintWriter out;
    /*
    int n      = sc.nextInt();        // read input as integer
    long k     = sc.nextLong();       // read input as long
    double d   = sc.nextDouble();     // read input as double
    String str = sc.next();           // read input as String
    String s   = sc.nextLine();       // read whole line as String
    out.println(result);              // print via PrintWriter
       */
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
