import java.io.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("D:\\A-large.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("D:\\Alarge.txt")));
        int cases = Integer.parseInt(br.readLine());
        for(int t = 1; t <= cases; t++) {
            String s = br.readLine();
            String last = Character.toString(s.charAt(0));
            for(int i = 1; i < s.length(); i++) {
                char c = s.charAt(i);
                if(c >= last.charAt(0)) {
                    last = c + last;
                }
                else {
                    last += c;
                }
            }
            pw.println("Case #" + t + ": " + last);
        }
        pw.close();

    }
}
