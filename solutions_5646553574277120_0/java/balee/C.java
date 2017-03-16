import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class C {

	static void subsetsAll(int[] items, boolean[] states, int index, int[] values) {
		if ( index == states.length ) {
			int sum = 0;
			for(int i = 0; i < index; i++)
				if ( states[i] )
					sum += items[i];
			if ( sum < values.length )
				values[sum] = 0;
		}
		else { 
			states[index] = true;
			subsetsAll(items, states, index + 1, values);
			states[index] = false;
			subsetsAll(items, states, index + 1, values);
		}
	}	
	
	private static String process(Scanner in) {
		
		int C = in.nextInt();
		int D = in.nextInt();
		int V = in.nextInt();
		
		int values[] = new int[V+1]; // pff
		for(int i = 0; i <= V; i++)
			values[i] = i;

		int[] items = new int[D];
		boolean[] states = new boolean[D];
		for(int i = 0; i < D; i++)
			items[i] = in.nextInt();
		
		subsetsAll(items, states, 0, values);

		//System.out.println(Arrays.toString(values));
		
		int result = 0;

		for(int i = 1; i <= V; i++) {
			if ( values[i] != 0 ) {
				result++;
				for(int j = V; j >= 1; j--)
					if ( values[j] == 0 && j + values[i] < values.length )
						values[j + values[i]] = 0;
				//System.out.println(Arrays.toString(values));
				values[i] = 0;
			}
		}
		
		return Integer.toString(result);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
