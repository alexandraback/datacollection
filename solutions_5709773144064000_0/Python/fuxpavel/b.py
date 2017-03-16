import sys
import time

def min_time(price, speed, target):
    current_speed = 2.0
    cookies = 0.0
    current_time = 0.0
    current_min = target/current_speed
    while True:
        time_added = price/current_speed
        if current_min < current_time + time_added + (target)/(current_speed + speed):
            return current_min
        current_time += time_added
        current_speed += speed
        current_min = current_time + target/current_speed

f = open(sys.argv[1])
cases = int(f.readline().strip())

for i in xrange(1, cases + 1):
    price, speed, target = [float(j) for j in f.readline().strip().split()]
    start = time.time()
    result = min_time(price, speed, target)
    print "Case #%d: %f" % (i, result)
