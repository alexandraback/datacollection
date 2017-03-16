import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Round1CQuestion1 {
	public static void main(String[] args) {
				
		try{
			FileInputStream fstream = new FileInputStream("C:\\Users\\Aries\\workspace\\Codejam\\inout\\A-small-attempt0-5.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			
			FileWriter fostream = new FileWriter("C:\\Users\\Aries\\workspace\\Codejam\\inout\\A-small-attempt0-5.out");
			BufferedWriter out = new BufferedWriter(fostream);
			
			strLine = br.readLine();
			Integer t = Integer.parseInt(strLine);
			for (int i=0;i<t;i++){
				System.out.println("Case "+(i+1));
				String line1 = br.readLine();
				StringTokenizer st = new StringTokenizer(line1);
				String w = st.nextToken();
				Integer n = Integer.parseInt(st.nextToken());
				int ans = 0;
				for (int j=0;j<w.length();j++){
					for (int k=j+1;k<=w.length();k++){
						String ww = w.substring(j,k);
//						System.out.println(ww);
						int cc = 0;
						for (int l=0;l<ww.length();l++){
							if (ww.charAt(l)=='a' ||ww.charAt(l)=='e' ||ww.charAt(l)=='i' ||ww.charAt(l)=='o' ||ww.charAt(l)=='u'){
								cc = 0;
							} else {
								cc++;
							}
							if (cc>=n){
								ans++;
								break;
							}
						}
					}
				}
				
				out.write("Case #"+(i+1)+": "+ans);
				if (i!=t-1){
					out.newLine();
				}
			}
			in.close();
			out.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	
}

