
def cal_num_wins(A,B,K):
  count = 0
  for first in xrange(A):
    for second in xrange(B):
      if first & second < K:
        count += 1

  return count

if __name__ == '__main__':
  T = int(raw_input())
  
  for i in xrange(1,T+1):
     A, B, K = tuple(int(x) for x in raw_input().split())
     print "Case #%s: %s" % (i, cal_num_wins(A,B,K))
     
   
