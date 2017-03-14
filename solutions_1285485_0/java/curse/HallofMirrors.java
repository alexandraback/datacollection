import java.io.*;
import java.util.StringTokenizer;

public class HallofMirrors {
	private static char[][] hall;
	private static byte[][] plane;

	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("D.in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("D.out"));
			int numCase = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCase; i++) {
				StringTokenizer st = new StringTokenizer(ifStream.readLine(), " ", false);
				int H = Integer.parseInt(st.nextToken());
				int W = Integer.parseInt(st.nextToken());
				int D = Integer.parseInt(st.nextToken());
				hall = new char[H][W];

				for (int j=0; j<H; j++) {
					String line = ifStream.readLine();
					for (int k=0; k<W; k++) {
						hall[j][k] = line.charAt(k);
					}
				}
				ofStream.println("Case #"+i+": "+HallofMirrors(H, W, D));
			}
			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static int HallofMirrors(int row, int col, int maxDis) {
		int size = maxDis*2+1;
		int center = maxDis;
		int left=0, right=0, up=0, down=0, result=0;
		int h, w, wSign, hSign, gcdhw;
		boolean first;

		setPlane(row, col, maxDis);
		for (int i=0; i<size; i++) {
			for (int j=0; j<size; j++) {
				h = diff(i, center);
				w = diff(j, center);
				if (plane[i][j] == 1 && h*h+w*w <= maxDis*maxDis) {
					if (h == 0 && w != 0) {
						if (j<center) {
							left = 1;
						}
						else {
							right = 1;
						}
					}
					else if (h != 0 && w == 0) {
						if (i>center) {
							up = 1;
						}
						else {
							down = 1;
						}
					}
					else if (h != 0 && w != 0) {
						first = true;
						hSign = 1;
						wSign = 1;
						if (i < center) {
							hSign = -1;
						}
						if (j < center) {
							wSign = -1;
						}
						gcdhw = gcd(h, w);
						h /= gcdhw;
						w /= gcdhw;
						for (int k=1; k<gcdhw; k++) {
							if (plane[center+(h*k*hSign)][center+(w*k*wSign)] == 1) {
								first = false;
								break;
							}
						}
						if (first) {
							result++;
						}
					}
				}
			}
		}
		result += left + right + up + down;

		return result;
	}

	private static int diff(int a, int b) {
		return (a >= b) ? (a-b) : (b-a);
	}

	private static int gcd(int a, int b) {
		int tmp;

		if (a < b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		while (b != 0) {	// Euclidean algorithm.
			tmp = a % b;
			a = b;
			b = tmp;
		}

		return a;
	}

	private static void setPlane(int row, int col, int maxDis) {
		int size = maxDis*2+1;
		int center = maxDis;
		int frameNum, tmp, i, j;
		int left=0, right=0, up=0, down=0;
		int curRow = center;
		int curCol = center;

		boolean find = false;
		for (i=1; i<row-1 && !find; i++) {
			for (j=1; j<col-1 && !find; j++) {
				if (hall[i][j] == 'X') {
					left = j-1;
					right = col-2-j;
					up = i-1;
					down = row-2-i;
					find = true;
				}
			}
		}

		plane = new byte[size][size];
		plane[center][center] = 1;
		frameNum = 1;
		while ((row-2)*(frameNum*2-1) < size || (col-2)*(frameNum*2-1) < size) {
			curRow += up*2+1;
			if (curRow >=0 && curRow < size && curCol >=0 && curCol < size) {
					plane[curRow][curCol] = 1;
			}
			tmp = up;
			up = down;
			down = tmp;
			for (i=0; i<(frameNum*2-1); i++) {	// left
				curCol -= left*2+1;
				tmp = left;
				left = right;
				right = tmp;
				if (curRow >=0 && curRow < size && curCol >=0 && curCol < size) {
					plane[curRow][curCol] = 1;
				}
			}
			for (i=0; i<frameNum*2; i++) {	// down
				curRow -= down*2+1;
				tmp = up;
				up = down;
				down = tmp;
				if (curRow >=0 && curRow < size && curCol >=0 && curCol < size) {
					plane[curRow][curCol] = 1;
				}
			}
			for (i=0; i<frameNum*2; i++) {	// right
				curCol += right*2+1;
				tmp = right;
				right = left;
				left = tmp;
				if (curRow >=0 && curRow < size && curCol >=0 && curCol < size) {
					plane[curRow][curCol] = 1;
				}
			}
			for (i=0; i<frameNum*2; i++) {	// up
				curRow += up*2+1;
				tmp = up;
				up = down;
				down = tmp;
				if (curRow >=0 && curRow <size && curCol >=0 && curCol < size) {
					plane[curRow][curCol] = 1;
				}
			}
			frameNum++;
		}
	}
}
