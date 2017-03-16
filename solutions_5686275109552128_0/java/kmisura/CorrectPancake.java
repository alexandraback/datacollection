package com.pancake;

import java.util.Comparator;
import java.util.PriorityQueue;

public class CorrectPancake {
	private int n;
	private PriorityQueue<Integer> bottlenecks;
	
	public CorrectPancake(String line){
		String tokens[] = line.split(" ");
		n = tokens.length;
		bottlenecks = new PriorityQueue<Integer>(n, new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				return -o1.compareTo(o2);
			}
		});
		for(int i=0;i<n;i++){
			bottlenecks.offer(Integer.parseInt(tokens[i]));
		}
	}
	
	public int getMinTime(){
		int best = solveWithLimit(new PriorityQueue<>(bottlenecks), bottlenecks.peek());
		for(int limit=bottlenecks.peek();limit>=1;limit--){
			int solution = solveWithLimit(new PriorityQueue<>(bottlenecks), limit);
			if(solution < best){
				best = solution;
			}
		}
		return best;
	}
	
	private int solveWithLimit(PriorityQueue<Integer> queue, int limit){
		int steps = 0;
		while(queue.peek() > limit){
			int t = queue.poll();
			int a = t-limit;
			int b = t-a;
			steps++;
			queue.add(a);
			queue.add(b);
		}
		return steps + queue.peek();
	}
}
