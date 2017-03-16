import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Aaron on 5/8/2016.
 */
public class Problem2C {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("C:\\Users\\Aaron\\IdeaProjects\\CodeJam1C\\src\\inputBsmall1.txt"));
        String numcases = in.nextLine();
        Problem2C problem2 = new Problem2C();
        ArrayList<String> cases = new ArrayList<>();
        //String[] cases = new String[Integer.parseInt(numcases)];
        while (in.hasNextLine()) {
            cases.add(in.nextLine());
        }
        int casecounter = 1;
        PrintWriter out = new PrintWriter(new File("C:\\Users\\Aaron\\IdeaProjects\\CodeJam1C\\src\\output.txt"));
        for(String word : cases) {
            out.println("Case #"+casecounter+": "+problem2.getAnswer(word));
            ++casecounter;
        }
        out.flush();
        out.close();
    }
    public String getAnswer(String testcase) {
        String[] test = testcase.split("\\s+");
        int numbuildings = Integer.parseInt(test[0]);
        int numways = Integer.parseInt(test[1]);
        long facbuildings = Long.parseLong(test[0]);
        if (numways > factorial(facbuildings-1)) return "IMPOSSIBLE";
        String output = "POSSIBLE\n";
        int[][] matrix = new int[numbuildings][numbuildings];
        for(int[] y : matrix) {
            for(int x : y) {
                x = 0;
            }
        }
        int x = 1;
        int y = 0;
        matrix[0][numbuildings-1] = 1;
        --numways;
        while(numways > 0 && y != numbuildings - 1) {
            matrix[y][x] = 1;
            matrix[x][numbuildings-1] = 1;
            ++x;
            if(x == numbuildings) {
                ++y;
                x = y+1;
            }
            --numways;
        }
        for(int[] row : matrix) {
            for(int col : row) {
                output += col;
            }
            output += "\n";
        }
        return output.substring(0,output.length()-1);
    }
    public long factorial(long number) {
        if (number <= 1) return 1;
        else return number + factorial(number - 1);
    }
}
