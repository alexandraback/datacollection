import java.util.Scanner;


public class Jam2016_QB {
	public static void print(char[] d) {
		for(char b: d) {
			System.out.print((char)b + " ");
		}
		System.out.println();
	}
	
	public static char r(char b){
		return (char)((b == '+') ? '-' : '+');
	}
	
	public static int findHappyEnd(char[] arr) {
		int idx = -1;
		for(char b: arr){
			if(b == '-')
				break;
			idx++;
		}
		
		return idx;
	}
	
	public static void reverse(char[] arr, int start, int end) {
//		if(start == end)
		int half = (end - start + 1)/2;
		int red = (end - start + 1)%2;
		for(int i=0; i<half; ++i) {
			char tmp = arr[end - i];
			arr[end - i] = r(arr[start + i]);
			arr[start + i] = r(tmp);
		}
		
		if(red != 0)
			arr[start + half] = r(arr[start + half]);
	}
	
	public static int solve(String str) {
		int cnt = 0;
		char[] carr = str.toCharArray();
		
//		System.out.println(str);
		
		int len = carr.length;
		for(int i = len-1; i>=0; --i){
			// find empty side
			if(carr[i] != '-')
				continue;
			
//			print(carr);
			
			// find happy side list from start
			int idx = findHappyEnd(carr);
//			System.out.println(i + ", " + idx);
			if(idx >= 0 && idx<i) {
				// flip head
				reverse(carr, 0, idx);
				cnt++;
			}
			
//			print(carr);

			// flip tail.
			reverse(carr, 0, i);
			cnt++;
		}
			
		return cnt;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Jam2016_QB	inst	= new Jam2016_QB();
			String str		= scanIn.next();
			
			int ret = inst.solve(str);
			
			System.out.println("Case #" + (i+1) + ": " + ret);
		}
		
		scanIn.close();
	}
}
