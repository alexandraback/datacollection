
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

class BigInt
{
public:

  BigInt()
  {
    mDigits.reserve(60);
  }

  //The actual square root is guaranteed to be >= this.
  void getSquareRootLowBound(BigInt &x)
  {
    x.mDigits.clear();
    if(mDigits.size() < 2)
    {
      return;
    }

    int lop = (mDigits.size() - 2) / 2;

    int take = mDigits.size() - lop * 2;
    assert(take == 2 || take == 3);

    int top;
    if(take == 2)
    {
      top = mDigits[mDigits.size() - 1] * 10 + mDigits[mDigits.size() - 2];
    }
    else
    {
      top = mDigits[mDigits.size() - 1] * 100 + mDigits[mDigits.size() - 2] * 10 + mDigits[mDigits.size() - 3];
    }

    top = (int)std::sqrt((float)top) - 1;

    x.set(top, lop);

    //Container::iterator lol = mDigits.begin() + (mDigits.size() + 1) / 2;
    //for(auto i = lol; i != mDigits.end(); ++i)
    //{
    //  x.mDigits.push_back(*i);
    //}
  }
  /*
  //The actual square root is guaranteed to be <= this.
  void getSquareRootHighBound(BigInt &x)
  {
    x.mDigits.clear();
    int index = (static_cast<int>(mDigits.size()) - 1) / 2;
    if(index < 0) index = 0;
    Container::iterator lol = mDigits.begin() + index;
    for(auto i = lol; i != mDigits.end(); ++i)
    {
      x.mDigits.push_back(*i);
    }
  }
  */
  bool operator<(const BigInt &other) const
  {
    if(mDigits.size() != other.mDigits.size())
    {
      return mDigits.size() < other.mDigits.size();
    }

    Container::const_reverse_iterator j = other.mDigits.rbegin();
    for(Container::const_reverse_iterator i = mDigits.rbegin(); i != mDigits.rend(); ++i, ++j)
    {
      if(*i != *j)
      {
        return *i < *j;
      }
    }
    return false;
  }

  bool operator>(const BigInt &other) const
  {
    return other < *this;
  }

  bool operator<=(const BigInt &other) const
  {
    return !(*this > other);
  }

  bool operator>=(const BigInt &other) const
  {
    return !(*this < other);
  }

  void set(const char *s)
  {
    mDigits.clear();
    const char *c = std::strchr(s, '\0');
    for(;;)
    {
      if(c == s) break;
      --c;
      mDigits.push_back(*c - '0');
    }
  }

  void set(long long x, int shift = 0)
  {
    mDigits.clear();
    mDigits.resize(shift);
    while(x != 0)
    {
      mDigits.push_back(x % 10);
      x /= 10;
    }
  }

  void multiplyByDigit(int x)
  {
    int carry = 0;
    for(Container::iterator i = mDigits.begin(); i != mDigits.end(); ++i)
    {
      int res = *i * x + carry;
      *i = res % 10;
      carry = res / 10;
    }
    if(carry != 0)
    {
      mDigits.push_back(carry);
    }
  }

  void add(const BigInt &other, int otherMult, int otherShift)
  {
    Container::const_iterator from = other.mDigits.begin();
    Container::iterator to = mDigits.begin();

    int carry = 0;
    while((otherShift != 0 || from != other.mDigits.end()) && to != mDigits.end())
    {
      int res = *to + carry;
      if(otherShift == 0) res += *from * otherMult;
      *to = res % 10;
      carry = res / 10;

      if(otherShift != 0) --otherShift;
      else ++from;

      ++to;
    }

    if(otherShift != 0 || from != other.mDigits.end())
    {
      for(int i = 0; i < otherShift; ++i)
      {
        mDigits.push_back(0);
      }
      mDigits.insert(mDigits.end(), from, other.mDigits.end());
      for(Container::iterator i = mDigits.end() - (other.mDigits.end() - from); i != mDigits.end(); ++i)
      {
        *i *= otherMult;
      }
      to = mDigits.end() - (other.mDigits.end() - from) - otherShift;

      while(carry != 0 && to != mDigits.end())
      {
        int res = *to + carry;
        *to = res % 10;
        carry = res / 10;
      }
      if(carry != 0)
      {
        assert(carry < 10);
        mDigits.push_back(carry);
      }
    }
    else if(to != mDigits.end())
    {
      while(carry != 0 && to != mDigits.end())
      {
        int res = *to + carry;
        *to = res % 10;
        carry = res / 10;
      }
      if(carry != 0)
      {
        assert(carry < 10);
        mDigits.push_back(carry);
      }
    }
  }

  void multiplyBy(BigInt &other)
  {
    BigInt copy = *this;
    mDigits.clear();
    int shift = 0;
    for(Container::iterator i = other.mDigits.begin(); i != other.mDigits.end(); ++i)
    {
      add(copy, *i, shift);
      ++shift;
    }
  }

  long long getValue() const
  {
    long long value = 0;

    for(Container::const_reverse_iterator i = mDigits.rbegin(); i != mDigits.rend(); ++i)
    {
      value *= 10;
      value += *i;
    }
    return value;
  }

