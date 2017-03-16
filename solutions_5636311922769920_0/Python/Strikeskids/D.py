#!/usr/bin/env python3

def compute_gold(k, c, s):
    if s * c < k: return 'IMPOSSIBLE'
    nums = []
    idx = 0
    for i in range(s):
        v = 0
        for j in range(c):
            v = v*k + (idx % k)
            idx += 1
        nums.append(v)
        if idx >= k: break
    return ' '.join(str(x+1) for x in nums)

def run_test(i):
    args = map(int, input().split(' '))
    print('Case #%d: %s' % (i, compute_gold(*args)))

def main():
    T = int(input())

    for t in range(T):
        run_test(t+1)

def extensive():
    import random
    for i in range(100000):
        compute_insomnia(random.randint(0, 10**6))
    exit(0)

if __name__ == '__main__': main()