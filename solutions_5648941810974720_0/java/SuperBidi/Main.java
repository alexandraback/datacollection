import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Vector;
import java.math.RoundingMode;

public class Main
{
    public static boolean executeOnStringTab(String[][] input, PrintWriter output)
    {
        int letterNumber[] = new int[100];
        for (int i = 0; i < 100; i ++)
            letterNumber[i] = 0;
        for (int i = 0; i < input[0][0].length(); i ++)
        {
            char c = input[0][0].charAt(i);
            letterNumber[c]++;
        }

        int digitNumber[] = new int[10];
        for (int i = 0; i < 10; i ++)
            digitNumber[i] = 0;

        digitNumber[0] = letterNumber['Z'];
        removeNumber(letterNumber, "ZERO", digitNumber[0]);
        digitNumber[2] = letterNumber['W'];
        removeNumber(letterNumber, "TWO", digitNumber[2]);
        digitNumber[8] = letterNumber['G'];
        removeNumber(letterNumber, "EIGHT", digitNumber[8]);
        digitNumber[3] = letterNumber['H'];
        removeNumber(letterNumber, "THREE", digitNumber[3]);
        digitNumber[6] = letterNumber['X'];
        removeNumber(letterNumber, "SIX", digitNumber[6]);
        digitNumber[7] = letterNumber['S'];
        removeNumber(letterNumber, "SEVEN", digitNumber[7]);
        digitNumber[5] = letterNumber['V'];
        removeNumber(letterNumber, "FIVE", digitNumber[5]);
        digitNumber[4] = letterNumber['F'];
        removeNumber(letterNumber, "FOUR", digitNumber[4]);
        digitNumber[9] = letterNumber['I'];
        removeNumber(letterNumber, "NINE", digitNumber[9]);
        digitNumber[1] = letterNumber['O'];

        String result = "";
        for (int i = 0; i < 10; i ++)
        {
            for (int j = 0; j < digitNumber[i]; j ++)
                result += String.valueOf(i);
        }

        return outputCase(output, result);
    }

    public static void removeNumber(int letterNumber[], String number, int value)
    {
        for (int i = 0; i < number.length(); i ++)
            letterNumber[number.charAt(i)] -= value;
    }

    public static boolean executeOnDataTab(Data input, PrintWriter output)
    {
        return outputCase(output, "Impossible");
    }

    public static void parseStringTab(PrintWriter output, BufferedReader br, int size, int sizeToAdd) throws Exception
    {
        String input[][] = new String[size][];

        for (int i = 0; i < size; i ++)
        {
            String line = br.readLine();
            String [] str = line.split(" ");
            input[i] = str;

            if (i == sizeToAdd)
            {
                size += Integer.parseInt(str[0]);
                String newInput[][] = new String[size][];
                for (int j = 0; j < input.length; j ++)
                    newInput[j] = input[j];
                input = newInput;
            }
        }

        executeOnStringTab(input, output);
    }

    public static void parseCharTab(PrintWriter output, BufferedReader br, int size) throws Exception
    {
        String input[][] = new String[size][];
        String line;

        for (int i = 0; i < size; i ++)
        {
            line = br.readLine();
            String [] str = new String[line.length()];

            for (int j = 0; j < line.length(); j ++)
            {
                str[j] = Character.toString(line.charAt(j));
            }
            input[i] = str;
        }

        executeOnStringTab(input, output);
    }

    public static void parseDataTab(PrintWriter output, BufferedReader br, int size, String str[]) throws Exception
    {
        Data data = new Data(str);
        for (int i = 1; i < size; i ++)
        {
            String line = br.readLine();
            str = line.split(" ");
            data.addLine(str);
        }

        executeOnDataTab(data, output);
    }

    public static int[] parseStringTab(String[] tab)
    {
        int[] result = new int[tab.length];
        for (int i = 0; i < tab.length; i ++)
            result[i] = Integer.parseInt(tab[i]);
        return result;
    }

