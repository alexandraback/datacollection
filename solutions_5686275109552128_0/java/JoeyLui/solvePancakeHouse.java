import java.util.*;
import java.io.*;

public class solvePancakeHouse {
    public static void main(String[] args) {
        String name = args[0];
        try {
            Scanner in = new Scanner(new File(name));
            try {
                
                 PrintWriter writer = new PrintWriter("pancake1.txt", "UTF-8");
                 int _n = Integer.parseInt(in.nextLine());
                 for (int l=0; l<_n; l++) {
                     int n = Integer.parseInt(in.nextLine());
                     //System.out.println("case #"+n);
                     String str = in.nextLine();
                    // System.out.println(str);
                     String[] s= str.split(" ");
                     PriorityQueue<String> pq = new PriorityQueue<String>(1000000, new Comparator<String>() {
                         public int compare(String n1, String n2) {
                             return Integer.parseInt(n2)-Integer.parseInt(n1);
                         }
                     });
                     
                     for (int i=0; i<n; i++) {
                         pq.add(s[i]);
                     }
                     int ret = 0;
                     while (pq.size() != 0) {
                         List<String> list = new ArrayList<String>();
                         String currS = pq.peek();
                         int curr = Integer.parseInt(currS);
                         while (pq.size() > 0) {
                             int ct = 0;
                             int element = Integer.parseInt(pq.peek());
                             if (element > (curr+1)/2) { 
                                 while (pq.size() > 0 && Integer.parseInt(pq.peek()) == element) {
                                     list.add(pq.poll());
                                     ct++;
                                 }
                                 
                                 int temp = pq.size() > 0 ? (Math.max(Integer.parseInt(pq.peek()), (curr+1)/2)) : (curr+1)/2;
                                 if (list.size() <= curr-temp) {
                                     break;                                 
                                 }
                             }
                             else {
                                 break;
                             }
                         } 
                         int toComp = pq.size() > 0 ? (Math.min(curr/2, curr-Integer.parseInt(pq.peek()))):curr/2;
                         if (list.size() > 0 && list.size() <= toComp) {                             
                             int sz = list.size();
                             ret += sz;
                             for (int j=0; j< sz; j++) {
                                 int currN = Integer.parseInt(list.get(j));
                                 int left = currN/2;
                                 int right = currN-left;
                                 pq.add(Integer.toString(left));
                                 pq.add(Integer.toString(right));
                             }
                         }
                         else {
                             ret += curr;
                             break;
                         }
                     }
                     writer.println("Case #"+(l+1)+": "+ret);
                    //System.out.println("Case #"+(l+1)+": "+ret);
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