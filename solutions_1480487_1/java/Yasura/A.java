import java.util.Scanner;

/**
 *
 * @author Yasura
 */
public class A {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int cases, n, num;
        double sum, mean=0, tmpsum;
        int[] scores, sort;
        double min;

        Scanner scan = new Scanner(System.in);
        cases = scan.nextInt();

        for (int i = 0; i < cases; i++) {
            tmpsum=sum=n = 0;
            num = scan.nextInt();
            scores = new int[num];
            sort = new int[num];
            for (int j = 0; j < num; j++) {
                sort[j] = scores[j] = scan.nextInt();
                sum+=sort[j];
            }

            for (int j = 1; j < num; j++) {
                int k = j;
                int B = sort[j];
                while ((k > 0) && (sort[k - 1] > B)) {
                    sort[k] = sort[k - 1];
                    k--;
                }
                sort[k] = B;
            }
            
            for (int j=0;j<num;j++){
                n++;
                tmpsum+=sort[j];
                if(((sum+tmpsum) / n)<sort[j]){
                    n--;
                    tmpsum-=sort[j];
                    break;
                }
                else
                    mean = (sum+tmpsum) / n;
                    
            }
            System.out.print("Case #" + (i + 1) + ": ");
            for (int j = 0; j < num; j++) {

                if (mean < scores[j]) {
                    min = 0;
                } else {
                    min = (mean - scores[j]) / sum * 100;
                }
                System.out.print(min);
                if (j != num - 1) {
                    System.out.print(" ");
                }
            }
            if (i != cases - 1) {
                System.out.println();
            }
        }

    }
}
