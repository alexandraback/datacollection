import java.util.Scanner;


public class Test1 {
	int solve(int n, String list) {
		int[]	iList	= new int[n+1];
		
		for(int i=0; i<n+1; ++i) {
			iList[i]	= list.charAt(i+1) - '0';
		}
		return	solveSub(n, iList);
	}
	
	int solveSub(int n, int[] list) {
		int	sMax	= 0;
		int	sCur	= 0;
		int	fCur	= 0;
		
		sMax	= n;
		for(int i=0; i<n+1; i++) {
			if(sCur >= sMax)
				break;
			
			if(i > sCur) {
				fCur++;
				sCur++;
			}
			
			sCur	+= list[i];
		}
		
		return	fCur;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Test1	inst	= new Test1();
			int		n		= scanIn.nextInt();
			
			String	str		= scanIn.nextLine();
			
			int	ret	= inst.solve(n, str);
			
			System.out.println("Case #" + (i+1) + ": " + ret);
		}
		
		scanIn.close();
	}
}
