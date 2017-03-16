import java.io.File;
import java.io.PrintWriter;
import java.util.*;

/**
 * Created by Vitaly Russinkovsky
 * Date: 5/5/12
 */
public class Main {


    private static final double EPS = 1e-11;

    static int getCount(double[] members) {
        double first = members[0] + EPS;
        int count = 1;
        for(int i = 2; i < members.length; i++) {
            double barrier = members[i];
            if(barrier > first) {
                return count;
            } else {
                count++;
            }
        }
        return count;
    }

    static double getWorst(double[] values, double point) {
        double[] model = Arrays.copyOf(values, values.length);
        Arrays.sort(model);
        int size = model.length;
        while (point > EPS) {
            int count = getCount(model);
            if(count < size) {
                double sum = (model[count] - model[0]) * (double) count;
                if(sum < EPS) {
                    double portion = point / (double)size;
                    for(int i = 0; i < size; i++) {
                        model[i] = model[i] + portion;
                    }
                    break;
                }
                double real = Math.min(sum, point);
                double portion = real / (double) count;
                for(int i = 0; i < count; i++) {
                    model[i] = model[i] + portion;
                }
                point = point - real;
                //System.out.println(point);
                //System.out.println(sum);
            } else {
                double portion = point / (double)size;
                for(int i = 0; i < size; i++) {
                    model[i] = model[i] + portion;
                }
                break;
            }
        }
        return model[0];
    }

    static boolean isAdvanced(double[] values, double my, double fraction) {
        double sum = 0.0;
        for(int i = 0; i < values.length; i++) {
            sum = sum + values[i];
        }
        sum = sum + my;
        my = my + sum * fraction;
        double points = sum * (1.0 - fraction);
        double other = getWorst(values, points);
        return other < my;
    }

    static boolean isAdvanced2(double[] all, int k, double fraction) {
        double sum = 0.0;
        for(int tt = 0; tt < all.length; tt++) {
            sum = sum + all[tt];
        }
        double myVal = all[k] + sum * fraction;
        double need = 0.0;
        for(int tt = 0; tt < all.length; tt++) {
            if(tt != k && all[tt] < myVal) {
                need = need + (myVal - all[tt]);
            }
        }

        return !((need + 1E-6) < (sum * (1.0 - fraction)));

    }

    static double solve(double[] all, int index) {
//        double[] copy = new double[all.length - 1];
//        double my = all[index];
//        int pos = 0;
//        for(int i = 0; i < all.length; i++) {
//            if(i != index) {
//                copy[pos++] = all[i];
//            }
//        }
        double high = 1.0;
        double low = 0.0;
        double search = 0.0;
        while ((high - low) > 5.0E-10) {
            search = 0.5 * (high + low);
            //System.out.println("" + index + ":" + search);
            if(isAdvanced2(all, index, search)) {
                high = search;
            } else {
                low = search;
            }
            //System.out.println(search);
        }
        return search;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(new File("A-large.in"));
        PrintWriter pw = new PrintWriter(new File("output.txt"));
        int ncase = sc.nextInt();
        for(int i = 0; i < ncase; i++) {
            int ncont = sc.nextInt();
            double[] all = new double[ncont];
            for(int j = 0; j < ncont; j++) {
                all[j] = sc.nextInt();
            }
            pw.print(String.format("Case #%d: ", i + 1));
            for(int k = 0; k < ncont; k++) {
                double sol = solve(all, k);

                // Verification
//                double sum = 0.0;
//                for(int tt = 0; tt < all.length; tt++) {
//                    sum = sum + all[tt];
//                }
//                double myVal = all[k] + sum * sol;
//                double need = 0.0;
//                for(int tt = 0; tt < all.length; tt++) {
//                    if(tt != k && all[tt] < myVal) {
//                        need = need + (myVal - all[tt]);
//                    }
//                }
//
//                if((need - 1E-6) < (sum * (1.0 - sol))) {
//                    System.out.println("Case" + (i + 1));
//                    System.out.println("Pos" + (k + 1));
//                    System.out.println(sol);
//                    System.out.println(myVal);
//                    System.out.println(need);
//                    System.out.println(sum * (1.0 - sol));
//                    System.out.println(sum);
//                    System.exit(0);
//
//                }


                pw.print(String.format("%11.6f", sol * 100.0));
            }
            pw.print("\n");
        }
        sc.close();
        pw.close();

    }

}
