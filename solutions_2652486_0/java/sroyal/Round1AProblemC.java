import java.util.*;
public class Round1AProblemC {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		System.out.println("Case #1:");
		int r = br.nextInt();
		int n = br.nextInt();
		int m = br.nextInt();
		int k = br.nextInt();
		HashMap<String, HashMap<Integer, Double>> map = new HashMap<String, HashMap<Integer, Double>>();
		ArrayList<String> ts = new ArrayList<String>();
		for(int i = 2;i<=5;i++){
			for(int j = i;j<=5;j++){
				for(int l = j;l<=5;l++){
					String cur = i+""+j+""+l;
					ts.add(cur);
					int[] nums = {i, j, l};
					HashMap<Integer, Double> temp = new HashMap<Integer, Double>();
					for(int cc = 0;cc<8;cc++){
						double prob = 1.0/8;
						int mult = 1;
						for(int w = 0;w<3;w++){
							if((cc & (1<<w)) != 0){
								mult*=nums[w];
							}
						}
						if(temp.containsKey(mult)){
							temp.put(mult, temp.get(mult)+prob);
						}
						else{
							temp.put(mult, prob);
						}
					}
					map.put(cur, temp);
				}
			}
		}
		for(int i = 0;i<r;i++){
			double[] prob = new double[ts.size()];
			double best = 0;
			String res = "";
			int[] mults = new int[k];
			for(int j = 0;j<k;j++){
				mults[j] = br.nextInt();
			}
			int pos = 0;
			for(String s : ts){
				double cp = 1;
				for(int j = 0;j<k;j++){
					if(!map.get(s).containsKey(mults[j])){
						cp = 0;
						break;
					}
					cp*=map.get(s).get(mults[j]);
				}
				if(cp > best){
					best = cp;
					res = s;
				}
				pos++;
			}
			System.out.println(res);
		}
	}
}
