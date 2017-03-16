import sys

def solve (X, R, C):
  if X > R and X > C: return "RICHARD"
  if X == 1:
    return "GABRIEL"
  if X == 2:
    if R*C % 2 == 0: return "GABRIEL"
    else: return "RICHARD"
  if X == 3:
    if R*C % 3 != 0: return "RICHARD"
    if R == 1 or C == 1: return "RICHARD"
    else: return "GABRIEL"
  if X == 4:
    if R == 1 or C == 1: return "RICHARD"
    if R*C == 8: return "RICHARD"
    if R*C == 12: return "GABRIEL"
    if R*C == 16: return "GABRIEL"
  # Not needed for small input, but true:
  if X >= 7: return "RICHARD"
  if R*C % X != 0: return "RICHARD"
  return "???"

f = open(sys.argv[1],"r")
T = int(f.readline())
for case in range(1,T+1):
  rawdata = f.readline().strip("\n").split()
  X = int(rawdata[0])
  R = int(rawdata[1])
  C = int(rawdata[2])
  winner = solve(X,R,C)
  print "Case #%i: %s" % (case, winner)
  
