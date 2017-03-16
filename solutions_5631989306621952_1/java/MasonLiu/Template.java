import java.io.*;
import java.util.*;


public class Template{
    public static void main(String[] args) throws Exception{
        MyScanner sc = new MyScanner();
        
        File outFile = new File("./out.txt").getAbsoluteFile();
        outFile.createNewFile();
        
        FileWriter fw = new FileWriter(outFile.getAbsoluteFile());
        BufferedWriter bw = new BufferedWriter(fw);
        
        out = new PrintWriter(new BufferedOutputStream(System.out));
        int t = sc.nextInt();
        for(int i = 0; i < t; i++){
            //out.print("Case #" + (i+1) + ":");
            String line = sc.nextLine();
            StringBuffer properLine = new StringBuffer();
            for(int j = 0; j < line.length(); j++){
                if(properLine.length() == 0 || ((Character)properLine.charAt(0)).compareTo(line.charAt(j)) > 0){
                    properLine.append(line.charAt(j));
                } else {
                    properLine.insert(0, line.charAt(j));
                }
            }
            bw.write("Case #" + (i+1) + ": " + properLine.toString() + "\n");
            //out.println(properLine.toString());
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
