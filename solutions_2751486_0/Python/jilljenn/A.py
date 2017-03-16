def r(w, n):
    vowels = 'aeiou'
    nvalue = 0
    nb_cons_so_far = 0
    dmax = -1
    for i in range(len(w)):
        if w[i] in vowels:
            nb_cons_so_far = 0
        else:
            nb_cons_so_far += 1
        if nb_cons_so_far >= n:
            dmax = i - n + 1
        nvalue += dmax + 1
    return nvalue

if __name__ == '__main__':
    T = int(raw_input())
    for i in range(T):
        w, n = raw_input().split()
        print 'Case #%d: %d' % (i + 1, r(w, int(n)))