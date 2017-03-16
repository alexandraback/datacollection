import java.util.*;

public class Main {
	public static int[] array = {1, 4, 9, 121, 484};
    public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		
		int t = s.nextInt(), c = 1;
		while (c <= t) {
			int n = s.nextInt();
			int m = s.nextInt();
			
			int count = func(n, m);
			System.out.println("Case #" + (c++) + ": " + count);
		}
	}
    
    public static int func(int start, int end) {
    	int count = 0; 
    	for (int i = 0; i < array.length; i++){
    		if (array[i] >= start && array[i] <= end) {
    			count++;
    		}
    	}
    	return count;
    }
}