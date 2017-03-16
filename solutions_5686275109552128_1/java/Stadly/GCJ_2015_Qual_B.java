import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class GCJ_2015_Qual_B {
	public static void main(String[] args) throws Exception {
      int cases = readInt();
      for(int t = 1; t <= cases; ++t) {
         PriorityQueue<Stack> plates = new PriorityQueue();
         int d = readInt();
         int[] count = new int[1001];
         for(int i = 0; i < d; ++i) {
            int pancakes = readInt();
            if(0 == count[pancakes])
               plates.add(new Stack(pancakes));
            ++count[pancakes];
         }
         
         int best = Integer.MAX_VALUE;
         int divisions = 0;
         while(plates.peek().size() > 3) {
            Stack stack = plates.poll();
            best = Math.min(best, divisions + stack.size());
            divisions += count[stack.size];
            plates.add(new Stack(stack));
         }
         best = Math.min(best, divisions + plates.peek().size());

         System.out.println("Case #"+t+": "+best);
      }
	}
   
   static class Stack implements Comparable<Stack> {
      public int size;
      public int divisions;
      
      public Stack(int size) {
         this.size = size;
         this.divisions = 1;
      }
      public Stack(Stack o) {
         this.size = o.size;
         this.divisions = o.divisions+1;
      }
      
      public int size() {
         return (int)Math.round(Math.ceil((double)size/divisions));
      }
      
      @Override
      public int compareTo(Stack o) {
         return Double.compare((double)o.size/o.divisions, (double)size/divisions);
      }
   }
	
	static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");
	static String readString() throws Exception {
		while(!st.hasMoreTokens())
			st = new StringTokenizer(stdin.readLine());
		return st.nextToken();
	}
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}
}
