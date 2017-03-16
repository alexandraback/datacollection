
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author ZuoZhong
 */
public class Dancer {

    public static void main(String[] args) throws IOException {
        File file = new File("B-large.in");
        BufferedReader in = new BufferedReader(new FileReader(file));
        String line = in.readLine();
        BufferedWriter out = new BufferedWriter(new FileWriter("Dancer_big_output.txt"));

        int T = Integer.parseInt(line);
        for (int x = 1; x <= T; x++) {
            line = in.readLine();
            String[] input = line.split(" ");
            int N = Integer.parseInt(input[0]); // number of googlers
            int S = Integer.parseInt(input[1]); // number of surprising score
            int p = Integer.parseInt(input[2]); // at least 1 score > p 
            int ans = 0;
            int lowerBound = 0;
            if (p == 0) {
                lowerBound = 0;
            } else if (p == 1) {
                lowerBound = 1;
            } else {
                lowerBound = 3 * p - 4;
            }

            for (int y = 3; y < N + 3; y++) {
                int score = Integer.parseInt(input[y]);
                if (score >= lowerBound) {
                    //fliter out lower bound surprising
                    if(score == (3*p-3) || score == (3*p-4)){
                        //within the suprising bound
                        if(S > 0){
                            S--;
                            ans++;
                        }
                    }else{
                        ans++;
                    }
                }
            }
            out.write("Case #" + x + ": " + ans);
            out.newLine();
            System.out.println("Case #" + x + ": " + ans);
        }
        in.close();
        out.close();
    }
}
