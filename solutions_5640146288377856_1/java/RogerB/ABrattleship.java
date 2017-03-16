package Round1C;

import java.util.Scanner;

public class ABrattleship {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int tests = sc.nextInt();
        for (int t = 1; t <= tests; t++) {
            int height = sc.nextInt();
            int width = sc.nextInt(); //1 in the small case
            int shipSize = sc.nextInt();
            int narrowHits = (width / shipSize) * height; //eliminating all large enough spaces for the ship
            int extraHits = shipSize - 1; //the number of hits to actually destroy the ship (and one was hit by the narrowing
            if (!(width % shipSize == 0)) { //there's an avoid at the last hit, but only if it's possible
                extraHits++;
            }
            int totalHits = narrowHits + extraHits;
            System.out.printf("Case #%d: %d%n", t, totalHits);
        }
        sc.close();
    }
}
