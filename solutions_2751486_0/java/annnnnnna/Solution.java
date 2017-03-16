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

	public static void main(String arg[]) {
		List<String> data = read(arg[0]);
		String tmp = data.get(0);
		int times = Integer.parseInt(tmp);
		List<String> outData = new ArrayList<String>();
		int m = 1;
		String maxMoteStr = "1000000";
		for (int n = 0; n < times; n++) {
			String names = data.get(m);
			m++;
			String baseName = names.split(" ")[0];
			BigInteger nLn = new BigInteger(names.split(" ")[1]);
			
			char baseNameArr[] = baseName.toCharArray();
			
			int result = 0;
			
			for (int h = 0; h < baseNameArr.length; h++) {
				for (int t = baseNameArr.length; t > h; t--) {
					String sbstr = baseName.substring(h, t);
//					System.out.print(sbstr + ":");
					boolean ok = chk(sbstr, nLn);
					if (ok) {
						result++;
					}
				}
			}
//			System.out.println();
			
			StringBuffer out = new StringBuffer();
			int c = n + 1;
			out.append("Case #" + c + ": " + result);
			System.out.println(out.toString());
			outData.add(out.toString());
		}
		write(arg[1], outData);
	}

	public static boolean chk(String str, BigInteger n) {
		BigInteger strLen = new BigInteger(new Integer(str.length()).toString());
		if (strLen.compareTo(n) < 0) return false;
		boolean ret = false;
		BigInteger combo = BigInteger.ZERO;
		char s[] = str.toCharArray();
		for (int h = 0; h < s.length; h++) {
			if (s[h] != 'a' && s[h] != 'i' && s[h] != 'u' && s[h] != 'e' && s[h] != 'o') {
				if (combo.compareTo(n) >= 0) {
					return true;
				}
				combo = combo.add(BigInteger.ONE);
			} else {
				if (combo.compareTo(n) >= 0) {
					return true;
				} else {
					combo = BigInteger.ZERO;
				}
			}
		}
		if (combo.compareTo(n) >= 0) {
			return true;
		} else {
			return false;
		}
	}
}
