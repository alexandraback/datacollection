import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;


public class C {
	public static void main(String args[])throws IOException{
		Scanner scan = new Scanner(new File("C.txt"));
		PrintWriter pw = new PrintWriter("C.out");
		int cases= scan.nextInt();
		for(int i = 1; i <= cases; i++){
			int kids = scan.nextInt();
			
			int[]vals = new int[kids];
			int[]pos = new int[kids];
			for(int l = 0; l < kids; l++){
				vals[l] = scan.nextInt();
			}
			boolean visited[] = new boolean[kids];
			int p = vals[0];
			int counter = 1;
			for(int z = 0; z < kids; z++){
				if(p==1){
					if(visited[1]==false){
						visited[1]=true;
						p = vals[1];
						counter++;
					}
					else if(visited[kids-1]==false){
						visited[kids-1]=true;
						p = vals[kids-1];
						counter++;
					}
				}
				else if(p==kids){
					if(visited[0]==false){
						visited[0]=true;
						p = vals[0];
						counter++;
					}
					else if(visited[kids-2]==false){
						visited[kids-2]=true;
						p = vals[kids-2];
						counter++;
					}
				}
				else if(visited[p-2]==false){
					visited[p-2]=true;
					p = vals[p-1];
					counter++;
				
				}
				else if(p<kids - 2 && visited[p+2]==false){
					visited[p+2]=true;
					p = vals[p+1];
					counter++;
				
				}
				else{
					break;
				}
			}
			if(counter>kids){
				counter = kids;
			}
			pw.printf("Case #%d: %d",i,counter);
			pw.println();
		}
		pw.close();
	}
}