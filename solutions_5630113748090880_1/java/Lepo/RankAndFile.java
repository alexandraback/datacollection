import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * Created by juanc on 15-Apr-16.
 */
public class RankAndFile {
    private static Scanner sn;
    private static PrintWriter writer;
    private final static boolean INLINE = true;
    private final static String INPUT = "B-large.in";
    private final static String OUTPUT = "answer";


    public static void main(String[] args) throws IOException {
        sn = Input.getScanner("resources/" + INPUT);
        writer = new PrintWriter("resources/" + OUTPUT);
        int T = Integer.parseInt(sn.nextLine());
        for (int i = 1; i <= T; i++) {
            if (INLINE)
                writer.print("Case #" + i + ": ");
            else
                writer.println("Case #" + i + ":");
            RankAndFileMain();
        }
        writer.close();

    }

    private static void RankAndFileMain() {
        int N = sn.nextInt();
        int[] heights = new int[4098];
        PriorityQueue<Integer> answer = new PriorityQueue<Integer>((a, b) -> a - b);

        int min = 0;
        for (int i = 0; i < 2 * N - 1; i++) {
            for (int j = 0; j < N; j++) {
                heights[sn.nextInt()]++;
            }
        }
        for (int i = 0; i < 4098; i++) {
            if ((heights[i] % 2) == 1) {
                answer.add(i);
            }
        }
        for (int i = 0; i<N; i++) {
            writer.print(answer.poll());
            if(i!=N-1)
                writer.print(" ");
        }
        writer.println();

        /*
        sn.nextLine();
        boolean flag = false;
        for(int i = 0; i<2*N-1; i++){
            if(vec[i][0]==min){
                if(matrix[0][0]==0){
                    for(int j = 0; j < N; j++){
                        matrix[0][j] = vec[i][j];
                    }
                }else{
                    for(int j = 0; j < N; j++){
                        matrix[j][0] = vec[i][j];
                    }
                    flag = true;
                }
            }
        }
        if(flag == false){

        }
        */


    }
}
