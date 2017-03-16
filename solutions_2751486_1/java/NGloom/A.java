import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;


public class A {
    
    static int find(List<Integer> list, int idx) {
        int l = -1;
        int h = list.size();
        while(l + 1 < h) {
            int mid = (l+h)/2;
            if(list.get(mid) < idx) {
                l = mid;
            } else {
                h = mid;
            }
        }
        return h;
    }
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("consonants.txt"));
            int num = in.nextInt();
            Set<Character> set = new HashSet<Character>();
            set.add('a');
            set.add('e');
            set.add('i');
            set.add('o');
            set.add('u');
            for(int z = 1; z <= num; z++) {
                String s = in.next();
                int n = in.nextInt();
                long cnt = 0;
                
                List<Integer> idxList = new ArrayList<Integer>();
                
                
                // to be opt
                int tmp = 0;
                for(int i = 0; i < s.length(); i++) {
                    if(set.contains(s.charAt(i))) {
                        tmp = 0;
                    } else {
                        tmp ++;
                        if(tmp >= n) {
                            idxList.add(i+1-n);
                        }
                    }
                }
               
                for(int i = 0; i < s.length(); i++) {
                    int idx = find(idxList,i);
                    if(idx == -1 || idx == idxList.size()) {
                        continue;
                    }
                    idx = idxList.get(idx);
                    cnt += (s.length() - (idx + n -1));
                }
                
                System.out.println(String.format("Case #%d: %d", z,cnt));
                
                
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
