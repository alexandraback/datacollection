import java.util.*;

public class Round1BC {
	public static ArrayList[] al;
	public static int[] arr;
	public static boolean toReturn;
	
	public static void select(int curr, int chosen, int amount, int sum, String list){
		if(toReturn){
			return;
		}
		
		if(chosen == amount){
			if(al[sum].size() > 0){
				System.out.println(al[sum].get(0).toString().trim());
				System.out.println(list.trim());
				toReturn = true;
			}else{
				al[sum].add(list);
			}
		}else{
			for(int i=curr; i<20; i++){
				select(i+1, chosen+1, amount, sum+arr[i], list + " " + arr[i]);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for(int i=0; i<t; i++){
			System.out.println("Case #" + (i+1) + ":");
			
			int n = sc.nextInt();
			
			arr = new int[n];
			
			for(int j=0; j<n; j++){
				arr[j] = sc.nextInt();
			}
			
			al = new ArrayList[2000001];
			toReturn = false;
			
			for(int j=0; j<2000001; j++){
				al[j] = new ArrayList<String>();
			}
			
			for(int j=0; j<20; j++){
				select(0, 0, j, 0, "");
			}
		}
	}
}
