import java.util.*;

/**
 * Created by BinghongFu on 4/15/16.
 */
public class RankAndFile {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int m = Integer.valueOf(s.nextInt());
        String[] result = new String[m];
        for(int i = 0; i < m; ++i){
            int n = Integer.valueOf(s.nextInt());
            int[] input = new int[n * (2 * n - 1)];
            for(int j = 0; j < n * (2 * n - 1); ++j){
                input[j] = s.nextInt();
            }
            result[i] = rankAndFile(input);
        }


        for(int i = 0; i < m; ++i){
            System.out.print("Case #" + String.valueOf(i + 1) + ": ");
            System.out.println(result[i]);
        }

    }

    private static String rankAndFile(int[] nums){
        HashMap<Integer, Integer> counter = new HashMap<>();
        for(int i : nums){
            if(!counter.containsKey(i))
                counter.put(i, 0);
            counter.put(i, counter.get(i) + 1);
        }

        ArrayList<Integer> result = new ArrayList<>();

        for(HashMap.Entry<Integer, Integer> entry : counter.entrySet()){
            if(entry.getValue() % 2 != 0){
                result.add(entry.getKey());
            }
        }

        Collections.sort(result);
        StringBuilder sb = new StringBuilder();
        for(int i : result){
            sb.append(i);
            sb.append(" ");
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }
}
