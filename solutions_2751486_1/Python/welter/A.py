import sys

vowels = ['a', 'e', 'i', 'o', 'u']

def solve():
    t = int(sys.stdin.readline().strip())

    for i in xrange(1, t + 1):
        word, n = sys.stdin.readline().strip().split()
        n = int(n)
        res = 0
        vow  = 0
        tab = [0 for k in xrange(len(word))]
        for j, let in enumerate(word):
            if word[j] not in vowels:
                vow += 1
            else:
                vow = 0
            tab[j] = vow
        vow = 0
        vow_i = -1
        for j in xrange(len(word)):
            end = 0
            while vow < n:
                vow_i += 1
                if vow_i < len(word):
                    if word[vow_i] not in vowels:
                        vow += 1
                    else:
                        vow = 0
                else:
                    end = 1
                    break
            if end:
                break
            res += len(word) - vow_i
            if vow_i - n + 1 == j:
                vow -= 1
        print 'Case #%d: %d' % (i, res)


if __name__ == "__main__":
    solve()

