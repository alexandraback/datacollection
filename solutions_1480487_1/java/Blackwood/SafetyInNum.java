import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Scanner;



public class SafetyInNum {
	public static void main(String[] args) throws IOException {
		BufferedWriter bw;
		FileOutputStream fos = new FileOutputStream("C:\\Users\\blackwood\\Downloads\\codejam.out");
		bw = new BufferedWriter(new OutputStreamWriter(fos));
		Scanner reader = new Scanner (System.in);
		int nCases = reader.nextInt();
		for(int i=1; i<=nCases; i++) {
			int nPerson = reader.nextInt();
			Person array[] = new Person[nPerson];
			int sum = 0;
			double average = 0;
			for(int j=0; j<nPerson; j++) {
				Person p = new Person();
				p.point= reader.nextInt();
				p.num = j;
				sum += p.point;
				array[j] = p;
			}
			average = sum *2.0/nPerson;
			Arrays.sort(array);
			double[] result = new double[nPerson];
			for(int j=nPerson-1; j>=0; j--) {
				if(array[j].point>=average) {
					result[array[j].num] = 0.0;
					average = average-(array[j].point-average)/j;
				} else {
					result[array[j].num] = (average-array[j].point)*100 / sum;
				}
			}
			StringBuilder resultStr = new StringBuilder();
			for(int j=0; j<nPerson; j++) {
				resultStr.append(result[j]);
				resultStr.append(" ");
			}
			String line ="Case #" + i + ": " + resultStr;
			System.out.println(line);
			bw.write(line);
			bw.newLine();
		}
		
		bw.close();
	}
	
	
	static class Person implements Comparable<Person>{
		int num;
		int point;

		@Override
		public int compareTo(Person p) {
			// TODO Auto-generated method stub
			return point-p.point;
		}
	}
}
