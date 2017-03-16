import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class MainA {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            String s = sc.nextLine();
            HashMap<Character, Integer> map = new HashMap<>();
            for(char ch : s.toCharArray()) {
                map.put(ch, map.getOrDefault(ch, 0)+1);
            }
            ArrayList<Integer> list = new ArrayList<>();
            int count = map.getOrDefault('Z', 0);
            for (int i=0;i < count;i++) {
                list.add(0);

            }
            if(count>0){
                map.put('Z', map.get('Z') - count);
                map.put('E', map.get('E') - count);
                map.put('R', map.get('R') - count);
                map.put('O', map.get('O') - count);
            }

            count = map.getOrDefault('W', 0);
            for (int i=0;i < count;i++) {
                list.add(2);
            }
            if(count>0){
                map.put('T', map.get('T') - count);
            map.put('W', map.get('W') - count);
            map.put('O', map.get('O') - count);}

            count = map.getOrDefault('U', 0);
            for (int i=0;i < count;i++) {
                list.add(4);
            }
            if(count>0){
                map.put('F', map.get('F') - count);
            map.put('O', map.get('O') - count);
            map.put('U', map.get('U') - count);
            map.put('R', map.get('R') - count);}

            count = map.getOrDefault('X', 0);
            for (int i=0;i < count;i++) {
                list.add(6);
            }
            if(count>0){
                map.put('S', map.get('S') - count);
            map.put('I', map.get('I') - count);
            map.put('X', map.get('X') - count);}
            count = map.getOrDefault('G', 0);
            for (int i=0;i < count;i++) {
                list.add(8);
            }
            if(count>0){
                map.put('E', map.get('E') - count);
            map.put('I', map.get('I') - count);
            map.put('G', map.get('G') - count);
            map.put('H', map.get('H') - count);
            map.put('T', map.get('T') - count);}
            count = map.getOrDefault('S', 0);
            for (int i=0;i < count;i++) {
                list.add(7);
            }
            if(count>0){
                map.put('S', map.get('S') - count);
            map.put('E', map.get('E') - count*2);
            map.put('V', map.get('V') - count);
            map.put('N', map.get('N') - count);}

            count = map.getOrDefault('F', 0);
            for (int i=0;i < count;i++) {
                list.add(5);
            }
            if(count>0){
                map.put('F', map.get('F') - count);
            map.put('I', map.get('I') - count);
            map.put('V', map.get('V') - count);
            map.put('E', map.get('E') - count);}
            count = map.getOrDefault('T', 0);
            for (int i=0;i < count;i++) {
                list.add(3);
            }
            if(count>0){
                map.put('T', map.get('T') - count);
            map.put('H', map.get('H') - count);
            map.put('R', map.get('R') - count);
            map.put('E', map.get('E') - count*2);}
            count = map.getOrDefault('O', 0);
            for (int i=0;i < count;i++) {
                list.add(1);
            }
            if(count>0){
                map.put('O', map.get('O') - count);
            map.put('N', map.get('N') - count);
            map.put('E', map.get('E') - count);}
            count = map.getOrDefault('I', 0);
            for (int i=0;i < count;i++) {
                list.add(9);
            }
            list.sort(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o1-o2;
                }
            });
            System.out.print("Case #" + t + ": ");
            for (int i: list) {
                System.out.print(i);
            }
            System.out.println();
        }
    }
}
