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
    res = numCon(s,n)

    # write
    fout.write("Case #%d: %d\n" %(t+1,res) )
    print 'Res:',res

  fin.close()
  fout.close()




def numCon(s,n):
  vow = ['a','e','i','o','u']
  a = 0
  b = n-2
  c = 0
  count = 0
  res = 0
  L = len(s)
  for i in range(L):
    if s[i] not in vow:
      if count == 0:
        a = i
      if count == n-1:
        c = b-n+1
        b = i
        res += (a-c)*(L-b)

      if count >= n:
        a = a+1
        c = a
        b = i
        res += (L-b)
      
      count += 1
    else:
      count = 0
  return res


if __name__ == "__main__":
  run(sys.argv[1])
