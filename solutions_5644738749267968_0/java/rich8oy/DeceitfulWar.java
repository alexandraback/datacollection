import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.TreeSet;


public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		if(args.length>0)
			try {
				System.setIn(new FileInputStream(args[0]));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for(int iCase=1;iCase<=T;iCase++){
			String ans="";
			int N=in.nextInt();
			TreeSet<Double> naomi=new TreeSet<Double>();
			TreeSet<Double> ken=new TreeSet<Double>();
			for(int i=0;i<N;i++) naomi.add(in.nextDouble());
			for(int i=0;i<N;i++) ken.add(in.nextDouble());
			

			//TreeSet<Double> kenTest=new TreeSet<Double>(ken);
			int y=0;
			TreeSet<Double>ntest=new TreeSet<Double>(naomi);
			for(double k:ken.descendingSet()){
				if(k>ntest.last()){
					ntest.pollFirst();
				}else{
					y++;
					ntest.pollLast();
				}
			}
			TreeSet<Double>ktest=new TreeSet<Double>(ken);
			int z=0;
			for(double n:naomi.descendingSet()){
				if(n>ktest.last()){
					z++;
					ktest.pollFirst();
				}else{
					ktest.tailSet(n, false).pollFirst();
				}
			}
			
			
			
			System.out.println("Case #" + iCase + ": "+ y+ " "+z);
		}
		
	}

}