    public static BigInteger sqrt(BigInteger n)
    {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0)
        {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if (mid.multiply(mid).compareTo(n) > 0)
                b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    private static final BigDecimal SQRT_DIG = new BigDecimal(150);
    private static final BigDecimal SQRT_PRE = new BigDecimal(10).pow(SQRT_DIG.intValue());

    private static BigDecimal sqrtNewtonRaphson  (BigDecimal c, BigDecimal xn, BigDecimal precision){
        BigDecimal fx = xn.pow(2).add(c.negate());
        BigDecimal fpx = xn.multiply(new BigDecimal(2));
        BigDecimal xn1 = fx.divide(fpx,2*SQRT_DIG.intValue(), RoundingMode.HALF_DOWN);
        xn1 = xn.add(xn1.negate());
        BigDecimal currentSquare = xn1.pow(2);
        BigDecimal currentPrecision = currentSquare.subtract(c);
        currentPrecision = currentPrecision.abs();
        if (currentPrecision.compareTo(precision) <= -1){
            return xn1;
        }
        return sqrtNewtonRaphson(c, xn1, precision);
    }

    public static BigDecimal sqrt(BigDecimal c){
        return sqrtNewtonRaphson(c,new BigDecimal(1),new BigDecimal(1).divide(SQRT_PRE));
    }

    public static HashMap<Integer, Integer> binaryWriting(int number)
    {
        HashMap<Integer, Integer> result = new HashMap<Integer, Integer>();
        int i = 2;
        int j = 1;
        while (number != 0)
        {
            if (number % i != 0)
            {
                result.put(j, 1);
                number = number - number % i;
            } else result.put(j, 0);
            j ++;
            i = i * 2;
        }

        return result;
    }

    public static int caseNumber = 0;
    public static boolean outputCase(PrintWriter output, String s)
    {
        caseNumber ++;
        if (s.length() != 0)
            output.println("Case #"+String.valueOf(caseNumber)+": "+s);
        else output.println("Case #"+String.valueOf(caseNumber)+":");
        trace("Case #"+String.valueOf(caseNumber)+": "+s);

        return true;
    }

    public static boolean outputVector(PrintWriter output, Vector<Integer> vector)
    {
        String s = "";
        for (int i = 0; i < vector.size(); i ++)
            s = s + vector.get(i) + " ";

        return outputCase(output, s);
    }

    public static boolean outputTab(PrintWriter output, String[] tab)
    {
        String s = "";
        for (int i = 0; i < tab.length; i ++)
        {
            if (s.length() != 0)
                s = s + " ";
            s = s + tab[i];
        }

        return outputCase(output, s);
    }

    public static boolean outputTab(PrintWriter output, String[][] tab)
    {
        String solution = "";
        for (int i = 0; i < tab.length; i ++)
        {
            String s = "";
            for (int j = 0; j < tab[i].length; j ++)
            {
                if (s.length() != 0)
                    s = s + "";
                s = s + tab[i][j];
            }
            solution = solution + "\n" + s;
        }

        return outputCase(output, solution);
    }

    public static boolean outputTab(PrintWriter output, int[] tab)
    {
        String s = "";
        for (int i = 0; i < tab.length; i ++)
        {
            if (s.length() != 0)
                s = s + " ";
            s = s + tab[i];
        }

        return outputCase(output, s);
    }

    public static void trace(long l)
    {
        System.out.println(l);
    }

    public static void trace(double l)
    {
        System.out.println(l);
    }

    public static void trace(String s)
    {
        System.out.println(s);
    }

    public static class Pair
    {
        public long x, y;

        public Pair(long a, long b)
        {
            x = a;
            y = b;
        }
    }

    public static class Line
    {
        int key;

        public Line(String str[])
        {
            key = Integer.parseInt(str[0]);
        }
    }

    public static class Data
    {
        int currentLine;
        Line lines[];
        Line begin;

        public Data(String str[])
        {
            currentLine = 0;
            lines = new Line[Integer.parseInt(str[1])];
        }

        public void addLine(String str[])
        {
            if (currentLine == 0)
                begin = new Line(str);
            else
            {
                Line line = new Line(str);
                lines[currentLine - 1] = line;
            }
            currentLine ++;
        }
    }

    public static int numberOfDigits(long number)
    {
        return String.valueOf(number).length();
    }

    public static long PPCM(long a, long b)
    {
        long x,t,m;
        if (b>a)
        {
            x=b;
            b=a;
            a=x;
        }

        if (a%b==0)
            return a;
        else
        {
            t=(a*b);
            while(b != 0)
            {
                x = a%b;
                a = b;
                b = x;
            }
            m=t/a;
            return m;
        }
    }

    public static long PGCD(long a, long b)
    {
        return (a * b) / PPCM(a, b);
    }

    public static void main (String[] args)
    {
        int sizeOfElement = 1;
        int lineToJumpBefore = 0;
        int lineToJumpAfter = 0;

        String file ="input.in";
        String output = "output.out";
        long timeInMillis = System.currentTimeMillis();

        try
        {
            FileWriter fw = new FileWriter (output);
            BufferedWriter bw = new BufferedWriter (fw);
            PrintWriter outputFile = new PrintWriter (bw);
            InputStream ips=new FileInputStream(file);
            InputStreamReader ipsr=new InputStreamReader(ips);
            BufferedReader br=new BufferedReader(ipsr);
            int numberOfExercices = Integer.parseInt(br.readLine());

            for (int i = 0; i < numberOfExercices; i ++)
            {
                for (int j = 0; j < lineToJumpBefore; j ++)
                    br.readLine();

                int size = sizeOfElement;
                int sizeToAdd = -1; //Ajoute la taille indiquée à cette ligne à size pendant la lecture de l'exercice

                //String line = br.readLine();
                //String [] str = line.split(" ");
                //size = Integer.parseInt(str[0]);

                //Tableau de String
                parseStringTab(outputFile, br, size, sizeToAdd);

                //Tableau de characters
                //parseCharTab(outputFile, br, size);

                //Data
                //parseDataTab(outputFile, br, size, str);

                for (int j = 0; j < lineToJumpAfter; j ++)
                    br.readLine();
            }
            br.close();
            outputFile.close();
        }
        catch (Exception e)
        {
            StringWriter sw = new StringWriter();
            PrintWriter pw = new PrintWriter(sw);
            e.printStackTrace(pw);
            trace(sw.toString());
        }
        trace("time "+(String.valueOf(System.currentTimeMillis() - timeInMillis)));
    }
}
