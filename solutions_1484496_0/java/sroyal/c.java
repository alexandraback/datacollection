import java.util.*;
public class c{
	public static int n;
	public static int[] nums;
	public static ArrayList<Integer> one, two;
	public static boolean found;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int cases = br.nextInt();
		for(int c = 0;c<cases;c++){
			n = br.nextInt();
			nums = new int[n];
			for(int i = 0;i<n;i++){
				nums[i] = br.nextInt();
			}
			one = new ArrayList<Integer>();
			two = new ArrayList<Integer>();
			found = false;
			go(new Stack<Integer>(), new Stack<Integer>(), 0, 0, 0);
			System.out.println("Case #"+(c+1)+":");
			if(!found){
				System.out.println("Impossible");
			}
			else{
				for(int i = 0;i<one.size();i++){
					System.out.print(one.get(i)+" ");
				}
				System.out.println();
				for(int i = 0;i<two.size();i++){
					System.out.print(two.get(i)+" ");
				}
				System.out.println();
			}
		}
	}
	public static void go(Stack<Integer> o, Stack<Integer> t, int pos, int s1, int s2){
		if(found){
			return;
		}
		if(pos == n){
			if(s1 == s2 && s1 != 0){
				for(int x : o){
					one.add(x);
				}
				for(int x : t){
					two.add(x);
				}
				found = true;
			}
			return;
		}
		o.push(nums[pos]);
		go(o, t, pos+1, s1+nums[pos], s2);
		o.pop();
		t.push(nums[pos]);
		go(o, t, pos+1, s1, s2+nums[pos]);
		t.pop();
		go(o, t, pos+1, s1,s2);
	}
}