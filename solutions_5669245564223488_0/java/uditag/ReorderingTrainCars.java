import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Created with IntelliJ IDEA.
 * User: udit.aga
 * Date: 5/11/14
 * Time: 3:33 PM
 * To change this template use File | Settings | File Templates.
 */
public class ReorderingTrainCars {
    private static BufferedReader bufferedReader;
    private static BufferedWriter bufferedWriter;
    private static int N;
    private static String[] cars;

    public static void main(String[] args) throws IOException {
        bufferedReader = new BufferedReader(new FileReader("C:\\Users\\udit.aga\\Downloads\\B-small-attempt0.in"));
        bufferedWriter = new BufferedWriter(new FileWriter("C:\\Users\\udit.aga\\Downloads\\out.txt"));

        int T = readInt();
        int k=0;
        while (T > 0){
            T--;
            k++;
            N = readInt();
            cars = readStringArray();

            long ways = findNumberOfWays();
            bufferedWriter.write("Case #"+k+": "+ways+"\n");
            bufferedWriter.flush();
        }

        bufferedReader.close();
        bufferedWriter.close();
        return;
    }

    private static long findNumberOfWays() {
        long ways=0;
        int[] temp = new int[N];
        for(int i=0;i<N;i++)
            temp[i] = i;

        do{
            String t = "";
            for(int i=0;i<N;i++){
                t += cars[temp[i]];
            }
            if(valid(t))
                ways++;

        }while (next_permutation(temp));

        return ways;
    }

    private static boolean valid(String t) {
        Map<Character,Boolean> visited = new HashMap<Character,Boolean>();
        int length = t.length();

        for(int i=0;i<length;i++){
            if(visited.containsKey(t.charAt(i)))
                return false;
            else if(i>0 && t.charAt(i) != t.charAt(i-1))
                visited.put(t.charAt(i-1),true);
        }
        return true;
    }

    private static boolean next_permutation(int[] p) {
        for (int a = p.length - 2; a >= 0; --a)
            if (p[a] < p[a + 1])
                for (int b = p.length - 1;; --b)
                    if (p[b] > p[a]) {
                        int t = p[a];
                        p[a] = p[b];
                        p[b] = t;
                        for (++a, b = p.length - 1; a < b; ++a, --b) {
                            t = p[a];
                            p[a] = p[b];
                            p[b] = t;
                        }
                        return true;
                    }
        return false;
    }

    private static String[] readStringArray() throws IOException {
        String input = bufferedReader.readLine();
        String[] temp = input.split(" ");
        return temp;
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
