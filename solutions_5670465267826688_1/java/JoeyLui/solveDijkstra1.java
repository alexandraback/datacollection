import java.util.*;
import java.io.*;

public class solveDijkstra1 {
    public static boolean helper(String s, long repeat, HashMap<Character, Integer> map, HashMap<Integer, Character> rmap) {
        StringBuilder sb = new StringBuilder();
        for (long i=0; i<repeat; i++) {
            sb.append(s);
        }
        s = sb.toString();
        int first = -1;
        int second = -1;
        boolean flag= true;
        char ch = s.charAt(0);
        for (int i=1; i<s.length(); i++) {
            if (flag == true && ch=='i' && first == -1) {
                first = i-1;
            }
            if (flag == true && ch=='k') {
                second = i-1;
            }
            char curr = s.charAt(i);
            if (ch=='l') {
                ch = curr;
            }
            else if (ch == curr) {
                ch = 'l';
                flag = !flag;
            }
            else if ((map.get(ch)+1)%3==(map.get(curr))%3) {
                ch = rmap.get((map.get(ch)+2)%3);
            }
            else {
                ch = rmap.get((map.get(ch)+1)%3);
                flag = !flag;
            }
        }
        
        if (flag==true || ch != 'l') { 
            return false;
        }
        else if (first != -1 && second != -1 && first < second) {
            return true;
        }
        else {
            return false;
        }
    }
    
    public static void main(String[] args) {
        String name = args[0];
        try {
            Scanner in = new Scanner(new File(name));
            try {
                 PrintWriter writer = new PrintWriter("DijkstraLarge.txt", "UTF-8");
                 int _n = Integer.parseInt(in.nextLine());
                 HashMap<Character, Integer> map = new HashMap<Character, Integer>();
                 map.put('i', 1);
                 map.put('j', 2);
                 map.put('k', 0);
                 HashMap<Integer, Character> rmap = new HashMap<Integer, Character>();
                 rmap.put(1, 'i');
                 rmap.put(2, 'j');
                 rmap.put(0, 'k');
                 for (int l=0; l<_n; l++) {
                     String[] tempStr = in.nextLine().split(" "); 
                     int lt = Integer.parseInt(tempStr[0]);
                     long x = Long.parseLong(tempStr[1]);
                     String s = in.nextLine();
                     //System.out.println("case #: "+(l+1)+" "+lt+" "+x);
                     if (x%4==0) {
                         writer.println("Case #"+(l+1)+": NO");
                         continue;
                     }
                     else if (x < 8) {
                         boolean blt = helper(s, x, map, rmap);
                         if (blt) {
                             writer.println("Case #"+(l+1)+": YES");
                         }
                         else {
                             writer.println("Case #"+(l+1)+": NO");
                         }
                     }
                     else {                         
                         boolean flag = true;
                         char ch = s.charAt(0);
                         HashSet<Character> set = new HashSet<Character>();
                         set.add(ch);
                         for (int i=1; i<s.length(); i++) {
                             char curr = s.charAt(i);
                             set.add(curr);
                             if (ch=='l') {
                                 ch = curr;
                             }
                             else if (ch == curr) {
                                 ch = 'l';
                                 flag = !flag;
                             }
                             else if ((map.get(ch)+1)%3==(map.get(curr))%3) {
                                 ch = rmap.get((map.get(ch)+2)%3);
                             }
                             else {
                                 ch = rmap.get((map.get(ch)+1)%3);
                                 flag = !flag;
                             }
                         }
                         //System.out.println(ch+" "+flag+" "+set.size());
                         if ((ch=='l' && (flag==true || x%2==0)) || (ch !='l' && (x%4 != 2)) || set.size()==1) {
                             writer.println("Case #"+(l+1)+": NO");
                             continue;
                         }
                         String tempS = s+s+s+s;
                         int first = -1;
                         int second = -1;
                         int len = tempS.length();
                         char ch1 = tempS.charAt(0);
                         char ch2 = tempS.charAt(len-1);
                         boolean flag1 = true;
                         boolean flag2 = true;
                         for (int i=1; i<len; i++) {
                             if (ch1=='i' && flag1 && first==-1) {
                                 first=i-1;
                             }
                             if (ch2=='k' && flag2 && second==-1) {
                                 second=len-i;
                             }
                             if (first != -1 && second != -1) {
                                 break;
                             }
                             char curr1 = tempS.charAt(i);
                             if (ch1=='l') {
                                 ch1 = curr1;
                             }
                             else if (ch1 == curr1) {
                                 ch1 = 'l';
                                 flag1 = !flag1;
                             }
                             else if ((map.get(ch1)+1)%3==(map.get(curr1))%3) {
                                 ch1 = rmap.get((map.get(ch1)+2)%3);
                             }
                             else {
                                 ch1 = rmap.get((map.get(ch1)+1)%3);
                                 flag1 = !flag1;
                             }
                             char curr2 = tempS.charAt(len-i-1);
                             if (ch2=='l') {
                                 ch2 = curr2;
                             }
                             else if (ch2 == curr2) {
                                 ch2 = 'l';
                                 flag2 = !flag2;
                             }
                             else if ((map.get(ch2)+2)%3==(map.get(curr2))%3) {
                                 ch2 = rmap.get((map.get(ch2)+1)%3);
                             }
                             else {
                                 ch2 = rmap.get((map.get(ch2)+2)%3);
                                 flag2 = !flag2;
                             } 
                         }
                         if (ch1=='i' && flag1 && first==-1) {
                             first=len-1;
                         }
                         if (ch2=='k' && flag2 && second==-1) {
                         second=0;
                         }
                         if (first != -1 && second != -1)
                             writer.println("Case #"+(l+1)+": YES");
                         else
                             writer.println("Case #"+(l+1)+": NO");
                     }
                 }
                 writer.close();
            }
            catch(IOException e) {
            }
            
            in.close();
        }
        catch (FileNotFoundException e) {
        }
    }
}