import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class ProblemC {
	
	static final String 	ID 			= ProblemC.class.getSimpleName().replaceFirst("Problem([A-Z])", "$1");
	static final boolean 	SMALL_SET 	= true;
	
	static void solve(Scanner scanner, StringBuilder builder) {
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		
		long[] a = new long[N];
		int[] A = new int[N];
		long[] b = new long[M];
		int[] B = new int[M];
		
		scanner.nextLine();
		for(int idx = 0; idx < N; idx++) {
			a[idx] = scanner.nextLong();
			A[idx] = scanner.nextInt();
		}
		
		boolean matches = false;
		
		scanner.nextLine();
		for(int idx = 0; idx < M; idx++) {
			b[idx] = scanner.nextLong();
			B[idx] = scanner.nextInt();
			
			if(!matches) {
				for(int tA : A) if(B[idx] == tA) { matches = true; break; }
			}
		}
		
		long result = 0;
		if(matches) {
			ST thAll = new ST(N, M, a, b, A, B, 0, 0);
			thAll.start();
			try { thAll.join(); } catch(Exception e) { e.printStackTrace(); }
			result = thAll.result;
			
//			while(ia < N && ib < M) {
//				int cntA = a[ia];
//				if(cntA <= 0) { ia++; continue; }
//				int cntB = b[ib];
//				if(cntB <= 0) { ib++; continue; }
//				
//				int tA = A[ia];
//				int tB = B[ib];
//				
//				if(tA == tB) {
//					int add = Math.min(cntA, cntB);
//					result += add;
//					
//					a[ia] -= add;
//					b[ib] -= add;
//					System.out.println("Added " + add + "["+tA+"]");
//				} else {
//					int rankA = 0;
//					int rankB = 0;
//					for(int i = ia; i < N; i++) if(A[i] == tA) rankA += a[i];
//					for(int i = ib; i < M; i++) if(B[i] == tB) rankB += b[i];
//					
//					System.out.println("Rank A"+rankA+"["+tA+"]" + " B"+rankB+"["+tB+"]");
//					if(rankA > rankB) {
//						System.out.println("Dropped " + b[ib] + " B" + tB);
//						b[ib] = 0;
//						continue;
//					} else if(rankB > rankA) {
//						System.out.println("Dropped " + a[ia] + " A" + tA);
//						a[ia] = 0;
//						continue;
//					}
//					
//					int distAtoB = -1;
//					for(int i = ib + 1; i < M; i++) if(B[i] == tA) { distAtoB = i - ib; break; }
//					int distBtoA = -1;
//					for(int i = ia + 1; i < N; i++) if(A[i] == tB) { distBtoA = i - ia; break; }
//					
//					System.out.println("Dist A["+tA+"]" + distAtoB + " to B["+tB+"]" + distBtoA);
//					if(distAtoB == -1) {
//						System.out.println("Dropped " + a[ia] + " A" + tA);
//						a[ia] = 0;
//					} else if(distBtoA == -1) {
//						System.out.println("Dropped " + b[ib] + " B" + tB);
//						b[ib] = 0;
//					} else if(distAtoB == distBtoA) {
//						if(a[ia+distAtoB] > b[ib+distBtoA]) {
//							System.out.println("Dropped " + b[ib] + " B" + tB);
//							b[ib] = 0;
//						} else {
//							System.out.println("Dropped " + a[ia] + " A" + tA);
//							a[ia] = 0;
//						}
//					} else if(distAtoB > distBtoA) {
//						System.out.println("Dropped " + a[ia] + " A" + tA);
//						a[ia] = 0;
//					} else {
//						System.out.println("Dropped " + b[ib] + " B" + tB);
//						b[ib] = 0;
//					}
//				}
//			}
		}
		
		builder.append(result);
	}
	
	static class ST extends Thread {
		volatile long result = 0;
		final long[] a;
		final long[] b;
		final int[] A;
		final int[] B;
		int ia;
		int ib;
		final int N;
		final int M;
		ST(int N, int M, long[] a, long[] b, int[] A, int[] B, int ia, int ib) { 
			this.N = N; this.M = M; this.a = a; this.b = b; this.A = A; this.B = B; this.ia = ia; this.ib = ib;
//			System.out.println("Thread from A" + ia + " B" + ib);
		}
		
		public void run() {
			while(ia < N && ib < M) {
				long cntA = a[ia];
				if(cntA <= 0) { ia++; continue; }
				long cntB = b[ib];
				if(cntB <= 0) { ib++; continue; }
				
				int tA = A[ia];
				int tB = B[ib];
				
				if(tA == tB) {
					long add = Math.min(cntA, cntB);
					result += add;
					
					a[ia] -= add;
					b[ib] -= add;
//					System.out.println("Added " + add + "["+tA+"]");
				} else {
					boolean doA = false;
					ST thA = null;
					for(int i = ia + 1; i < N; i++) if(A[i] == tB) { doA = true; break; }
					if(doA) {
						long[] acl = a.clone();
						acl[ia] = 0;
						thA = new ST(N, M, acl, b.clone(), A.clone(), B.clone(), ia+1, ib);
						thA.start();
					}
					
//					boolean doB = false;
					ST thB = null;
//					for(int i = ib + 1; i < M; i++) if(B[i] == tA) { doB = true; break; }
//					if(doB) {
						long[] bcl = b.clone();
						bcl[ib] = 0;
						thB = new ST(N, M, a.clone(), bcl, A.clone(), B.clone(), ia, ib+1);
						thB.start();
//					}
					
					try {
						if(thA != null) thA.join();
						if(thB != null) thB.join();
					} catch(Exception e) { e.printStackTrace(); }
					
					this.result += Math.max(thA != null ? thA.result : 0, thB != null ? thB.result : 0);
					break;
				}
			}
		}
	};
	
	static String problemName()	{ return ID + "-" + (SMALL_SET ? "small" : "large"); }
	static String inFilename() 	{ return problemName() + ".in"; }
	static String outFilename()	{ return problemName() + ".out"; }
	
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new File(inFilename()))) {
			try (BufferedWriter writer = new BufferedWriter(new FileWriter(outFilename()))) {
				int numCases = scanner.nextInt();
						
				long tm = System.currentTimeMillis();
				StringBuilder builder = new StringBuilder();
				for(int caseIdx = 0; caseIdx < numCases; caseIdx++) {
					builder.setLength(0);
					scanner.nextLine();
					
					solve(scanner, builder);
					
					String caseOutput = String.format("Case #%d: %s", caseIdx + 1, builder.toString());
					
					System.out.println(caseOutput);
					writer.append(caseOutput);
					writer.newLine();
				}
				System.out.println("Finished in " + ((System.currentTimeMillis() - tm) / 1000) + " seconds");
			}
		} catch(Throwable scannerEx) {
			scannerEx.printStackTrace();
		}
	}

}
