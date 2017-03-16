using System.Diagnostics;
using System.Numerics;

using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace FairAndSquare
{
    [TestClass]
    public class FairAndSquareTests
    {
        [TestMethod]
        public void IsPalindrome_EvenLength()
        {
            Assert.IsTrue(FairAndSquare.IsPalindrome(BigInteger.Parse("123456789987654321")));
            Assert.IsFalse(FairAndSquare.IsPalindrome(BigInteger.Parse("123456788987654321")));
        }

        [TestMethod]
        public void IsPalindrome_OddLength()
        {
            Assert.IsTrue(FairAndSquare.IsPalindrome(BigInteger.Parse("12345678987654321")));
            Assert.IsFalse(FairAndSquare.IsPalindrome(BigInteger.Parse("12345679987654321")));
        }

        [TestMethod]
        public void GetPalindrome_Exact()
        {
            Assert.AreEqual(new BigInteger(12321), FairAndSquare.GetNextPalindrome(new BigInteger(12321)).GetValue());
            Assert.AreEqual(new BigInteger(123321), FairAndSquare.GetNextPalindrome(new BigInteger(123321)).GetValue());
        }

        [TestMethod]
        public void GetPalindrome_NotExact()
        {
            Assert.AreEqual(new BigInteger(12421), FairAndSquare.GetNextPalindrome(new BigInteger(12322)).GetValue());
            Assert.AreEqual(new BigInteger(12321), FairAndSquare.GetNextPalindrome(new BigInteger(12320)).GetValue());

            Assert.AreEqual(new BigInteger(124421), FairAndSquare.GetNextPalindrome(new BigInteger(123322)).GetValue());
            Assert.AreEqual(new BigInteger(123321), FairAndSquare.GetNextPalindrome(new BigInteger(123320)).GetValue());
        }

        [TestMethod]
        public void GetPalindrome_Power10()
        {
            Assert.AreEqual(new BigInteger(99999), FairAndSquare.GetNextPalindrome(new BigInteger(99999)).GetValue());
            Assert.AreEqual(new BigInteger(999999), FairAndSquare.GetNextPalindrome(new BigInteger(999999)).GetValue());
            Assert.AreEqual(new BigInteger(10001), FairAndSquare.GetNextPalindrome(new BigInteger(10000)).GetValue());
            Assert.AreEqual(new BigInteger(100001), FairAndSquare.GetNextPalindrome(new BigInteger(100000)).GetValue());
        }

        [TestMethod]
        public void PalindromesInRange_ExactBounds()
        {
            var range = FairAndSquare.PalindromesInRange(8, 22);
            Assert.AreEqual(9, range.current.GetValue());
            Assert.IsTrue(range.Next());
            Assert.AreEqual(11, range.current.GetValue());
            Assert.IsFalse(range.Next());
        }

        [TestMethod]
        public void PalindromesInRange_NonExactBounds()
        {
            var range = FairAndSquare.PalindromesInRange(90, 120);
            Assert.AreEqual(99, range.current.GetValue());
            Assert.IsTrue(range.Next());
            Assert.AreEqual(101, range.current.GetValue());
            Assert.IsTrue(range.Next());
            Assert.AreEqual(111, range.current.GetValue());
            Assert.IsFalse(range.Next());
        }

        [TestMethod]
        [Timeout(42)] // 10000 tests at 42ms is 420s = 7m
        public void TestPerformance_Large1()
        {
            FairAndSquare.FairAndSquareInRange(1, new BigInteger(1e14));
        }

        [TestMethod]
        //[Timeout(450)] // 1000 tests at 450ms is 450s = 7m30
        public void TestPerformance_Large2()
        {
            FairAndSquare.FairAndSquareInRange(new BigInteger(5e99), new BigInteger(6e99));
        }
    }
}
