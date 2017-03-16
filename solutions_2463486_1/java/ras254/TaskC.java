
import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;
import java.util.TreeSet;

public class TaskC 
{
    public static void main(String[] args) throws Exception
    {
        _numbers.add("1");
        _numbers.add("4");
        _numbers.add("9");
        Generate12();
        Generate14();
        Generate16();
        Generate18();
        Generate22();

        BufferedReader in = new BufferedReader(new FileReader("C-large-1.in"));
        PrintWriter out = new PrintWriter(new File("C-large-1.out"));


        int T, t;
        String[] ab;
        BigInteger i;
        BigInteger i1 = new BigInteger("1");

        T = Integer.parseInt(in.readLine());

        for (t = 1; t <= T; t++)
        {
            ab = in.readLine().split(" ");
            i = new BigInteger(ab[1]).add(i1);
            out.println(String.format("Case #%d: %d", t, _numbers.subSet(ab[0], i.toString()).size()));
        }

        in.close();
        out.close();
    }

    private static boolean IsPalindrome(String s)
    {
        boolean b = true;
        int _len = s.length();
        int _len2 = _len / 2;
        int _len_1 = _len - 1;

        for (int i = 0; i < _len2; i++)
        {
            if (s.charAt(i) != s.charAt(_len_1 - i))
            {
                b = false;
                break;
            }
        }

        return b;
    }


    private static long _count = 0;
    private static TreeSet<String> _numbers = new TreeSet<>(new StringComp());
    private static void CheckInt(String str)
    {
        BigInteger i2 = new BigInteger(str).pow(2);
        if (IsPalindrome(i2.toString()))
        {
            //System.out.println(String.format("%d) %s %s", ++_count, str, i2.toString()));
            _numbers.add(i2.toString());
        }
    }

    private static class StringComp implements Comparator<String>
    {
        @Override
        public int compare(String o1, String o2)
        {
            if (o1.length() < o2.length())
                return -1;
            else if (o1.length() > o2.length())
                return 1;
            else
                return o1.compareTo(o2);
        }
    }

    private static void Generate12()
    {
        String _zeros = "";
        String _str;
        
        for (int z = 0; z <= 24; z++)
        {
            _str = "1" + _zeros + _zeros + "1";
            CheckInt(_str);
            if (z < 24)
                for (int j = 0; j <= 2; j++)
                {
                    _str = "1" + _zeros + j + _zeros + "1";
                    CheckInt(_str);
                }
            _zeros += "0";
        }
    }

    private static void Generate22()
    {
        String _zeros = "";
        String _str;

        for (int z = 0; z <= 24; z++)
        {
            _str = "2" + _zeros + _zeros + "2";
            CheckInt(_str);
            if (z < 24)
                for (int j = 0; j <= 1; j++)
                {
                    _str = "2" + _zeros + j + _zeros + "2";
                    CheckInt(_str);
                }
            _zeros += "0";
        }
    }

    private static void Generate14()
    {
        byte[] _digits = new byte[50];
        String _str;

        for (int l = 2; l <= 25; l++)
        {
            for (int c = 3; c >= 0; c--)
            {
                Arrays.fill(_digits, (byte)48);
                if (c == 3)
                {
                    _digits[0] = 49;
                    _digits[2 * l - 1] = 49;
                    for (int i = 1; i < l; i++)
                    {
                        _digits[i] = 49;
                        _digits[2 * l - 1 - i] = 49;
                        _str = new String(_digits, 0, 2 * l);
                        CheckInt(_str);
                        _digits[2 * l - 1 - i] = 48;
                        _digits[i] = 48;
                    }
                } else if (l < 25)
                {
                    _digits[0] = 49;
                    _digits[2 * l] = 49;
                    _digits[l] = (byte)(48 + c);
                    for (int i = 1; i < l; i++)
                    {
                        _digits[i] = 49;
                        _digits[2 * l - i] = 49;
                        _str = new String(_digits, 0, 2 * l + 1);
                        CheckInt(_str);
                        _digits[2 * l - i] = 48;
                        _digits[i] = 48;
                    }
                }
            }
        }
    }

