import java.io.File;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.util.Scanner;


public class second {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception { 
			Scanner sc = new Scanner(new File("in.txt"));
			FileWriter out = new FileWriter(new File("out.txt"));
			int T = new Integer(sc.nextLine());
			for(int i = 1 ; i < T+1 ; i++)
			{
				int E= sc.nextInt();
				int R = sc.nextInt();
				int N = sc.nextInt();
				long maxe = (long)E;
				 E = (int) Math.min(E, maxe);
				int[] vi = new int[N];
				for(int j  = 0; j < N ; j++)
				{
					vi[j] = sc.nextInt();
				}
				long sum = 0;
				for(int j = 0; j <N ; j++)
				{
					 
					boolean thereisbigger = false;
					int biggeraddr =-1;
					for(int h = j ; h < N ; h++)
						if(vi[h]>vi[j])
						{
							thereisbigger=true;
							biggeraddr = h;
						}
					if(!thereisbigger  ){
						 sum+= (long)vi[j]*((long)E);
						 E = R;		
						 E = (int) Math.min(E, maxe);
					}
					else
					{
						 
						long add =(long) R*((long)(biggeraddr-j)) + (long) E;
						System.out.println(add +" add");
						if(add>maxe)
						{
							 long drop = Math.min(E,add-maxe);
						 
								sum+=(long)vi[j]* (drop);
								System.out.println((long)vi[j]* (add-maxe)  + "   " +"added");
								E-=(drop) ;
								E+=R;
								E = (int) Math.min(E,maxe);
								System.out.println(E);
							 
						}
						else{
							if(E+R>maxe)
								sum+= (E+R-maxe)*vi[j];
							E = (int) Math.min(E+R, maxe);
							 
						}
					}
					System.out.println ("round " + j+"  :  "+sum + "    "  + E);
				}
				
				System.out.println("Case #"+i+": "+sum);
				out.write("Case #"+i+": "+sum+"\n");
				try{ sc.nextLine();}
				catch(Exception e){}

			}
			out.flush();
			sc.close();
			out.close(); 
	}

}
