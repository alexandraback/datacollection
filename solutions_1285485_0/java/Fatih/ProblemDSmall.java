import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemDSmall {

	ProblemDSmall() throws IOException {
		
		Scanner reader = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int cases = reader.nextInt();
		
		for(int i = 1; i <= cases; i++) {
			int H = reader.nextInt();
			int W = reader.nextInt();
			int D = reader.nextInt();
			int x = 0, y = 0;
			
			reader.nextLine();
			for(int j = 0; j < H; j++) {
				String line = reader.nextLine();
				int index = line.indexOf('X');
				if(index>0) {
					x = index;
					y = j;
				}
			}
						
			boolean[][] image = new boolean[2*D+1][2*D+1];
			putimage(D,D,D-x,D+W-x-1,D-y,D+H-y-1,image);
			int result = count(image,D);
			
			writer.write("Case #"+i+": "+result);
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	private void putimage(int x, int y, int left, int right, int top, int bottom, boolean[][] image) {
		if(x<0||y<0||x>=image.length||y>=image.length) return;
		if(image[y][x]) return;
		image[y][x] = true;
		if(x>left) putimage(2*left+1-x,y,left,right,top,bottom,image);
		if(y>top) putimage(x,2*top+1-y,left,right,top,bottom,image);
		if(x<right) putimage(2*right-x-1,y,left,right,top,bottom,image);
		if(y<bottom) putimage(x,2*bottom-y-1,left,right,top,bottom,image);
	}
	
	private int count(boolean[][] image, int D) {
		int c = 0;
		for(int i = 0; i <= D; i++) {
			for(int j = 0; j <= D; j++) {
				if(i*i+j*j>D*D) continue;
				if(i==0&&j==0) continue;
				int iinc = i/gcd(i,j);
				int jinc = j/gcd(i,j);
				if(image[D-i][D+j]) {
					c++;
					int x = D+j;
					int y = D-i;
					while(x<image.length&&y>=0) {
						image[y][x]=false;
						x+=jinc;
						y-=iinc;
					}
				}
				if(image[D-i][D-j]) {
					c++;
					int x = D-j;
					int y = D-i;
					while(x>=0&&y>=0) {
						image[y][x]=false;
						x-=jinc;
						y-=iinc;
					}
				}
				if(image[D+i][D-j]) {
					c++;
					int x = D-j;
					int y = D+i;
					while(y<image.length&&x>=0) {
						image[y][x]=false;
						x-=jinc;
						y+=iinc;
					}
				}
				if(image[D+i][D+j]) {
					c++;
					int x = D+j;
					int y = D+i;
					while(x<image.length&&y<image.length) {
						image[y][x]=false;
						x+=jinc;
						y+=iinc;
					}
				}
			}
		}
		return c;
	}
	
	private int gcd(int a, int b) {
		if(b==0) return a;
		return gcd(b,a%b);
	}
	
	public static void main(String[] args) throws IOException {
		new ProblemDSmall();
	}
}
