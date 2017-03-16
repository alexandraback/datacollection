import java.math.BigInteger;
import java.util.*;

/**
 * Created by james on 16/04/09.
 */
public class Sheep {
    public static void main(String[] args) {
        Integer ints[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        Set<Integer> goal = new LinkedHashSet<>(Arrays.asList(ints));
        Scanner in = new Scanner(System.in);
        int number = in.nextInt();
        ArrayList<Long> ns = new ArrayList<>(number);
        for(int i = 0; i < number; i++){
            Long n = in.nextLong();
            ns.add(n);
        }
        for(int i = 1; i <= number; i++){
            Long n = ns.get(i-1);
            System.out.printf("Case #%d: ", i);
            if(n == 0)
                System.out.println("INSOMNIA");
            else {
                int count = 0;
                Set<Integer> current = new LinkedHashSet<>();
                while(!current.equals(goal)){
                    count++;
                    current.addAll(getInts(n * count));
                }
                System.out.println("" + n * count);
            }
        }

    }

    static public Set<Integer> getInts(Long b){
        LinkedHashSet<Integer> result = new LinkedHashSet<>();
        while(b > 0){
            result.add( (int)(b % 10));
            b /= 10;
        }
        return result;
    }
}
