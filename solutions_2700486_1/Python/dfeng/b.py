from operator import mul

nCk = lambda n,k: int(round(
    reduce(mul, (float(n-i)/(i+1) for i in range(k)), 1)
))

tri = [1]
for n in range(1,1000):
  tri.append(n * 2 * (2*n+1) / 2 + (n * 2 + 1))
# print tri


def main():
  n = int(input())
  for i in range(n):
    num, x, y = [abs(int(x)) for x in raw_input().split()]
    # print num, x, y

    # what round is x,y in
    rxy = (x + y) / 2 + 1

    if rxy == 1:
      prob = float(1)
      print 'Case #%s: %s' % (i + 1, prob)
      continue
    # else:

    # diagonal number
    dnum = [j for j,trinum in enumerate(tri) if num <= trinum][1]
    # print 'Diagonal position of xy: %s' % rxy
    # print 'Diagonal number of final diamond: %s' % dnum

    if dnum > rxy:
      prob = float(1)
      print 'Case #%s: %s' % (i + 1, prob)
      continue
    if dnum < rxy:
      prob = float(0)
      print 'Case #%s: %s' % (i + 1, prob)
      continue

    if num in tri:
      prob = float(1)
      print 'Case #%s: %s' % (i + 1, prob)
      continue


    # numbers left in the round
    pos = num - tri[dnum - 2]
    # print 'Triangles left: %s' % pos
    
    level = y+1
    # print 'Level %s' % level

    maxn = dnum*2 - 1
    # print 'Max: %s' % maxn

    if level == maxn:
      prob = float(0)
      print 'Case #%s: %s' % (i + 1, prob)
      continue

    tot = 2**pos
    prob = 0

    if pos - maxn + 1 >= level:
      prob = float(1)
      print 'Case #%s: %s' % (i + 1, prob)
      continue

    for ls in range(level, pos + 1):
      # print nCk(pos, ls)
      # print tot
      prob += nCk(pos, ls)/tot
    print 'Case #%s: %s' % (i + 1, prob)
    continue
   

    # print dnum, rxy

    # print 'Case #%s: %s' % (i + 1, fun(A, motes) )
main()