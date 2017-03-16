import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

import org.apache.commons.math3.Field;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).mainA();
	}
	
	public long GCD(long a, long b){
		if (a<=0){
			return b;
		}
		return GCD(b%a,a);
	}
	
	public void main(){
//		scanFile("x-small-attempt0.in");
//		scanFile("x-large.in");
		s.useDelimiter(Pattern.compile("\\s"));
//		outputInFile("As0_0.out");
		int T=s.nextInt();
		for (int i=0;i<T;i++){

		}
	}
	
	public void mainA(){
		scanFile("A-small-attempt0.in");
//		scanFile("x-large.in");
		s.useDelimiter(Pattern.compile("\\s|/"));
		outputInFile("As0_0.out");
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			long P=s.nextLong();
			long Q=s.nextLong();
			long g=GCD(P,Q);
//			showln("%d/%d %d",P,Q,g);
			long Pd=P/g;
			long Qd=Q/g;
			int p=0;
			boolean impossible=false;
			while ((Qd&1)==0){
				Qd=Qd>>1;
				p++;
			}
			if (Qd==1&&p<=40){
//				showln("Qd==2^%d",p);
				for (int j=p-1;j>=0;j--){
					if (((Pd>>j)&1)==1){
						showln("Case #%d: %d",i+1,p-j);
						break;
					}
				}
			}else{
				impossible=true;
				showln("Case #%d: impossible",i+1);
			}
		}
	}


}
