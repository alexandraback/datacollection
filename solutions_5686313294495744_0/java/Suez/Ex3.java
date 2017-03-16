import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Ex3 {
    private final static String input = "C-small-attempt0.in";
    private final static String output = "out.txt";
    private PrintWriter out;

    public int execute(String[][] data) {
        int n = data.length;

        HashSet<String> first = new HashSet<>();
        HashSet<String> second = new HashSet<>();
        for (int i=0; i<n; i++) {
            first.add(data[i][0]);
            second.add(data[i][1]);
        }

        return n-Math.max(first.size(), second.size());
    }


    public void runTests(Scanner input) throws FileNotFoundException {
        out = new PrintWriter(output);
        int testsNo = Integer.valueOf(input.nextLine());
        
        for (int i=1; i<=testsNo; i++) {
            int n  = Integer.valueOf(input.nextLine());


            String[][] data = new String[n][2];
            for (int j=0; j<n; j++) {
                String[] someData = input.nextLine().split(" ");
                data[j][0] = someData[0];
                data[j][1] = someData[1];
            }

            int res = execute(data);
            out.print("Case #"+i+": ");
            out.print(res);
            out.println();
        }
        out.close();
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new FileInputStream(input));
        new Ex3().runTests(file);
        file.close();
    }
}
