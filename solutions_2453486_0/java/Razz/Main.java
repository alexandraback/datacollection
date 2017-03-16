import java.util.HashMap;

public class Main {
	public static void main(String[] args) throws java.io.FileNotFoundException,java.io.IOException{
		//store the winning combinations		
		HashMap<String,Character> outcomes=new HashMap<String,Character>();
		outcomes.put("XXXX",'X');outcomes.put("TXXX",'X');outcomes.put("XTXX",'X');outcomes.put("XXTX",'X');outcomes.put("XXXT",'X');
		outcomes.put("OOOO",'O');outcomes.put("TOOO",'O');outcomes.put("OTOO",'O');outcomes.put("OOTO",'O');outcomes.put("OOOT",'O');
		
		java.io.BufferedReader bRead=new java.io.BufferedReader(new java.io.FileReader("F:\\A-small-attempt0.in"));
		java.io.BufferedWriter bWrite=new java.io.BufferedWriter(new java.io.FileWriter("F:\\A-small-attempt0.out"));
		StringBuffer output=new StringBuffer();
		int noCases=Integer.parseInt(bRead.readLine());
		
		String[] tBoard=new String[4];String line=null;char gameOutcome;//could be 'X','O','D',N'
		for(int i=0;i<noCases;i++){
			gameOutcome='D';
			for(int b=0;b<4;b++)
				tBoard[b]=bRead.readLine();
			
			GameLogic:{
				for(int cur=0;cur<4;cur++){//check for horizontal wins
					if(outcomes.containsKey(tBoard[cur])){gameOutcome=outcomes.get(tBoard[cur]);break GameLogic;}
				}			
				for(int cur=0;cur<4;cur++){//check for vertical wins
					line=new String(new char[]{tBoard[0].charAt(cur),tBoard[1].charAt(cur),tBoard[2].charAt(cur),tBoard[3].charAt(cur)});
					if(outcomes.containsKey(line)){gameOutcome=outcomes.get(line);break GameLogic;}
				}
				//check for diagonal wins
				line=new String(new char[]{tBoard[0].charAt(0),tBoard[1].charAt(1),tBoard[2].charAt(2),tBoard[3].charAt(3)});
				if(outcomes.containsKey(line)){gameOutcome=outcomes.get(line);break GameLogic;}
				line=new String(new char[]{tBoard[0].charAt(3),tBoard[1].charAt(2),tBoard[2].charAt(1),tBoard[3].charAt(0)});
				if(outcomes.containsKey(line)){gameOutcome=outcomes.get(line);break GameLogic;}
				//check for not completion of game
				for(int v=0;v<4;v++)for(int h=0;h<4;h++)if(tBoard[h].charAt(v)=='.'){gameOutcome='N';break GameLogic;}
			}//end game logic
			
			switch(gameOutcome){
			case 'X':output.append("Case #"+(i+1)+": X won"+"\n");break;
			case 'O':output.append("Case #"+(i+1)+": O won"+"\n");break;
			case 'D':output.append("Case #"+(i+1)+": Draw"+"\n");break;
			case 'N':output.append("Case #"+(i+1)+": Game has not completed"+"\n");break;
			}
			bRead.readLine();//skip the empty line
		}
		bWrite.write(output.toString());
		bWrite.close();bRead.close();
	}
}
