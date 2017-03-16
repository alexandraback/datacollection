#!/usr/bin/python
import os,io,math,sys

def run(filename):

  fair=[]
  fin = open(filename, 'r')
  fout = open('output.out','w')
  T = int(fin.readline())
  
  for t in range(T):
    # read
    [r,x]=fin.readline().split(" ")
    r = long(r)
    x = long(x)

    # solve
    res = long(nring(r,x))+1  

    
    # write
    fout.write("Case #%d: %d\n" %(t+1,res) )
    print 'Res:',res

  fin.close()
  fout.close()

def nring(r,x):
  return (-3.0-2.0*r+math.sqrt(8L*x+(2L*r-1L)*(2L*r-1L)))/4

if __name__ == "__main__":
  run(sys.argv[1])
