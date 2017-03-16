import java.util.*;
import java.io.*;

public class solveDijkstra {
    public static void main(String[] args) {
        String name = args[0];
        try {
            Scanner in = new Scanner(new File(name));
            try {
                
                 PrintWriter writer = new PrintWriter("Dijkstra.txt", "UTF-8");
                 int _n = Integer.parseInt(in.nextLine());
                 for (int l=0; l<_n; l++) {
                     String[] tempStr = in.nextLine().split(" "); 
                     int len = Integer.parseInt(tempStr[0]);
                     long x = Long.parseLong(tempStr[1]);
                     String str = in.nextLine();
                     StringBuilder sb = new StringBuilder();
                     for (long i=0; i<x; i++) {
                         sb.append(str);
                     }
                     String s = sb.toString();
                     HashMap<Character, Integer> map = new  HashMap<Character, Integer>();
                     map.put('i', 1);
                     map.put('j', 2);
                     map.put('k', 0);
                     HashMap<Integer, Character> rmap = new HashMap<Integer, Character>();
                     rmap.put(1, 'i');
                     rmap.put(2, 'j');
                     rmap.put(0, 'k');
                     boolean flag = true;
                     char ch = s.charAt(0);
                     int first = -1;
                     int second = -1;
                     for (int i=1; i<s.length(); i++) {
                         if (flag == true && ch=='i' && first == -1) {
                             first = i-1;
                         }
                         if (flag == true && ch=='k') {
                             second = i;
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

                         writer.println("Case #"+(l+1)+": NO");
                     }
                     else if (first != -1 && second != -1 && first < second) {
                         writer.println("Case #"+(l+1)+": YES");
                     }
                     else {
                         writer.println("Case #"+(l+1)+": NO");
                     }
                    //System.out.println();
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