package codeRound1A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class C {
	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		
		int caseCnt = sc.nextInt();sc.nextLine();
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			StringBuilder sb = new StringBuilder();
			System.out.println(caseNum);
			
			int N = sc.nextInt();
			long[] set = new long[N];
//			long[][] inter = new long[N][N];
			for(int i=0;i<N;i++) {
				set[i]=sc.nextLong();
			}
//			for(int i=1;i<N;i++){
//				for(int j=0;j<N-i;j++) {
//					inter[i][j]=inter[i-1][j]+inter[0][j+i];
//				}
//			}
			HashMap<Long, LinkedList<Long>> result = new HashMap<Long, LinkedList<Long>>();
			outerloop:
			for(int i=1;i<=N;i++) {
				int[] indice = new int[i];
				for(int j=0;j<i;j++) {
					indice[j]=j+1;
				}
				while(indice[0]<N-i) {
					if(indice[i-1]==N) {
						int offset=N-2;
						for(int j=i-2;j>=0;j--) {
							if(indice[j]!=offset--) {
								int test=indice[j];
								for(int k=j;k<=i-1;k++) {
									indice[k]=++test;
								}
							}
						}
					}
					long interm=0;
					LinkedList<Long> list = new LinkedList<Long>();
					for(int j : indice) {
						System.out.println(j);
						list.add(set[j]);
						interm+=set[j];
					}
					if(result.containsKey(interm)) {
						sb.append("\n");
						for(long l : list)
							sb.append(l+" ");
						sb.append("\n");
						for(long l : result.get(interm))
							sb.append(l+" ");
						break outerloop;
					} else {
						result.put(interm, list);
					}
					indice[i-1]++;
				}
			}
//			ArrayList<ArrayList<Long>> result = new ArrayList<ArrayList<Long>>();
//			ArrayList<Long> list = new ArrayList<Long>();
//			for(int i=0;i<N;i++) {
//				list.add(set[i]);
//			}
//			for(int i=1;i<N;i++) {
//				for(int j=0;j<result.get(i-1).size()*(N-i)/(i+1);j++) {
//					(j/(N-j/N))
//				}
//			}
			if(sb.length()==0)
				sb.append("impossible");
			pw.println("Case #" + caseNum + ": " + sb.toString());
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
}
