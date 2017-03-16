#!/usr/bin/env python3

def rindex(arr, value):
    renum = zip(range(len(arr)-1, -1, -1), reversed(arr))
    return next(i for i, v in renum if v == value)

def flip(arr, a, b):
    arr[a:b] = [not arr[i] for i in range(b-1, a-1, -1)]

def count_flips(inp):
    if '-' not in inp: return 0
    arr = [x == '+' for x in inp] + [True]
    flips = 0
    back = rindex(arr, False) + 1
    while back > 0:
        # Find the first minus
        st = arr.index(False)
        # If there are plusses
        if st != 0:
            flips += 1
            flip(arr, 0, st)
        size = arr.index(True)
        flips += 1
        flip(arr, 0, back)
        back -= size
    return flips

def run_test(i):
    v = input()
    print('Case #%d: %s' % (i, count_flips(v)))

def main():
    T = int(input())

    for t in range(T):
        run_test(t+1)

if __name__ == '__main__': main()