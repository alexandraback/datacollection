import java.util.*;

public class A{
    static Scanner s;
    public static void main(String[] args){
        s = new Scanner(System.in);
        int cases = s.nextInt();
        for(int i = 0; i < cases; i++) {
            int result = solve();
            System.out.printf("Case #%d: %d\n", i+1, result);
        }
    }

    public static int solve() {
        int self = s.nextInt();
        int num = s.nextInt();
        List<Integer> arr = new ArrayList<Integer>();
        List<Integer> track = new ArrayList<Integer>();
        for(int i = 0; i < num; i++) {
            arr.add(s.nextInt());
        }
        int result = 0;
        int temp = 0;
        boolean remove = false;

        if(self <= 1) {
            return arr.size();
        }

        while(arr.size() > 0) {

            remove = false;
outerloop:
            if(!remove) {
                for (Integer curr : arr) {
                    if (curr < self) {
                        temp = curr;
                        self += curr;
                        remove = true;
                        break outerloop;
                    }
                }
            }
            if(remove) {
                arr.remove((int) arr.indexOf((Integer)temp));
            } else {
                self = (self * 2) - 1;
                track.add(result + arr.size());
                result++;
            }
        }

        track.add(result);
        return Collections.min(track);



    }
}



