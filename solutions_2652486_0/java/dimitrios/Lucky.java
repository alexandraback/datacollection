 public class Lucky {

 	public static void main(String[] args) {
 		java.util.Scanner sc = new java.util.Scanner(System.in);
 		final int LIM = 5;
 		int T = sc.nextInt(),	// always equals to 1
 			R = sc.nextInt(),
 			N = sc.nextInt(),
 			M = sc.nextInt(),
 			K = sc.nextInt();
 		System.out.println("Case #1:");
 		great:
 		for(int t=1; t<=R; t++) {
 			int n = 0;
 			int[] gar = new int[LIM+1];
 			//Vector<Vector<Integer>> f = new Vector<Vector<Integer>>();
 			for(int k=0; k<K; k++) {
 				int p = sc.nextInt();
 				if(p==1) continue;
 				int[] g = new int[LIM+1];
 				while(p>1) {
 					if(p%3==0) { p = p/3; g[3]++; }
 					else if(p%5==0) { p = p/5; g[5]++; }
 					else if(p%4==0) { p = p/4; g[4]++; }
 					else if(p%2==0) { p = p/2; g[2]++; }
 				}
 				for(int i=2; i<=LIM; i++) {
 					if(gar[i]<g[i]) gar[i] = g[i];
 				}
 			}
 			int sum = 0;
 			for(int i=2; i<=LIM; i++) sum+= gar[i];
 			int r = N;
 			r-= sum;
			switch(r) {
			case 0:
				System.err.println("Exact match:");
				output(gar);
				break;
			case 1:
				if(gar[4]>0) {
					gar[4]--;
					gar[2]+= 2;
					System.err.println("Split 4 to 2+2");
				} else {
					gar[2]++;
					System.err.println("Suppose there was a 2");
				}
				output(gar);
				break;
			case 2: case 3:
				while(gar[4]>0) {
					gar[4]--; r--;
					gar[2]+= 2;
					System.err.println("Split 4 to 2+2");
				}
				while(r>0) {
					gar[2]++; r--;
					System.err.println("Suppose there was a 2");
				}
				output(gar);
				break;
			}
 		}
 	}

 	public static void output(int[] data) {
 		for(int i=2; i<data.length; i++)
 			for(int k=0; k<data[i]; k++)
 				System.out.print(i);
 		System.out.println();
 	}

 }