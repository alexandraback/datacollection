import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: udit.aga
 * Date: 5/11/14
 * Time: 4:07 PM
 * To change this template use File | Settings | File Templates.
 */
public class Enclosure {
    private static BufferedReader bufferedReader;
    private static BufferedWriter bufferedWriter;
    private static int N;
    private static int M;
    private static int K;

    public static void main(String[] args) throws IOException {
        bufferedReader = new BufferedReader(new FileReader("C:\\Users\\udit.aga\\Downloads\\C-small-attempt0.in"));
        bufferedWriter = new BufferedWriter(new FileWriter("C:\\Users\\udit.aga\\Downloads\\out.txt"));

        int T = readInt();
        int k=0;
        while (T > 0){
            T--;
            k++;
            int[] inputArray = readIntArray();
            N = inputArray[0];
            M = inputArray[1];
            K = inputArray[2];

            int minStones = findMinStonesRequired();
            bufferedWriter.write("Case #"+k+": "+minStones+"\n");
            bufferedWriter.flush();
        }

        bufferedWriter.close();
        bufferedReader.close();
        return;
    }

    private static int findMinStonesRequired() {
        if(K <= 4 || N <=2 || M <=2 )
            return K;
        if(N == 3 || M == 3)
            return findMinStonesRequired3();
        return findMinStonesRequired4();
    }

    private static int findMinStonesRequired4() {
        if(K <= 4)
            return K;
        if(N == 4 && M == 4){
            if(K <= 7)
                return K-1;
            if(K <= 9)
                return K-2;
            if(K <= 11)
                return K-3;
            return K-4;
        }

        if(K <= 7)
            return K-1;
        if(K <= 9)
            return K-2;
        if(K <= 11)
            return K-3;
        if(K <= 13)
            return K-4;
        if(K <= 15)
            return K-5;
        return K-6;
    }

    private static int findMinStonesRequired3() {
        if(K <= 4)
            return K;
        if(N == 3 && M == 3)
            return  (K-1);
        if((N == 3 && M == 4) || (M == 3 && N == 4)){
            if(K <= 7)
                return K-1;
            else
                return K-2;
        }
        if((N == 3 && M == 5) || (M == 3 && N == 5)){
            if(K <= 7)
                return K-1;
            if(K <= 10)
                return K-2;
            return K-3;
        }
        if(K <= 7)
            return K-1;
        if(K <= 10)
            return K-2;
        if(K <= 13)
            return K-3;
        return K-4;
    }

    private static int readInt() throws IOException {
        String input;
        input = bufferedReader.readLine();
        int val;
        val = Integer.parseInt(input);
        return val;
    }


    private static int[] readIntArray() throws IOException {
        String input;
        input = bufferedReader.readLine();
        String[] temp = input.split(" ");
        int[] val = new int[temp.length];
        for(int i=0;i<temp.length;i++)
            val[i] = Integer.parseInt(temp[i]);
        return val;
    }
}
