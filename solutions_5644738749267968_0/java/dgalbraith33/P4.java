import java.util.Scanner;
import java.util.Arrays;
import java.util.ArrayList;

public class P4 {
    public static Scanner stdin = new Scanner(System.in);

    public static void main(String[] args) {
        int numCases = Integer.parseInt(stdin.nextLine());

        for(int i = 1; i <= numCases; i++) {
            execute(i);
        }
    }

    public static void execute(int run) {
        int numCards = Integer.parseInt(stdin.nextLine());
        double[] nArray = parseArray();
        double[] kArray = parseArray();

        Arrays.sort(nArray);
        Arrays.sort(kArray);


        ArrayList<Double> n = asList(nArray);
        ArrayList<Double> k = asList(kArray);

        int reg = regularWar(n,k);
        int dec = deceitWar(n,k);

        System.out.println("Case #"+run+": "+dec+" "+reg);
    }

    public static double[] parseArray() {
        String[] row = stdin.nextLine().split(" ");
        double[] res = new double[row.length];
        for(int i = 0; i < row.length; i++) {
            res[i] = Double.parseDouble(row[i]);
        }

        return res;
    }

    public static int regularWar(ArrayList<Double> n, ArrayList<Double> k) {
        n = (ArrayList<Double>)n.clone();
        k = (ArrayList<Double>)k.clone();
        int wins = 0;
        while(n.size() > 0) {
            if(n.get(0) > k.get(k.size()-1)) {
                wins++;
                n.remove(0);
                k.remove(0);
            }
            else {
                int index = findBeats(n.get(0),k);
                n.remove(0);
                k.remove(index);
            }
        }
        return wins;
    }

    public static int findBeats(double d, ArrayList<Double> k) {
        for(int i = 0; i < k.size(); i++) {
            if(k.get(i) > d) {
                return i;
            }
        }
        return -1;
    }

    public static int deceitWar(ArrayList<Double> n , ArrayList<Double> k) {

        int wins = 0;
        while(n.size() > 0) {
            if(n.get(0) > k.get(0)) {
                wins++;
                n.remove(0);
                k.remove(0);
            }
            else {
                n.remove(0);
                k.remove(k.size()-1);
            }
        }
        return wins;
    }

    public static ArrayList<Double> asList(double[] arr) {
        ArrayList<Double> list = new ArrayList<Double>();
        for(double d : arr) {
            list.add(d);
        }
        return list;
    }
}