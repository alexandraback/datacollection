package round1c;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class C {
	
	public static class Item {
		public int type;
		public long count;
		
		public Item(int type, long count) {
			this.type = type;
			this.count = count;
		}

		@Override
		public String toString() {
			return "Type: " + type + ", Count: " + count;
		}
		
		
	}
	
	public static long max = 0;
	
	public static void solve(List<Item> boxes, List<Item> toys, long currentCount) {
		if (boxes.isEmpty() || toys.isEmpty()) {
			if (currentCount > max) {
				max = currentCount;
			}
		} else if (boxes.get(0).type == toys.get(0).type) {
			//System.out.println("Count: " + currentCount + ", " + boxes + ", " + toys);
			List<Item> newBoxes = new ArrayList<Item>(boxes.size());
			List<Item> newToys = new ArrayList<Item>(toys.size());
			Item firstBox = boxes.get(0);
			Item firstToy = toys.get(0);
			long used = Math.min(firstBox.count, firstToy.count);
			if (firstBox.count > used) {
				newBoxes.add(new Item(firstBox.type, firstBox.count - used));
			}
			if (firstToy.count > used) {
				newToys.add(new Item(firstToy.type, firstToy.count - used));
			}
			for (int i=1;i<boxes.size();i++) {
				newBoxes.add(boxes.get(i));
			}
			for (int i=1;i<toys.size();i++) {
				newToys.add(toys.get(i));
			}
			solve(newBoxes, newToys, currentCount + used);
		} else {
			List<Item> newBoxes = new ArrayList<Item>(boxes.size());
			for (int i=1;i<boxes.size();i++) {
				newBoxes.add(boxes.get(i));
			}
			solve(newBoxes, toys, currentCount);

			List<Item> newToys = new ArrayList<Item>(boxes.size());
			for (int i=1;i<toys.size();i++) {
				newToys.add(toys.get(i));
			}
			solve(boxes, newToys, currentCount);
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i=0;i<t;i++) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			List<Item> boxes = new ArrayList<Item>(n);
			List<Item> toys = new ArrayList<Item>(m);
			
			for (int j=0;j<n;j++) {
				long count = sc.nextLong();
				int type = sc.nextInt();
				boxes.add(new Item(type, count));
			}
			for (int j=0;j<m;j++) {
				long count = sc.nextLong();
				int type = sc.nextInt();
				toys.add(new Item(type, count));
			}
			
			max = 0;
			solve(boxes, toys, 0);
			
			System.out.println("Case #" + (i + 1) + ": " + max);
		}
	}
}
