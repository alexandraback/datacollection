/**
 * Created by lin on 4/23/14.
 */
public class BSolution {

    public static int simple(int A, int B, int K) {
        int ret = 0;
        for(int i = 0; i < A; ++i) {
            for(int j = 0; j < B; ++j) {
                int and = i & j;
                //System.out.println("" + i + " " + j + " " + and);
                if(and < K) {
                    ret ++;
                }

            }
        }
        return ret;

    }

    public static void main(String[] args) {

        String[] tokens = args;
        System.out.println(BSolution.simple(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), Integer.parseInt(tokens[2])));
    }
}
