import java.util.*;

public class b {
	
	static int getMax(SortedMap<Integer, Integer> map, int special, int max) {
		int number = map.lastKey();
		int count = map.get(number);
		
		if (number <= 3) {
			return Math.min(max, number+special);
		}
	
		map.remove(number);
		int min = max;
		int start = number / 2 + number % 2;
		for (int child1 = start; child1 < number; child1++) {
			SortedMap<Integer, Integer> other = new TreeMap<Integer, Integer>(map);
			int child2 = number - child1;
			int cnt1 = 0;
			if (other.containsKey(child1)) {
				cnt1 = other.get(child1);
			}
			other.put(child1, cnt1 + count);

			int cnt2 = 0;
			if (other.containsKey(child2)) {
				cnt2 = other.get(child2);
			}
			other.put(child2, cnt2 + count);
			
			int divide = getMax(other, count, number);
			min = Math.min(min, divide + special);
		}

		return min;
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {

			int D = in.nextInt();
			int[] P = new int[D];

			SortedMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
			for (int i = 0; i < P.length; i++) {
				P[i] = in.nextInt();
				
				int cnt = 0;
				if (map.containsKey(P[i])) {
					cnt = map.get(P[i]);
				}
				
				map.put(P[i], cnt + 1);
			}
			
			int max = map.lastKey();
			int total = getMax(map, 0, max);
			
//			for (int i = 0; i < P.length; i++) {
//				System.out.printf("%d, ", P[i]);
//			}
//			System.out.println();
			System.out.printf("Case #%d: %d\n", t, total);
		}
	}
//	
//	static int calc(PriorityQueue<Integer> queue, int minute, int min) {
//		System.out.printf("In minute %d, min is %d, queue is \n", minute, min);
//		Integer[] data1 = queue.toArray(new Integer[queue.size()]);
//		for (int i = 0; i < data1.length; i++) {
//			System.out.printf("%d, ", data1[i]);
//		}
//		System.out.println();
//		
//		if(minute >= min)
//			return min;
//		if(queue.isEmpty())
//			return Math.min(minute, min);
//		
//		PriorityQueue<Integer> next = new PriorityQueue<>(1, Collections.reverseOrder());
//		Integer[] data = queue.toArray(new Integer[queue.size()]);
//		for (int i = 0; i < data.length; i++) {
//			if (data[i] > 1) {
//				next.add(data[i] - 1);
//			}
//		}
//		
//		int notdivide = calc(next, minute+1, min);
//		min = Math.min(min, notdivide);
//		
//		int max = queue.poll();
//		if (max <= 3) {
//			// do not need to devide
//			return min;
//		} else {
//			int child1 = max / 2 + max % 2;
//			for (int child = child1; child < max; child++) {
//				int child2 = max - child;
//
//				PriorityQueue<Integer> another = new PriorityQueue<>(1, Collections.reverseOrder());
//				another.addAll(queue);
//				another.add(child);
//				another.add(child2);
//				int divide = calc(another, minute+1, min);
//				min = Math.min(min, divide);
//			}
//			
//			return min;
//		}
//		
//	}
//	
//	public static void main2(String[] args) {
//		Scanner in = new Scanner(System.in);
//
//		int T = in.nextInt();
//		for (int t = 1; t <= T; t++) {
//
//			int D = in.nextInt();
//			int[] P = new int[D];
//			
//			PriorityQueue<Integer> queue = new PriorityQueue<Integer>(1, Collections.reverseOrder());
//			for (int i = 0; i < P.length; i++) {
//				P[i] = in.nextInt();
//				queue.add(P[i]);
//			}
//			
//			int total = calc(queue, 0, Integer.MAX_VALUE);
//			System.out.printf("Case #%d: %d\n", t, total);
//		}
//	}
}