import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Main {

    
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\D-small-attempt0.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\output.txt"));
		int T=scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			int y=0;int z=0;
			int N=scanner.nextInt();
			double[] Naomi=new double[N];
			for (int j = 0; j < N; j++) {
				Naomi[j]=scanner.nextDouble();
			}
			double[] Ken=new double[N];
			for (int j = 0; j < N; j++) {
				Ken[j]=scanner.nextDouble();
			}
			Arrays.sort(Naomi);
			Arrays.sort(Ken);
			int index=N-1;
			for (int j = N-1; j >=0; j--) {
				while(index>=0){
					if (Ken[index]>Naomi[j]) {
						y++;
						index--;
						continue;
					}
					else {
						index--;
						break;
					}
				}
			}
			y=N-y;
			boolean[] fired=new boolean[N];
			Arrays.fill(fired, false);
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (Naomi[j]>Ken[k]) {
						continue;
					}
					else {
						if (!fired[k]) {
							fired[k]=true;
							z++;
							break;
						}
						else {
							for (int k2 = k+1; k2 < N; k2++) {
								if (!fired[k2]) {
									fired[k2]=true;
									z++;
									break;
								}
							}
							break;
						}
					}
				}
			}
			z=N-z;
			printWriter.println("Case #"+i+": "+y+" "+z);
						
		}
		printWriter.close();
	}	 	 
}

