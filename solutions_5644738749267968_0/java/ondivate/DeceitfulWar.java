import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
				
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			int N=Integer.parseInt(br.readLine());
			double nao[]=new double[N];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				nao[i]=Double.parseDouble(st.nextToken());
			}
			Arrays.sort(nao);
			double ken[]=new double[N];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				ken[i]=Double.parseDouble(st.nextToken());
			}
			Arrays.sort(ken);
			System.out.println(Arrays.toString(nao));
			System.out.println(Arrays.toString(ken));
			
			//war strategy:
			//ken plays lowest higher than nao's or lowest if he does not have
			int ans2=0;
			{
				LinkedList<Double> listn=new LinkedList<Double>();
				TreeSet<Double> listk=new TreeSet<Double>();
				for(int i=0;i<N;i++){
					listn.add(nao[i]);
					listk.add(ken[i]);
				}
				//count naomi wins
				for(int i=0;i<N;i++){
					Double playn=listn.poll();
					Double playk=listk.ceiling(playn);
					if(playk==null)
						playk=listk.pollFirst();
					else
						listk.remove(playk);
					System.out.println(playn+" "+playk);
					if(playn>playk)
						ans2++;
				}
			}
			
			
			
			//deceitful war strategy:
			//ken plays the same as above
			//naomi says high number if her smallest is larger than ken's smallest
			//and a second to the highest otherwise
			int ans1=0;
			{
				LinkedList<Double> listn=new LinkedList<Double>();
				LinkedList<Double> listk=new LinkedList<Double>();
				for(int i=0;i<N;i++){
					listn.add(nao[i]);
					listk.add(ken[i]);
				}
				//count naomi wins

				for(int i=0;i<N;i++){
					Double playn=0.0;
					Double playk=0.0;
					if(listn.peek()>listk.peek()){
						playn=listn.pollFirst();
						playk=listk.pollFirst();
					}
					else{
						playn=listn.pollFirst();
						playk=listk.pollLast();
					}
					if(playn>playk)
						ans1++;
				}
			}
			
			
			
			
			
			
			bw.append("Case #"+cn+": "+ans1+" "+ans2+"\n");
			System.out.println("cn "+cn+": "+ans1+" "+ans2);
			System.out.println();
		}
		bw.flush();

	}

}
