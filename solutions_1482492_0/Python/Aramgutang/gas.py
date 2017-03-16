# Usage: python safety.py input.txt > output.txt
from decimal import Decimal
from operator import add
import sys

def solve_quad(a, b, c):
    a1 = (-b + Decimal(float(b**2 - Decimal(4.0)*a*c)**0.5))/(Decimal(2.0)*a)
    a2 = (-b - Decimal(float(b**2 - Decimal(4.0)*a*c)**0.5))/(Decimal(2.0)*a)
    return max(a1, a2)

with open(sys.argv[1]) as input:
    for case in xrange(1, int(input.readline().strip())+1):
        D, N, A = input.readline().strip().split(' ')
        D, N, A = Decimal(D), int(N), int(A)
        times = []
        for time in xrange(0, N):
            times.append(map(Decimal, input.readline().strip().split(' ')))
        accelerations = map(Decimal, input.readline().strip().split(' '))
        print 'Case #%s:' % case
        for acceleration in accelerations:
            d = Decimal(0.0)
            t = Decimal(0.0)
            v = Decimal(0.0)
            for i in xrange(0, len(times)-1):
                segment_d = (times[i+1][1] - times[i][1])
                segment_t = (times[i+1][0] - times[i][0])
                other_d = times[i][1] - d
                other_v = segment_d / segment_t
                intersect_t = solve_quad(Decimal(0.5)*acceleration, -other_v, v-other_d)
                if times[i+1][1] >= D:
                    if times[i][1] + other_v * intersect_t <= D:
                        answer = (D - times[i][1]) / other_v + times[i][0]
                    else:
                        answer = t + solve_quad(Decimal(0.5)*acceleration, v, d-D)
                    break
                if 0.0 <= intersect_t <= segment_t:
                    d = times[i+1][1]
                    v = other_v
                else:
                    d += v * segment_t + Decimal(0.5) * acceleration * segment_t
                    v += acceleration * (segment_t*segment_t)
                t = times[i+1][0]
                print d, v, t
            print answer