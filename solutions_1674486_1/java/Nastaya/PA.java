import java.io.*;
import java.util.*;
import java.text.*;

public class ProblemA {

	public static void main(String[] args) {
		try {
			new ProblemA().solve();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	boolean[][] grid;
	int[] twoormores;
	
    public void solve() throws IOException {
	System.setIn(new FileInputStream("D:\\inputA.in"));
    	Scanner scan = new Scanner(System.in);
    	PrintWriter out = new PrintWriter(System.out);

    	int T = scan.nextInt();
    	for (int i=0;i<T;i++) {
    		int N = scan.nextInt();
    		grid = new boolean[N][N];
    		twoormores = new int[N];
    		
    		for (int j=0;j<N;j++) {
    			int H = scan.nextInt();
    			if (H == 0) continue;
    			
    			for (int k=0;k<H;k++) {
    				int temp = scan.nextInt();
    				grid[j][temp - 1] = true;
    				twoormores[j]++;
    			}
    		}
    		
    		boolean yes = false;
    		for (int j=0;j<N;j++) {
    			if (twoormores[j] >= 2) {
    				if (scanGrid(j)) {
    					yes = true;
    					break;
    				}
    			}
    		}
    		
    		if (yes) {
    			out.println("Case #"+(i+1)+": Yes");
    		} else {
    			out.println("Case #"+(i+1)+": No");
    		}
    	}
    	

		out.flush();
		out.close();
		scan.close();
    }

    private boolean scanGrid(int row) {
    	boolean[] state = new boolean[grid.length];
    	
    	state[row] = true;
    	List<Integer> list = new ArrayList<Integer>();
    	for (int i=0;i<grid.length;i++) {
    		if (!grid[row][i]) continue;
    		
    		state[i] = true;
    		list.add(i);
    	}
    	
    	while (list.size() > 0) {
    		row = list.get(0);
    		list.remove(0);
    		
    		for (int i=0;i<grid.length;i++) {
        		if (!grid[row][i]) continue;
        		
        		if (state[i]) return true;
        		state[i] = true;
        		list.add(i);
        	}
    	}
    	
    	return false;
    }

}
