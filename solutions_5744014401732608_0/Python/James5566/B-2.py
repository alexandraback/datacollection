def main():
 t=int(raw_input()) 
 for caseIdx in xrange(1,t+1):
  B,M=map(int,raw_input().strip().split(' '))
  solve(caseIdx,B,M)
def solve(caseIdx,B,M):
 maxPsblM=maxWays(B)
 if M>maxPsblM:
  print "Case #{}: {}".format(caseIdx,"IMPOSSIBLE")
  return
 print "Case #{}: {}".format(caseIdx,"POSSIBLE")
 if M==maxPsblM:
  connectToLast="1"*(B-1)
 else:
  connectToLast="0"+("{0:b}".format(M)[::-1])
 for i in xrange(B-1):
  slidesFromI="0"*(i+1)+"1"*(B-i-2)
  if i<len(connectToLast):
   slidesFromI+=connectToLast[i]
  else:
   slidesFromI+="0"
  print slidesFromI
 print "0"*B
 return
def maxWays(B):
 return 2**(B-2)
if __name__=='__main__':
 main()
# Created by pyminifier (https://github.com/liftoff/pyminifier)

