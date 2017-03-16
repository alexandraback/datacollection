#!/usr/bin/python
import os,io,math,sys

def run(filename):

  fin = open(filename, 'r')
  fout = open('output.out','w')
  T = int(fin.readline())
  
  for t in range(T):
    # read
    [A,N]=[ int(i) for i in fin.readline().split(" ")]
    mote = [ int(i) for i in fin.readline().split(" ")]
    mote = sorted(mote)
    mact = len(mote)
    act = 0
    print mote
   
    while mact > act and A != 1:
      # do a step
      if mote[0] < A:
        A += mote[0]
        mote = mote[1:]
        mact = min(mact, act+len(mote))
      else:
        A += A-1
        act += 1


    # solve
    res = mact

    
    # write
    fout.write("Case #%d: %d\n" %(t+1,res) )
    print 'Res:',res

  fin.close()
  fout.close()

if __name__ == "__main__":
  run(sys.argv[1])
