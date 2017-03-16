import java.io.*;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Vahid
 * Date: 5/4/12
 * Time: 10:32 AM
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
            int nodes = input.nextInt();
            int[][] path = new int[nodes][nodes];

            for (int i=0; i<nodes; i++){
                for (int k=0; k<nodes; k++){
                    path[i][k] = 0;
                }
            }

            for (int i=0; i<nodes; i++){
                int m = input.nextInt();
                for (int k=0; k<m; k++){
                    int p = input.nextInt();
                    path[i][p-1] = 1;
                }
            }

            int[][] diamond = new int[nodes][nodes];

            for (int i=0; i<nodes; i++){
                for (int k=0; k<nodes; k++){
                    diamond[i][k] = path[i][k];
                }
            }

            int[][] mult = path.clone();

            boolean  found = false;

            all:for (int i=0; i< nodes-2; i++){
                int[][] result = new int[nodes][nodes];
                for (int x=0; x<nodes; x++){
                    for (int y=0; y<nodes; y++){
                        int sum =0;
                        for (int z=0; z<nodes; z++){
                            sum += mult[x][z] * path [z][y];
                        }
                        result[x][y] =sum;
                        diamond[x][y] += sum;
                        if (diamond[x][y]>1)  found = true;
                        break  all;
                    }
                }
                mult = result;

            }


            for (int x=0; x<nodes; x++)
                for (int y=0; y<nodes; y++)
                    if (diamond[x][y]>1) found = true;

            String result = "No";
            if (found) result = "Yes";

        output.write("Case #"+(j+1)+": "+result);
        output.newLine();


        }

        output.close();
        input.close();
    }
}
