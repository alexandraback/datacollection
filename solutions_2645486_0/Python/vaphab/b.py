#!/usr/bin/python
import os,io,math,sys

def run(filename):
  global R
  global E

  fair=[]
  fin = open(filename, 'r')
  fout = open('output.out','w')
  T = int(fin.readline())
  
  for t in range(T):
    # read
    [E,R,N]=fin.readline().split(" ")
    E = int(E)
    R = int(R)
    N = int(N)
    V = [ int(v) for v in fin.readline().split(" ")]
    

    # solve
    res = dp(E,V)
    
    # write
    fout.write("Case #%d: %d\n" %(t+1,res) )
    print 'Res:',res

  fin.close()
  fout.close()

def dp(ce,v):
  if len(v) <=0:
    return 0
  m = 0
  for i in range(0,ce+1):
    e=ce-i
    m=max(m,v[0]*i+dp(min(e+R,E),v[1:]))
  
  return m

if __name__ == "__main__":
  run(sys.argv[1])
