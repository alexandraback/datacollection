 public class Lucky {

 	public static void main(String[] args) {
 		java.util.Scanner sc = new java.util.Scanner(System.in);
 		final int LIM = 8;
 		int T = sc.nextInt(),	// always equals to 1
 			R = sc.nextInt(),
 			N = sc.nextInt(),
 			M = sc.nextInt(),
 			K = sc.nextInt();
 		System.out.println("Case #1:");
 		int exact = 0;
 		great:
 		for(int t=1; t<=R; t++) {
 			int n = 0;
 			int[] gar = new int[LIM+1];
 			//Vector<Vector<Integer>> f = new Vector<Vector<Integer>>();
 			for(int k=0; k<K; k++) {
 				long p = sc.nextLong();
 				if(p==1) continue;
 				int[] g = new int[LIM+1];
 				while(p>1) {
 					if(p%6==0) { p = p/6; g[6]++; }
 					else if(p%3==0) { p = p/3; g[3]++; }
 					else if(p%5==0) { p = p/5; g[5]++; }
 					else if(p%7==0) { p = p/7; g[7]++; }
 					else if(p%8==0) { p = p/8; g[8]++; }
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
			if(r==0) {
				System.err.println("Exact match:");
				exact++;
				output(gar);
			} else {
				while(gar[8]>0 && r>0) {
					gar[8]--; r--;
					gar[2]++; gar[4]++;
					System.err.println("Split 8 to 2*4");
				}
				while(gar[6]>0 && r>0) {
					gar[6]--; r--;
					gar[2]++; gar[3]++;
					System.err.println("Split 6 to 2*3");
				}
				while(gar[4]>0 && r>0) {
					gar[4]--; r--;
					gar[2]+= 2;
					System.err.println("Split 4 to 2*2");
				}
				while(r>0) {
					gar[2]++; r--;
					System.err.println("Suppose there was a 2");
				}
				output(gar);
			}
 		}
 		System.err.printf("Exact matches: %d / 8000 (%.2f%%)", exact, (float)exact/R);
 	}

 	public static void output(int[] data) {
 		for(int i=2; i<data.length; i++)
 			for(int k=0; k<data[i]; k++)
 				System.out.print(i);
 		System.out.println();
 	}

 }