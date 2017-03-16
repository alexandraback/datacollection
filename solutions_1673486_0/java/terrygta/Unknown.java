import java.io.*;
import java.math.*;
import java.text.DecimalFormat;

public class Unknown {
	private double[] pro;
	private double[] pro_each;
	int pro_size;
	int size;
	public void cal(String filename) throws NumberFormatException, IOException
	{
		BufferedReader in = new BufferedReader(new FileReader(filename));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bar.txt")));
		int count = 1;
		String s = in.readLine();
		int all = Integer.parseInt(s);
		while((s = in.readLine()) != null)
		{
			
			double result = 0;
			if(count > all)
			{
				System.out.println("error");
				break;
			}
			String[] elements = s.split(" ");
			pro_size = Integer.parseInt(elements[0]);
			size = Integer.parseInt(elements[1]);
			pro = new double[(int)Math.pow(2, pro_size)];
			pro_each = new double[pro_size];
			s = in.readLine();
			elements = s.split(" ");
			for(int i = 0; i < elements.length; i++)
				pro_each[i] = Double.parseDouble(elements[i]);
			for(int i = 0; i < pro.length; i++)
			{
				double value = 1;
				String binary = Integer.toBinaryString(i);
				int binary_size = binary.length();
				for(int j = binary_size; j < pro_size; j++)
					binary = "0" + binary;
					
				for(int j = 0; j < pro_size; j++)
				{
					if(binary.charAt(j) == '0')
						value = value * pro_each[j];
					else
						value = value * (1 - pro_each[j]);
				}
				pro[i] = value;
			}
			result = m1();
			double temp = m2();
			if(temp < result)
				result = temp;
			temp = m3();
			if(temp < result)
				result = temp;
			temp = m4();
			if(temp < result)
				result = temp;
			BigDecimal bd = new BigDecimal(result);
			bd = bd.setScale(6,BigDecimal.ROUND_HALF_UP);
			DecimalFormat df= new DecimalFormat("######0.000000");
			out.println("Case #" + count +": " + df.format(bd.doubleValue()));
			count = count + 1;
		}
		out.close();
	}
	
	public double m1()
	{
		double result = 0;
		for(int i = 0; i < pro.length; i++)
		{
			int time = size - pro_size + 1;
			if(i != 0)
				time = size - pro_size + 1 + size + 1;
			result = result + time * pro[i];
		}
		return result;
	}
	
	public double m2()
	{
		double result = 0;
		for(int i = 0; i < pro.length; i++)
		{
			int time = size - pro_size + 3;
			if(i != 0)
			{
				String binary = Integer.toBinaryString(i);
				int binary_size = binary.length();
				for(int j = binary_size; j < pro_size; j++)
					binary = "0" + binary;
				for(int j = 0; j < binary.length(); j++)
				{
					if(binary.charAt(j) == '1')
					{
						if(j == pro_size - 1)
							time = size - pro_size + 3;
						else
							time = size - pro_size + 3 + size + 1;
						break;
					}
				}
			}
			result = result + time * pro[i];
		}
		return result;
	}
	
	public double m3()
	{
		double result = 0;
		for(int i = 0; i < pro.length; i++)
		{
			int time = size - pro_size + 5;
			if(i != 0)
			{
				String binary = Integer.toBinaryString(i);
				int binary_size = binary.length();
				for(int j = binary_size; j < pro_size; j++)
					binary = "0" + binary;
				for(int j = 0; j < binary.length(); j++)
				{
					if(binary.charAt(j) == '1')
					{
						if(j == pro_size - 2 || j == pro_size - 1)
							time = size - pro_size + 5;
						else
							time = size - pro_size + 5 + size + 1;
						break;
					}
				}
			}
			result = result + time * pro[i];
		}
		return result;
	}
	
	public double m4()
	{
		double result = 0;
		for(int i = 0; i < pro.length; i++)
		{
			int time = size + 2;
			result = result + time * pro[i];
		}
		return result;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		Unknown r = new Unknown();
		r.cal("1.in");
	}

}
