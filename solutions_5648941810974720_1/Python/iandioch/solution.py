import sys

n = int(sys.stdin.readline())

def rem(d, s):
    for c in s:
        if c in d:
            d[c] -= 1
    return d

def get(s):
    counts = {}
    for c in s:
        if c in counts:
            counts[c] += 1
        else:
            counts[c] = 1

    nums = [0 for i in xrange(10)]
    while 'X' in counts and counts['X'] > 0:
        counts = rem(counts, 'SIX')
        nums[6] += 1
    while 'S' in counts and counts['S'] > 0:
        counts = rem(counts, 'SEVEN')
        nums[7] += 1
    while 'V' in counts and counts['V'] > 0:
        counts = rem(counts, 'FIVE')
        nums[5] += 1
    while 'F' in counts and counts['F'] > 0:
        counts = rem(counts, 'FOUR')
        nums[4] += 1
    while 'Z' in counts and counts['Z'] > 0:
        counts = rem(counts, 'ZERO')
        nums[0] += 1
    while 'R' in counts and counts['R'] > 0:
        counts = rem(counts, 'THREE')
        nums[3] += 1
    while 'H' in counts and counts['H'] > 0:
        counts = rem(counts, 'EIGHT')
        nums[8] += 1
    while 'T' in counts and counts['T'] > 0:
        counts = rem(counts, 'TWO')
        nums[2] += 1
    while 'O' in counts and counts['O'] > 0:
        counts = rem(counts, 'ONE')
        nums[1] += 1
    while 'N' in counts and counts['N'] > 0:
        counts = rem(counts, 'NINE')
        nums[9] += 1
    
    ans = ''
    for i in xrange(10):
        while nums[i] > 0:
            ans += str(i)
            nums[i] -= 1
    return ans 

for i in xrange(1, n+1):
    s = sys.stdin.readline()
    ans = get(s)
    print 'Case #{}: {}'.format(i, ans)
