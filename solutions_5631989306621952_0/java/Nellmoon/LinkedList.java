import java.util.*;
public class LinkedList {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        String holder;
         ArrayList<Character> arr;
         int counter = 1;
        while(cases-- > 0){
            arr = new ArrayList<>();
            holder = in.next();
            arr.add(holder.charAt(0));
            for(int i = 1; i < holder.length(); i++){
                
                if (holder.charAt(i) >= arr.get(0))
                    arr.add(0, holder.charAt(i));
                else
                    arr.add(holder.charAt(i));
            }
            String ans = "";
            for (int i = 0; i < holder.length(); i++){
                ans += arr.get(i);
            }
            System.out.println("Case #"+counter+": "+ans);
            counter++;
        }
    
    }
    
}
