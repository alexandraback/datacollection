import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * Created by Tor on 09.04.2016.
 */
public class CountingSheep {

    public Integer getLastNumber(Integer baseNumber) {
        if(baseNumber==0) {
            return null;
        }

        Set<Integer> seen = new HashSet<Integer>();
        for(int i=0;i<=9;i++) {
            seen.add(i);
        }
        Integer current = baseNumber;
        removeDigits(seen, current);
        while(!seen.isEmpty()) {
            current += baseNumber;
            removeDigits(seen, current);
        }

        return current;
    }

    private void removeDigits(Set<Integer> seen, Integer current) {
        while(current>0) {
            int lastDigit = current%10;
            seen.remove(lastDigit);
            current = current/10;
        }
    }

    public static void main(String[] args) {
        CountingSheep cs = new CountingSheep();
        Scanner s = new Scanner(System.in);

        int numAttempts = s.nextInt();
        for(int i=1;i<=numAttempts;i++) {
            Integer number = cs.getLastNumber(s.nextInt());

            System.out.format("Case #%d: %s\n", i, number==null?"INSOMNIA":number.toString());
        }
    }
}
