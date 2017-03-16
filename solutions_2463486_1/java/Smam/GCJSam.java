package com.smamhost.gcj1c;

import java.io.CharArrayReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.Scanner;
import java.util.Vector;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.TimeUnit;

public class GCJSam {
	protected static class GCJThread implements Callable<String>{
		private int testNb = 0;
		
		//Test variables
		public static Vector<Long> squarePal;
		public Long A,B;
		
		public GCJThread(int testNb, Scanner s){
			this.testNb = testNb;
			//Scan input here
			A = s.nextLong();
			B= s.nextLong();
		}
		
		
		private String compute(){
			int max = squarePal.size();
			Long res = new Long(0);
			for(int i=0;i<max;i++){
				if(squarePal.get(i)>=A && squarePal.get(i)<=B){
					res++;
				}
			}
			return res.toString();
		}
		
		@Override
		public String call() throws Exception {
			System.out.println("GO "+this.testNb);
			String output = compute();
			System.out.println("Case "+this.testNb+": "+output);
			return output;
		}
		
	};
	
	public static final int    MAX_THREADS = 8;
	public static final String  INPUT_FILE = "C-large-1.in";
	public static final String OUTPUT_FILE = "C-large-1.out";
	
	public static void computeAllPal(){
		ExecutorService exe = Executors.newFixedThreadPool(MAX_THREADS);
		GCJThread.squarePal = new Vector<Long>();
		GCJThread.squarePal.add(1L);
		GCJThread.squarePal.add(4L);
		GCJThread.squarePal.add(9L);
		for(int i=11;i<=99;i+=11){
			exe.execute(new Runner(i));
		}
		exe.shutdown();
		try {
			exe.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS);
			Collections.sort(GCJThread.squarePal);

		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

	
	public static class Runner implements Runnable{
		
		private int root;
		public Runner(int root){
			this.root=root;
		}
			
		public boolean isPal(Long nbLong){
			String nb = nbLong.toString();
			int max = nb.length()/2;
			for(int i=0;i<max;++i){
				if(nb.charAt(i)!= nb.charAt(nb.length()-1-i)){
					return false;
				}
			}
			return true;
		}
		
		public void run(){
			char[] charArray = {'0','1','2','3','4','5','6','7','8','9'};
			ArrayDeque<Long> deck = new ArrayDeque<Long>();
			deck.add(new Long(root));
			while(!deck.isEmpty()){
				Long currPal = deck.pollFirst();
				Long currPalSq = currPal*currPal;
				if(currPalSq <= 100000000000000L && isPal(currPalSq)){
					GCJThread.squarePal.add(currPalSq);
				}
				String currPalStr = currPal.toString();
				if(currPalSq <= 100000000000000L && currPalStr.length()%2 == 0){
					String upper = currPalStr.substring(0, currPalStr.length()/2);
					String lower = currPalStr.substring(currPalStr.length()/2, currPalStr.length());
					for(int i=0;i<10;++i){
						deck.add(new Long(upper+charArray[i]+lower));
						deck.add(new Long(upper+charArray[i]+charArray[i]+lower));
					}
				}
			}
		}
	}

	
	public static void main(String[] args) throws FileNotFoundException {

		//instanciate the threadpool
		ExecutorService threadPool = Executors.newFixedThreadPool(MAX_THREADS);
		
		//Access ressources$
		Scanner s;
		s = new Scanner(new FileReader(INPUT_FILE));
		
		//Create the vector of callable GCJThread
		int N = s.nextInt();
		ArrayList<GCJThread> testArray = new ArrayList<GCJThread>();
		for(int i = 0; i<N;++i){
			testArray.add(new GCJThread(i+1, s));
		}
		//Close ressource
		s.close();

		computeAllPal();

		//Execute tests
		ArrayList<Future<String>> resultVector = new ArrayList<Future<String>>();
		for(int i = 0; i<N;++i){
			resultVector.add(threadPool.submit(testArray.get(i)));
		}
		
		//Print result
		try {
			FileWriter fw;
			fw = new FileWriter(OUTPUT_FILE);
			for(int i = 0; i<N;++i){
				String output = "Case #"+(i+1)+": "+resultVector.get(i).get()+"\n";
				fw.write(output);
			}
			fw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		threadPool.shutdown();

	}

}
