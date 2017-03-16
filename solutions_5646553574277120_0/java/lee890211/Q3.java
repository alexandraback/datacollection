import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;

public class Q3 {
	public static void main(String[] args) {
		try {
			Scanner sc = new Scanner(new FileInputStream(new File("C-small-attempt2.in")));
			BufferedWriter bos = new BufferedWriter(new FileWriter(new File("C-small-attempt2.out")));
			int cNum = Integer.parseInt(sc.nextLine());
			for (int i = 0; i < cNum; i++) {
				String[] nums = sc.nextLine().split(" ");
				int C = Integer.parseInt(nums[0]);
				int D = Integer.parseInt(nums[1]);
				int V = Integer.parseInt(nums[2]);
				
				nums = sc.nextLine().split(" ");
				
				int[] denominations = new int[nums.length];
				for (int d=0; d<nums.length; d++) {
					denominations[d] = Integer.parseInt(nums[d]);
				}
				
				boolean[] mem = new boolean[V+1];
				mem[0] = true;
				int max = 0;
				for (int d=0; d<nums.length; d++) {
					max = max+denominations[d];
					for (int v=denominations[d]; v<=max&&v<=V; v++) {
//						System.out.println(i+ " "+denominations[d]+" "+d+" "+v+" "+max);
						if (mem[v-denominations[d]]) mem[v] = true;
					}
				}
				
				int required = 0;
				int newDenom = 0;
				while ((newDenom = findNewDenom(mem, V)) != -1) {
					required ++;
//					System.out.println(i+ " "+newDenom);
					for (int v=V; v>=newDenom; v--) {
						if (mem[v-newDenom]) mem[v] = true;
					}
				}
				
				bos.write(String.format("Case #%d: %d\n", i + 1, required));
				bos.flush();
			}
			sc.close();
			bos.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static int findNewDenom(boolean[] mem, int to) {
		for (int i=0; i<=to; i++) {
//			System.out.println(mem[i]);
			if (!mem[i]) return i;
		}
		return -1;
	}
}
