import sys
import itertools
import math

def rl(*args):
    return sys.stdin.readline().strip()

def main():
    T = int(rl())
    for c in range(1, T+1):
        N = int(rl())
        cars = rl().split()
        partitions = [(set(cars[0]), [cars[0]])]
        for car in cars[1:]:
            for s, l in partitions:
                if s.intersection(car):
                    s.update(car)
                    l.append(car)
                    break
            else:
                partitions.append((set(car), [car]))
        p = []
        for s, l in partitions:
            x = [l[0]]
            for car in l[1:]:
                for i, cx in enumerate(x):
                    if car[-1] == cx[0]:
                        x.insert(i, car)
                        break
                    elif car[0] == cx[-1]:
                        j = i + 1
                        while j < len(x):
                            cx = x[j]
                            if cx != car[0]*len(cx):
                                break
                            j += 1
                        x.insert(j, car)
                        break
                else:
                    # could not insert
                    break
            else:
                # all inserted fine
                seen = set()
                for k, g in itertools.groupby(''.join(x)):
                    if k in seen:
                        break
                    seen.add(k)
                else:
                    # train valid
                    cur = ''
                    nx = 1
                    n = 0
                    for i, car in enumerate(x):
                        if car == car[0]*len(car):
                            if car[0] != cur:
                                if n >= 2:
                                    nx *= n
                                n = 0
                            n += 1
                            cur = car[0]
                        else:
                            cur = ''
                            if n >= 2:
                                nx *= n
                            n = 0
                    if n >= 2:
                        nx *= n
                    p.append(math.factorial(nx))
                    continue
                # train invalid
            print 'Case #%d: 0' % c
            break
        else:
            r = reduce(int.__mul__, p, 1) * math.factorial(len(p)) % 1000000007
            print 'Case #%d: %d' % (c, r)

if __name__ == '__main__':
    main()
