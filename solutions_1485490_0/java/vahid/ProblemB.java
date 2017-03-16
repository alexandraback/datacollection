import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Vahid
 * Date: 5/4/12
 * Time: 10:33 AM
 * To change this template use File | Settings | File Templates.
 */
public class ProblemB {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new BufferedReader(new FileReader("input.txt")));
        BufferedWriter output = new BufferedWriter(new FileWriter("ProblemB.txt"));

        int lines = input.nextInt();
        input.nextLine();
//        output.write("Case #"+(j+1)+": "+map.get(new Integer(c-item))+ " " + k);
//        output.newLine();

        for (int j=0; j<lines; j++){
            int n = input.nextInt();
            int m = input.nextInt();

            BigInteger[] a = new BigInteger[n];
            int[] aType = new  int[n];

            BigInteger[] b = new BigInteger[m];
            int[] bType = new  int[m];

            for (int i=0; i<n; i++){
                a[i] = input.nextBigInteger();
                aType[i] = input.nextInt();
            }
            for (int i=0; i<m; i++){
                b[i] = input.nextBigInteger();
                bType[i] = input.nextInt();
            }

            BigInteger res =lcs(0, a, aType, 0, b, bType);
            System.out.println(res);
            output.write("Case #"+(j+1)+": "+ res);
            output.newLine();


        }

        output.close();
        input.close();
    }

    private static BigInteger lcs(int i, BigInteger[] a, int[] aType, int j, BigInteger[] b, int[] bType) {
        //System.out.println(i +" "+j);
        if ((i>=a.length) || (j>= b.length)) return new BigInteger("0");
        if (aType[i]!=bType[j]) return lcs(i,a,aType,j+1,b,bType).max(lcs(i+1,a,aType,j,b,bType));

        BigInteger val = null;

        int compare = a[i].compareTo(b[j]);
        BigInteger temp =null;

        int change =0;

        if (compare>0){
            change =1;
            temp = a[i];
            a[i] = a[i].subtract(b[j]);
            val = (b[j]);
            j++;

        }
        if (compare<0){
            change = 2;
            temp = b[j];
            b[j] = b[j].subtract(a[i]);
            val = (a[i]);
            i++;
        }
        if (compare==0){
            val = a[i];
            i++;
            j++;

        }
        BigInteger result = val.add(lcs(i,a,aType,j,b,bType));
        if (change==1){
            a[i] =temp;
        }
        if (change==2){
            b[j] =temp;
        }

        return result;

    }


}
