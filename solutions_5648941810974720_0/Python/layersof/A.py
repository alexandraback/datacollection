def main():
    N = input()
    for i in range(N):
        S = raw_input()
        print 'Case #%d: %s' % (i+1, solve(S))


def solve(S):
    counts = [0 for i in range(10)]

    from collections import Counter
    cnt = Counter()
    for c in S: cnt[c] += 1

    def remove(word):
        for c in word:
            cnt[c] -= 1

    while cnt['W']: 
        remove('TWO')
        counts[2] += 1
    while cnt['U']:
        remove('FOUR')
        counts[4] += 1
    while cnt['X']:
        remove('SIX')
        counts[6] += 1
    while cnt['G']:
        remove('EIGHT')
        counts[8] += 1
    while cnt['Z']:
        remove('ZERO')
        counts[0] += 1

    while cnt['O']:
        remove('ONE')
        counts[1] += 1
    while cnt['R']:
        remove('THREE')
        counts[3] += 1
    while cnt['F']:
        remove('FIVE')
        counts[5] += 1
    while cnt['S']:
        remove('SEVEN')
        counts[7] += 1

    while cnt['E']:
        remove('NINE')
        counts[9] += 1

    s = ''
    for i in range(10):
        while counts[i]:
            s += str(i)
            counts[i] -= 1
    return s
        





























if __name__ == '__main__':
    main()
