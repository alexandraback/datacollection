
def solve():
  #f = open("in.txt", 'r')
  f = open("B-small-attempt1.in", 'r')
  #f = open("B-large.in", 'r')
  T = int(f.readline())
  for t in range(1,T+1):
    print "Case #%d:" %t, 
    [X, Y] = [int(k) for k in f.readline().split()]
    if Y<0:
      yy = "NS"
    else:
      yy = "SN"
    if X<0:
      xx = "EW"
    else:
      xx = "WE"
    res = xx*abs(X)+yy*abs(Y)
    print res

solve()

