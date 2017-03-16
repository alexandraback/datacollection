import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: udit.aga
 * Date: 5/11/14
 * Time: 2:40 PM
 * To change this template use File | Settings | File Templates.
 */
public class PartElf {
    private static BufferedReader bufferedReader;
    private static BufferedWriter bufferedWriter;
    private static long P;
    private static long Q;
    public static void main(String[] args) throws IOException {
        bufferedReader = new BufferedReader(new FileReader("C:\\Users\\udit.aga\\Downloads\\A-large.in"));
        bufferedWriter = new BufferedWriter(new FileWriter("C:\\Users\\udit.aga\\Downloads\\out.txt"));

        int T = readInt();
        int k=0;
        while (T > 0){
            T--;
            k++;
            readPQ();
            removeCommonFactors();
            int minRequired = findMinNumberOfGenerationsReq();
            if(minRequired == -1 || minRequired > 40){
                bufferedWriter.write("Case #"+k+": impossible\n");
            }
            else
                bufferedWriter.write("Case #"+k+": "+minRequired+"\n");
            bufferedWriter.flush();
        }

        bufferedWriter.close();
        bufferedReader.close();
        return;
    }

    private static void removeCommonFactors() {
        long gcd = gcd(Q,P);
        Q /= gcd;
        P /= gcd;
    }

    private static long gcd(long q, long p) {
        while (p > 0){
            long r = q%p;
            q = p;
            p = r;
        }
        return q;
    }

    private static int findMinNumberOfGenerationsReq() {
        if(!powerOf2(Q)){
            return -1;
        }
        int minGenerations=0;
        while(P < Q && minGenerations < 50){
            P = 2*P;
            minGenerations++;
        }

        return minGenerations;
    }

    private static boolean powerOf2(long q) {
        while(q > 1){
            if(q%2 != 0)
                return false;
            q /= 2;
        }
        return true;
    }

    private static void readPQ() throws IOException {
        String input = bufferedReader.readLine();
        String[] temp = input.split("/");
        P = Long.parseLong(temp[0]);
        Q = Long.parseLong(temp[1]);
    }

    private static int readInt() throws IOException {
        String input;
        input = bufferedReader.readLine();
        int val;
        val = Integer.parseInt(input);
        return val;
    }

}
