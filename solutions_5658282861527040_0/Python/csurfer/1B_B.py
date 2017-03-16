from io import open

def process(inp):
  a, b, k = map(int, inp.readline().split(' '))
  cp = []
  for i in xrange(a):
    for j in xrange(b):
      cp.append([i, j])
  cnt = 0
  for el in cp:
    if el[0] & el[1] < k:
      cnt += 1
  return cnt

def output(strOut, out):
  print strOut
  out.write(u"{}\n".format(strOut))

def main():
  inp = open("input.txt")
  out = open("output.txt", "wb+")
  tC = int(inp.readline())
  tc = tC
  while tc > 0:
    tc -= 1
    ans = process(inp)
    output(u"Case #{}: {}".format(tC-tc, ans), out)
  inp.close()
  out.close()

if __name__ == "__main__":
  main()
