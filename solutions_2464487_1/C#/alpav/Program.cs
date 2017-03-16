using System;using System.Collections.Generic;using System.Linq;using System.Text;using System.IO;using System.Diagnostics;using System.Numerics;using lib;
namespace t2013_1A_0{class Program:g {

static void Main(string[] args){
	using(var rd=File.OpenText(@"..\..\in3.txt"))
	using(var w=File.CreateText(@"..\..\out3.txt"))
	foreach(var T in rep(int.Parse(rd.ReadLine()))){
		var src=rd.ReadLine().Split(' ').Select(e=>BigInteger.Parse(e)).ToArray();
		var r=src[0];
		var t=src[1];

		var r2=r*2;
		var r23=r2+3;
		var r23sq=BigInteger.Pow(r23,2);
		var sqa=r23sq+(t-r2-1)*8;
		var sqrt=Sqrt(sqa);
		var r4=sqrt-r23;
		var r5=r4/4;
		var res=r5+1;

      w.WriteLine("Case #"+(T+1)+": "+res);
      Console.WriteLine("Case #"+(T+1)+":"+res);
    }
    Console.WriteLine("-------------------------------------------");
    Console.WriteLine("done");
    Console.ReadKey();
}

	static public BigInteger Sqrt(BigInteger n)
    {
        if (n == 0) return 0;
        if (n > 0)
        {
            int bitLength = Convert.ToInt32(Math.Ceiling(BigInteger.Log(n, 2)));
            BigInteger root = BigInteger.One << (bitLength / 2);

            while (!isSqrt(n, root))
            {
                root += n / root;
                root /= 2;
            }

            return root;
        }

        throw new ArithmeticException("NaN");
    }
private static Boolean isSqrt(BigInteger n, BigInteger root)
    {
        BigInteger lowerBound = root*root;
        BigInteger upperBound = (root + 1)*(root + 1);

        return (n >= lowerBound && n < upperBound);
    }
}}
