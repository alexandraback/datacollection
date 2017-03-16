import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Dance {

	/**
	 * @param args
	 */
	
	static double test(int a, int b, double [] ps){
		double tmp=1.0;
		for(int i=0; i<a; i++){
			tmp *= ps[i];
		}
		double keep= tmp*(b+1) + ((1-tmp)*(a+(2*b)+2));
		//System.out.println("keep"+keep);
		double tmp2 = 1.0;
		for(int i=0; i<a; i++){
			
			int ok=(b+1+(2*(a-i)));
		    double k= tmp2*ok + ((1-tmp2)*(ok+a+b+1));
		    if (k < keep) keep = k;
		    //System.out.println("i bkspaces:"+(a-i)+"probcorrect:"+tmp2+",k="+k);
		    tmp2 *= ps[i];
		}
		double enter = a+b+2;
		return (keep < enter?keep:enter);
	}
	
	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int nbtests;
		try {
			nbtests = new Integer(br.readLine());
			for (int i=0; i<nbtests; i++){
				String s = br.readLine();
				String []tmp = s.split(" ",2);
				int a = new Integer(tmp[0]);
				int b = new Integer(tmp[1]);
				
				String[] ps = br.readLine().split(" ",a);
				double []ds = new double[a];
				for (int j=0; j<a; j++) ds[j]=new Double(ps[j]);
				
				System.out.println("Case #"+(i+1)+": " + test(a,b-a,ds));
			}
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		

	}

}
