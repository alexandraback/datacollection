#!/usr/bin/env python
# encoding: utf-8
"""
B.py
"""

import sys, math

def main():
    f = open(sys.argv[1])
    T = int(f.readline())
    
    for t in xrange(T):
        D, N, A = f.readline().split()
        D = float(D)
        N = int(N)
        A = int(A)
        spaceTime = []
        for _ in xrange(N):
            spaceTime.append(map(float, f.readline().split()))
        accelerations = map(float, f.readline().split())
        
        # Fix any which are past the target
        for n in xrange(N):
            t_i, x_i = spaceTime[n]
            if x_i > D:
                if n == 0:
                    spaceTime[0] = (0, D)
                else:
                    t_im1, x_im1 = spaceTime[n-1]
                    speed = (x_i - x_im1)/(t_i - t_im1)
                    t_i = (D - x_im1)/speed
                    spaceTime[n] = (t_i, D)
                del spaceTime[n+1:]
                break
        
        limitAccelerations = []
        currentLimit = float('+inf')
        for i, (t_i, x_i) in enumerate(spaceTime):
            if i == 0: continue
            a_max = 2.0 * x_i / (t_i**2)
            if a_max >= currentLimit:
                continue
            limitAccelerations.append((2.0 * x_i / (t_i**2), i))
        
        print "Case #%i:" % (t+1)
        
        for a in accelerations:
            for a_i, i in limitAccelerations:
                if a > a_i:
                    i_limit = i
                    break
            else:
                print math.sqrt(2*D/a)
                continue
            result = -1.0
            for t_i, x_i in spaceTime[i_limit:]:
                result = max(result, math.sqrt(2*D/a) + t_i - math.sqrt(2*x_i/a))
            assert result > 0.0
            print result
        

if __name__ == "__main__":
    sys.exit(main())
