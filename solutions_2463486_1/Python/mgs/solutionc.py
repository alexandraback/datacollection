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

def makelist(top_val):
  cur_len=1
  pal_list = []
  j=1
  while True:
    if len(pal_list)>0:
      print len(str(pal_list[-1]))
    while len(str(j)) < (cur_len+1)/2+1:
      pal = buildPalendrome(j,cur_len)
      pal2 = pal**2
      if pal2 > top_val:
        return pal_list
      if isPalendrome(pal2):
        pal_list.append(pal2)
      j=j+1
    cur_len = cur_len + 1
    j=long(10**((cur_len+1)/2-1))
  return -1#Something horrible has happened


#First, pregenerate list (faster)
top_val = long(1e14)+1
fairsquares = np.matrix(makelist(top_val))

fin = open("input.txt",'r')
fout = open("output.txt",'w')

T = int(fin.readline().strip())
for i_case in range(T):
  AB_str = fin.readline().strip().split(' ')
  A = long(AB_str[0])
  B = long(AB_str[1])
  count = np.multiply(np.less_equal(fairsquares,B),np.greater_equal(fairsquares,A)).sum()
  out = "Case #"+str(i_case+1)+": "+str(count)+"\n"
  fout.write(out)

fin.close()
fout.close()

