import java.io.FileReader;
import java.io.PrintWriter;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            //these variables handle input and output from plain text files
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int cases = in.nextInt();
            for (int caseIndex = 1; caseIndex <= cases; caseIndex++) {
                int c = in.nextInt();
                int d = in.nextInt();
                int v = in.nextInt();
                List<Integer> denom = new ArrayList<Integer>();
                for (int i = 0; i < d; i++) {
                    denom.add(in.nextInt());
                }
                Collections.sort(denom);

                int answer = 0;
                for (int price = 1; price <= v; price++) {
                    int value = price;
                    for (int j = denom.size() - 1; j >= 0; j--) {
                        if (value >= denom.get(j)){
                            value -= denom.get(j);
                        }
                    }
                    if(value!=0){
                        answer++;
                        denom.add(price);
                        Collections.sort(denom);
                    }
                }//end for price
//                for(int i:denom){
//                    System.out.printf("%d ",i);
//                }
                out.printf("Case #%d: %d\n",caseIndex,answer);

            }//end for caseIndex

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }
}
