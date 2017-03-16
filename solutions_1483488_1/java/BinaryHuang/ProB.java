import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.HashSet;
import java.util.Set;


public class ProB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File infile = new File("C-large.in");
		File outfile = new File("out.txt");
		BufferedReader reader = null;
		BufferedWriter writer = null;
		try{
			reader = new BufferedReader(new FileReader(infile));
			writer = new BufferedWriter(new FileWriter(outfile));
			String ss = reader.readLine();
			String out;
			String []nums;
			int t = Integer.parseInt(ss),i,j,res;
			int a,b;
			for(i=1;i<=t;i++){
				out = "Case #" + i + ": ";
				ss = reader.readLine();
				nums = ss.split(" ");
				a = Integer.parseInt(nums[0]);
				b = Integer.parseInt(nums[1]);
				res = 0;
				for(j=a;j<b;j++){
					res += isRecycle(j,b);
				}
				out += res;
				writer.write(out);
				writer.newLine();
			}
			reader.close();
			writer.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	private static int isRecycle(int p,int b){
		int res = 0;
		String s = "";
		Set set = new HashSet();
		s += p;
		int len = s.length();
		int base = 1,i,max;
		for(i=1;i<len;i++) base *= 10;
		max = base * 10;
		int head,tail;
		while(base >= 10){
			head = p / base;
			tail = p % base;
			if(tail >= (base / 10)){
				tail *= max / base;
				tail += head;
				if(tail > p && tail <=b) {
					if(!set.contains(tail)){
						set.add(tail);
						res++;
					}
				}
			}
			base /= 10;
		}
		return res;
	}
	
	private static void sort(int []scores,int n)
	{
		int i,j,t,s;
		for(i=0;i<n;i++){
			t = i;
			s = scores[i];
			for(j=i+1;j<n;j++){
				if(scores[j] > s){
					s = scores[j];
					t = j;
				}
			}
			s = scores[i];
			scores[i] = scores[t];
			scores[t] = s;
		}
	}

}
