package OminousOmino;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by xuchen on 4/11/15.
 */
public class OminousOmino {

    public static void main(String[] args) {

        try {
            Scanner scanner = new Scanner(new File("src/OminousOmino/D-small-attempt0.in"));
            PrintWriter writer = new PrintWriter(new File("src/OminousOmino/result.txt"));

            int caseCnt = scanner.nextInt();

            for (int i = 0; i < caseCnt; i++){

                int X = scanner.nextInt();
                int R = scanner.nextInt();
                int C = scanner.nextInt();
                String winner = "";

                if (R*C % X != 0){
                    winner = "RICHARD";
                }else if (X == 1 || X == 2){
                    winner = "GABRIEL";
                }else if (X == 3){
                    if (R == 1 || C == 1){
                        winner = "RICHARD";
                    }else {
                        winner = "GABRIEL";
                    }
                }else if (X == 4){
                    if (R == 1 || C == 1 || R == 2 || C == 2){
                        winner = "RICHARD";
                    }else {
                        winner = "GABRIEL";
                    }
                }

                writer.println("Case #"+ (i+1) +": " + winner);
            }

            writer.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
