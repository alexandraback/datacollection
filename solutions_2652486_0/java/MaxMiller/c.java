import java.util.*;

public class c {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt(), r = in.nextInt(), n = in.nextInt(), m = in.nextInt(), k = in.nextInt();
		System.out.println("Case #1:");

		for(int line=0; line<r; ++line) {
			int[] inout = new int[10];
			ArrayList<Integer> unprocessed = new ArrayList<Integer>();

			for(int prod=0; prod<k; ++prod) {
				int x = in.nextInt();

				if(x == 9) {
					inout[3] = 2;
				}
				else if(x == 25) {
					inout[5] = 2;
				}
				else if(x == 3) {
					if(inout[3] < 1)
						inout[3] = 1;
				}
				else if(x == 5) {
					if(inout[5] < 1)
						inout[5] = 1;
				}
				else if(x == 15) {
					if(inout[3] < 1)
						inout[3] = 1;
					if(inout[5] < 1)
						inout[5] = 1;
				}
				else if(x == 6) {
					if(inout[3] < 1)
						inout[3] = 1;
					if(inout[2] < 1)
						inout[2] = 1;
				} 
				else if(x == 10) {
					if(inout[2] < 1)
						inout[2] = 1;
					if(inout[5] < 1)
						inout[5] = 1;
				} 
				else if(x == 120) {
					if(inout[2] < 1)
						inout[2] = 1;
					if(inout[3] < 1)
						inout[3] = 1;
					if(inout[4] < 1)
						inout[4] = 1;
					if(inout[5] < 1)
						inout[5] = 1;
				}
				else if(x == 30) {
					if(inout[3] < 1)
						inout[3] = 1;
					if(inout[5] < 1)
						inout[5] = 1;
					if(inout[2] < 1)
						inout[2] = 1;
				}
				else {
					if(x%4 == 0) {
						if((int)(Math.random()*100)%2 == 0)
							unprocessed.add(2);
						else unprocessed.add(4);
					}
					else if(x%2 == 0) unprocessed.add(2);
					if(x%3 == 0) unprocessed.add(3);
					if(x%5 == 0) unprocessed.add(5);
				}
			}

			ArrayList<Integer> out = new ArrayList<Integer>();

			for(int i=0; i<inout.length; ++i) {
				if(out.size() < n && inout[i] > 0) {
					out.add(i);
					--inout[i];
					--i;
				}
			}

			while(out.size() < n && unprocessed.size() > 0) {
				int idx = 0 + (int)(Math.random() * ((unprocessed.size() - 0) + 1));
				if(idx >= unprocessed.size()) idx = unprocessed.size()-1;
				if(idx < 0) idx = 0;
				int val = unprocessed.get(idx);
				out.add(val);
				// unprocessed.remove(idx);
			}

			while(out.size() < n) {
				out.add(2 + (int)(Math.random() * ((m - 2) + 1)));
			}

			for(int i=0; i<out.size(); ++i) {
				System.out.print(out.get(i));
			}
			System.out.println();
		}


	}
}