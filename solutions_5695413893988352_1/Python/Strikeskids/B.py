#!/usr/bin/env python3

import sys

def brute_scores(c, j):
    l = len(c)

    def tostr(n):
        return ('%%0%dd' % l) % n

    def match(i, b):
        for x, y in zip(tostr(i), b):
            if x != y and y != '?': return False
        return True

    best = None

    for cb in range(10**l):
        if not match(cb, c): continue
        for jb in range(10**l):
            if not match(jb, j): continue
            val = abs(cb - jb)
            if not best or best[0] > val:
                best = (val, [cb, jb])

    return ' '.join(map(tostr, best[1]))

def minimize(arr, st=0):
    for i in range(st, len(arr)):
        if arr[i] == None:
            arr[i] = 0
    return arr

def maximize(arr, st = 0):
    for i in range(st, len(arr)):
        if arr[i] == None:
            arr[i] = 9
    return arr

def fill_same(a, b, st):
    for i in range(st, -1, -1):
        if a[i] == None:
            if b[i] == None:
                a[i] = 0
                b[i] = 0
            else:
                a[i] = b[i]
        elif b[i] == None:
            b[i] = a[i]
        else:
            assert b[i] == a[i]
    return (a, b)

def flip(a, b):
    return (b, a)

# JUMP a down
def fill_jump_down(a, b, st):
    jumped = False
    for i in range(st, -1, -1):
        if a[i] == None:
            if b[i] == None:
                b[i] = 0
                if jumped:
                    a[i] = 0
                else:
                    a[i] = 9
            else:
                if jumped:
                    a[i] = b[i]
                elif b[i] == 0:
                    a[i] = 9
                else:
                    a[i] = b[i]-1
                    jumped = True
        elif b[i] == None:
            if jumped:
                b[i] = a[i]
            elif a[i] == 9:
                b[i] = 0
            else:
                return (None, None)
        else:
            assert b[i] == a[i]

    if jumped:
        return (a, b)
    else:
        return (None, None)

# Jump b up
def fill_jump_up(a, b, st):
    aorig = a[:]
    borig = b[:]

    jumped = False
    for i in range(st, -1, -1):
        if a[i] == None:
            if b[i] == None:
                a[i] = 0
                if jumped:
                    b[i] = 0
                else:
                    b[i] = 1
                    jumped = True
            else:
                if jumped:
                    a[i] = b[i]
                elif b[i] == 0:
                    a[i] = 9
                else:
                    return (None, None)
        elif b[i] == None:
            if jumped:
                b[i] = a[i]
            elif a[i] == 9:
                b[i] = 0
            else:
                b[i] = a[i]+1
                jumped = True
        else:
            assert b[i] == a[i]

    if not jumped:
        return (None, None)

    return (a, b)

def orig_to_mod(orig):
    return [None if x == '?' else int(x) for x in orig]

def compute_dif(a, b):
    dif = 0
    for i in range(len(a)):
        dif *= 10
        dif += a[i] - b[i]
    return abs(dif)

def compute_scores(corig, jorig):
    c = orig_to_mod(corig)
    j = orig_to_mod(jorig)
    l = len(c)

    # Make sure to do smaller c, j first

    best = [float('Infinity'), None]
    def update_best(arr1, arr2):
        nonlocal best
        if arr1 == None or arr2 == None:
            return
        dif = compute_dif(arr1, arr2)
        nxt = [dif, (arr1, arr2)]
        if nxt < best: # Ensures small c first
            best[:] = nxt
    
    for i in range(l):
        if c[i] == None or j[i] == None: continue # Half-open or full-open
        elif c[i] == j[i]: continue # Fake force
        # Actual force
        if c[i] > j[i]:
            # Big c, small j with jump down
            update_best(*fill_jump_down(maximize(c[:], i+1), minimize(j[:], i+1), i-1))

            # Small c, big j
            update_best(*fill_same(minimize(c[:], i+1), maximize(j[:], i+1), i-1))

            # Big c, small j with jump up
            update_best(*fill_jump_up(maximize(c[:], i+1), minimize(j[:], i+1), i-1))
        else:
            # Small c with jump down, big j
            update_best(*flip(*fill_jump_down(maximize(j[:], i+1), minimize(c[:], i+1), i-1)))

            # Big c, small j
            update_best(*fill_same(maximize(c[:], i+1), minimize(j[:], i+1), i-1))

            # Small c with jump up, big j
            update_best(*flip(*fill_jump_up(maximize(j[:], i+1), minimize(c[:], i+1), i-1)))
        break
    else:
        update_best(*fill_same(c[:], j[:], l-1))

    return ' '.join(''.join(map(str, x)) for x in best[1])

def run_test(i):
    # print('Case #%d: %s' % (i, brute_scores(*(input().split()))))
    print('Case #%d: %s' % (i, compute_scores(*(input().split()))))

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