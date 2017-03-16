import sys

def carry_over(c, R, E):
  return min(c + R, E)

def process_case(infile):
  line = [int(v) for v in infile.readline().split()]
  E = line[0]
  R = line[1]
  N = line[2]
  
  v = [int(v) for v in infile.readline().split()]
  
  T = [[0 for e in range(E+1)] for n in range(N)]
  
  for e in range(E+1):
    T[N-1][e] = e * v[N-1]
    
  for n in range(N-2, -1, -1):
    for e in range(E+1):
      if (e == 0):
        T[n][e] = T[n+1][R]
      else:
        T[n][e] = max(v[n] + T[n][e-1], T[n+1][carry_over(e, R, E)])
  
  return T[0][E]

filename = sys.argv[1]

infile = open(filename)

T = int(infile.readline())

for x in range(T):
  sys.stdout.write("Case #")
  sys.stdout.write(str(x+1))
  sys.stdout.write(": ")
  
  print process_case(infile)
  
infile.close()
