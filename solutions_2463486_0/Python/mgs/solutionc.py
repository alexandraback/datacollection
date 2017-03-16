import numpy as np

def buildPalendrome(j,cur_len):
  s = str(j)
  if cur_len % 2 == 0:
    return long(s + s[::-1])
  else:
    return long(s+s[0:len(s)-1][::-1])

def isPalendrome(p):
  s = str(p)
  return s == s[::-1]

def count(A,B):
  a = long(np.sqrt(float(A))) #may be too low
  if a**2 > A:
    print "ERROR! a too big!"
  str_a = str(a)
  cur_len = len(str_a)
  k = long(str_a[0:(len(str_a)+1)/2])#starting point for left side
  pal_count = 0
  j=k
  while True:
    while len(str(j)) < (cur_len+1)/2+1:
      pal = buildPalendrome(j,cur_len)
      pal2 = pal**2
      if pal2 > B:
        return pal_count
      if pal2 >= A and isPalendrome(pal2):
        pal_count = pal_count + 1
      j=j+1
    cur_len = cur_len + 1
    j=long(10**((cur_len+1)/2-1))
  return -1#Something horrible has happened

fin = open("input.txt",'r')
fout = open("output.txt",'w')

T = int(fin.readline().strip())

for i_case in range(T):
  AB_str = fin.readline().strip().split(' ')
  A = long(AB_str[0])
  B = long(AB_str[1])
  out = "Case #"+str(i_case+1)+": "+str(count(A,B))+"\n"
  fout.write(out)

fin.close()
fout.close()

