import java.util.*;

public class C{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int nCases = sc.nextInt();
		for(int caseN = 1; caseN <= nCases; caseN++){
			int n = sc.nextInt();
			int m = sc.nextInt();
			LinkedList<Pair> boxes = new LinkedList<Pair>();
			LinkedList<Pair> toys = new LinkedList<Pair>();
			for(int i = 0; i < n; i++){
				boxes.add(new Pair(sc.nextLong(), sc.nextInt()));
			}
			for(int i = 0; i < m; i++){
				toys.add(new Pair(sc.nextLong(), sc.nextInt()));
			}
			System.out.printf("Case #%d: " + findNum(boxes, toys) + "\n", caseN);
		}
	}
	public static long findNum(LinkedList<Pair> boxes, LinkedList<Pair> toys){
		//System.out.println("boxes: " + boxes);
		//System.out.println("toys:  " + toys);
		//System.out.println();
		if(boxes.size() == 0 || toys.size() == 0){
			return 0;
		}
		long sum = 0;
		Pair box = boxes.removeFirst();
		Pair toy = toys.removeFirst();
		if(box.type == toy.type){
			long num = 0;
			if(box.num < toy.num){
				toy.num -= box.num;
				toys.addFirst(toy);

				sum = box.num + findNum(boxes, toys);
				toy.num += box.num;
				boxes.addFirst(box);

				return sum;
			}
			else if(box.num > toy.num){
				box.num -= toy.num;
				boxes.addFirst(box);

				sum = toy.num + findNum(boxes, toys);
				box.num += toy.num;
				toys.addFirst(toy);

				return sum;
			}
			else{
				sum = toy.num + findNum(boxes, toys);
				boxes.addFirst(box);
				toys.addFirst(toy);

				return sum;
			}

		}
		else{
			boxes.addFirst(box);
			//System.out.println("Removing toy");
			long num1 = findNum(boxes, toys);
			boxes.removeFirst();

			toys.addFirst(toy);
			//System.out.println("Removing box");
			long num2 = findNum(boxes, toys);
			
			boxes.addFirst(box);

			if(num1 > num2){
				return num1;
			}
			else{
				return num2;
			}
		}
	}
	/*public static long upperBound(LinkedList<Pair> ll){
		long sum = 0;
		for(Pair p : ll){
			sum += p.num;
		}
		return p;
	}*/
}
class Pair{
	long num;
	int type;
	public Pair(long n, int t){
		num = n;
		type = t;
	}
	public String toString(){
		return "num=" + num + " type=" + type;
	}
}