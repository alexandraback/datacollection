package pkg;

import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;


public class Solution {
    public static List<String> read(String fileName) {
    	List<String> ret = new ArrayList<String>();
        FileReader f = null;
        BufferedReader b = null;
    	try{
            f = new FileReader(fileName);
            b = new BufferedReader(f);
            String s;
            while((s = b.readLine())!=null) {
                ret.add(s);
            }
        } catch(Exception e) {
        	e.printStackTrace();
        } finally {
        	try {
        		if (b != null) {
        			b.close();
        		}
        	} catch (Exception e) {
        		e.printStackTrace();
        	}
        	try {
        		if (f != null) {
        			f.close();
        		}
        	} catch (Exception e) {
        		e.printStackTrace();
        	}

        }
        return ret;
    }
    public static void write(String fileName, List<String> data) {
        FileWriter f = null;
        try{
        	File outF = new File(fileName);
            f = new FileWriter(outF);
            for(int n = 0; n < data.size(); n++) {
            	f.write(data.get(n));
            	f.write("\r\n");
            }
        }catch(Exception e){
        	e.printStackTrace();
        } finally {
        	try {
        		if (f != null) {
        			f.close();
        		}
        	} catch (Exception e) {
        		e.printStackTrace();
        	}
        }
    }

    static int nowX = 0;
    static int nowY = 0;
	static int add = 1;
	static StringBuffer result = new StringBuffer();
	public static void main(String arg[]) {
		List<String> data = read(arg[0]);
		String tmp = data.get(0);
		int times = Integer.parseInt(tmp);
		List<String> outData = new ArrayList<String>();
		int m = 1;
		for (int n = 0; n < times; n++) {
			String xy = data.get(m);
			m++;
			int X = (new Integer(xy.split(" ")[0])).intValue();
			int Y = (new Integer(xy.split(" ")[1])).intValue();
			
			nowX = 0;
			nowY = 0;
			add = 0;
			result = new StringBuffer();
			
			int farX = Math.abs(nowX - X);
			int farY = Math.abs(nowY - Y);
			while (!(nowX == X && nowY == Y)) {
				if (add > 500) break;
				farX = Math.abs(nowX - X);
				farY = Math.abs(nowY - Y);
				if (farX > farY ) {
					// X‰“‚¢
					if (X > nowX) {
						for (int xx = nowX; xx < farX*2; xx++) {
							if (xx % 2 == 1) {
								move("E");
							} else {
								move("W");
							}
						}
					} else {
						for (int xx = nowX; xx < farX*2; xx++) {
							if (xx % 2 == 1) {
								move("W");
							} else {
								move("E");
							}
						}
					}
				} else {
					// Y‰“‚¢
					if (Y > nowY) {
						for (int yy = nowY; yy < farY*2; yy++) {
							if (yy % 2 == 1) {
								move("N");
							} else {
								move("S");
							}
						}
					} else {
						for (int yy = nowY; yy < farY*2; yy++) {
							if (yy % 2 == 1) {
								move("S");
							} else {
								move("N");
							}
						}
					}
				}
			}
//			System.out.println();
			
			StringBuffer out = new StringBuffer();
			int c = n + 1;
			out.append("Case #" + c + ": " + result.toString());
			System.out.println(out.toString());
			outData.add(out.toString());
		}
		write(arg[1], outData);
	}

	public static void move(String adr){
		add++;
		result.append(adr);
		if (adr.equals("N")) {
			nowY += add;
		}
		if (adr.equals("S")) {
			nowY -= add;
		}
		if (adr.equals("E")) {
			nowX += add;
		}
		if (adr.equals("W")) {
			nowX -= add;
		}
	}
}
