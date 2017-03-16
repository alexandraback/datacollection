package codejam;

import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class DeceitfulWar {
	
	int blocks;
	double[] weights1,weights2;
	
	public DeceitfulWar(RandomAccessFile rafin) throws Exception{
		String inputline;
		StringTokenizer st;
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		blocks = Integer.parseInt(st.nextToken());
		weights1 = new double[blocks];
		weights2 = new double[blocks];
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		for (int i=0; i<blocks; i++)
			weights1[i] = Double.parseDouble(st.nextToken());
		
		inputline = rafin.readLine();
		st = new StringTokenizer(inputline," ");
		for (int i=0; i<blocks; i++)
			weights2[i] = Double.parseDouble(st.nextToken());
	}
	
	public DeceitfulWar() {
		// TODO Auto-generated constructor stub
	}

	public String getStatus() throws Exception{
		StringBuffer sb = new StringBuffer();
		/*
		ArrayList<Double> list = new ArrayList<Double>();
		//list.add(1.0);
		//list.add(2.0);
		//list.add(3.0);
		System.out.println("id=" + getInsertId(list,0.5));
		System.out.println("id=" + getInsertId(list,1.5));
		System.out.println("id=" + getInsertId(list,2.5));
		*/
		
		
		int id1,id2;
		int len = weights1.length;
		double w1,w2;

		List<Double> list1 = sort(weights1);
		//System.out.println(list1);
		List<Double> list2 = sort(weights2);
		//System.out.println(list2);
		int score=0;

		for (int i=0; i<len; i++) {
			id1 = id1ByDeceitfulWar(list1, list2);
			if (id1>=0) {
				w1 = list1.get(id1);
				id2 = id2ByWar(list2, 1.0);
				w2 = list2.get(id2);
				if (w1 > w2)
					score++;
				list1.remove(id1);
				list2.remove(id2);
				System.out.println(id1);
			} else
				break;
		}
		System.out.println("Score = " + score);
		sb.append(score);
		
		list1 = sort(weights1);
		list2 = sort(weights2);
		score = 0;
		for (int i=0; i<len; i++) {
			id1 = id1ByWar(list1);
			w1 = list1.get(id1);
			id2 = id2ByWar(list2, w1);
			w2 = list2.get(id2);
			if (w1 > w2)
				score++;
			list1.remove(id1);
			list2.remove(id2);
			System.out.println(id1);
		}
		System.out.println("Score = " + score);
		sb.append(" " + score);
		
		return sb.toString();
	}

	public int id1ByWar(List<Double> woods) throws Exception {
		//return (int)(Math.random()*woods.size());
		return 0;
	}
	
	public int id1ByDeceitfulWar(List<Double> woods1, List<Double> woods2) throws Exception {
		double w2 = woods2.get(0);
		int id = getInsertId(woods1, w2);
		if (id<woods1.size())
			return id;
		else
			return -1;
	}
	
	public int id2ByWar(List<Double> woods, double toldWeight) throws Exception {
		if (woods.size()<=0) throw new Exception("Index overflow for woods!");
		int id = getInsertId(woods, toldWeight);
		if (id>=woods.size())
			return 0;
		else
			return id;
	}
	
	public List<Double> sort(double[] ds) throws Exception {
		List<Double> list = new ArrayList<Double>(ds.length);
		
		int id;
		for (int i=0; i<ds.length; i++) {
			//System.out.println(ds[i]);
			id = getInsertId(list, ds[i]);
			//System.out.println("id=" + id);
			list.add(id, ds[i]);
			//System.out.println("added");
		}
		
		return list;
	}
	
	public int getInsertId(List<Double> list, double x) throws Exception{
		int len = list.size();
		int id = len/2;
		int begin,end;
		begin=0; end=len;
		while (id>=0 && id<len) {
			//System.out.println("id -- " + id);
			//Thread.currentThread().sleep(100);
			if (list.get(id)>x && (id==0 || list.get(id-1)<x))
				return id;
			if (list.get(id)>x) {
				end = id;
				id = (begin+end)/2;
			}
			else {
				begin = id+1;
				id = (begin+end)/2;
			}
		}
		if (id>=len)
			id = len;
		return id;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			
			/*
			DeceitfulWar bull = new DeceitfulWar();
			bull.getStatus();
			
			if (true) return;
			*/
			
			String infilename="d:/codejam/data/D-small-attempt0.in";
			String outfilename="d:/codejam/data/D-small-attempt0.out";
			RandomAccessFile rafin = new RandomAccessFile(infilename, "r");
			RandomAccessFile rafout = new RandomAccessFile(outfilename, "rw");
			rafout.setLength(0);
			
			int count = Integer.parseInt(rafin.readLine().trim());
			DeceitfulWar o;
			System.out.println(count + " cases.");
			for (int i=1; i<=count; i++) {
				o = new DeceitfulWar(rafin);
				rafout.writeBytes("Case #" + i + ": " + o.getStatus());
				if (i<count)
					rafout.writeBytes("\r\n");
				System.out.println("Case " + i + " dealed!");
				System.gc();
			}
			
			rafin.close();
			rafout.close();
		} catch (Exception e) {
			e.printStackTrace(System.out);
		}

	}


}