  //least significant digit first
  typedef std::vector<int> Container;
  Container mDigits;

};

void advance(int *pos, int &quota, int *&end, int quotaMultiplier = 2)
{
  if(end == pos) end = pos + 1;
  if(*pos == 0 && quota >= 1 * quotaMultiplier)
  {
    quota -= 1 * quotaMultiplier;
    *pos = 1;
  }
  else if(*pos == 1 && quota >= 3 * quotaMultiplier)
  {
    //add 1, then subtract 4
    quota -= 3 * quotaMultiplier;
    *pos = 2;
  }
  else if(*pos == 2 && quota >= 5 * quotaMultiplier)
  {
    //add 4, then subtract 9
    quota -= 5 * quotaMultiplier;
    *pos = 3;
  }
  else
  {
    quota += *pos * *pos * quotaMultiplier;
    *pos = 0;
    advance(pos + 1, quota, end);
  }
}

//according to http://oeis.org/A057135 a palindrome x's square is also a palindrome if and only if the sum of the squares of the digits of x is less than 10
/*
void checkSquareRoot(long long x)
{
  BigInt b;
  b.set(x);
  assert(b.getValue() == x);

  BigInt low;
  b.getSquareRootLowBound(low);
  assert(low.getValue() * low.getValue() <= x);

  BigInt high;
  b.getSquareRootHighBound(high);
  assert(high.getValue() * high.getValue() >= x);
}
*/
int main()
{
  /*
  {
    BigInt test;
    test.set(42);

    assert(test.getValue() == 42);

    BigInt test2 = test;

    test2.multiplyByDigit(3);
    assert(test2.getValue() == 126);

    test2.multiplyBy(test);
    assert(test2.getValue() == 5292);

    assert(test.getValue() == 42);

    checkSquareRoot(0);
    checkSquareRoot(1);
    checkSquareRoot(10);
    checkSquareRoot(33);
    checkSquareRoot(23);
    checkSquareRoot(100);
    checkSquareRoot(333);
    checkSquareRoot(1089);
    checkSquareRoot(182793854);
  }
  */

  BigInt value;
  BigInt fairAndSquare;

  BigInt abig;
  BigInt bbig;

  BigInt alow, blow;
  BigInt ahigh, bhigh;

  int t;
  std::scanf("%d", &t);
  for(int tt = 0; tt < t; ++tt)
  {
    char a[110];
    char b[110];
    std::scanf("%s %s", a, b);

    abig.set(a);
    bbig.set(b);

    abig.getSquareRootLowBound(alow);
    //abig.getSquareRootHighBound(ahigh);
    bbig.getSquareRootLowBound(blow);
    //bbig.getSquareRootHighBound(bhigh);

    //long long tried = 0;
    //long long multed = 0;

    long long count = 0;
    {
      //overlap: 345 -> 34543

      int digits[100] = {};
      int quota = 9;
      int *end = digits;
      bool seenStart = false;

      for(;;)
      {
        //++tried;

        value.mDigits.clear();
        const int *at = end - 1;
        while(at >= digits)
        {
          value.mDigits.push_back(*at);
          --at;
        }
        at = digits + 1;
        while(at < end)
        {
          value.mDigits.push_back(*at);
          ++at;
        }

        bool setThisTime = false;
        if(!seenStart)
        {
          if(value >= alow)
          {
            //++multed;
            fairAndSquare.mDigits = value.mDigits;
            fairAndSquare.multiplyBy(value);
            setThisTime = true;
            if(fairAndSquare >= abig)
            {
              seenStart = true;
            }
          }
        }

        if(seenStart)
        {
          if(value > blow)
          {
            if(!setThisTime)
            {
              //++multed;
              fairAndSquare.mDigits = value.mDigits;
              fairAndSquare.multiplyBy(value);
            }
            if(fairAndSquare > bbig)
            {
              break;
            }
          }

          ++count;
          assert(count > 0);
        }

        advance(digits, quota, end, 1);
      }
    }
    {
      //repeat: 345 -> 345543

      int digits[100] = {};
      int quota = 9;
      int *end = digits;
      bool seenStart = false;

      for(;;)
      {
        //++tried;

        value.mDigits.clear();
        const int *at = end - 1;
        while(at >= digits)
        {
          value.mDigits.push_back(*at);
          --at;
        }
        at = digits;
        while(at < end)
        {
          value.mDigits.push_back(*at);
          ++at;
        }

        bool setThisTime = false;
        if(!seenStart)
        {
          if(value >= alow)
          {
            //++multed;
            fairAndSquare.mDigits = value.mDigits;
            fairAndSquare.multiplyBy(value);
            setThisTime = true;
            if(fairAndSquare >= abig)
            {
              seenStart = true;
            }
          }
        }

        if(seenStart)
        {
          if(value > blow)
          {
            if(!setThisTime)
            {
              //++multed;
              fairAndSquare.mDigits = value.mDigits;
              fairAndSquare.multiplyBy(value);
            }
            if(fairAndSquare > bbig)
            {
              break;
            }
          }

          ++count;
          assert(count > 0);
        }

        advance(digits, quota, end);
      }
    }

    std::printf("Case #%d: %lld\n", tt + 1, count);
  }
}
