from fractions import Fraction

def time(start, speed, x):
    return (x - start) / speed

for t in range(1, int(input()) + 1):
    factory_cost, factory_speed, x = [float(i) for i in input().strip().split()]
    answer, best, speed = 0, time(0, 2, x), 2
    while True:
        answer += time(0, speed, factory_cost)
        speed += factory_speed
        cur = answer + time(0, speed, x)
        if cur > best:
            break
        best = cur
    print('Case #{}: {:.20f}'.format(t, best))
