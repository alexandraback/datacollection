package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class TestClass {

	public static void main (String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C:\\in.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\out.txt"));
		TestClass testClass = new TestClass();

		int caseNum = Integer.parseInt(reader.readLine());
		for(int i=0; i<caseNum; i++) {
			String line = reader.readLine();
			String[] numbers = line.split(" ");

			int N = Integer.parseInt(numbers[0]);
			List<Integer> scores = new ArrayList<Integer>();

			for(int j=0; j<N; j++) {
				scores.add(Integer.parseInt(numbers[j+1]));
			}
			List<Integer> s1 = new ArrayList<Integer>();
			List<Integer> s2 = new ArrayList<Integer>();
			testClass.getC(scores, s1, s2);
			writer.write("Case #" + (i+1) + ":\n");

			if(s1.isEmpty()) {
				writer.write("Impossible");
			} else {
				for(int j=0; j<s1.size(); j++) {
					writer.write(Integer.toString(s1.get(j)));
					if(j != s1.size() - 1) {
						writer.write(" ");
					}
				}
				writer.write("\n");

				for(int j=0; j<s2.size(); j++) {
					writer.write(Integer.toString(s2.get(j)));
					if(j != s2.size() - 1) {
						writer.write(" ");
					}
				}
			}
			writer.write("\n");

			writer.flush();
			scores.clear();
		}
	}

	private void getC(List<Integer> nums, List<Integer> s1, List<Integer> s2) {
		int pos = (int)Math.pow(2, nums.size());
		int sum1 = 0;
		int sum2 = 0;
		for(int i=1; i<pos-1; i++) {
			sum1 = 0;
			String b1 = getBinaryNum(i, nums.size());
			for(int j=0; j<b1.length(); j++) {
				if(b1.charAt(j) == '1') {
					sum1 += nums.get(j);
				}
			}

			for(int j=1; j<pos-1; j++) {
				String b2 = getBinaryNum(j, nums.size());
				sum2 = 0;
				for(int k=0; k<b2.length(); k++) {
					if(b2.charAt(k) == '1') {
						if(b1.charAt(k) == '1') {
							break;
						}
						sum2 += nums.get(k);
						if(sum1 == sum2) {
							for(int l=0; l<b1.length(); l++) {
								if(b1.charAt(l) == '1') {
									s1.add(nums.get(l));
								}
							}

							for(int l=0; l<b2.length(); l++) {
								if(b2.charAt(l) == '1') {
									s2.add(nums.get(l));
								}
							}
							return;
						} else if(sum2 > sum1) {
							break;
						}
					}
				}
			}
		}
	}

	private LinkedList<Double> getA(List<Integer> scores) {
		Integer sum = 0;
		for(Integer score : scores) {
			sum += score;
		}

		return getAHelper(scores, sum * 2);
	}

	private LinkedList<Double> getAHelper(List<Integer> scores, int points) {
		LinkedList<Double> ret = new LinkedList<Double>();
		Double avg = new Double(points) / scores.size();

		Integer sum = 0;
		for(Integer score : scores) {
			sum += score;
		}

		for(int i=0; i<scores.size(); i++) {
			if(avg <= scores.get(i)) {
				points -= scores.get(i);
				scores.remove(i);
				ret = getAHelper(scores, points);
				ret.add(i, new Double(0));
				return ret;
			}
		}
		for(Integer score : scores) {
			ret.add((avg - new Double(score)) / new Double(points - sum) * new Double(100));
		}
		return ret;
	}

	private int getSwitchForBooleanTree(BooleanTreeNode node, int value) {
		if(node.And == -1 || !node.change) {
			return node.value == value ? 0 : -1;
		} else {
			int left1 = getSwitchForBooleanTree(node.left, 1);
			int left0 = getSwitchForBooleanTree(node.left, 0);
			int right1 = getSwitchForBooleanTree(node.right, 1);
			int right0 = getSwitchForBooleanTree(node.right, 0);
			int and = -1;
			int or = -1;

			if(value == 1) {
				and = getSwitchForBooleanTreeHelper(left1, right1);
				if(right1 == -1) {
					or = left1;
				} else if(left1 == -1) {
					or = right1;
				} else {
					or = min(right1, left1);
				}
			} else if(value == 0) {
				if(right0 == -1) {
					and = left0;
				} else if(left0 == -1) {
					and = right0;
				} else {
					and = min(right0, left0);
				}
				or = getSwitchForBooleanTreeHelper(left0, right0);
			}

			if(!node.change) {
				return node.And == 1 ? and : or;
			} else {
				if(node.And == 1) {

				}
			}
		}
		throw new RuntimeException("It's not scientific!");
	}

	private int getSwitchForBooleanTreeHelper(int i, int j) {
		if(i == -1 || j == -1) {
			return -1;
		}
		return i + j;
	}

	private class BooleanTreeNode {
		public int value;
		public int And;
		public boolean change;
		public BooleanTreeNode left;
		public BooleanTreeNode right;

		public BooleanTreeNode(int value, int and) {
			this.value = value;
			this.And = and;
			change = false;
			left = null;
			right = null;
		}
	}

	private List<Integer> getPrimeNum(int max) {
		List<Integer> ret = new ArrayList<Integer>();
		boolean[] nums = new boolean[max+1];
		Arrays.fill(nums, true);
		for(int i=2; i<nums.length/2; i++) {
			int tmp = 2 * i;
			while(tmp < nums.length) {
				nums[tmp] = false;
				tmp += i;
			}
		}
		for(int i=2; i<nums.length; i++) {
			if(nums[i]) {
				ret.add(i);
			}
		}
		return ret;
	}

	private String format(String pattern, double value) {
		DecimalFormat myFormatter = new DecimalFormat(pattern);
		return myFormatter.format(value);
	}

	private int[] getMilkShake(int N, List<Customer> customers) {
		int[] ret = new int[N];
		Arrays.fill(ret, 0);
		boolean flag = true;
		while(flag) {
			flag = false;
			for(Customer customer : customers) {
				if(!customer.getMalt && customer.unmaltNum == 0) {
					if(customer.malt == -1) {
						return null;
					}

					int turnMalted = customer.malt;
					ret[turnMalted] = 1;
					customer.getMalt = true;

					for(Customer customer1 : customers) {
						if(customer1.malt == turnMalted) {
							customer1.getMalt = true;
						} else if(customer1.unmalt.contains(turnMalted)) {
							customer1.unmaltNum--;
						}
					}
					flag = true;
					break;
				}
			}
		}
		return ret;
	}

	private class Customer {
		public int malt;
		public List<Integer> unmalt;
		public boolean getMalt;
		public int unmaltNum;

		public Customer(int malt, List<Integer> unmalt) {
			this.malt = malt;
			this.unmalt = new ArrayList<Integer>(unmalt);
			getMalt = false;
			unmaltNum = unmalt.size();
		}

		public Customer(List<Integer> unmalt) {
			this(-1, unmalt);
		}
	}

	private long getMinScalarProduct(long[] xs, long[] ys) {
		Arrays.sort(xs);
		Arrays.sort(ys);
		long min = 0;
		for(int i=0; i<xs.length; i++) {
			min += xs[i] * ys[xs.length - 1 - i];
		}
		return min;
	}

	private int getB(LinkedList<Level> levels) {
		Collections.sort(levels);
		int star = 0;
		int trial = 0;
		boolean flag = false;

		while(!levels.isEmpty()) {
			if(levels.get(0).bi <= star) {
				if(levels.get(0).doneA) {
					star++;
				} else {
					star += 2;
				}
				trial++;
				levels.removeFirst();
			} else {
				for(int i= levels.size()-1; i>=0; i--) {
					if(levels.get(i).ai <= star && !levels.get(i).doneA) {
						star += 1;
						trial++;
						levels.get(i).doneA = true;
						flag = true;
						break;
					}
				}
				if(flag) {
					flag = false;
					continue;
				}
				return -1;
			}
		}

		return trial;
	}

	private class Level implements Comparable<Level>{
		public int ai;
		public int bi;
		public boolean doneA;

		@Override
		public int compareTo(Level o) {
			return bi - o.bi;
		}

		public Level(int ai, int bi) {
			this.ai = ai;
			this.bi = bi;
			doneA = false;
		}
	}

	private Double getA(int A, int B, List<Double> possibs) {
		Double third = new Double(A + B + 1);
		Double forth = new Double(B + 2);
		Double min = third > forth ? forth : third;
		for(int i=0; i<A; i++) {
			Double sum = new Double(1);

			Double pos1 = possibs.get(A - i);
			if(i > 0) {
				pos1 += possibs.get(A);
			}
			int key1 = i + B - A + i + 1;

			Double pos2 = new Double(1) - pos1;
			int key2 = key1 + B + 1;

			sum = pos1 * key1 + pos2 * key2;

			if(sum < min) {
				min = sum;
			}
		}
		return min;
	}

	private List<Double> getPossibility(List<Double> Ais) {
		List<Double> times = new ArrayList<Double>();
		times.add(new Double(1));
		for(int i=0; i<Ais.size(); i++) {
			times.add(times.get(i) * Ais.get(i));
		}

		List<Double> poss = new ArrayList<Double>();
		for(int i=0; i<Ais.size(); i++) {
			poss.add( (1-Ais.get(i)) * times.get(i) );
		}
		poss.add(times.get(Ais.size()));

		return poss;
	}

	private int getSwitchRowNum(int[][] matrix) {
		int ret = 0;
		int[] line = new int[matrix.length];
		Arrays.fill(line, 0);
		for(int i=0; i<matrix.length; i++) {
			for(int j=matrix.length-1; j>=0; j--) {
				if(matrix[i][j] == 1) {
					line[i] = j;
					break;
				}
			}
		}

		boolean flag = true;
		while(flag) {
			flag = false;
			for(int i=0; i<line.length; i++) {
				if(line[i] > i) {
					for(int j=i+1; j<line.length; j++) {
						if(line[j] <= i) {
							for(int k=j; k>i; k--) {
								swap(line, k, k-1);
							}
							ret += j - i;
							flag = true;
							break;
						}
					}
				}
			}
		}

		return ret;
	}

	private void swap(int[] line, int i, int j) {
		int tmp = line[i];
		line[i] = line[j];
		line[j] = tmp;
	}

	private long minBase(String msg) {
		Map<Character, Character> charMap = new HashMap<Character, Character>();
		charMap.put(msg.charAt(0), '1');
		int index = 0;
		String ret = "1";

		for(int i=1; i<msg.length(); i++) {
			char c = msg.charAt(i);
			if(!charMap.containsKey(c)) {
				if(index > 9) {
					charMap.put(c, (char)('a' + index-10));
				} else {
					charMap.put(c, (char)('0' + index));
				}
				if(index == 0) {
					index += 2;
				} else {
					index++;
				}
			}
			ret += charMap.get(c);
		}
		return stringToLong(ret, index < 2 ? 2 : index);
	}

	private double getPossibility(FeatureTree root, HashSet<String> features) {
		//tree ::= (weight [feature tree tree])
		double ret = root.weight;
		if(!root.feature.equals("")) {
			if(features.contains(root.feature)) {
				ret *= getPossibility(root.left, features);
			} else {
				ret *= getPossibility(root.right, features);
			}
		}
		return ret;
	}

	private class FeatureTree {
		public FeatureTree(double weight) {
			this.weight = weight;
			feature = "";
			left = null;
			right = null;
		}

		public FeatureTree(double weight, String feature, FeatureTree left, FeatureTree right) {
			this.weight = weight;
			this.feature = feature;
			this.left = left;
			this.right = right;
		}

		public double weight;
		public String feature;
		public FeatureTree left;
		public FeatureTree right;
	}

	private FeatureTree parseFeatureTree(BufferedReader reader) throws IOException {
		String token = getToken(reader, '[');
		if(token.equals("(")) {
			token = getToken(reader, '[');
		} else {
			token = token.substring(1);
		}

		if(token.endsWith(")")) {
			return new FeatureTree(Double.parseDouble(token.substring(0, token.length()-1)));
		}
		String token1 = getToken(reader, ')');
		if(token1.equals(")")) {
			return new FeatureTree(Double.parseDouble(token.substring(0, token.length())));
		} else {
			FeatureTree ret = new FeatureTree(Double.parseDouble(token), token1, parseFeatureTree(reader), parseFeatureTree(reader));
			getToken(reader, ')');
			return ret;
		}
	}

	private String getToken(BufferedReader reader, char stopChar) throws IOException {
		char c = (char)reader.read();
		for(; c == ' ' || c == '\n'; c = (char)reader.read()) {}
		String ret = "";
		for(; c != ' ' && c != '\n'; c = (char)reader.read()) {
			ret += c;
			if(c == stopChar) {
				break;
			}
		}
		return ret;
	}

	private String getNextNum(String num) {
		for(int i=num.length()-1; i>0; i--) {
			if(num.charAt(i) > num.charAt(i-1)) {
				int j = i;
				for(; j+1 < num.length() && num.charAt(j+1) > num.charAt(i-1); j++) {}
				if(j != num.length()-1) {
					return num.substring(0, i-1) + num.charAt(j) + sortString(num.substring(i-1, j) + num.substring(j+1));
				} else {
					return num.substring(0, i-1) + num.charAt(j) + sortString(num.substring(i-1, num.length()-1));
				}
			}
		}
		if(num.length() == 1) {
			return num + "0";
		} else {
			String ret = sortString(num);
			if(ret.startsWith("0")) {
				for(int i=1; i<ret.length(); i++) {
					if(ret.charAt(i) != '0') {
						if(i+1 <ret.length()) {
							num = ret.charAt(i) + ret.substring(0, i) + ret.substring(i+1);
						} else {
							num = ret.charAt(i) + ret.substring(0, i);
						}
						return num.charAt(0) + "0" + num.substring(1);
					}
				}
			} else {
				return ret.charAt(0) + "0" + ret.substring(1);
			}
		}
		return "";
	}

	private String sortString(String str) {
		char[] tmp = str.toCharArray();
		Arrays.sort(tmp);
		return String.valueOf(tmp);
	}

	private int getRecycleNum(int A, int B) {
		//A <= n < m <= B
		int ret = 0;
		Set<Integer> tmp = new HashSet<Integer>();
		for(int num=A; num<=B; num++) {
			String numStr = Integer.toString(num);
			int length = numStr.length();
			for(int i=0; i<length-1; i++) {
				String numStr2 = numStr.substring(1, numStr.length()) + numStr.charAt(0);
				int num2 = Integer.parseInt(numStr2);
				if(num2 <= B && num2 > num && !tmp.contains(num2)) {
					ret++;
				}
				tmp.add(num2);
				numStr = numStr2;
			}
			tmp.clear();
		}
		return ret;
	}

	private int getNumOfGoogler(int S, int p, List<Integer> points) {
		if(p == 0) {
			return points.size();
		}
		int ret = 0;
		for(int point : points) {
			if(point >= 3 * p - 2) {
				ret++;
			} else if(point >= 3 * p - 4 && S > 0 && p > 1) {
				S--;
				ret++;
			}
		}
		return ret;
	}


	Map<Character, Character> map = new HashMap<Character, Character>();

	private String getTranslation(String gs) {
		String ret = "";
		for(int i=0; i<gs.length(); i++) {
			ret += map.get(gs.charAt(i));
		}
		return ret;
	}

	private void getTranslation() {
		String gs1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String gs2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String gs3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String str1 = "our language is impossible to understand";
		String str2 = "there are twenty six factorial possibilities";
		String str3 = "so it is okay if you want to just give up";
		map.put('q', 'z');
		map.put('z', 'q');
		getTranslation(gs1, str1);
		getTranslation(gs2, str2);
		getTranslation(gs3, str3);
	}

	private void getTranslation(String gs, String str) {
		for(int i=0; i<gs.length(); i++) {
			map.put(gs.charAt(i), str.charAt(i));
		}
	}

	private int getHappyNum(List<Integer> bases) {
		for(int i=bases.get(0); ; i++) {
			boolean breakOut = false;
			for(int base : bases) {
				if(!isNumHappy(i, base)) {
					breakOut = true;
					break;
				}
			}
			if(!breakOut) {
				return i;
			}
		}
	}

	private boolean isNumHappy(int num, int base) {
		int sum = 0;
		List<String> previous = new ArrayList<String>();
		while(sum != 1) {
			sum = 0;
			String numStr = intToString(num, base);
			if(previous.contains(numStr)) {
				return false;
			}
			previous.add(numStr);
			for(int i=0; i<numStr.length(); i++) {
				sum += Math.pow(numStr.charAt(i) - '0', 2);
			}
			num = sum;
		}
		return true;
	}

	/**
	 * Accept 0~9 a~z
	 * @param str
	 * @param base
	 * @return
	 */
	private long stringToLong(String str, int base) {
		long ret = 0;
		long pow = 1;
		for(int i=str.length()-1; i>=0; i--) {
			if(str.charAt(i) >= 'a') {
				ret += (str.charAt(i) - 'a' + 10) * pow;
			} else {
				ret += (str.charAt(i) - '0') * pow;
			}
			pow *= base;
		}
		return ret;
	}

	private String intToString(int i, int base) {
		return intToString(i, base, 0);
	}

	private String intToString(int i, int base, int length) {
		String ret = "";
		while(i != 0) {
			ret = i % base + ret;
			i /= base;
		}
		if(ret.length() < length) {
			ret = new String(new char[length - ret.length()]).replace("\0", "0") + ret;
		}
		return ret;
	}

	private int getTicketFair(int P, int M[], int price[]) {
		int min = Integer.MAX_VALUE;
		int teamNum = (int)Math.pow(2, P);
		int gameNum = teamNum - 1;
		int possibility = (int)Math.pow(2, gameNum);
		for(int i=0; i<possibility; i++) {
			String buy = getBinaryNum(i, gameNum);
			int sum = 0;
			if(doesTeamWork(M, buy)) {
				for(int k=0; k<gameNum; k++) {
					if(buy.charAt(k) == '1') {
						sum += price[k];
					}
				}
			}
			if(sum != 0 && sum < min) {
				min = sum;
			}
		}
		return min;
	}

	private boolean doesTeamWork(int M[], String buy) {
		for(int i=0; i<M.length; i++) {
			int index = i / 2;
			int indexPlus = (buy.length() + 1) / 2;
			int sum = 0;
			int gameNum = 0;
			while(index < buy.length()) {
				if(buy.charAt(index) == '1') {
					sum++;
				}
				gameNum++;
				index = indexPlus + i / (int)Math.pow(2, gameNum+1);
				indexPlus = indexPlus + indexPlus / 2;
			}
			if(gameNum - M[i] > sum) {
				return false;
			}
		}
		return true;
	}

	private String getBinaryNum(int i, int length) {
		String ret = Integer.toBinaryString(i);
		if(ret.length() < length) {
			return new String(new char[length - ret.length()]).replace("\0", "0") + ret;
		}
		return ret;
	}

	private class Chick {
		Chick(int b, int t, int x, int v) {
			T = t;
			B = b;
			X = x;
			V = v;
			arrive = (B - X) / (double)V <= T;
		}

		private int T;
		private int B;
		private int X;
		private int V;
		private boolean arrive;
	}

	private int getSwapNum(List<Chick> chicken, int K) {
		int ret = 0;
		for(int i=chicken.size()-1; i>=0; i--) {
			if(K == 0) {
				break;
			}
			if(!chicken.get(i).arrive) {
				ret += K;
			} else {
				K--;
			}
		}
		if(K != 0) {
			return -1;
		}
		return ret;
	}

	private class Directory {
		Directory(String n) {
			name = n;
			dirs = new ArrayList<Directory>();
		}

		Directory getChild(String name) {
			for(Directory dir : dirs) {
				if(dir.name.equals(name)) {
					return dir;
				}
			}
			return null;
		}

		private String name;
		private List<Directory> dirs;
	}

	private int getNumOfMkdir(Directory root, List<List<String>> newDirs) {
		int ret = 0;
		Directory curr, pre;
		for(List<String> newDir : newDirs) {
			curr = root;
			for(String folder : newDir) {
				pre = curr;
				curr = curr.getChild(folder);
				if(curr == null) {
					ret++;
					pre.dirs.add(new Directory(folder));
					curr = pre.getChild(folder);
				}
			}
		}
		return ret;
	}

	private List<String> getDirNames(String dir) {
		List<String> ret = new ArrayList<String>(Arrays.asList(dir.split("/")));
		ret.remove(0);
		return ret;
	}

	private String rotate(int K, char[][] position) {
		char[][] rotated = new char[position.length][position.length];
		for(int i=0; i<position.length; i++) {
			for(int j=0; j<position.length; j++) {
				rotated[j][position.length-1-i] = position[i][j];
			}
		}
		for(int j=0; j<position.length; j++) {
			int tmp = position.length - 1;
			for(int i=position.length-1; i>=0; i--) {
				if(rotated[i][j] != '.') {
					rotated[tmp][j] = rotated[i][j];
					tmp--;
				}
			}
			for(; tmp>=0; tmp--) {
				rotated[tmp][j] = '.';
			}
		}

		boolean r = checkColor('R', K, rotated);
		boolean b = checkColor('B', K, rotated);

		if(r && b) {
			return "Both";
		} else if(r) {
			return "Red";
		} else if(b) {
			return "Blue";
		} else {
			return "Neither";
		}
	}

	private boolean checkColor(char color, int K, char[][] rotated) {
		int num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				if(rotated[i][j] == color) {
					num++;
					if(num == K) {
						return true;
					}
				} else {
					num = 0;
				}
			}
			num = 0;
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				if(rotated[j][i] == color) {
					num++;
					if(num == K) {
						return true;
					}
				} else {
					num = 0;
				}
			}
			num = 0;
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				for(int k=0; k<K; k++) {
					if(i+k >=rotated.length || j+k >= rotated.length) {
						break;
					}
					if(rotated[i+k][j+k] == color) {
						num++;
						if(num == K) {
							return true;
						}
					} else {
						break;
					}
				}
				num = 0;
			}
		}

		num = 0;
		for(int i=0; i<rotated.length; i++) {
			for(int j=0; j<rotated.length; j++) {
				for(int k=0; k<K; k++) {
					if(i+k >=rotated.length || j-k < 0) {
						break;
					}
					if(rotated[i+k][j-k] == color) {
						num++;
						if(num == K) {
							return true;
						}
					} else {
						break;
					}
				}
				num = 0;
			}
		}

		return false;
	}

	private class WalkWay implements Comparable<WalkWay>{
		WalkWay(int b, int e, int w) {
			B = b;
			E = e;
			W = w;
		}

		private int B;
		private int E;
		private int W;

		@Override
		public int compareTo(WalkWay o) {
			if(W == o.W) {
				return 0;
			}
			return W < o.W ? -1 : 1;
		}
	}

	private Double getMinTimeForWalkWay(int X, int S, int R, Double t, List<WalkWay> walkWays) {
		int walkWayNum = walkWays.size();
		int tmp = 0;
		for(int i=0; i<X; i++) {
			if(tmp >= walkWayNum) {
				walkWays.add(new WalkWay(i, X, 0));
				break;
			}
			if(i < walkWays.get(tmp).B) {
				walkWays.add(new WalkWay(i, walkWays.get(tmp).B, 0));
				i = walkWays.get(tmp).E - 1;
				tmp++;
			} else if(i == walkWays.get(tmp).B) {
				i = walkWays.get(tmp).E - 1;
				tmp++;
			}
		}
		Collections.sort(walkWays);

		Double ret = new Double(0);
		for(WalkWay walkWay : walkWays) {
			if(t > 0) {
				Double ideaT = (new Double(walkWay.E) - walkWay.B) / (walkWay.W + R);
				if(t >= ideaT) {
					t -= ideaT;
					ret += ideaT;
				} else {
					Double pass = t * (walkWay.W + R);
					ret += t + (new Double(walkWay.E) - pass - walkWay.B) / (walkWay.W + S);
					t = new Double(-1);
				}
			} else {
				ret += (new Double(walkWay.E) - walkWay.B) / (walkWay.W + S);
			}
		}

		return ret;
	}

	private String getPerfertHarmony(Long L, Long H, List<Long> frequencise) {
		boolean flag = true;
		for(long i=L; i<=H; i++) {
			flag = true;
			for(Long frequency : frequencise) {
				if(i % frequency != 0 && frequency % i != 0) {
					flag = false;
					break;
				}
			}
			if(flag) {
				return "" + i;
			}
		}
		return "NO";
	}

	private Long getRocketTime(Long L, Long t, Long N, List<Long> distance) {
		Long sum = new Long(0);
		List<Long> singleDis = new ArrayList<Long>();
		for(Long dis : distance) {
			sum += dis;
		}
		Long nRound = N / distance.size();
		Long nRemain = N % distance.size();
		Long time = nRound * sum;
		for(int i=0; i<nRemain; i++) {
			time += distance.get(i);
			singleDis.add(distance.get(i));
		}
		time *= 2;

		if(t >= time || L == 0) {
			return time;
		}

		Long pass = t/2;
		Long passRound = pass / sum;
		Long passRemain = pass % sum;
		Long passRoundRemain = nRound - passRound;

		if(t != 0) {
			for(int i=0; i<distance.size(); i++) {
				if(passRemain > 0) {
					passRemain -= distance.get(i);
				} else {
					singleDis.add(distance.get(i));
				}
			}
			if(passRemain != 0) {
				singleDis.add(-passRemain);
			}
			passRoundRemain--;
		}

		Collections.sort(distance);
		Collections.sort(singleDis);

		Long minus = new Long(0);
		int singleDisIndex = singleDis.size()-1;
		for(int i=distance.size()-1; i>=0; i--) {
			while(singleDisIndex >= 0 && singleDis.get(singleDisIndex) >= distance.get(i)) {
				minus += singleDis.get(singleDisIndex);
				singleDisIndex--;
				L--;
			}
			if(L <= passRoundRemain) {
				minus += L * distance.get(i);
				break;
			} else {
				minus += passRoundRemain * distance.get(i);
				L -= passRoundRemain;
			}
		}

		return time - minus;
	}

	private char[][] tiles;
	private boolean test() {
		for(int i=0; i<tiles.length; i++) {
			for(int j=0; j<tiles[i].length; j++) {
				if(tiles[i][j] == '#') {
					if(i+1 >= tiles.length || j+1 >= tiles[i+1].length || tiles[i][j+1] != '#' || tiles[i+1][j] != '#' || tiles[i+1][j+1] != '#') {
						return false;
					}
					tiles[i][j] = '/';
					tiles[i+1][j] = '\\';
					tiles[i][j+1] = '\\';
					tiles[i+1][j+1] = '/';
				}
			}
		}
		return true;
	}

	private String test1(List<String> words, String seq) {
		int maxScore = -1;
		String maxString = "";

		for(String word : words) {
			int score = -1;
			StringBuilder wildCard = new StringBuilder(new String(new char[word.length()]).replace("\0", "_"));
			List<String> words2 = new ArrayList<String>(words);
			int words2Size = words.size();

			for(int i=0; i<seq.length(); i++) {
				Character seqChar = seq.charAt(i);
				int j=0;

				while(j<words2Size) {
					if(words2.get(j).indexOf(seqChar) != -1) {
						break;
					}
					j++;
				}

				if(j == words2Size) {
					continue;
				}

				if(word.indexOf(seqChar) == -1) {
					score++;
				} else {
					int beginIndex = 0;
					while(true) {
						beginIndex = word.indexOf(seqChar, beginIndex);
						if(beginIndex == -1) {
							break;
						}
						wildCard.setCharAt(beginIndex, seqChar);
						beginIndex++;
					}

					for(j=0; j<words2Size; j++) {
						if(!killerWordWildCard(words2.get(j), wildCard.toString(), seqChar)) {
							words2.remove(words2.get(j));
							words2Size--;
							j--;
						}
					}

					if(words2Size == 1) {
						break;
					}
				}
			}
			if(score > maxScore) {
				maxScore = score;
				maxString = word;
			}
		}
		return maxString;
	}

	private boolean killerWordWildCard(String word, String wildCard, Character notIn) {
		if(!wildCardMatch(word, wildCard)) {
			return false;
		} else if(notIn != null) {
			int begin = -1;
			while(true) {
				if(begin+1 >= word.length()) {
					break;
				}
				begin = word.indexOf(notIn, begin + 1);
				if(begin == -1) {
					break;
				}
				if(wildCard.charAt(begin) != notIn) {
					return false;
				}
			}
			//			wildCard.indexOf(notIn);
		}
		return true;
	}

	private boolean wildCardMatch(String str1, String str2) {
		if(str1.length() != str2.length()) {
			return false;
		}
		for(int i=0; i<str1.length(); i++) {
			if(str2.charAt(i) != '_' && str1.charAt(i) != str2.charAt(i)) {
				return false;
			}
		}
		return true;
	}

	private Integer max(Integer... numbers) {
		int max = numbers[0];

		for(Integer number : numbers) {
			if(number > max) {
				max = number;
			}
		}
		return max;
	}

	private Double max(Double... numbers) {
		Double max = numbers[0];

		for(Double number : numbers) {
			if(number > max) {
				max = number;
			}
		}
		return max;
	}

	private Integer min(Integer... numbers) {
		Integer min = numbers[0];

		for(Integer number : numbers) {
			if(number < min) {
				min = number;
			}
		}
		return min;
	}

	private Double min(Double... numbers) {
		Double min = numbers[0];

		for(Double number : numbers) {
			if(number < min) {
				min = number;
			}
		}
		return min;
	}

	private int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}

	private int gcd(int a, int b) {
		while(a != b) {
			if(a > b) {
				a -= b;
			} else {
				b -= a;
			}
		}
		return a;
	}
}
