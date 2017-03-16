import java.util.Scanner;

public class Bullseye {

    public static void main(String[] args) {
        new Bullseye().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);

        int numCases = s.nextInt();
        for(int i=1;i<=numCases;i++) {
            long radius = s.nextLong();
            long paint = s.nextLong();

            int numRings = 0;
            while(2*radius+1 <= paint) {
                numRings++;
                paint = paint - (2*radius+1);
                radius += 2;
            }

            System.out.println("Case #"+i+": "+numRings);
        }
    }
}
