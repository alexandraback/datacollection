import java.util.*;

class QC{

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int kase = sc.nextInt();
		for(int k = 1; k<=kase; k++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			int count = 0;
			for(int x= A; x<B; x++){
				int[] cyc = new int[Integer.toString(x).length()];
				int m = 10;
				for(int i = 0; i<cyc.length; i++){
					cyc[i] = Integer.parseInt((x%m)+""+x/m);
					m= m*10;
				}
				Arrays.sort(cyc);
				for(int i = 0; i<cyc.length; i++){
					if(cyc[i]>x && cyc[i] <=B && (i==0 || cyc[i]!=cyc[i-1])) count++;
				}
			}
			System.out.println("Case #"+k+": "+count);
		}
	}
}
