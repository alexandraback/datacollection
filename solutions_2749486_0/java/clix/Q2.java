package round_1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Q2 {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileReader buf = new FileReader("C:\\Users\\bond\\Desktop\\input.in");
		BufferedReader br = new BufferedReader(buf);
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		String[] outputs=new String[cases];
		for(int i=1;i<=cases;i++){
			String[] inp=br.readLine().split(" ");
			int x=Integer.parseInt(inp[0]);
			int y=Integer.parseInt(inp[1]);
			String out="";
			if(x>0){
				while(x!=0){
				out+="WE";
				x--;
				}
			}
			else if(x<0){
				while(x!=0){
				out+="EW";
				x++;
				}
			}
			
			if(y>0){
				while(y!=0){
				out+="SN";
				y--;
				}
			}
			else if(y<0){
				while(y!=0){
				out+="NS";
				y++;
				}
			}
			outputs[i-1]="Case #" + i + ": " + out+ "\n";
		}
		br.close();
		buf.close();
		FileWriter buf1 = new FileWriter(new File("C:\\Users\\bond\\Desktop\\OutputDance1.txt"), true);
		BufferedWriter bw1 = new BufferedWriter(buf1);
		for (int i = 0; i < cases; i++) {
			bw1.write(outputs[i]);
		}
		bw1.close();
		buf1.close();
		
		/*for (int i = 0; i < cases; i++) {
		System.out.println(outputs[i]);
		}		
*/
	}

}
