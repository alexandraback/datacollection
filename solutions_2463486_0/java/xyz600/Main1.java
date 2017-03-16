import java.util.*;

class Main {

    public static void main(String[] args){

	final Scanner stdin = new Scanner(System.in);
	final int T = stdin.nextInt();

	for(int t = 1; t <= T; t++){
	    long start = stdin.nextLong();
	    long end = stdin.nextLong();

	    solve(start, end, t);
	}
    }

    static void solve(long start, long end, int t){
	long squaredStart = (long)(Math.ceil(Math.sqrt(start)));
	long squaredEnd = (long)(Math.sqrt(end));

	int count = 0;
	for (long i = squaredStart; i <= squaredEnd; i++){
	    if (isPalindrome(i) && isPalindrome(i * i)){
		//System.out.printf("hit! %d and %d\n", i, i * i);
		count++;
	    }
	}
	System.out.printf("Case #%d: %d\n", t, count);
    }

    static boolean isPalindrome(long l){
	final String numStr = Long.toString(l);
	final int digit = numStr.length();
	for (int i = 0; i < digit; i++){
	    if (numStr.charAt(i) != numStr.charAt(digit - 1 - i)){
		return false;
	    }
	}
	return true;
    }    
}
