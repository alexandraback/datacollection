import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class Task2 {


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(new File("t.txt")));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File("out.txt")));
        Task2 instance = new Task2();
        int num = Integer.parseInt(reader.readLine().trim());
        for (int i = 0; i < num; i++) {
            String[] orig = reader.readLine().split(" +");
            writer.write("Case #" + (i + 1) + ": ");
            Map<Integer, String> map = new HashMap<Integer, String>();
            int[] nums = new int[20];
            boolean founded;
            int res = 0;
            int ind =0 ;
            for (int j = 0; j < nums.length; j++) {
                nums[j] = Integer.parseInt(orig[j + 1]);
            }
            founded = false;
            for (int j = 0; j < nums.length; j++) {
                map.put(nums[j], String.valueOf((char) ('a' + j)));
            }

            for(int ll = 0 ; ll < nums.length && !founded; ll++){
                for (int j = 0; j < nums.length && !founded; j++) {
                    Map<Integer, String> submap = new HashMap<Integer, String>();
                    for (Integer k : map.keySet()) {
                        if (!map.containsKey(nums[j] + k) && !submap.containsKey(nums[j] + k)) {
                            submap.put(nums[j] + k, String.valueOf((char) ('a' + j) + map.get(k)));
                        } else {
                            if (map.containsKey(nums[j] + k)) {
                                if (isGood(j, k, map, nums)) {
                                    founded = true;
                                    res = nums[j];
                                    ind = k;
                                    break;
                                }
                            } else {
                                if (isGood(j, k, submap, nums)) {
                                    founded = true;
                                    res = nums[j];
                                    ind = k;
                                    break;
                                }
                            }
                        }
                    }
                    map.putAll(submap);
                }
            }

            if (!founded) {
                writer.write("Impossible");
            } else {
                writer.write('\n');
                String s1 = map.get(res) +  map.get(ind);
                String s2 = map.get(res + ind);
                for (int j = 0; j < s1.length(); j++) {
                    writer.write("" +nums[s1.charAt(j) - 'a']);
                    if (j < s1.length() - 1) {
                        writer.write(" ");
                    }
                }
                writer.write('\n');
                for (int j = 0; j < s2.length(); j++) {
                    writer.write("" +nums[s2.charAt(j) - 'a']);
                    if (j < s2.length() - 1) {
                        writer.write(" ");
                    }
                }
            }
            if (i < num - 1) {
                writer.write('\n');
            }
        }
        writer.close();
        reader.close();
    }


    public static boolean isGood(int i, int sum,Map<Integer, String> map, int[] nums) {
        String s1 = map.get(sum) + String.valueOf((char) ('a' + i));
        String s2 = map.get(sum + nums[i]);
        for (int j = 0; j < s1.length(); j++) {
            for (int k = j+1; k < s1.length(); k++) {
                if(s1.charAt(j) == s1.charAt(k)){
                    return false;
                }

            }
        }
        for (int j = 0; j < s2.length(); j++) {
            for (int k = j+1; k < s2.length(); k++) {
                if(s2.charAt(j) == s2.charAt(k)){
                    return false;
                }

            }
        }
        for (int j = 0; j < s1.length(); j++) {
            if (s2.indexOf(s1.charAt(j)) > -1) {
                return false;
            }
        }
        return true;
    }
}
