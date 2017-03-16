import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Set;
import java.util.regex.Pattern;

import org.apache.commons.math3.Field;

import static java.lang.Math.*;





public class Main extends Util {
	

	
	public static void main(String[] args){
		(new Main()).mainB();
	}
	
	public void mainC(){
//		scanFile("C:\\Users\\GeoGebra\\Downloads\\input-level2.txt");
//		waitForInputSignal();
		s.useDelimiter(Pattern.compile("\\D"));
		showln("This %s.","works");
		
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			int R=s.nextInt();
			int C=s.nextInt();
			int M=s.nextInt();
			showln("%d %d %d",R,C,M);
		}
	}
	
	public void mainB(){
		scanFile("B-small-attempt0.in");
//		scanFile("C:\\Users\\GeoGebra\\Downloads\\input-level2.txt");
//		waitForInputSignal();
		Locale.setDefault(Locale.US);
		s.useDelimiter(Pattern.compile("\\s"));
		outputInFile("B1s.out");
//		showln("This %s.","works");
		
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			double C=s.nextDouble();
			double F=s.nextDouble();
			double X=s.nextDouble();
//			showln("%f %f %f",C,F,X);
			double last=X/2;
			double ls=0;
			for (int r=1;;r++){
				ls+=C/(2+(r-1)*F);
				if (ls+X/(2+r*F)>last){
					showln("Case #%d: %.8f",i+1,last);
					break;
				}else{
					last=ls+X/(2+r*F);
				}
			}
			
//			showln("%d %d %d",R,C,M);
		}
	}

	public void mainA(){
		scanFile("A-small-attempt0.in");
//		waitForInputSignal();
		s.useDelimiter(Pattern.compile("\\D"));
//		showln("This %s.","works");
		
		int T=s.nextInt();
		for (int i=0;i<T;i++){
			show("Case #%d: ",i+1);
			int a1=s.nextInt();
			Set<Integer> l1=new HashSet<Integer>();
			for (int j=0;j<4;j++){
				for (int k=0;k<4;k++){
					if (j==a1-1){
						l1.add(s.nextInt());
					}else{
						s.nextInt();
					}
				}
			}
			int a2=s.nextInt();
			Set<Integer> l2=new HashSet<Integer>();
			for (int j=0;j<4;j++){
				for (int k=0;k<4;k++){
					if (j==a2-1){
						l2.add(s.nextInt());
					}else{
						s.nextInt();
					}
				}
			}
			l1.retainAll(l2);
			if (l1.size()==1){
				showln("%d",l1.iterator().next());
			}else if (l1.size()>1){
				showln("Bad magician!");
			}else{
				showln("Volunteer cheated!");
			}
//			showln("%d %d %s %s",a1,a2,l1.toString(),l2.toString());
			
		}
	}

}