    private static void Generate16()
    {
        byte[] _digits = new byte[50];
        String _str;

        for (int l = 2; l <= 25; l++)
        {
            for (int c = 3; c >= 0; c--)
            {
                Arrays.fill(_digits, (byte)48);
                if (c == 3)
                {
                    _digits[0] = 49;
                    _digits[2 * l - 1] = 49;
                    for (int i1 = 1; i1 < l - 1; i1++)
                    {
                        _digits[i1] = 49;
                        _digits[2 * l - 1 - i1] = 49;
                        for (int i2 = i1 + 1; i2 < l; i2++)
                        {
                            _digits[i2] = 49;
                            _digits[2 * l - 1 - i2] = 49;
                            _str = new String(_digits, 0, 2 * l);
                            CheckInt(_str);
                            _digits[i2] = 48;
                            _digits[2 * l - 1 - i2] = 48;
                        }
                        _digits[2 * l - 1 - i1] = 48;
                        _digits[i1] = 48;
                    }
                } else if (l < 25)
                {
                    _digits[0] = 49;
                    _digits[2 * l] = 49;
                    _digits[l] = (byte)(48 + c);
                    for (int i1 = 1; i1 < l - 1; i1++)
                    {
                        _digits[i1] = 49;
                        _digits[2 * l - i1] = 49;
                        for (int i2 = i1 + 1; i2 < l; i2++)
                        {
                            _digits[i2] = 49;
                            _digits[2 * l - i2] = 49;
                            _str = new String(_digits, 0, 2 * l + 1);
                            CheckInt(_str);
                            _digits[i2] = 48;
                            _digits[2 * l - i2] = 48;
                        }
                        _digits[2 * l - i1] = 48;
                        _digits[i1] = 48;
                    }
                }
            }
        }
    }

    private static void Generate18()
    {
        byte[] _digits = new byte[50];
        String _str;

        for (int l = 2; l <= 25; l++)
        {
            for (int c = 3; c >= 0; c--)
            {
                Arrays.fill(_digits, (byte)48);
                if (c == 3)
                {
                    _digits[0] = 49;
                    _digits[2 * l - 1] = 49;
                    for (int i1 = 1; i1 < l - 2; i1++)
                    {
                        _digits[i1] = 49;
                        _digits[2 * l - 1 - i1] = 49;
                        for (int i2 = i1 + 1; i2 < l - 1; i2++)
                        {
                            _digits[i2] = 49;
                            _digits[2 * l - 1 - i2] = 49;
                            for (int i3 = i2 + 1; i3 < l; i3++)
                            {
                                _digits[i3] = 49;
                                _digits[2 * l - 1 - i3] = 49;
                                _str = new String(_digits, 0, 2 * l);
                                CheckInt(_str);
                                _digits[i3] = 48;
                                _digits[2 * l - 1 - i3] = 48;
                            }
                            _digits[i2] = 48;
                            _digits[2 * l - 1 - i2] = 48;
                        }
                        _digits[2 * l - 1 - i1] = 48;
                        _digits[i1] = 48;
                    }
                } else if (l < 25)
                {
                    _digits[0] = 49;
                    _digits[2 * l] = 49;
                    _digits[l] = (byte)(48 + c);
                    for (int i1 = 1; i1 < l - 2; i1++)
                    {
                        _digits[i1] = 49;
                        _digits[2 * l - i1] = 49;
                        for (int i2 = i1 + 1; i2 < l - 1; i2++)
                        {
                            _digits[i2] = 49;
                            _digits[2 * l - i2] = 49;
                            for (int i3 = i2 + 1; i3 < l; i3++)
                            {
                                _digits[i3] = 49;
                                _digits[2 * l - i3] = 49;
                                _str = new String(_digits, 0, 2 * l + 1);
                                CheckInt(_str);
                                _digits[i3] = 48;
                                _digits[2 * l - i3] = 48;
                            }
                            _digits[i2] = 48;
                            _digits[2 * l - i2] = 48;
                        }
                        _digits[2 * l - i1] = 48;
                        _digits[i1] = 48;
                    }
                }
            }
        }
    }
}
