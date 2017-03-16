#!/usr/bin/python
from sys import argv
fout = open("output.txt","w")
def maxs(s):
  ret = s[0]
  iret = 0
  for i, e in enumerate(s):
    if ord(e) > ord(ret):
      ret = e
      iret = i
  return iret
    

def f(s):
  s = s[::-1]
  build = '' 
  other = ''
  while(s): 
    build+=s[maxs(s)]
    other+=s[:maxs(s)]
    s = s[maxs(s)+1:]
  return  build+other[::-1]


if __name__ == "__main__":
  for i, line in enumerate(open(argv[1]).readlines()):
    if i!=0: 
      fout.write(("Case #%d: "%i)+f(line.strip())+'\n')
