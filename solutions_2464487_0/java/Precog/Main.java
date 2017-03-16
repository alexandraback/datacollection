import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            BigDecimal r = new BigDecimal(sc.next());
            BigDecimal t = new BigDecimal(sc.next());
            BigDecimal max = t;
            BigDecimal rad = r.add(new BigDecimal(1+""));
            BigDecimal tempRad = r;
            int counter = 0;
            BigDecimal area = new BigDecimal("0.0");
//            System.out.println("MAX : "+max);
            while(area.compareTo(max) != 1)    {
                BigDecimal area1 = rad.multiply(rad);
                BigDecimal area2 = tempRad.multiply(tempRad);
                area = area.add(area1.subtract(area2));
//                System.out.println("area : "+area);
                rad=rad.add(new BigDecimal(2+""));
                tempRad=tempRad.add(new BigDecimal(2+""));
                if(area.compareTo(max) != 1) {
                    counter++;
                }
                else
                    if(counter == 0)
                        counter = 1;
            }
            System.out.println("Case #"+i+": "+counter);
        }
    }

}