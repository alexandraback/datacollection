import java.io.*;
import java.util.*;


public class Digits{
    public static void main(String[] args) throws Exception{
        MyScanner sc = new MyScanner();
        File outFile = new File("./out.txt").getAbsoluteFile();
        outFile.createNewFile();
        FileWriter fw = new FileWriter(outFile.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int t = sc.nextInt();
        for(int cases = 0; cases < t; cases++){
            String line = sc.nextLine();
            HashMap<Character, Integer> chars = new HashMap<>();
            int[] nums = new int[10];
            for(int i = 0; i < line.length(); i++){
                if(chars.containsKey(line.charAt(i))){
                    chars.put(line.charAt(i), chars.get(line.charAt(i)) + 1);
                } else {
                    chars.put(line.charAt(i), 1);
                }
            }
            while(chars.containsKey('Z') && chars.get('Z') > 0){
                chars.put('Z', chars.get('Z') - 1);
                chars.put('E', chars.get('E') - 1);
                chars.put('R', chars.get('R') - 1);
                chars.put('O', chars.get('O') - 1);
                nums[0]++;
            }
            while(chars.containsKey('W') && chars.get('W') > 0){
                chars.put('T', chars.get('T') - 1);
                chars.put('W', chars.get('W') - 1);
                chars.put('O', chars.get('O') - 1);
                nums[2]++;
            }
            while(chars.containsKey('X') && chars.get('X') > 0){
                chars.put('S', chars.get('S') - 1);
                chars.put('I', chars.get('I') - 1);
                chars.put('X', chars.get('X') - 1);
                nums[6]++;
            }
            while(chars.containsKey('S') && chars.get('S') > 0){
                chars.put('S', chars.get('S') - 1);
                chars.put('E', chars.get('E') - 1);
                chars.put('V', chars.get('V') - 1);
                chars.put('E', chars.get('E') - 1);
                chars.put('N', chars.get('N') - 1);
                nums[7]++;
            }
            while(chars.containsKey('V') && chars.get('V') > 0){
                chars.put('F', chars.get('F') - 1);
                chars.put('I', chars.get('I') - 1);
                chars.put('V', chars.get('V') - 1);
                chars.put('E', chars.get('E') - 1);
                nums[5]++;
            }
            while(chars.containsKey('F') && chars.get('F') > 0){
                chars.put('F', chars.get('F') - 1);
                chars.put('O', chars.get('O') - 1);
                chars.put('U', chars.get('U') - 1);
                chars.put('R', chars.get('R') - 1);
                nums[4]++;
            }
            while(chars.containsKey('G') && chars.get('G') > 0){
                chars.put('E', chars.get('E') - 1);
                chars.put('I', chars.get('I') - 1);
                chars.put('G', chars.get('G') - 1);
                chars.put('H', chars.get('H') - 1);
                chars.put('T', chars.get('T') - 1);
                nums[8]++;
            }
            while(chars.containsKey('O') && chars.get('O') > 0){
                chars.put('O', chars.get('O') - 1);
                chars.put('N', chars.get('N') - 1);
                chars.put('E', chars.get('E') - 1);
                nums[1]++;
            }
            while(chars.containsKey('T') && chars.get('T') > 0){
                chars.put('T', chars.get('T') - 1);
                chars.put('H', chars.get('H') - 1);
                chars.put('R', chars.get('R') - 1);
                chars.put('E', chars.get('E') - 1);
                chars.put('E', chars.get('E') - 1);
                nums[3]++;
            }
            while(chars.containsKey('N') && chars.get('N') > 0){
                chars.put('N', chars.get('N') - 1);
                chars.put('I', chars.get('I') - 1);
                chars.put('N', chars.get('N') - 1);
                chars.put('E', chars.get('E') - 1);
                nums[9]++;
            }
            String ans = "";
            for(int i = 0; i < nums.length; i++){
                for(int j = 0; j < nums[i]; j++){
                    ans += i;
                }
            }
            //out.println("Case #" + (cases + 1)+ ": " + ans);
            bw.write("Case #" + (cases + 1) + ": " + ans + "\n");
        }
        
        bw.close();
        out.close();
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
