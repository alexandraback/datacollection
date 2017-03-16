from __future__ import division
import sys


DEFAULT_COOKIES_PER_SECOND = 2


def main():
    file = open(sys.argv[1], 'r')
    T = int(file.readline().strip())
    
    for trial in xrange(1,T+1):
        sys.stdout.write("Case #%d: " % trial)
        
        data = file.readline().strip().split()
        C = float(data[0])
        F = float(data[1])
        X = float(data[2])
        
        cps = DEFAULT_COOKIES_PER_SECOND
        total_time = 0
        while True:
            next_farm_time = C / cps
            finish_time = X / cps
            if (finish_time > next_farm_time + X / (cps + F)):
                cps += F
                total_time += next_farm_time
            else:
                total_time += finish_time
                break
        
        sys.stdout.write("%.7f\n" % total_time)


if __name__ == '__main__':
    main()