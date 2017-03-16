package magictrick;

import java.util.Scanner;

public class Opera {
	public static void main(String[] args){
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();

		for (int i = 0;i<T ;i++){
			
			int t = in.nextInt();
			String a = in.next();
			int[] aud = new int[t+1];
			
			for (int n =0; n < t + 1; n++){
				aud[n] =((int) a.charAt(n))-48;
		//		System.out.println("char = " + a.charAt(n));
		//		System.out.println(aud[n]);
			}
			

			
			
			int ans = friends(aud);
			
			//ArrayList am = new ArrayList();
			//System.out.format("Case #%d: %f\n",i+1 , time);
			//check if arrays are equal: Arrays.equals(ar, arr)
			System.out.println("Case #" + (i+1) + ": " + ans);
		
	}
}


public static int checkInt(int ind, int[] aud){
	int fri = 0;
	int standing = 0;
	
	for (int i = 0; i < ind; i++){
		standing += aud[i];
	}
	
	if (ind > standing)
	fri = ind - standing;
	
	return fri;
}

public static int friends(int[] aud){
	int fri = 0;
	
	for (int i = 1; i < aud.length; i++){
		int ans = checkInt(i, aud);
		fri += ans;
		aud[0] = aud[0] + ans;
	}
	
	return fri;
}

}