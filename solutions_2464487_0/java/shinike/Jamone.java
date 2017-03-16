import java.util.*;
public class Jamone {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		
		for(int i=0;i<n;i++){
			double r=sc.nextDouble();
			double t=sc.nextDouble();
			double m=(2*t)/(Math.sqrt((1-2*r)*(1-2*r)+8*t)+2*r-1);
			System.out.println("Case #"+(i+1)+": "+(long)Math.floor(m));
			
		}
	}

}
