

public class Jeu {

	private double C;
	private double F;
	private double X;
	
	private double R;
	private double T;
	
	public Jeu(String string) {
		String[] split = string.split(" ");
		C = Double.valueOf(split[0]);
		F = Double.valueOf(split[1]);
		X = Double.valueOf(split[2]);
		R = Double.valueOf(2);
	}
	
	public String compute() {
		T = X / R;
		
		double Tprime = C / R + X / (R + F);
		double prec = Math.pow(10, -16);
		// Tprime < T
		while (Tprime < T && Math.abs(T - Tprime) > prec) {
			T = Tprime;
			Tprime = Tprime - X / (R + F);
			R = R + F;
			Tprime = Tprime + C / R + X / (R + F);
		}
		T = (double) Math.round(T * 10000000) / 10000000;
		String s = String.valueOf(T);
		int indexOf = s.indexOf(".");
		String substring = s.substring(indexOf + 1);
		if (substring.length() == 1) {
			return String.valueOf(T + "000000");
		} else if (substring.length() == 2) {
			return String.valueOf(T + "00000");
		} else if (substring.length() == 3) {
			return String.valueOf(T + "0000");
		} else if (substring.length() == 4) {
			return String.valueOf(T + "000");
		} else if (substring.length() == 5) {
			return String.valueOf(T + "00");
		} else if (substring.length() == 6) {
			return String.valueOf(T + "0");
		} 
		return String.valueOf(T);
	}
	
}
