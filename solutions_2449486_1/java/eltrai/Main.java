import java.util.Scanner;


public class Main {
    public static void main (String[] args) {
         Scanner in = new Scanner(System.in);
         int cases = in.nextInt(); in.nextLine();

         for(int T=0; T<cases; T++) {
        	 boolean possible = true;
        	 int N = in.nextInt();
        	 int M = in.nextInt();
        	 byte[] tab = new byte[N*M];
        	 byte max_l[] = new byte[N];
        	 byte max_c[] = new byte[M];
        	 for(int i=0; i<N;i++) {
        		 for(int j=0; j<M; j++) {
        			 tab[i*M+j] = in.nextByte();
        			 if(max_l[i] < tab[i*M+j])
        				 max_l[i] = tab[i*M+j];
        			 if(max_c[j] < tab[i*M+j])
        				 max_c[j] = tab[i*M+j];
        		 }
        	 }
        	 for(int i=0; i<N;i++) {
        		 for(int j=0; j<M; j++) {
        			 if(tab[i*M+j] < max_l[i] && tab[i*M+j] < max_c[j]) {
        				 possible = false;
        			 }
        		 }
        	 }
        	 
             System.out.print("Case #" + (T+1) + ": ");
             if(possible)
            	 System.out.println("YES");
             else
            	 System.out.println("NO");
         }
    }
}
