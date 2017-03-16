import java.util.*;
import java.io.*;

public class SafetyNumbers {
	
	// Variables preprocess
	

    static void preprocess() {
        
    }

    void solve(Scanner sc, PrintWriter pw) {
		int N = sc.nextInt();
		float[] scores = new float[N];
		float somme=0;
		for(int i=0;i<N;i++){
			scores[i]=sc.nextFloat();
			somme+=scores[i];
		}
		float tri[] = scores.clone();
		Arrays.sort(tri);
		for(int i=0;i<N;i++){
			float n = scores[i];
			int c = 0;
			float y = 1;
			float add=0;
			while(tri[c]<n){
				y-=(n-tri[c])/somme;
				if(y<=0){
					pw.print(" ");
					pw.print("0.0");
					break;
				}
				c++;
			}
			c++;
			if(y>0){
				while(true){
					if(c==N){
						add+=y/N;
						pw.print(" ");
						pw.print(100*add);
						break;
					}
					float temp =c*(tri[c]-tri[c-1])/somme;
					if(y-temp<0){
						add+=y/c;
						pw.print(" ");
						pw.print(100*add);
						break;
					}
					else{
						add+=temp/c;
						y-=temp;
						c++;
					}
				}
			}
		}
        pw.println();
    }

    public static void main(String[] args) throws Exception {
        preprocess();

        Scanner sc = new Scanner(new FileReader("input.txt"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ":");
            new SafetyNumbers().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
