import java.io.IOException;

/**
 * Copyright - Arghya Sur
 * Created by sur on 4/9/16.
 */
public class QRB {
    private static void flipOrder(char[] order, int l) {
        for(int i = 0; i <= l/2;  i++) {
            if(l % 2 == 0 && i == l/2) {
                break;
            }
            char temp = order[i];
            int k = l - i - 1;
            order[i] = order[k];
            order[k] = temp;
            order[i] = (order[i] == '+')? '-': '+';
            if(i != k) {
                order[k] = (order[k] == '+') ? '-' : '+';
            }
        }

        //System.out.println(order);
    }

    public static void main(String[] args) throws IOException {

        java.io.BufferedReader r = new java.io.BufferedReader
                (new java.io.InputStreamReader (System.in));

        String line;
        int c = 0;
        int t = Integer.parseInt(r.readLine());

        while(t > 0) {
            line = r.readLine();
            char order[] = line.toCharArray();
            //System.out.println(order);

            int n = 0;
            int j = order.length;

            while(j > 0) {
                int i = j - 1;
                while (i >= 0 && order[i] == '+') {
                    i--;
                }
                j = i + 1;
                if(j == 0) {
                    break;
                }

                if(order[0] == '-') {
                    //System.out.println("j  = "  +j);
                    flipOrder(order, j);
                    n++;
                } else {
                    int k = j - 2;
                    while(k >= 0 && order[k] != '+') {
                        k--;
                    }
                    flipOrder(order, k + 1);
                    flipOrder(order, j);
                    n = n + 2;
                }
                j--;
            }

            System.out.println("Case #" + (c + 1) + ": " + n);
            t--;
            c++;
        }
    }
}
