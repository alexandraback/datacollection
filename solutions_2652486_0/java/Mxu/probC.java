import java.util.*;
import java.io.*;

public class probC {

    public static int[] nums = new int[]{2,3,4,5};
    public static int[][] dyn = new int[126][21];
    public static void main(String ... args) throws IOException {
        Scanner input = new Scanner(System.in);
        PrintWriter out = new PrintWriter("probC.out");
        for(int a=0;a<choices.length;a++) {
            double prob = 1/8.0;
            for(int b=0;b<samples.length;b++) {
                int prod = 1;
                for(int u=0;u<samples[0].length;u++) {
                    if(samples[b][u]==1) {
                        prod *= nums[choices[a][u]];
                    }
                }
                dyn[prod][a]+=1;
            }
        }
        /*
        for(int i=0;i<10;i++) {
            String cool = "";
            for(int u=0;u<65;u++) {
                cool+=Arrays.toString(choices[i])+" prob: "+dyn[u][i]+" ";
            }
            System.out.println(cool);
        }
        */
        int t = input.nextInt();
        int r = input.nextInt();
        int n = input.nextInt();
        int m = input.nextInt();
        int k = input.nextInt();
        System.out.println("Case #1: ");
        out.println("Case #1: ");
        for(int i=1;i<=r;i++) {
            double[] sums = new double[21];
            for(int z=0;z<k;z++) {
                int p = input.nextInt();
                int total = 0;
                for(int q=0;q<21;q++) {
                    total += dyn[p][q];
                }
                for(int q=0;q<21;q++) {
                    sums[q]+=dyn[p][q]/(double)total;
                }
            }
            double max = 0;
            int maxid=0;
            for(int u=0;u<21;u++) {
                if(sums[u]>max) {
                    max=sums[u];
                    maxid=u;
                }
            }
            String str="";
            for(int kz=0;kz<choices[maxid].length;kz++)
                str+=nums[choices[maxid][kz]];
            out.println(str);
            System.out.println(str);

        }
        out.close();

    }
    public static int[][] choices = new int[][] {
        {0, 0, 0},
            {0, 0, 1},
            {0, 0, 2},
            {0, 0, 3},
            {0, 1, 1},
            {0, 1, 2},
            {0, 1, 3},
            {0, 2, 2},
            {0, 2, 3},
            {0, 3, 3},
            {1, 1, 1},
            {1, 1, 2},
            {1, 1, 3},
            {1, 2, 2},
            {1, 2, 3},
            {1, 3, 3},
            {2, 2, 2},
            {2, 2, 3},
            {2, 3, 3},
            {3, 3, 3}};
    /*
    public static int[][] choices = new int[][]{
        {0, 0, 0},
            {0, 0, 1},
            {0, 0, 2},
            {0, 1, 1},
            {0, 1, 2},
            {0, 2, 2},
            {1, 1, 1},
            {1, 1, 2},
            {1, 2, 2},
            {2, 2, 2}
    };
    */
    public static int[][] samples = new int[][] {
        {0, 0, 0},
            {1, 0, 0},
            {1, 1, 0},
            {1, 1, 1},
            {1, 0, 1},
            {0, 1, 0},
            {0, 1, 1},
            {0, 0, 1}};
}

