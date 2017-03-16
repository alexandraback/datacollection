
def rotate(l):
  l.append(l[0])
  l.pop(0)
  return l

def returnlist(num):
  l = list(str(num))
  retlist = []
  for i in range(0, len(l)-1):
    l = rotate(l)
    retlist.append(''.join(l))
  return retlist   

if __name__ == '__main__':
  inputs = raw_input()
  cnt = 0
  for i in range(0, int(inputs)):
    d = {}
    l = raw_input().split()
    A = int(l[0])
    B = int(l[1])
    cnt = cnt + 1
    for j in range(A, B+1):      
      lst = returnlist(j)
      for k in lst:
        if int(k) > B or int(k) < A or j == int(k):
          continue
        if j < int(k):
          d[(j,int(k))] = 1
        else:
          d[(int(k),j)] = 1
    print "Case #" + str(cnt) + ": " + str(len(d))
     
