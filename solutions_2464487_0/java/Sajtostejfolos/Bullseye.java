import java.io.*;

public class Bullseye {

    private static void debug(String msg) {
        System.err.println(msg);
    }
    
    public static void main(String[] args) throws Exception {
        String inputfile = args[0];
        String outputfile = args[1];
        
        BufferedReader in = new BufferedReader(new FileReader(inputfile));
        PrintWriter out = new PrintWriter(new FileWriter(outputfile));
        
        int cases = Integer.parseInt(in.readLine());
        debug("Number of test cases: " + cases);
        
        for (int i = 1; i <= cases; ++i) {
            debug("Processing Case #" + i);
            
            String[] numbers = in.readLine().split(" ");
            assert(numbers.length == 2) : "incorrect number of numbers " + numbers.length;
            long radius = Long.parseLong(numbers[0]);
            long paint = Long.parseLong(numbers[1]);

            long n = 1;
            while (true) {
                paint -= 2 * radius + 4 * n - 3;
                if (paint < 0)
                    break;
                ++n;
            }
            --n;
            out.println("Case #" + i + ": " + n);
        }
        
        out.close();
        in.close();
    }
}
