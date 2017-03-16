import java.io.*;
import java.util.*;

public class InputHandler {
    public static void main(String[] args) {
        try {
            BufferedReader br =
                    new BufferedReader(new InputStreamReader(System.in));
            String line;

            int caseCount = 1;
            br.readLine();

            while ((line = br.readLine()) != null) {
                String[] tokens = line.split(" ");
                String answer = Mine.solution(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2]));

                System.out.print("Case #" + caseCount + ":\n" + answer);
                caseCount++;

            }

        } catch (IOException io) {
            io.printStackTrace();
        }

    }

}
