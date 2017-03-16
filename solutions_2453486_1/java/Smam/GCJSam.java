package com.smamhost.gcj1a;

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
		char[] board = new char[16];
		boolean finished = true;
		
		public GCJThread(int testNb, Scanner s){
			this.testNb = testNb;
			//Scan input here
			for(int i =0;i<4;++i){
				String currStr = s.next();
				for(int j=0;j<4;++j){
					board[i*4+j] = currStr.charAt(j);
					if(currStr.charAt(j) == '.'){
						this.finished = false;
					}
				}
			}
		}
		
		
		private char checkline(int startoffset,int rowIncrement,int colIncrement){
			//check lines
			char precChar = board[startoffset];
			for(int i = 1; i<4;++i){
				int index = startoffset+i*4*rowIncrement+i*colIncrement;
				//update precChar:
				if(board[index] == 'X' || board[index] == 'O'){
					if(precChar == 'T'){
						precChar = board[index];
					}
					if(board[index]!=precChar){
						return '.';
					}
				}
				else if(board[index] == '.'){
					return '.';
				}
			}
			return precChar;
		}
		
		private String compute(){
			//check lines
			char buf;
			for(int i = 0; i<4;++i){
				buf = checkline(i*4, 0, 1);
				if(buf != '.'){
					return buf+" won";
				}
				buf = checkline(i, 1, 0);
				if(buf != '.'){
					return buf+" won";
				}
			}
			
			buf = checkline(0, 1, 1);
			if(buf != '.'){
				return buf+" won";
			}
			
			buf = checkline(3, 1, -1);
			if(buf != '.'){
				return buf+" won";
			}
			if(finished)
				return "Draw";
			else
				return "Game has not completed";
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
	public static final String  INPUT_FILE = "A-large.in";
	public static final String OUTPUT_FILE = "A-large.out";
	
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
