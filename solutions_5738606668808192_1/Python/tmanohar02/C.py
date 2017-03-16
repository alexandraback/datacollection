def helper(n=16, j=50):
  for i in range(j):
    number = ((1L << (n/2)) + 1L) * ((1L << ((n/2) - 1)) + (i << 1) + 1L)
    print "{0:b}".format(number),
    for j in range(2, 11):
      print pow(long(j), n/2) + 1,
    print

def main():
  t = raw_input()
  line = raw_input()
  n = int(line.split(' ')[0])
  j = int(line.split(' ')[1])
  print "Case #1:"
  helper(n, j)

if __name__ == '__main__':
  main()

