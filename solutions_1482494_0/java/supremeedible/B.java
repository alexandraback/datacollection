import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class B {
	public static void main(String[] args) {
			Scanner scan = new Scanner(System.in);
			int T = scan.nextInt();
			
			for(int K = 1; K <= T; K++) {
					int N = scan.nextInt();
					List<Level> lv = new ArrayList<Level>();
					
					for(int i = 0; i < N; i++) {
						lv.add(new Level(scan.nextInt(), scan.nextInt()));
					}
					
					int stars = 0, games = 0;
					
					Collections.sort(lv, new Comparator<Level>() {
						public int compare(Level l1, Level l2) {
							//if(l1.b == l2.b) return (l1.a - l2.a);
							return l1.b - l2.b;
						}						
					});
					
					boolean TooBad = false;
					
					while(!lv.isEmpty() && !TooBad) {
						for(int i = 0; i < lv.size(); i++) {
							Level l = lv.get(i);
							if(l.b <= stars) {
								lv.remove(i--);
								games++;
								if(l.a == 3000) stars++;
								else stars += 2;
							} else break;
						}
						
						if(lv.isEmpty()) break;
						
						int s = stars;
					
						for(int i = lv.size() - 1; i >= 0; i--) {
							if(lv.get(i).a <= stars) {
								lv.get(i).a = 3000;
								games++;
								stars++;
								break;
							}
						}
						
						if(s == stars) { TooBad = true; }
					}
					
					if(TooBad) System.out.printf("Case #%d: Too Bad\n", K);
					else System.out.printf("Case #%d: %d\n", K, games);
			}
	}
}

class Level {
	public int a;
	public int b;
	
	public Level(int a, int b) { this.a = a; this.b = b; }
	public String toString() {
		return a + " " + b;
	}
/*	
	public static int byA(Level l1, Level l2) {
		if(l1.a == l2.a) return (l1.b - l2.b);
		return l1.a - l2.a;
	}*/
}

/*
		while(lv->size) {
			list_quick_sort(lv, byB);
			printf("List sorted with size %d\n", lv->size);

			for(i = 0; i < lv->size; i++) {
				printf("Testing element %d\n", i);
				if(stars >= ((level *)(lv->data[i]))->b) {
					stars += 2;
					games++;
					list_remove(lv, i--);
				} else break;
			}

			if(lv->size == 0) break;

			int j = 0;

			for(i = 1; i < lv->size; i++)
				if(byA(lv->data[i], lv->data[j]) < 0) j = i;

			if(((level *)(lv->data[i]))->a > stars) {
				stars = -1; // Too Bad
				break;
			} else {
				games++;
				stars++;
				((level *)(lv->data[i]))->a = 3000; // can't use this anymore
			}
		}

		if(stars == -1)
			printf("Case #%d: Too Bad\n", K);
		else
			printf("Case #%d: %d\n", K, games);
	}
}*/