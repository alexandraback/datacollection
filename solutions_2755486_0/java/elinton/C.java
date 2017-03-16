package codejam;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;


public class C extends CodeJam {

	public C(String file) throws Exception {
		super(file);
	}
	
	class Tribe {
		int attacks = 0;
		int dj, ni, wi, ei, si, delta_di, delta_pi,delta_si;
		
		Tribe(int[] data) {
			dj = data[0];
			ni = data[1];
			wi = data[2];
			ei = data[3];
			si = data[4];
			delta_di = data[5];
			delta_pi = data[6];
			delta_si = data[7];
		}
		
		public boolean canAttack() {
			return attacks < ni;
		}

		public boolean attack() {
			dj += delta_di;
			wi += delta_pi;
			ei += delta_pi;
			si += delta_si;
			attacks++;
			
			return attacks == ni;
		}
		
		@Override
		public String toString() {
			return "["+wi+","+ei+"] height: "+si+" day: "+dj;
		}
	}
	
	@Override
	public Object processCase(int caseNumber) throws Exception {
		int n = readLineInt();
		
		List<Tribe> tribes = new ArrayList<Tribe>(n);
		
		for (int i = 0; i < n; i++) {
			int[] readIntArray = readIntArray();
			//dj, ni, wi, ei, si, delta_di, delta_pi and delta_si 
			
			tribes.add(new Tribe(readIntArray));
			
		}
		
		HashMap<Integer, Integer> wall = new HashMap<Integer, Integer>();
		
		long successAttacks = 0;
		int day = 0;
		do {
			HashMap<Integer, Integer> newWall = new HashMap<Integer, Integer>();
			List<Tribe> outTribes = new ArrayList<Tribe>();
			for (Tribe tribe : tribes) {
				if (tribe.dj != day) continue;
				boolean successAttack = false;
				for (int i = tribe.wi; i < tribe.ei; i++) {
					Integer part = wall.get(i);
					if (part == null || part < tribe.si) {
						successAttack = true;
						if (newWall.get(i) == null || newWall.get(i) < tribe.si) {
							newWall.put(i, tribe.si);
						}
					}
				}
				if (successAttack) {
					successAttacks++;
				}
				
				if (tribe.attack()) {
					outTribes.add(tribe);
				}
			}
			tribes.removeAll(outTribes);
			wall.putAll(newWall);
			day++;
		} while(!tribes.isEmpty());
		
		
		return successAttacks;
		
	}
	
	public static void main(String[] args) throws IOException, InterruptedException, Exception {
		new C("C-small-attempt1.in").start();
		
	}

}
