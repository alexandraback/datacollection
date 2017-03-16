package com.google.codejam;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class ReadIO {
	private FileReader fileReader;
	private BufferedReader bufferedReader;
	public ReadIO(String filepath) {
		try {
			File file = new File(filepath);
			fileReader = new FileReader(file);
			bufferedReader = new BufferedReader(fileReader);
		} catch (Exception ex) {
			
		}
	}
	
	public String readLine() {
		try {
			return bufferedReader.readLine();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	public void close() {
		if (bufferedReader != null) {
			try {
				bufferedReader.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			bufferedReader = null;
		}
		if (fileReader != null) {
			try {
				fileReader.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			fileReader = null;
		}
	}
}

class WriteIO {
	private FileOutputStream fos;
	private OutputStreamWriter writer;
	public WriteIO(String filepath) {
		try {
			File file = new File(filepath);
			file.createNewFile();
			fos = new FileOutputStream(file);
			writer = new OutputStreamWriter(fos);
		} catch (Exception ex) {
			
		}
	}
	
	public void writeLine(String str) {
		try {
			writer.write(str+ System.getProperty("line.separator"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void close() {
		if (writer != null) {
			try {
				writer.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			try {
				writer.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			writer = null;
		}
		if (fos != null) {
			try {
				fos.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			fos = null;
		}
	}
}

public class GreatWall {
	private ReadIO mRead;
	private WriteIO mWrite;
	public void setIO(ReadIO read, WriteIO write) {
		mRead = read;
		mWrite = write;
	}
	
	static class Tribe {
		public int initDay; 
		public int attackCount;
		public int west;
		public int east;
		public int strength;
		public int delta_day;
		public int delta_distance;
		public int delta_strenth;
		
		public int c_west;
		public int c_east;
		public int c_strength;
		public Tribe(int initDay, int attackCount, int west, int east, int strength,
				int delta_day, int delta_distance, int delta_strenth) {
			this.initDay = initDay;
			this.attackCount = attackCount;
			this.west = west;
			this.east = east;
			this.strength = strength;
			this.delta_day = delta_day;
			this.delta_distance = delta_distance;
			this.delta_strenth = delta_strenth;
			
			c_west = west;
			c_east = east;
			c_strength = strength;
		}
		public void attackOnce() {
			c_west += delta_distance;
			c_east += delta_distance;
			c_strength += delta_strenth;
		}
	}
	
	static class Attack {
		public int[] wall = new int[5000000];
		public static final int OFFSET = 10000;
		public Tribe[] tribes;
		int getResult() {
			Map<Integer, List<Integer>> schedule = new HashMap<Integer, List<Integer>>();
			List<Integer> listDays = new ArrayList<Integer>();
			for (int i = 0; i<tribes.length; ++i) {
				Tribe tribe = tribes[i];
				int day = tribe.initDay;
				int attackCount = tribe.attackCount;
				int delta_day = tribe.delta_day;
				while (attackCount > 0) {
					List<Integer> list = schedule.get(day);
					if (list == null) {
						listDays.add(day);
						List<Integer> tribeIndexList = new ArrayList<Integer>();
						tribeIndexList.add(i);
						schedule.put(day, tribeIndexList);
					} else {
						list.add(i);
					}
					attackCount--;
					day += delta_day;
				}
			}
			Collections.sort(listDays);
			int win = 0;
			for (Integer day : listDays) {
				List<Integer> tribeIndexList = schedule.get(day);
				for (int index : tribeIndexList) {
					Tribe tribe = tribes[index];
					int west = tribe.c_west+OFFSET;
					int east = tribe.c_east+OFFSET;
					int strength = tribe.c_strength;
					for (int i = west*2; i<=east*2; ++i) {
						if (i< 0 || i> 50000) {
							int j = 0;
							j++;
						}
						if (wall[i] < strength) {
							win++;
							break;
						}
					}
				}
				for (int index : tribeIndexList) {
					Tribe tribe = tribes[index];
					int west = tribe.c_west+OFFSET;
					int east = tribe.c_east+OFFSET;
					int strength = tribe.c_strength;
					for (int i = west*2; i<=east*2; ++i) {
						if (wall[i] < strength) {
							wall[i] = strength;
						}
					}
					tribe.attackOnce();
				}
			}
			return win;
		}
	}
	public void process() {
		int caseCount = Integer.parseInt(mRead.readLine());
		for (int i = 0; i<caseCount; ++i) {
			int tribeCount = Integer.parseInt(mRead.readLine());
			Tribe[] tribes = new Tribe[tribeCount];
			for (int j = 0; j<tribeCount; ++j) {
				String[] str = mRead.readLine().split(" ");
				tribes[j] = new Tribe(Integer.parseInt(str[0]),
						Integer.parseInt(str[1]), Integer.parseInt(str[2]),
						Integer.parseInt(str[3]), Integer.parseInt(str[4]),
						Integer.parseInt(str[5]), Integer.parseInt(str[6]),
						Integer.parseInt(str[7]));
			}
			Attack attack = new Attack();
			attack.tribes = tribes;
			String result = String.format("Case #%d: %d", i+1, attack.getResult());
			mWrite.writeLine(result);
		}
	}
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ReadIO read = new ReadIO("C-small-attempt1.in");
		WriteIO write = new WriteIO("output.txt");
		GreatWall demo = new GreatWall();
		demo.setIO(read, write);
		demo.process();
		read.close();
		write.close();
		demo.setIO(null, null);
	}

}
