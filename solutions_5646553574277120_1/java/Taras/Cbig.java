import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class Cbig {
	
	public Cbig(){
		Scanner in;
		try {
				//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/c.in"));
				//in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/C-small-attempt0.in"));
				in = new Scanner(new FileReader("/home/taras/workspace/GoogleCodeJam_1C/src/C-large.in"));
				
				int t = in.nextInt();
				
				StringBuilder resultBuilder = new StringBuilder();
				
				List<Coin> coins = new ArrayList<Coin>();
				
				for(int i = 0; i < t; i++){
					coins.clear();
					int c = in.nextInt();
					int d = in.nextInt();
					long v = in.nextLong();
					for(int j=0;j<d; j++){
						Coin coin = new Coin(in.nextLong(), false);
						coins.add(coin);
					}
					resultBuilder.append("Case #"+(i+1)+": "+findSolution(c,d,v, coins)+"\n");
				}
				
				
				System.out.println(resultBuilder.toString());
				String content = resultBuilder.toString();
				 
				File file = new File("/home/taras/workspace/GoogleCodeJam_1C/src/c2.out");
		
				// if file doesnt exists, then create it
				if (!file.exists()) {
					file.createNewFile();
				}
		
				FileWriter fw = new FileWriter(file.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);
				bw.write(content);
				bw.close();
		
				System.out.println("Done");
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
	public static void main(String[] args) {	
		new Cbig();
	}


	private  int findSolution(int c, int d, long v, List<Coin> coins){
		System.out.println("findSolution: c:"+c+" d:"+d+" v:"+v);
		int result = 0;
		
		
		
		Collections.sort(coins, comparator);
		printCoins(coins);
		
		//we can form everything up to current
		long current = 0;
		
		while(current<v){
			System.out.println("current:"+current);
			boolean findCoin = false;
			
			for(int i=0;i<coins.size();i++){
				if(!findCoin)
				if(!coins.get(i).used){
					if(coins.get(i).value<=current+1){
						coins.get(i).used = true;
						System.out.println("use coin:"+coins.get(i).value);
						current +=coins.get(i).value*c;
						findCoin = true;
						break;
					}
				}
			}
			
			if(!findCoin){
				result++;
				Coin coin = new Cbig.Coin(current+1, true);
				System.out.println("add coin:"+(current+1));
				coins.add(coin);
				current +=coin.value*c;
				findCoin = true;
			}
		}
		
		
		
		return result;
	}

	static Comparator<Coin> comparator = new Comparator<Coin>() {
		@Override
		public int compare(Coin o1, Coin o2) {
			if(o1.value>o2.value){
				return 1;
			}else if(o1.value==o2.value){
				return 0;
			}else return -1;
		}
	};
	
	private static void printCoins(List<Coin> coins){
		for(int i=0;i<coins.size();i++){
			System.out.println("coin #"+i+" value:"+coins.get(i).value);
		}
	}
	
	private class Coin{
		public long value;
		public boolean used;
		public Coin(long l, boolean used){
			this.value = l;
			this.used = used;
		}
	}
}
