import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class InfiniteHouseOfPancakes {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int times = reader.nextInt();
		
		for(int t = 0; t < times; t++){
			int dishNumber = reader.nextInt();
			int min = 10;
			int max = 0;
			int[] array = new int[dishNumber];
			for(int d = 0; d < dishNumber; d++){
				array[d] = reader.nextInt();
				if (max < array[d]){
					max = array[d];
				}
			}
			Arrays.sort(array);
			min = max;
			for(int pivot = max; pivot> 0; pivot--){
				int index = array.length -1;
				int count = 0;
				while(index >= 0 && array[index] > pivot){
					int buff = array[index] - pivot;
					buff = (int) Math.ceil(((double) buff) / pivot);
					count += buff;
					index--;
				}
				count += pivot;
				if(min > count){
					min = count;
				}
			}
//			PriorityQueue<Integer> q = new PriorityQueue<Integer>
//				(dishNumber, new MyComparator<Integer>());
//			for(int d = 0; d < dishNumber; d++){
//				int integer = reader.nextInt();
//				System.out.print(integer);
//				q.add(integer);
//			}
//			System.out.println();
//			int[] array = new int[q.peek() + 1];
//			for(Integer ints: q){
//				array[ints] += 1;
//			}
//			int min = q.peek();
//			int count = 0;
//			while(check(array, q)){
//				int i = q.remove();
//				if(i % 2 == 0){
//					q.add(i/2);
//					q.add(i/2);
//					array[i/2] += 2;
//				} else {
//					q.add(i/2 + 1);
//					q.add(i/2);
//					array[i/2 + 1] += 1;
//					array[i/2] += 1;
//				}
//				count++;
//				array[i]--;
//				if(min > q.peek() + count){
//					min = q.peek() + count;
//				}
//			}
			System.out.println("Case #" + (t+1) + ": " + min);
			
		}
		
		reader.close();
	}
	
	static boolean check(int[] array, PriorityQueue<Integer> q){
		int first = q.peek();
		return array[first] * 2 < first;
	}
	
	static class MyComparator<Integer> implements Comparator<Integer>{

		@Override
		public int compare(Integer arg1, Integer arg0) {
			int i1 = ((java.lang.Integer) arg1).intValue();
			int i2 = ((java.lang.Integer) arg0).intValue();
			return i2 - i1;
		}
		
	}
		
	

}
