import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
    public static int calculate(int curMote, int[] sortedMotes, int from) {
        if(from >= sortedMotes.length) {
            return 0;
        }
        if(curMote > sortedMotes[from]) {
            return calculate(curMote + sortedMotes[from], sortedMotes, from + 1);
        }

        int skip = sortedMotes.length - from;

        if(curMote == 1) { return skip; }

        int absorb = 0;
//        System.out.print("Before " + curMote + " ");
        while(curMote <= sortedMotes[from]) {
            curMote += curMote - 1;
            absorb++;
        }
//        System.out.println("After " + absorb + " " + curMote);
        return Math.min(skip, absorb + calculate(curMote + sortedMotes[from], sortedMotes, from+1));
    }

    public static void main(String[] args) {
//        int[] motes = new int[] {1, 30, 45, 13, 42, 83, 15, 68, 1};
//        Arrays.sort(motes);
//
//        for(Integer i : motes)
//            System.out.print(i + " ");
//
//        System.out.println();
//
//        System.out.println(calculate(6, motes, 0));
        Scanner scanner = new Scanner(System.in);
        int T = Integer.parseInt(scanner.nextLine());
        for(int i= 0 ; i <  T; i++) {
            String tokens[] = scanner.nextLine().split(" ");
            int A = Integer.parseInt(tokens[0]);
            int others = Integer.parseInt(tokens[1]);

            int othersArr[] = new int[others];
            int j =0;
            tokens = scanner.nextLine().split(" ");
            for(String token : tokens) {
                othersArr[j++] = Integer.parseInt(token);
            }
            Arrays.sort(othersArr);
            System.out.println("Case #" + (i+1) + ": " + calculate(A, othersArr, 0));

//            for(Integer mote : othersArr) {
//                System.out.print(mote);
//            }
        }
    }
}
