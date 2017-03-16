import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class GoogleDance {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine().trim());
		for(int t=1;t<=cases;t++){
			String ln=br.readLine().trim();
			String[] inp=ln.split(" ");
			int n=Integer.parseInt(inp[0]);
			int s=Integer.parseInt(inp[1]);
			int p=Integer.parseInt(inp[2]);
			int[] scores=new int[n];
			int count=0, sleft=s;
			for(int i=0;i<n;i++){
				
				scores[i]=Integer.parseInt(inp[3+i]);
				int avg = scores[i]/3;
				int rem = scores[i]%3;
				//System.out.println("i : "+i+" --> "+scores[i]+" :: "+avg+" :: "+rem+" :s"+sleft+" :c "+count);
				if(avg>=p){
					count++;
					continue;
				}
				if(rem>=1 && (avg+1)>=p){
					count++;
					continue;
				}
				if(sleft>0){
					switch (rem) {
					case 0:
						if(avg>0 && (avg+1)>=p){
							sleft--;
							count++;
							continue;
						}
						break;
					case 1:
						break;
					case 2:
						if((avg+2)>=p){
							sleft--;
							count++;
							continue;
						}
						break;

					default:
						break;
					}
				}
			}
			System.out.println("Case #"+t+": "+count);
			
		}
	}

}
