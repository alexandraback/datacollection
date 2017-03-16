import java.util.Scanner;


public class Test3 {
	byte[][]	mulArray	= {
			{0,  0,  0,  0,  0},
			{0,  1,  2,  3,  4},
			{0,  2, -1,  4, -3},
			{0,  3, -4, -1,  2},
			{0,  4,  3, -2, -1}
	};

	byte[][]	mulArrayNeg	= {
			{0,  0,  0,  0,  0},
			{0, -1, -2, -3, -4},
			{0, -2,  1, -4,  3},
			{0, -3,  4,  1, -2},
			{0, -4, -3,  2,  1}
	};
	
	public byte getIdx(char in) {
		if(in == 'i')
			return	2;
		else if(in == 'j')
			return	3;
		else
			return	4;
	}

	public byte mul(byte a, byte b) {
		if(a > 0) {
			if(b > 0)
				return	mulArray[a][b];
			else
				return	mulArrayNeg[a][-b];
		} else {
			if(b > 0)
				return	mulArrayNeg[-a][b];
			else
				return	mulArray[-a][-b];
		}
	}
	
	public boolean solve(int l, long x, String str) {
		byte[] list	= new byte[l];
		
		for(int i=0; i<l; ++i) {
			list[i]	= getIdx(str.charAt(i));
		}
		
		return	solveSub(l, x, list);
	}
	
	public boolean solveSub(int l, long x, byte[] list) {
		long		loop	= (x < 4) ? x : 4;
		int		idxJ_Lstart	= 0;
		long		idxJ_Xstart	= 0;
		byte	tmpI		= 1;
		
		boolean	check	= true;
		for(; idxJ_Xstart < loop; idxJ_Xstart++) {
			for(idxJ_Lstart=0; idxJ_Lstart<l; ++idxJ_Lstart) {
				tmpI	= mul(tmpI, list[idxJ_Lstart]);
				if(tmpI == 2 || tmpI == -2) {
					check	= false;
					break;
				}
			}
			if(!check)
				break;
		}
		
		if(tmpI != 2 && tmpI != -2)
			return	false;
		
		idxJ_Lstart++;
		
//		System.out.println("I: " + tmpI + ", " + idxJ_Xstart + ", " + idxJ_Lstart);
		
		
		
		long		loop2	= (x < 4) ? 0 : x-4;
		int		idxJ_Lend	= l-1;
		long		idxJ_Xend	= x-1;
		byte	tmpK		= 1;
		
		check	= true;
		for(; idxJ_Xend >= loop2; idxJ_Xend--) {
			for(idxJ_Lend=l-1; idxJ_Lend>=0; idxJ_Lend--) {
				tmpK	= mul(list[idxJ_Lend], tmpK);
				if(tmpK == 4 || tmpK == -4) {
					check	= false;
					break;
				}
			}
			if(!check)
				break;
		}
		
		if(tmpK != 4 && tmpK != -4)
			return	false;
		
		idxJ_Lend--;
		
//		System.out.println("K: " + tmpK + ", " + idxJ_Xend + ", " + idxJ_Lend);

		
		
		if((idxJ_Xstart + 5) <= idxJ_Xend) {
			idxJ_Xend	= ((idxJ_Xend - idxJ_Xstart + 1 - 2) % 4) + 1 + idxJ_Xstart;
		}
		
		byte	tmpJ	= 1;
		for(long i=idxJ_Xstart; i<=idxJ_Xend; ++i) {
			int	s	= (i == idxJ_Xstart) ? idxJ_Lstart : 0;
			int	e	= (i == idxJ_Xend) ? idxJ_Lend : l-1;
			for(int j=s; j<=e; ++j) {
				tmpJ	= mul(tmpJ, list[j]);
			}
		}
		
//		System.out.println(tmpJ + ", " + (tmpI + tmpJ + tmpK));
		
		tmpI	*= tmpJ;
		tmpI	*= tmpK;
		
		if(tmpI == 24)
			return	true;
		return	false;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Test3	inst	= new Test3();
			int		l		= scanIn.nextInt();
			long		x		= scanIn.nextLong();
			
			String	str		= scanIn.nextLine();
			str		= scanIn.nextLine();
			
			boolean	ret	= inst.solve(l, x, str);
			
			if(ret)
				System.out.println("Case #" + (i+1) + ": YES");
			else
				System.out.println("Case #" + (i+1) + ": NO");
		}
		
		scanIn.close();
	}
}
