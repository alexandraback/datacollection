a = open("A-large.in").read().split("\n")
a = [a[i-4:i] for i in xrange(5,len(a),5)]
def check(x):
 rows = x + ["".join([z[i] for z in x]) for i in xrange(4)]+[x[0][0]+x[1][1]+x[2][2]+x[3][3],x[0][3]+x[1][2]+x[2][1]+x[3][0]]
 for row in rows:
  if "." not in row and "X" not in row:
   return "O won"
  if "." not in row and "O" not in row:
   return "X won"
 if "." not in "".join(x):
   return "Draw"
 return "Game has not completed"
open("A-large.out","w").write("\n".join(["Case #%d: %s" % (i, check(a[i-1])) for i in xrange(1,len(a)+1)]))
