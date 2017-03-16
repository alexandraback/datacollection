import java.util.Scanner;

public class b {
	public static void main(String[] args){

		Scanner in = new Scanner(System.in);
		int numOfLines = new Integer(in.nextLine());
		for (int i= 1; i<=numOfLines; i++){
			String [] lineValues = in.nextLine().split(" ");
			int numberOfPlayers = new Integer(lineValues[0]);
			int numberOfSupers = new Integer(lineValues[1]);
			int bestResul = new Integer(lineValues[2]);
			int bestResulMin1 = bestResul-1>0 ? bestResul-1 : 0;
			int bestResulMin2 = bestResul-2>0 ? bestResul-2 : 0;
			int res = 0;
			//System.out.println("number of players: "+numberOfPlayers);
			for (int j =3; j<numberOfPlayers+3;j++)
			{
				//System.out.println("j="+j);
				Integer puntuations= new Integer(lineValues[j]);
				if(puntuations>= bestResul+2*(bestResulMin1))
				{
					res++;
					continue;
				}else if (numberOfSupers>0)
				{
					if (puntuations>= bestResul+2*(bestResulMin2))
					{
						res++;
						numberOfSupers--;
						continue;
					}
				}
			}		
		System.out.format("Case #%d: %d\n", i, res);
		}
		return;
	}
}