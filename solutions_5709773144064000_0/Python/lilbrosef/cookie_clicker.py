import sys


def decide_purchase(goal, rate, farm_price, farm_rate):
    conservative = goal / rate
    farm_time = farm_price / rate
    radical = farm_time + goal / (rate + farm_rate)
    decided = conservative > radical
    if decided:
        return True, farm_time
    else:
        return False, conservative


def simulate(farm_price, farm_rate, goal):
    time = 0.0
    rate = 2.0
    while True:
        decided, elapsed = decide_purchase(goal, rate, farm_price, farm_rate)
        if decided:
            time += elapsed
            rate += farm_rate
        else:
            return time + elapsed


def main(filename):
    with open(filename) as fd:
        num_tests = int(fd.readline())
        for i in xrange(num_tests):
            c, f, x = [float(t) for t in fd.readline().split()]
            print 'Case #{0}: {1:.7f}'.format(i + 1, simulate(c, f, x))

if __name__ == '__main__':
    main(sys.argv[1])
