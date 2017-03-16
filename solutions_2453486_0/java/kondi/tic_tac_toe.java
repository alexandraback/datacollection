import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;


public class tic_tac_toe {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws  Exception {
		 Scanner sc = new Scanner(new File("in.txt"));
		 FileWriter out = new FileWriter(new File("out.txt"));
		 int T = new Integer(sc.nextLine());
		 for(int i = 1 ; i < T+1 ; i++)
		 {
			 String res = "Draw";
			 String [] s = new String[4];
			 String[]sx = new String[4];
			 String[]so =new String[4];
			 for(int j = 0; j <4 ; j++){
				 s[j] = sc.nextLine();
				 sx[j] = s[j].replace('T', 'X');
				 so[j] = s[j].replace('T', 'O');
				  System.out.println("*************" + sx[j]);
			 }
			 for(int j = 0; j <4 ; j++)
				 if(s[j].indexOf('.')>-1)
					 res="Game has not completed";
			 for(int j = 0; j <4 ; j++)
			 {
				 if(sx[j].charAt(0) == 'X' && sx[j].charAt(1)== 'X' &&sx[j].charAt(2) == 'X' &&sx[j].charAt(3) == 'X'  )
				 {	 res = "X won"; System.out.println("xxxx");}
				 if(so[j].charAt(0) == 'O' && so[j].charAt(1)== 'O' &&so[j].charAt(2) == 'O' &&so[j].charAt(3) == 'O'  )
				 {	 res = "O won"; System.out.println("jj");}
				 if(sx[0].charAt(j) == 'X' && sx[1].charAt(j)== 'X' &&sx[2].charAt(j) == 'X' &&sx[3].charAt(j) == 'X'  )
				 {	 res = "X won"; System.out.println("111xxxx");}
				 if(so[0].charAt(j) == 'O' && so[1].charAt(j)== 'O' &&so[2].charAt(j) == 'O' &&so[3].charAt(j) == 'O'  )
				 {	 res = "O won"; System.out.println("jssj");}
				 if(sx[0].charAt(0) == 'X' && sx[1].charAt(1)== 'X' &&sx[2].charAt(2) == 'X' &&sx[3].charAt(3) == 'X'  )
				 {	 res = "X won"; System.out.println("4343xxxx");}
				 if(so[0].charAt(0) == 'O' && so[1].charAt(1)== 'O' &&so[2].charAt(2) == 'O' &&so[3].charAt(3) == 'O'  )
				 {	 res = "O won"; System.out.println("jsssaj");}
				 if(sx[0].charAt(3) == 'X' && sx[1].charAt(2)== 'X' &&sx[2].charAt(1) == 'X' &&sx[3].charAt(0) == 'X'  )
				 {	 res = "X won"; System.out.println("46567xxxx");}
				 if(so[0].charAt(3) == 'O' && so[1].charAt(2)== 'O' &&so[2].charAt(1) == 'O' &&so[3].charAt(0) == 'O'  )
				 {	 res = "O won"; System.out.println("jssasdsdj");}
			 }
			 System.out.println("Case #"+i+": "+res);
			 out.write("Case #"+i+": "+res+"\n");
				try{ sc.nextLine();}
				catch(Exception e){}
		 }
		 out.flush();
		 sc.close();
		 out.close();
	}

}
