import java.util.Scanner;


public class A2013 {

	/**
	 * @param args
	 */
	public static void main(String args[]){
		Scanner scn = new Scanner(System.in);
		String str;
		str = scn.nextLine();
		int T = Integer.parseInt(str);

		for(int t = 1;t<=T;t++){
			String strs[] = new String[10];
			
			strs[0] = scn.nextLine();
			strs[1] = scn.nextLine();
			strs[2] = scn.nextLine();
			strs[3] = scn.nextLine();
			
			strs[4] = ""+strs[0].charAt(0) + strs[1].charAt(0) + strs[2].charAt(0) + strs[3].charAt(0);
			strs[5] = ""+strs[0].charAt(1) + strs[1].charAt(1) + strs[2].charAt(1) + strs[3].charAt(1);
			strs[6] = ""+strs[0].charAt(2) + strs[1].charAt(2) + strs[2].charAt(2) + strs[3].charAt(2);
			strs[7] = ""+strs[0].charAt(3) + strs[1].charAt(3) + strs[2].charAt(3) + strs[3].charAt(3);
			
			strs[8] = ""+strs[0].charAt(0) + strs[1].charAt(1) + strs[2].charAt(2) + strs[3].charAt(3);
			strs[9] = ""+strs[0].charAt(3) + strs[1].charAt(2) + strs[2].charAt(1) + strs[3].charAt(0);
			
			int res = 0;
			for(String string : strs){
				if(string.replaceAll("T", "O").equals("OOOO")){
					res = 1;
					break;
				}
				else if(string.replaceAll("T", "X").equals("XXXX")){
					res = 2;
					break;
				}
			}
			
			if(res==0){
				if(strs[0].contains(".")||strs[1].contains(".")||strs[2].contains(".")||strs[3].contains(".")){
					res = 3;
				}
			}
			
			if(res==0)
				System.out.println("Case #" + t +": Draw");
			else if(res == 1)
				System.out.println("Case #" + t +": O won");
			else if(res == 2)
				System.out.println("Case #" + t +": X won");
			else if(res == 3)
				System.out.println("Case #" + t +": Game has not completed");
			
			if(t!=T)
				str = scn.nextLine();
		}
	}

}
