import sys

def sqrt(n):
  a, b = divmod(n.bit_length(), 2)
  x = 2**(a + b)
  while True:
    y = (x + n//x) // 2
    if y >= x:
      return x
    x = y

if __name__ == '__main__':
  tests = int(sys.stdin.readline())
  for test in range(1, tests + 1):
    r, t = [int(x) for x in sys.stdin.readline().split()]
    ans = (-2*r + 1 + sqrt(4*(r**2 - r) + 1 + 8*t)) // 4
    print("Case #" + str(test) + ": " + str(ans))
