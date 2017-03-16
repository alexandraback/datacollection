import sys, math

def isFair(i):
    reverse = 0
    original = i
    while i:
        reverse = 10 * reverse + i % 10
        i = int(i / 10)
    if reverse == original:
        return True
    else:
        return False

if __name__ == '__main__':
    count = int(sys.stdin.readline())
    for r in range(1, count + 1):
        left, right = tuple([int(i) for i in sys.stdin.readline().split()])
        accum = 0
        for i in range(math.ceil(left ** 0.5), int(right ** 0.5) + 1):
            if isFair(i) and isFair(i ** 2):
                accum = accum + 1
        print('Case #%d: %d' % (r, accum))

