package problems;

import java.io.IOException;
import java.io.Writer;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

import codeBook.GCJProblem;
import codeBook.GCJProblemHandler;

/**
 * @author piet
 *
 *	GCJ: Qualification 2015 Problem B
 */
public class B implements GCJProblem{
	int D;
	Integer[] P;
	
	public static void main(String[] args) {
		new GCJProblemHandler("B-small-2", B.class).run();
	}

	@Override
	public void readTestcase(Scanner in) {
		D = in.nextInt();
		P = new Integer[D];
		for(int i=0;i<D;i++) P[i] = in.nextInt();
	}
	
	@Override
	public void solve(Writer out) throws IOException {
		int mintime = Integer.MAX_VALUE;
		for(int normalMinutes = 1;normalMinutes<=1000;normalMinutes++){
			int specialMinutes = 0;
			for(int i=0;i<D;i++) specialMinutes += (int)(Math.ceil(1.*P[i]/normalMinutes)-1);
			if(normalMinutes+specialMinutes < mintime) mintime = normalMinutes+specialMinutes;
		}
		out.write(" " + mintime);
	}

//	@Override  // wrong solution
//	public void solve(Writer out) throws IOException {
//		LinkedList<Integer> p = new LinkedList<>();
//		for(Integer i:P) p.add(i);
//		Collections.sort(p, Collections.reverseOrder());
//		int mintime = p.peekFirst();
//		for(int specialminutes = 0;specialminutes < 1000 && p.peekFirst() > 3;){
//			do{
//				int first = p.pollFirst();	
//				p.add(first - first/2);
//				p.add(first/2);
//				specialminutes++;
//			}while(p.peekFirst()+specialminutes >= mintime && p.peekFirst() > 3);
//			
//			Collections.sort(p, Collections.reverseOrder());
//			
//			if(p.peekFirst()+specialminutes < mintime) mintime = p.peekFirst()+specialminutes;
//		}
//		out.write(" " + mintime);
//		//simulate(mintime);
//	}
	
	// for bugfixing
//	private void simulate(int mintime){
//		for(int sim=0;sim<100000;sim++){
//			LinkedList<Integer> p = new LinkedList<>();
//			for(Integer i:P) p.add(i);
//			int time = 0;
//			//System.out.println();
//			while(!p.isEmpty()){
//				//System.out.print("\n" + p.size() + " ");for(int i=0;i<p.size();i++) System.out.print(p.get(i)+" ");
//				if(Math.random() < 0.6){
//					for(int i=0;i<p.size();i++){
//						p.set(i, p.get(i)-1);
//						if(p.get(i) == 0) {p.remove(i);i--;}
//					}
//				}
//				else{  // special minute
//					int quelle = (int)(Math.random()*p.size());
//					if(p.get(quelle) == 1){
//						for(int i=0;i<p.size();i++){
//							p.set(i, p.get(i)-1);
//							if(p.get(i) == 0) {p.remove(i);i--;}
//						}
//						time++;continue;
//					}
//					int amount = (int)(Math.random()*(p.get(quelle)-1)) + 1;
//					if(Math.random() < 0.8 || p.size()<2){
//						p.set(quelle, p.get(quelle)-amount);
//						p.add(amount);
//					}
//					else{
//						int target = (int)(Math.random()*p.size());
//						while(target == quelle) target = (int)(Math.random()*p.size());
//						p.set(quelle, p.get(quelle)-amount);
//						p.set(target, p.get(target)+amount);
//					}
//				}
//				time++;
//			}
//			if(time<mintime){
//				System.out.println("TADA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
//				System.out.println(D);
//				for(int i=0;i<D;i++) System.out.print(P[i]+" ");
//				System.out.println();
//				System.out.println(mintime + " != " + time);
//				System.exit(0);
//			}
//		}
//	}
}