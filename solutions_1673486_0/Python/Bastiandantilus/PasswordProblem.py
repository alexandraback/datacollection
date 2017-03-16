from __future__ import division
import sys


if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())

    for _t in range(t):
        A, B = [int(x) for x in f.readline().strip().split()]
        P = [float(x) for x in f.readline().strip().split()]
        #print A, B, P
        PT = 1
        for _n in range(len(P)):
            PT = P[_n] * PT
        #print PT, B-A, B-A + B
        ET = PT * (B - A + 1) + (1 - PT) * ((B - A + 1) + B + 1)
        
        Enter_T = B + 2

        for x in range(A):
          BP = 1
          for _n in range(x):
             BP = P[_n] * BP
          BT = BP * (B - x  + (A - x)) + (1 - BP) * ((B - x + (A - x)) + B + 1) + 1
          if BT < ET:
             ET = BT

        score = 0
        print ("Case #" + str(_t+1) + ": " + str(min(ET, Enter_T )))
    

