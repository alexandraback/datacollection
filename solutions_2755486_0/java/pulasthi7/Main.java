import java.util.*;

/* pulasthi7@gmail.com */
public class Main {
    static Scanner sc;
    public static void main(String[] args) {
        sc = new Scanner(System.in);
        int T = sc.nextInt();
        long stime = System.nanoTime();
        for (int i = 0; i < T; i++) {
            System.err.println("Solving case "+(i+1));
            System.out.print("Case #" + (i + 1) + ": ");
            solve();
        }
        System.err.println("Finished in "+((System.nanoTime()-stime)/1000000)+" ms");
    }

    static void solve(){
        int N = sc.nextInt();
        TreeMap<Integer, ArrayList<Attack>> attacks = new TreeMap<Integer, ArrayList<Attack>>();
        int success = 0;
        for (int i = 0; i < N; i++) {
            int firstday = sc.nextInt();
            int nAttacks = sc.nextInt();
            int wi = sc.nextInt();
            int ei = sc.nextInt();
            int s = sc.nextInt();
            int days = sc.nextInt();
            int trav = sc.nextInt();
            int ds = sc.nextInt();

            for (int j = 0; j < nAttacks; j++) {
                int attackday = firstday+j*days;
                int west = wi+trav*j;
                int east = ei+trav*j;
                int power = s+ds*j;
                if(attacks.containsKey(attackday)){
                    attacks.get(attackday).add(new Attack(west,east,power));
                }else {
                    ArrayList<Attack> at = new ArrayList<Attack>();
                    at.add(new Attack(west,east,power));
                    attacks.put(attackday,at);
                }
            }
        }
        HashMap<Integer,Integer> heights = new HashMap<Integer, Integer>();
        for (Map.Entry<Integer, ArrayList<Attack>> entry: attacks.entrySet()) {
            HashMap<Integer, Integer> temp = new HashMap<Integer, Integer>();
            for(Attack attack:entry.getValue()){
                boolean attacked = false;
                for (int i = attack.from*2; i <= attack.to*2 ; i++) {
                    if((!heights.containsKey(i)&&attack.power>0)||(heights.containsKey(i)&&heights.get(i)<attack
                            .power)){
                        attacked = true;
                        if(!temp.containsKey(i)){
                            temp.put(i,attack.power);
                        }
                        else if(temp.get(i)<attack.power){
                            temp.put(i,attack.power);
                        }

                    }
                }
                if(attacked){
                    success++;
                }
            }
            heights.putAll(temp);
        }
        System.out.println(success);
    }
}
class Attack{
    Attack(int from, int to, int power) {
        this.from = from;
        this.to = to;
        this.power = power;
    }

    int from;
    int to;
    int power;
}