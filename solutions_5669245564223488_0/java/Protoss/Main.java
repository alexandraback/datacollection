import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;



public class Main {
	public static int size = 0;
	public static void	dfs(ArrayList<String> input, String concat)	{
		if(input.size() == 0)	{
			//System.out.println("concat " + concat);
			int[] table = new int[26];
			for(int i = 0; i < concat.length(); i++)	{
				if(i==0)	table[concat.charAt(i) - 'a'] = 1;
				else {
					if( concat.charAt(i) != concat.charAt(i-1) && table[concat.charAt(i) - 'a'] != 0) return;
					table[concat.charAt(i) - 'a'] = 1;
				}
			}
			size++; return;
		}
		
		for(int i = 0; i < input.size(); i++)	{
			//if(concat.isEmpty() || concat.charAt(concat.length()-1) == input.get(i).charAt(0) )	{
				String temp = input.get(i);
				input.remove(i);
				dfs(input, concat+temp);
				input.add(i, temp);
			//}
		}
	}

	public static void main(String[] args){
		Scanner scanner = new Scanner( System.in );
		
		int T  = Integer.parseInt(scanner.nextLine());
		int line  = 0;
		ArrayList<ArrayList<String>> input = new ArrayList<ArrayList<String>>();
		ArrayList<Integer> ans = new ArrayList<Integer>();
		while (scanner.hasNextLine())	{
			String Line = scanner.nextLine();
			Line = scanner.nextLine();
			String[] Lines = Line.split(" ");
			ArrayList<String> temp = new ArrayList<String>();
			for( int i = 0; i < Lines.length; i++)
				temp.add(Lines[i]);
			input.add(temp);
				//System.out.println(x + " " + y);
		}
		
		//for ( int i = 0;  i < input.size(); i++)
			//System.out.println(input.get(i)[0]);
		for ( int i = 0; i < input.size(); i++){
			int caseid = i +1;
			System.out.print("Case #"+caseid+": ");
			size = 0;
			//if(caseid == 2)	{
				dfs(input.get(i), "");
				System.out.println(size);
			//}
		}

	}
}
