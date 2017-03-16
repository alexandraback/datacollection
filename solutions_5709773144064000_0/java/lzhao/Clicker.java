
public class Clicker {
    public static double timeTaken(double C, double F, double X) {
        if(C >= X) {

            return X/2;
        }

        int k = 0;
        double timePassed = C / 2;
        while(true) {
            double r0 = 2 + F * k;
            double r1 = 2 + F * (k + 1);
            double t0 = (X - C)/r0;
            double t1 = X/r1;

            if(t0 < t1) {
                timePassed += t0;
                break;
            } else {
                timePassed += C/r1;
                k++;
            }

        }
        return timePassed;

    }

    public static void main(String[] args) {
        System.out.println(Clicker.timeTaken(Double.parseDouble(args[0]), Double.parseDouble(args[1]), Double.parseDouble(args[2])));
    }

}
