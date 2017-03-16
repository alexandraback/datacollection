import sys
import re


def handle_case(case_num):
    N = int(sys.stdin.readline())
    unfinished_levels = set(range(N))
    i2fst = {}
    i2snd = {}
    half = set()
    firsts = []
    seconds = []
    for i in range(N):
        f, s = map(int, sys.stdin.readline().split())
        i2fst[i] = f
        i2snd[i] = s
        firsts.append((f, i))
        seconds.append((s, i))

    firsts.sort(key=lambda p: p[0])
    seconds.sort(key=lambda p: p[0])
    # print firsts
    # print seconds

    star_number = 0
    iterations = 0
    while len(unfinished_levels):
        if seconds[0][0] <= star_number:
            iterations += 1
            if seconds[0][1] in half:
                star_number += 1
            else:
                star_number += 2
            unfinished_levels.remove(seconds[0][1])
            seconds = seconds[1:]
            continue
        if not len(firsts):
            print 'Case #%s: Too Bad' % (case_num)
            return
        if firsts[0][1] not in unfinished_levels:
            firsts = firsts[1:]
            continue
        if firsts[0][0] <= star_number:
            cands = [f for f in firsts if f[0] <= star_number]
            c = cands[0]
            b = i2snd[c[1]]
            for oc in cands[1:]:
                if i2snd[oc[1]] > b:
                    b = i2snd[oc[1]]
                    c = oc

            half.add(c[1])
            firsts.remove(c)
            iterations += 1
            star_number += 1
            continue
        print 'Case #%s: Too Bad' % (case_num)
        return
    

    print 'Case #%s: %s' % (case_num, iterations)


def main():
    T = int(sys.stdin.readline().strip())
    for case_num in xrange(1, T+1):
        handle_case(case_num)


if __name__ == '__main__':
    main()