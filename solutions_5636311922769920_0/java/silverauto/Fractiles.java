package main;

public class Fractiles extends CodeJamBase {
    int[] slots;
    char[] track;
	@Override
	public String doResolve(int count, String line, int lineNum) {
		String[] strs = line.split(this.SPACE_CHAR);
		int k = Integer.parseInt(strs[0]);
		int c = Integer.parseInt(strs[1]);
		int s = Integer.parseInt(strs[2]);
		String result = "";
//		System.out.println(k + " "+c+" " + s);
		if(c == 1) {
			for(int i=1;i<=k;i++) {
				result += i + " ";
			}
			return result;
		} else if(k == 1) {
			result = "1";
			return result;
		} else if(k == s) {
			for(int i=2;i<=k;i++) {
				result += i + " ";
			}
			
			return result;
		}
//		int slotNum = (int) Math.pow(k, c);
//		System.out.println("slotNum= " + slotNum);
//		slots = new int[slotNum];
//		track = new char[k];				
//		permutate(k, c, 0);
		return null;
	}
	
//	void permutate(int k, int c, int index) {
//		if(index == track.length) {
//			String org = charArrayToString(track);
//			System.out.println("org : " + org);
//			String artwork = org;
//			for(int i=0;i<c;i++) {
//				int size = artwork.length();
//				StringBuilder result = new StringBuilder();
//				for(int j=0;j<size;j++) {
//					result.append(getReplacement(org, artwork, j, k));
//				}
//				artwork = result.toString();
//				System.out.println("artwork: " + artwork);
//				int artworkSize = artwork.length();
//				for(int a=0;a<artworkSize;a++) {
//					slots[a] += artwork.charAt(a) == 'L' ? 1 : 0;
//				}
//				
//			}
//			return;
//		}
//		
//		track[index] = 'G';
//		permutate(k, c, index+1);
//		
//		track[index] = 'K';
//		permutate(k, c, index+1);
//	}
	
	public String getReplacement(String org, String artwork, int pos, int k) {
		if(artwork.charAt(pos) == 'G') {
			return getGSeq(k);
		} else {
		    return org;
		}
	}
	
	private String getGSeq(int length) {
		StringBuilder gSeq = new StringBuilder();
		for(int i=0;i<length;i++) {
			gSeq.append("G");
		}
		return gSeq.toString();
	}
	
	String charArrayToString(char[] charArray) {
		StringBuilder str = new StringBuilder();
		for(char ch : charArray) {
			str.append(ch);
		}
		return str.toString();
	}

	public static void main(String[] args) {
		Fractiles test = new Fractiles();
		test.start();

	}

}
