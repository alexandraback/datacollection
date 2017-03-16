

public class Tribe implements Comparable<Tribe> {
		private long next_attack;
		private long delta_attack;
		private long delta_x;
		private long delta_strength;
		
		
		private long attacks_remaining;
		private long next_strength;
		private long next_ini_x;
		private long next_fin_x;
		
		public Tribe (String linea) {
			String[] pedazos = linea.split(" ");
			next_attack = Long.parseLong(pedazos[0]);
			attacks_remaining = Long.parseLong(pedazos[1]);
			next_ini_x = Long.parseLong(pedazos[2]);
			next_fin_x = Long.parseLong(pedazos[3]);
			next_strength = Long.parseLong(pedazos[4]);
			delta_attack = Long.parseLong(pedazos[5]);
			delta_x = Long.parseLong(pedazos[6]);
			delta_strength = Long.parseLong(pedazos[7]);
		}
		
		public Tribe(Tribe t) {
			next_attack = t.next_attack;
			attacks_remaining = t.attacks_remaining;
			next_ini_x = t.next_ini_x;
			next_fin_x = t.next_fin_x;
			next_strength = t.next_strength;
			delta_attack = t.delta_attack;
			delta_x = t.delta_x;
			delta_strength = t.delta_strength;
		}
		
		public long getDay() {
			return next_attack;
		}
		
		public long getStrength() {
			return next_strength;
		}
		public long getIniX() {
			return next_ini_x;
		}
		public long getFinX() {
			return next_fin_x;
		}
		public boolean attack() {
			next_attack += delta_attack;
			next_ini_x += delta_x;
			next_fin_x += delta_x;
			next_strength += delta_strength;
			attacks_remaining--;
			if(next_strength <= 0)
				return false;
			return attacks_remaining > 0;
		}

		@Override
		public int compareTo(Tribe o) {
			if(next_attack == o.next_attack)
				return 0;
			if(next_attack < o.next_attack)
				return -1;
			return 1;
		}
		
	}