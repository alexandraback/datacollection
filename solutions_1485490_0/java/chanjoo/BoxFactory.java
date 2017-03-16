package codejam;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class BoxFactory extends Solver {

	public static void main(String...args) {
		BoxFactory solver = new BoxFactory();
//		solver.solveSample();
		solver.solveSmall(1);
//		solver.solveLarge();
	}
	
	public BoxFactory() {
		super('C');
	}

	Line box;
	Line toy;
	long current;
	long made;
	Set<Long> types;
	
	@Override
	public void read(Scanner in) {
		types = new HashSet<Long>();
		current = made = 0;
		box = new Line(in.nextInt());
		toy = new Line(in.nextInt());
		box.read(in);
		toy.read(in);
	}
	
	@Override
	public String evaluate() {
		boolean keepgoing = true;
		while(keepgoing) {
			long score = Long.MIN_VALUE;
			long typeToMake = -1;
			for(Long t: types) {
				long trashOfBox = box.countTrashFor(t);
				long trashOfToy = toy.countTrashFor(t);
				long availble = min(box.countAvailableFor(t), toy.countAvailableFor(t));
				if(score < availble - trashOfBox - trashOfToy) {
					typeToMake = t;
					score = availble - trashOfBox - trashOfToy;
				}
			}
			
			keepgoing = box.dumpFor(typeToMake) && toy.dumpFor(typeToMake);
			if(!keepgoing) break;
			
			long availableBox = box.available(typeToMake);
			long availableToy = toy.available(typeToMake);
			long available = Math.min(availableBox, availableToy);
			
			keepgoing = box.use(available) && toy.use(available);
			
			made += available;
		}
		
		return String.valueOf(made);
	}
	
	private long min(long a, long b) {
		return a<b?a:b;
	}
	
	class Line {
		int chunk;
		long remain;
		int cursor;
		long[] count;
		long[] type;
		
		public Line(int chunk) {
			this.chunk = chunk;
			count = new long[chunk];
			type = new long[chunk];
		}
		
		public void read(Scanner in) {
			for(int i=0; i<chunk; i++) {
				count[i] = in.nextLong();
				type[i] = in.nextLong();
				types.add(type[i]);
			}
			cursor = 0;
			remain = count[0];
		}
		
		public long countTrashFor(long type) {
			if(this.type[cursor]==type) return 0;
			long trash = remain;
			for(int i=cursor+1; i<chunk; i++) {
				if(this.type[i]==type) break;
				trash += count[i];
			}
			return trash;
		}
		
		public long countAvailableFor(long type) {
			if(this.type[cursor]==type) return remain;
			for(int i=cursor+1; i<chunk; i++) {
				if(this.type[i]==type)
					return count[i];
			}
			return 0;
		}
		
		public boolean dumpFor(long type) {
			while(this.type[cursor]!=type) {
				cursor++;
				if(cursor==chunk) return false;
				remain = count[cursor];
			}
			return true;
		}
		
		public long available(long type) {
			if(this.type[cursor]==type) return remain;
			for(int i=cursor+1; i<chunk; i++) {
				if(this.type[i]==type) 
					return count[i];
			}
			return 0;
		}
		
		public boolean use(long count) {
			remain -= count;
			if(remain==0) {
				cursor++;
				if(cursor==chunk) return false;
				remain = this.count[cursor];
			} else if(remain<0) {
				throw new RuntimeException("?????");
			}
			
			return true;
		}
	}
}
