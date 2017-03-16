package war;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class WAR {

	int nblocks;
	private List<Double> naomis = new LinkedList<>();
	private List<Double> kens = new LinkedList<>();

	public WAR(int n, String naomis, String kens){
		nblocks = n;
		String naomisStrings[] = naomis.split(" ");
		String kensStrings[] = kens.split(" ");
		for(String naomi:naomisStrings)
			this.naomis.add(Double.parseDouble(naomi));
		for(String ken:kensStrings)
			this.kens.add(Double.parseDouble(ken));
		Collections.sort(this.naomis);
		Collections.sort(this.kens);
	}
	public int solveDeceitfulWar(){
		List<Double> naomisAlt = new LinkedList<>(naomis);
		List<Double> kensAlt = new LinkedList<>(kens);
		int naomisScore = 0;
		int kensScore = 0;
		while(!naomisAlt.isEmpty()){
			//pick naomis
			double naomisSmallest = naomisAlt.remove(0);
			double kensSmallest = kensAlt.get(0);
			if(naomisSmallest > kensSmallest){
				kensAlt.remove(0);//smallest agains smallest
				naomisScore++;
				continue;
			}

			double kensBiggest = kensAlt.remove(kensAlt.size()-1);
			double told_naomi = (naomisSmallest+kensBiggest)/2.0;
			for(int i = kensAlt.size()-1;i>=0;i--){
				double kensNotBiggest = kensAlt.get(i);
				if(kensNotBiggest != kensBiggest){
					told_naomi = (kensNotBiggest+kensBiggest)/2.0;
					break;
				}
			}
			kensScore++;
		}
		return naomisScore;
	}
	public int solveWar(){
		List<Double> naomisAlt = new LinkedList<>(naomis);
		List<Double> kensAlt = new LinkedList<>(kens);
		int naomisScore = 0;
		int kensScore = 0;
		while(!naomisAlt.isEmpty()){
			//pick naomis
			double naomisBiggest = naomisAlt.remove(naomisAlt.size()-1);
			double kensBiggest = kensAlt.get(kensAlt.size()-1);
			if(naomisBiggest < kensBiggest){
				kensAlt.remove(kensAlt.size()-1);//Ken won with his biggest
				kensScore++;
				continue;
			}
			kensAlt.remove(0);//ken sacrifice his smallest
			naomisScore++;
		}
		return naomisScore;
	}
	static public void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("input_war.txt"));
		int nTest = Integer.parseInt(bf.readLine());
		for(int t = 1;t<=nTest;t++){
			int n = Integer.parseInt(bf.readLine());
			WAR war = new WAR(n,bf.readLine(),bf.readLine());
			System.out.println("Case #"+t+": "+war.solveDeceitfulWar() + " "+ war.solveWar());
		}
		bf.close();
	}
}
