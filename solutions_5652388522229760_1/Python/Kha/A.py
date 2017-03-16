import sys

f = sys.stdin #open('C-small-practice.in')
def get_int(): return int(f.readline())
def get_ints(): return [int(s) for s in f.readline().split()]

for t in range(get_int()):
    n = get_int()
    digs = set()
    k = 1
    if n == 0:
        print('Case #%d: INSOMNIA' % (t+1))
    else:
        while True:
            digs |= set(str(k * n))
            # print(digs)
            if len(digs) == 10:
                print('Case #%d: %d' % (t+1, k * n))
                break
            k += 1
