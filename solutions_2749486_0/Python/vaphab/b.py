#!/usr/bin/python
import os,io,math,sys

def run(filename):

  fin = open(filename, 'r')
  fout = open('output.out','w')
  T = int(fin.readline())
  
  for t in range(T):
    # read
    [X,Y]=[ int(i) for i in fin.readline().split(" ")]
    

    # solve
    res = ""
    for i in range(abs(X)):
      res += "EW" if X < 0 else "WE"

    for i in range(abs(Y)):
      res += "NS" if Y < 0 else "SN"

    # write
    fout.write("Case #%d: %s\n" %(t+1,res) )
    print 'Res:',res

  fin.close()
  fout.close()

if __name__ == "__main__":
  run(sys.argv[1])
