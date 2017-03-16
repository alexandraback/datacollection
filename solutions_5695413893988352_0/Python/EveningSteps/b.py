# coding: utf-8

def repl(s, n, cnt):
    c = 0
    ss = ''
    for i in xrange(len(s)):
        if s[i] == '?':
            ss += n[c]
            c += 1
        else:
            ss += s[i]
    return ss


def solve(a, b):
    ca, cb = a.count('?'), b.count('?')
    cur_min = 1e40
    for i in xrange(10**ca):
        cur_a = repl(a, str('{0:0{w}}'.format(i, w=ca)), ca)

        for j in xrange(10**cb):
            cur_b = repl(b, str('{0:0{w}}'.format(j, w=cb)), cb)
            diff = abs(int(cur_a, 10) - int(cur_b, 10))

            if diff < cur_min:
                ans_a, ans_b = cur_a, cur_b
                cur_min = diff

    return ans_a, ans_b


def main():
    n = int(raw_input())
    for i in xrange(n):
        a, b = raw_input().split()
        ra, rb = solve(a, b)
        print "Case #{}: {} {}".format(i+1, ra, rb)

if __name__ == '__main__':
    main()
