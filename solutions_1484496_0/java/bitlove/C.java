import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class C {
	
	public static void find(List<Long> pos, List<Long> neg,  ArrayList<Set<Long>> sets, long nums[], int index, long target){
		long num = nums[index];
		if(index == 0){
			if(num == target)
				pos.add(num);
			else if(num == -target)
				neg.add(num);
			return;
		}
		
		Set<Long> set = sets.get(index - 1);
		long t1 = target - num;
		long t2 = target + num;
		if(set.contains(t1)){
			pos.add(num);
			find(pos , neg , sets, nums, index - 1 , t1);
		}else if(set.contains(t2)){
			neg.add(num);
			find(pos, neg , sets, nums , index - 1 , t2);
		}else{
			find(pos, neg , sets, nums , index - 1 , target);
		}
	}
	
	public static List<List<Long>> solve(int N , long[] nums){
		ArrayList<Set<Long>> results = new ArrayList<Set<Long>>();
		
		long zero = 0;
		long first = nums[0];
		Set<Long> firstSet = new HashSet<Long>();
		firstSet.add(first);
		firstSet.add(-first);
		firstSet.add(zero);
		results.add(firstSet);
		
		List<Long> positive = new ArrayList<Long>();
		List<Long> negative = new ArrayList<Long>();
		
		List<List<Long>> rets = new ArrayList<List<Long>>();
		for (int i = 1; i < nums.length; i++) {
			long num = nums[i];
			Set<Long> set = new HashSet<Long>();
			Set<Long> prev = results.get(i - 1);
			set.addAll(prev);

			for (Long pvalue : prev) {
				long t1 = pvalue + num;
				if(t1 == 0){
					find(positive, negative , results, nums , i , 0);
					if(positive.size() > 0 && negative.size() > 0){
						rets.add(positive);
						rets.add(negative);
						return rets;
					}else{
						positive.clear();
						negative.clear();
					}
				}
				long t2 = pvalue - num;
				if(t2 == 0){
					find(positive, negative , results, nums , i , 0);
					if(positive.size() > 0 && negative.size() > 0){
						rets.add(positive);
						rets.add(negative);
						return rets;
					}else{
						positive.clear();
						negative.clear();
					}
				}
					
				set.add(t1);
				set.add(t2);
			}
			results.add(set);
		}
		return null;
	}
	
	public static double sum(List<Long> r){
		double sum = 0;
		for(int i = 0 ; i < r.size() ; i ++){
			sum = sum + r.get(i);
		}
		return sum;
	}
	
	public static void main(String args[]) throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(new File("C-small-attempt1.in")));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("C.txt")));
		String line = reader.readLine();
		int T = Integer.parseInt(line);
		for(int i = 0 ; i < T ; i ++){
			line = reader.readLine();
			String tokens[] = line.split("\\s+");
			int N = Integer.parseInt(tokens[0]);
			long[] nums = new long[N];
			for(int j = 1 ; j < N + 1 ; j ++){
				nums[j - 1] = Long.parseLong(tokens[j]);
			}
			
			List<List<Long>> results = solve(N , nums);
			if(results == null)
				writer.write("Case #" + (i + 1) + ": Impossible\r\n");
			else{
				writer.write("Case #" + (i + 1) + ": \r\n");
				List<Long> positive = results.get(0);
				System.out.println(sum(positive));
				for(int j = 0 ; j < positive.size() ; j ++){
					if(j == 0)
						writer.write("" + positive.get(j));
					else
						writer.write(" " + positive.get(j));
				}
				writer.write("\r\n");
				List<Long> negative = results.get(1);
				System.out.println(sum(negative));
				for(int j = 0 ; j < negative.size() ; j ++){
					if(j == 0)
						writer.write("" + negative.get(j));
					else
						writer.write(" " + negative.get(j));
				}
				writer.write("\r\n");
			}
		}
		reader.close();
		writer.close();
	}

}
