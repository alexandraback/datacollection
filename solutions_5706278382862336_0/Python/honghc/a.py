import math
import fractions

def isPower (num, base):
    if base == 1 and num != 1: return False
    if base == 1 and num == 1: return True
    if base == 0 and num != 1: return False
    power = int (math.log (num, base) + 0.5)
    return base ** power == num

T = int(raw_input())
for case in range(1, T+1):
  s = raw_input().split('/')
  P = float(s[0])
  Q = float(s[1])
  count = 0
  while(Q/P!=1):
    # print 'P: #{0}, Q: #{1}'.format(P,Q)
    gcd = fractions.gcd(P,Q)
    if (gcd!=0):
      P=P/gcd
      Q=Q/gcd
    if(not isPower(Q,2) and Q!=1):
      count="impossible"
      break;
    if (P>Q/2):
      count+=1
      break;
    else:
      P1 = 1
      while(P1*2<P):
        P1= P1*2;
      P = P1
      Q = math.floor(Q/2.0)
    count+=1
  print 'Case #{0}: {1}'.format(case, count)