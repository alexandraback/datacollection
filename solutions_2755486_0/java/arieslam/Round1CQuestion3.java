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


public class Round1CQuestion3 {
	public static void main(String[] args) {
				
		try{
			FileInputStream fstream = new FileInputStream("C:\\Users\\Aries\\workspace\\Codejam\\inout\\C-small-attempt1.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			
			FileWriter fostream = new FileWriter("C:\\Users\\Aries\\workspace\\Codejam\\inout\\C-small-attempt1.out");
			BufferedWriter out = new BufferedWriter(fostream);
			
			strLine = br.readLine();
			Integer t = Integer.parseInt(strLine);
			for (int i=0;i<t;i++){
				System.out.println("Case "+(i+1));
				String line1 = br.readLine();
				Integer nn = Integer.parseInt(line1);
				int[] d = new int[nn];
				int[] n = new int[nn];
				int[] w = new int[nn];
				int[] e = new int[nn];
				int[] s = new int[nn];
				int[] dd = new int[nn];
				int[] dp = new int[nn];
				int[] ds = new int[nn];
				int maxday = 0;
				HashMap<Integer, Integer> wallH = new HashMap<Integer,Integer>();
				HashMap<Integer, Integer> wallH5 = new HashMap<Integer,Integer>();
				int wmost = 0;
				int emost = 0;
				
				for (int j=0;j<nn;j++){
					
					String linej = br.readLine();
					StringTokenizer st1 = new StringTokenizer(linej);
					d[j] = Integer.parseInt(st1.nextToken());
					n[j] = Integer.parseInt(st1.nextToken());
					w[j] = Integer.parseInt(st1.nextToken());
					e[j] = Integer.parseInt(st1.nextToken());
					s[j] = Integer.parseInt(st1.nextToken());
					dd[j] = Integer.parseInt(st1.nextToken());
					dp[j] = Integer.parseInt(st1.nextToken());
					ds[j] = Integer.parseInt(st1.nextToken());
					int latest = d[j]+n[j]*dd[j];
					int www, eee;
					if (dp[j]>0){
						www = w[j];
						eee = e[j]+n[j]*dp[j];
					} else {
						www = w[j]+n[j]*dp[j];
						eee = e[j];
					}
					if (www<wmost){
						wmost = www;
					}
					if (eee>emost){
						emost = eee;
					}
					if (latest > maxday){
						maxday = latest;
					}
				}
//				System.out.println("wmost = "+wmost+" emost = "+emost);
				for (int j=wmost;j<=emost;j++){
					wallH.put(j, 0);
					wallH5.put(j,0);
				}
				int succeed = 0;
				for (int j=0;j<maxday;j++){
//					System.out.println("day "+j);
					HashMap<Integer, Integer> fix = new HashMap<Integer, Integer>();
					HashMap<Integer, Integer> fix5 = new HashMap<Integer, Integer>();
					for (int k=0;k<nn;k++){
//						System.out.println("k= "+k);
						boolean success = false;
						int times = (j-d[k])/dd[k];
						if (j>=d[k] && (((j-d[k]) % dd[k])==0) && times <n[k]){
//							System.out.println(k + "attack");
							for (int l=w[k]+times*dp[k];l<=e[k]+times*dp[k];l++){
//								System.out.println("Wall at "+l+" is "+wallH.get(l));
//								System.out.println("Strength is "+(s[k]+times*ds[k]));
								if (wallH.get(l) < (s[k] +times*ds[k])){
									success = true;
									if (fix.get(l) == null){
										fix.put(l, s[k]+times*ds[k]);
									} else {
										fix.put(l, Math.max(fix.get(l), s[k]+times*ds[k]));
									}
								}
							}
							for (int l=w[k]+times*dp[k];l<e[k]+times*dp[k];l++){
//								System.out.println("Wall5 at "+l+" is "+wallH5.get(l));
//								System.out.println("Strength5 is "+(s[k]+times*ds[k]));
								if (wallH5.get(l) < (s[k] +times*ds[k])){
									success = true;
									if (fix5.get(l) == null){
										fix5.put(l, s[k]+times*ds[k]);
									} else {
										fix5.put(l, Math.max(fix5.get(l), s[k]+times*ds[k]));
									}
								}
							}
						}
						if (success) succeed++;
//						System.out.println("succeed= "+succeed);
					}
					for (Integer k:fix.keySet()){
						wallH.put(k, fix.get(k));
					}
					for (Integer k:fix5.keySet()){
						wallH5.put(k, fix5.get(k));
					}
				}
				
				out.write("Case #"+(i+1)+": "+succeed);
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

