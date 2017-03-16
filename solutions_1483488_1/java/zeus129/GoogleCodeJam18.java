import java.io.*;


public class GoogleCodeJam18 {   
    
    public static void main(String[] args) throws IOException {

        FileInputStream getFile = new FileInputStream("C:\\1\\in1.txt");

        PrintWriter out = new PrintWriter(new File("C:\\1\\output.out"));
        BufferedReader br = new BufferedReader(new InputStreamReader(getFile));

        String strLine;
        strLine = br.readLine().trim();
        int test = Integer.parseInt(strLine);

        for (int i=0;i<test;i++) {
            strLine = br.readLine().trim();
            long incrementor = 0;
            String[] strings = strLine.split(" ");
            long A = Integer.parseInt(strings[0].trim());
            long B = Integer.parseInt(strings[1].trim());
            for (long num = A; num <= B; num++) {
                incrementor = incrementor + CodeJadu(num, A, B);
            }
            int k = i+1;
            out.println("Case #" + k + ": " + incrementor);
        }
        out.flush();
        out.close();
        br.close();
    }
    public static long CodeJadu(long present, long A, long B)
    {
        long initial = present;
        long sum = 0;
        int numdigits = (int) Math.log10((double)present);
        int multiplier = (int) Math.pow(10.0, (double)numdigits);
        while(true)
        {
            long q = present / 10;
            long r = present % 10;
            present = present / 10;
            present = present + multiplier * r;
            if(present == initial)
                break;
            if (initial < A) break;
            if (initial >= A && initial < present && present <= B) {
                sum++;
            }
        }
        return sum;


    }
}