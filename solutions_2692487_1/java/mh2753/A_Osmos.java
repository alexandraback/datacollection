import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class A_Osmos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        try {

            int T = Integer.parseInt(in.readLine());

            for (int tc=1;tc<=T;tc++) {
                System.out.print("Case #" + tc + ": ");
                
                StringTokenizer st = new StringTokenizer(in.readLine());
                
                int a = Integer.parseInt(st.nextToken());
                int n = Integer.parseInt(st.nextToken());                                
                
                int m[] = new int[n]; 
                
                st = new StringTokenizer(in.readLine());
                
                for (int i=0;i<n;i++) { 
                	m[i] = Integer.parseInt(st.nextToken());
                }
                
                Arrays.sort(m);
                
                if (a==1) { 
                	System.out.println(n);
                	continue;
                }
                
                int add[] = new int[n];
                for (int i=0;i<add.length;i++) { 
                	add[i] = 0;
                }
                
                for (int i=0;i<n;i++) { 
                	while (a<=m[i]) { 
                		a+=(a-1);
                		add[i]++;
                	}
                	a+=m[i];
                }
                
                int c = n;
                int sf = 0;
                for (int i=0;i<n;i++) {
                	sf+=add[i];
                	c = Math.min(c, sf + n-i-1);
                }
                
                System.out.println(c);
            }

        }catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }


	}

}
