import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class BFF {
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("C-small-attempt4.in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=numCases;c++) {
			int n = Integer.parseInt(s.nextLine());
			int[] bff = new int[n+1];
			String friendLine = s.nextLine();
			String[] friendArr = friendLine.split("\\s+");
			for(int i = 1;i<=n;i++) {
				int friendID = Integer.parseInt(friendArr[i-1]);
				bff[i] = friendID;
				
			}
			System.out.println("Case #" + c + ": " + countPerms(bff));
		}
	}
	public static int countPerms(int[] bff) {
		
		int max = 0;
		for(int start = 1;start<bff.length;start++) {
			boolean[] marked = new boolean[bff.length];
			int[] seq = new int[bff.length];
			seq[0] = start;
			marked[start] = true;
			//seq[1] = bff[start];
			//marked[bff[start]] = true;
			
			int val = getMax(seq,bff,marked,1);
			if(val>max) {
				max = val;
			}
		}
		return max;
	}
	
	public static boolean check(int[] soFar, int[] bff, int count) {
		boolean result = true;
		for(int i = 0;i<count;i++) {
			int child = soFar[i];
			int friend = bff[child];
			if(friend != soFar[(i+1)%count] && friend != soFar[(i-1+count)%count]) {
				/*System.out.println("INVALID");
				System.out.println(Arrays.toString(soFar));
				System.out.println(Arrays.toString(bff));
				System.out.println(count);
				System.exit(1);*/
				result = false;
			}
		}
		return result;
	}
	
	public static int getMax(int[] soFar, int[] bff, boolean[] marked, int count) {
		
		//System.out.println(Arrays.toString(soFar) + " " + count);
		
		int lastFriend = soFar[count-1];
		
			if(count > 1 && soFar[count-2] != bff[lastFriend]) { //if the last guy is not sitting next to their bff
				if(!marked[bff[lastFriend]]) { //if the bff hasn't already been added
					count++;
					soFar[count-1] = bff[lastFriend]; 
					marked[bff[lastFriend]] = true;
					
					int result = getMax(soFar,bff,marked,count);
					soFar[count-1] = 0;
					marked[bff[lastFriend]] = false;
					return result;
				} else {
					if(bff[lastFriend] == soFar[0]) {
						//System.out.println("SUCCESS RETURNING " + count);
						if(check(soFar,bff,count)) {
							//System.out.println("VALID " + Arrays.toString(soFar) + " " + count);
							return count;
						} else {
							//System.out.println("INVALID " + Arrays.toString(soFar) + " " + Arrays.toString(bff) + " " + count);
							return 0;
						}
					} else {
						//System.out.println("NO FRIEND FOR " + lastFriend);
						return 0;
					}
				}
			} else { //the last guy is already sitting next to their bff
				
				
				int max = 0;
				if(check(soFar,bff,count)) {
					max = count;
				}
				for(int i = 1;i<bff.length;i++) {
					if(!marked[i]) {
						count++;
						soFar[count-1] = i;
						marked[i] = true;
						int val = getMax(soFar,bff,marked,count);
						marked[i] = false;
						count--;
						soFar[count] = 0;
						if(val > max) {
							max = val;
						}
					}
				}
				//System.out.println("SUCESS RETURNING " + max);
				return max;
			}
		
		
		
		
	}
	
}
