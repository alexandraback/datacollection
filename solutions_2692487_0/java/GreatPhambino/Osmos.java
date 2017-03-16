import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
    public static int[] data;
    
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt0.in")));
        Scanner scanner = new Scanner(reader);
        boolean console = false;
        BufferedWriter out = new BufferedWriter(new FileWriter("Osmos.txt"));

        int loop = scanner.nextInt();
        for (int i = 1; i <= loop; i++) {
            int sum = scanner.nextInt();
            data = new int[scanner.nextInt()];
            for(int j = 0; j < data.length; j++) {
                data[j] = scanner.nextInt();
            }
            Arrays.sort(data);
            /*System.out.println(Arrays.toString(data));
            System.out.println(sum);*/
            int min = calculate(0, 0, sum);

            if (!console)
                out.write("Case #" + i + ": " + min + "\n");
            else
                System.out.print("Case #" + i + ": " + min + "\n");
        }
        scanner.close();
        out.close();
    }
    
    public static int calculate(int count, int j, int sum) {
        //System.out.println(count + " " + j + " " + sum);
        for(; j < data.length; j++) {
            if(data[j] < sum) {
                sum+=data[j];
            } else if(sum+sum-1 > data[j]) {
                count++;
                sum+= (sum-1) + data[j];
            } else {
                return Math.min(count + (data.length-j),
                        ((sum-1) == 0) ? Integer.MAX_VALUE : calculate(count+1, j, sum+sum-1));
            }
        }
        return count;
    }
}