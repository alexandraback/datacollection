import java.io.*;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Vahid
 * Date: 4/27/12
 * Time: 9:36 AM
 * To change this template use File | Settings | File Templates.
 */
public class ProblemA {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new BufferedReader(new FileReader("input.txt")));
        BufferedWriter output = new BufferedWriter(new FileWriter("ProblemA.txt"));

        int lines = input.nextInt();
        input.nextLine();
//        output.write("Case #"+(j+1)+": "+map.get(new Integer(c-item))+ " " + k);
//        output.newLine();

        for (int j=0; j<lines; j++){

            int written = input.nextInt();
            int total = input.nextInt();

            float[] prob = new float[written];
            float[] totalProb = new float[written+1];
            totalProb[0] = 1;
            for (int i = 0; i<written; i++){
                prob[i] = input.nextFloat();
                totalProb[i+1] = totalProb[i] * prob[i];
            }

            float minimum = 2 + ((float)total);

            for (int back =0; back<= written; back++){
                float value = totalProb[written-back] * (1 + back + total - (written-back))
                              + (((float)1)-totalProb[written-back]) * (1 + back + total - (written-back) + total + 1);

                if (value<minimum) minimum = value;
            }
        output.write("Case #"+(j+1)+": "+ minimum);
        output.newLine();


        }

        output.close();
        input.close();
    }
}
