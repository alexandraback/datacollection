using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace GoogleCodeJam2014
{
    class Program
    {
        static void Main(string[] args)
        {
            //abcdefghijklmnopqrstuvwxyz = 26
            string fileName = "input.in";
            using (var reader = new StreamReader(fileName))
            {
                int cases = int.Parse(reader.ReadLine().Trim());
                using (var writer = new StreamWriter("output.out"))
                {
                    for (int i = 0; i < cases; i++)
                    {
                        var line = reader.ReadLine();
                        int cartsNumber = int.Parse(line);
                        line = reader.ReadLine();
                        var lineValues = line.Split(' ');

                        List<Cart> carts = new List<Cart>();
                        for (int c = 0; c < cartsNumber; c++)
                            carts.Add(new Cart(lineValues[c].ToCharArray()));

                        List<CartSet> cartSets = new List<CartSet>();
                        foreach (Cart cart in carts)
                        {
                            bool added = false;
                            int currentSet = 0;
                            while (!added)
                            {
                                if (currentSet >= cartSets.Count())
                                    cartSets.Add(new CartSet());
                                if (cartSets[currentSet].AddCart(cart))
                                    added = true;
                                currentSet++;
                            }
                        }

                        bool setValid = true;
                        BigInteger result = 1;
                        foreach (var set in cartSets)
                        {
                            if (!set.IsValid())
                            {
                                setValid = false;
                                break;
                            }
                            result = result * set.P();
                        }

                        writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, (setValid ? (BigInteger.ModPow(result, 1, 1000000007)).ToString() : "0")));
                    }
                }
            }
        }

        public class Cart
        {
            public int mask;
            public int front;
            public int end;

            public Cart(char[] letters)
            {

                for (int i = 0; i < letters.Length; i++)
                {
                    if (i == 0)
                        front = 1 << (letters[i] - 'a');
                    if (i + 1 == letters.Length)
                        end = 1 << (letters[i] - 'a');
                    mask |= 1 << (letters[i] - 'a');
                }
            }
        }

        public class CartSet
        {
            public int mask;
            public List<Cart> carts;

            public CartSet()
            {
                mask = 0;
                carts = new List<Cart>();
            }

            public bool AddCart(Cart cart)
            {
                if (mask == 0 || (mask & cart.mask) > 0)
                {
                    carts.Add(cart);
                    mask |= cart.mask;
                    return true;
                }
                return false;
            }

            public bool IsValid()
            {
                int m = 0;
                Cart last = null;
                foreach (var cart in carts.OrderBy(c => c.front).ThenBy(c => c.end))
                {
                    if (cart.front == cart.end && (cart.front != cart.mask)) //wrong cart
                        return false;
                    if (last == null)
                    {
                        last = cart;
                        m = cart.mask;
                    }
                    else
                    {
                        if (last.end != cart.front)
                            return false;
                        if (((cart.mask ^ cart.front) & m) > 0)
                            return false;
                        m |= cart.mask;
                        last = cart;
                    }
                }
                return true;
            }

            public BigInteger P()
            {
                BigInteger joins = 0;
                int used = 0;
                foreach (int f in carts.Where(c => c.front == c.end).Select(c => c.front))
                {
                    var j = carts.Where(c => (c.front == c.end) && (c.front == f)).Count();
                    if (j > 1)
                    {
                        used += j;
                        var jj = 1;
                        for (int s = 1; s <= j; s++)
                            jj *= s;
                        joins += jj;
                    }
                }
                return (joins > 0) ? joins : 1;
            }
        }


    }
}
