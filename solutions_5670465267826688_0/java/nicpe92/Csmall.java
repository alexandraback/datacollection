import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Csmall {
	
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		int[][] prod = new int[8][8];
		for (int i = 0; i < 8; i++) {
			prod[i][0]=i;
			prod[0][i]=i;
			prod[i][7]=7-i;
			prod[7][i]=7-i;
		}
		prod[1][1]=7; prod[1][2]=3; prod[1][3]=5;
		prod[2][1]=4; prod[2][2]=7; prod[2][3]=1;
		prod[3][1]=2; prod[3][2]=6; prod[3][3]=7;
		for (int i = 4; i <8; i++) {
			prod[i][1] = 7-prod[7-i][1]; prod[i][2] = 7-prod[7-i][2]; prod[i][3] = 7-prod[7-i][3];
			prod[i][4] = prod[7-i][3]; prod[i][5] = prod[7-i][2]; prod[i][6] = prod[7-i][1];
			prod[7-i][4]=prod[i][3]; prod[7-i][5]=prod[i][2]; prod[7-i][6]=prod[i][1];
		}
		for (int cas = 1; cas <=T; cas++) {
			String[] spl = in.readLine().split(" ");
			int L = Integer.parseInt(spl[0]);
			int X = Integer.parseInt(spl[1]);
			String s = in.readLine();
			String tot = "";
			for (int i = 1; i <=X; i++) {
				tot = tot + s;
			}
			int idx = 0;
			int curP = 0;
			boolean foundi = false;
			while(!foundi && idx<tot.length())
			{
				int curV = -1;
				if(tot.charAt(idx)=='i')
					curV=1;
				else if(tot.charAt(idx)=='j')
					curV=2;
				else curV=3;
				curP = prod[curP][curV];
				if(curP==1)
					foundi=true;
				idx++;
			}
			curP=0;
			boolean foundj = false;
			while(!foundj && idx<tot.length())
			{
				int curV = -1;
				if(tot.charAt(idx)=='i')
					curV=1;
				else if(tot.charAt(idx)=='j')
					curV=2;
				else curV=3;
				curP = prod[curP][curV];
				if(curP==2)
					foundj=true;
				idx++;
			}
			curP=0;
			while(idx<tot.length())
			{
				int curV = -1;
				if(tot.charAt(idx)=='i')
					curV=1;
				else if(tot.charAt(idx)=='j')
					curV=2;
				else curV=3;
				curP = prod[curP][curV];
				idx++;
			}
			boolean foundk = (curP==3);
			String ans ="";
			if(foundi && foundj && foundk)
				ans = "YES";
			else ans = "NO";
			System.out.println("Case #"+cas+": "+ans);
		}
	}

}
