package com.smamhost.gcj1b;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class GCJSam {
	private static class GCJThread implements Callable<String>{
		private int testNb = 0;
		
		//Test variables
		private int      N;
		private int      M;
		private int[][] lawn;
		
		public GCJThread(int testNb, Scanner s){
			this.testNb = testNb;
			//Scan input here
			N = s.nextInt();
			M = s.nextInt();
			lawn = new int[N][M];
			for(int i = 0;i<N;++i){
				for(int j=0;j<M;++j){
					lawn[i][j]=s.nextInt();
				}
			}
		}
		
		
		private String compute(){
			for(int i = 0;i<N;++i){
				for(int j = 0;j<M;++j){
					boolean validRow = true;
					boolean validCol = true;
					for(int k=0;k<N;k++){
						if(lawn[k][j] > lawn[i][j]){
							validRow = false;
						}
					}
					for(int k=0;k<M;k++){
						if(lawn[i][k] > lawn[i][j]){
							validCol = false;
						}
					}
					if(!validCol && !validRow){
						return "NO";
					}
					
					
				}
			}
			return "YES";
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
	public static final String  INPUT_FILE = "B-large.in";
	public static final String OUTPUT_FILE = "B-large.out";
	
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
