import java.io.*;
import java.util.*;

public class Kingdom {
	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("B-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Kingdom.out")));
		StringTokenizer st;
		
		Comparator<Star> comp1 = new LvOneComparator();
		Comparator<Star> comp2 = new LvTwoComparator();
		
		ArrayList<Star> tempArray = new ArrayList<Star>();
		
        PriorityQueue<Star> queue1 = new PriorityQueue<Star>(10, comp2);
        PriorityQueue<Star> queue2 = new PriorityQueue<Star>(10, comp1);
		
		st = new StringTokenizer(f.readLine());
		int T = Integer.parseInt(st.nextToken());
		
		int[] result = new int[T];
		
		for(int i = 0; i < T; i++) {
			result[i] = 0;
		}
		
		int N;
		int a, b;
		int coin;
		Star temp;
		int tempMaxLv;
		int tempLv;
		int tempIndex;
		for(int i = 0; i < T; i++) {
			queue1.clear();
			queue2.clear();
			
			st = new StringTokenizer(f.readLine());
			N = Integer.parseInt(st.nextToken());
			for(int j = 0; j < N; j++) {
				st = new StringTokenizer(f.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				temp = new Star(a, b);
				queue1.add(temp);
				queue2.add(temp);
			}
			coin = 0;
			while(queue1.size() != 0) {
				tempArray.clear();
				temp = queue1.peek();
				if(temp.isDone) {
//					System.out.println("LV2 is done:\ncoin: " + coin + " lv2: " + temp.lv2);
					queue1.poll();
					continue;
				}
//				System.out.println("LV2:\ncoin: " + coin + " lv2: " + temp.lv2);
				if(coin >= temp.lv2) {
//					System.out.println(" abc");
					temp.isDone = true;
					result[i]++;
//					System.out.println("result i: " + result[i]);

					if(temp.isDoneOne)
						coin += 1;
					else
						coin += 2;
					queue1.poll();
				}
				else {
					if(queue2.size() == 0)
						break;
					tempLv = Integer.MAX_VALUE;
					temp = queue2.peek();
					if(temp.isDone) {

						queue2.poll();
						continue;
					}
					else {
						tempMaxLv = temp.lv2;
						tempLv = temp.lv1;
						tempIndex = 0;
						while(tempLv <= coin) {
							tempArray.add(temp);
							if(temp.lv2 >= tempMaxLv)
								tempIndex = tempArray.size() - 1;
							queue2.poll();
							if(queue2.size() == 0)
								break;
							temp = queue2.peek();
							tempLv = temp.lv1;
						}
//						System.out.println("temp size: " + tempArray.size());
						if(tempArray.size() != 0)
							temp = tempArray.get(tempIndex);
						for(int k = 0; k < tempArray.size(); k++) {
							if(k != tempIndex)
								queue2.add(tempArray.get(k));
						}
//						System.out.println("CompareLV1:\ncoin: " + coin);
//						System.out.println(" lv 1, 2: " + temp.lv1 + " " + temp.lv2);
						if( (coin < temp.lv1) || (temp.isDoneOne) ) {
							result[i] = 0;
							break;
						}
						else {
							result[i]++;
//							System.out.println("result i: " + result[i]);
							coin++;
							temp.isDoneOne = true;
						}
					
					}
				}
			}
		}
		
		for(int k1 = 0; k1 < T; k1++) {
			if(result[k1] == 0)
				out.println("Case #" + (k1 + 1) + ": Too Bad");
			else
				out.println("Case #" + (k1 + 1) + ": " + result[k1]);
		}
		
		out.close();
	}
}

class Star {
	Star(int x1, int x2) {
		lv1 = x1;
		lv2 = x2;
		isDoneOne = false;
		isDone = false;
	}
	public int lv1;
	public int lv2;
	public boolean isDoneOne;
	public boolean isDone;
}

class LvOneComparator implements Comparator<Star> {
	public int compare(Star x, Star y) {
		if(x.lv1 < y.lv1)
			return -1;
		else if (x.lv1 > y.lv1)
			return 1;
		else {
			if(x.lv2 > x.lv2)
				return -1;
			else if(x.lv2 < x.lv2)
				return 1;
			else
				return 0;
		}
			
	}
}

class LvTwoComparator implements Comparator<Star> {
	public int compare(Star x, Star y) {
		if(x.lv2 < y.lv2)
			return -1;
		else if (x.lv2 > y.lv2)
			return 1;
		else {
			return 0;
		}
	}
}
