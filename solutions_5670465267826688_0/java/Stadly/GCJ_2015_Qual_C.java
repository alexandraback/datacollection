import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class GCJ_2015_Qual_C {
	public static void main(String[] args) throws Exception {
      int cases = readInt();
      int[][] mult =
      {  {  1, 0, 3, 2, 5, 4, 7, 6  }
      ,  {  0, 1, 2, 3, 4, 5, 6, 7  }
      ,  {  3, 2, 0, 1, 7, 6, 4, 5  }
      ,  {  2, 3, 1, 0, 6, 7, 5, 4  }
      ,  {  5, 4, 6, 7, 0, 1, 3, 2  }
      ,  {  4, 5, 7, 6, 1, 0, 2, 3  }
      ,  {  7, 6, 5, 4, 2, 3, 0, 1  }
      ,  {  6, 7, 4, 5, 3, 2, 1, 0  }
      };
      int[] convert = new int[108];
      convert[105] = 3;
      convert[106] = 5;
      convert[107] = 7;

      for(int t = 1; t <= cases; ++t) {
         int l = readInt();
         long x = readLong();
         String chars = readString();
         
         int block = 1;
         for(int i = 0; i < l; ++i)
            block = mult[block][convert[chars.charAt(i)]];
         
         int identity = 4;
         if(1 == block)
            identity = 1;
         else if(0 == block)
            identity = 2;
      
         int[] pre = new int[l*identity+1];
         int[] post = new int[l*identity+1];
         pre[0] = 1;
         post[0] = 1;
         ArrayList<Integer> start = new ArrayList();
         ArrayList<Integer> end = new ArrayList();
         for(int i = 0; i < l*identity; ++i) {
            pre[i+1] = mult[pre[i]][convert[chars.charAt(i%l)]];
            post[i+1] = mult[convert[chars.charAt((l*identity-i-1)%l)]][post[i]];
            if(3 == pre[i+1])
               start.add(i);
            if(7 == post[i+1])
               end.add(i);
         }
         
         boolean ok = false;
         TEST:
         for(int s : start) {
            for(int e : end) {
               long left = x - Math.round(Math.ceil((double)(s+1)/l));
               left -= Math.round(Math.ceil((double)(e+1)/l));
               
               int m = 1;
               if(left >= 0) {
                  m = post[(l*identity-s-1)%l];
                  left %= identity;
                  for(int i = 0; i < left; ++i)
                     m = mult[m][block];
                  m = mult[m][pre[(l*identity-e-1)%l]];
               } else {
                  for(int i = s+1; i < x*l-e-1; ++i)
                     m = mult[m][convert[chars.charAt(i%l)]];
               }
               
               if(5 == m) {
                  ok = true;
                  break TEST;
               }
            }
         }
         
         if(ok)
            System.out.println("Case #"+t+": YES");
         else
            System.out.println("Case #"+t+": NO");
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
	static long readLong() throws Exception {
		return Long.parseLong(readString());
	}
}
