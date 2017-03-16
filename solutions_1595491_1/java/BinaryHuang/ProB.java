import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.Reader;


public class ProB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File infile = new File("B-large.in");
		File outfile = new File("out.txt");
		int []scores = new int[222];
		BufferedReader reader = null;
		BufferedWriter writer = null;
		try{
			reader = new BufferedReader(new FileReader(infile));
			writer = new BufferedWriter(new FileWriter(outfile));
			String ss = reader.readLine();
			String out;
			String []nums;
			int t = Integer.parseInt(ss),i,j,res;
			int n,s,p,temp,rest;
			for(i=1;i<=t;i++){
				out = "Case #" + i + ": ";
				ss = reader.readLine();
				nums = ss.split(" ");
				n = Integer.parseInt(nums[0]);
				s = Integer.parseInt(nums[1]);
				p = Integer.parseInt(nums[2]);
				for(j=3;j<3+n;j++){
					scores[j-3] = Integer.parseInt(nums[j]);
				}
				sort(scores,n);
				res = 0;
				for(j=0;j<n;j++){
					temp = scores[j] /3;
					rest = scores[j] - temp * 3;
					if(rest > 0) temp++;
					if(temp >= p) res++;
					else{
						if(rest == 2 && s > 0 && temp + 1 >= p){
							s--;
							res++;
						}
						if(rest == 0 && s > 0 && temp > 0 && temp + 1 >= p){
							s--;
							res++;
						}
					}
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
