#!/usr/bin/python
import os,io,math,sys

def run(filename):

  fin = open(filename, 'r')
  fout = open('output.out','w')
  T = int(fin.readline())
  
  for t in range(T):
    # read
    [s,n]= fin.readline().split(" ")
    n = int(n)
   
    # solve
    res = 0
    for i in range(len(s)):
      for j in range(i-1,len(s)):
        if numCon(s[i:j+1]) >=n :
          res += 1
    
    # write
    fout.write("Case #%d: %d\n" %(t+1,res) )
    print 'Res:',res

  fin.close()
  fout.close()




def numCon(s):
  vow = ['a','e','i','o','u']
  count = 0
  m = 0
  for i in range(len(s)):
    if s[i] not in vow:
      count += 1
      m= max(m, count)
    else:
      count = 0

  return m

if __name__ == "__main__":
  run(sys.argv[1])
