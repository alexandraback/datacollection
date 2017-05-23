import sys
import math

def isFair(i):
    mstr=str(i)
    if mstr==mstr[::-1]:
        return True
    return False

if __name__=='__main__':
    t = int(sys.stdin.readline())
    for i in range(t):
        sys.stdout.write("Case #{}: ".format(i + 1))
        low, high = tuple(map(int, sys.stdin.readline().split()))
        count = 0
        for i in range(int(math.ceil(low ** 0.5)), int(high ** 0.5) + 1):
            if isFair(i) and isFair(i ** 2):
                count = count + 1
        sys.stdout.write('{}\n'.format(count))
