#!/usr/bin/python

import sys

T = sys.stdin.readline()

counter = 1
for line in sys.stdin:
    (c, f, x) = map(float, line.strip().split())
    
    speed = 2.0
    min = x/speed
    cur = 0.0
    
    
    while True:
        time = c/speed
        if cur + time + (x/(f+speed)) < min:
            cur += time
            speed += f
            min = cur + (x/speed)
        else:
            break
        
    print 'Case #{}: {}'.format(counter, min) 
    counter += 1
    
    