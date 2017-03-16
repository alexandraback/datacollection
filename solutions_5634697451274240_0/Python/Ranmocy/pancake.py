# Flip stack from 0 to l as group
def flip(stack, l):
    temp = stack[:l+1]
    temp.reverse()
    for i in xrange(l+1):
        stack[i] = 1 - temp[i] # flip

def solve(stack):
    count = 0
    n = len(stack)
    last_negative = n - 1
    print 'start'
    print stack
    while last_negative >= 0:
        # update last_negative
        while last_negative >= 0 and stack[last_negative] == 1:
            last_negative -= 1
        # if all set
        if last_negative < 0:
            return count

        # find first_negative
        first_negative = 0
        while first_negative < n and stack[first_negative] == 1:
            first_negative += 1
        # if all set (impossible)
        if first_negative >= n:
            return count

        if first_negative > 0:
            flip(stack, first_negative - 1)
            count += 1
        flip(stack, last_negative)
        count += 1

        print stack
    return count

with open('pancake.in', 'r') as fin:
    with open('pancake.out', 'w') as fout:
        T = int(fin.readline())
        for i in xrange(1, T+1):
            t = fin.readline()
            a = [0 if c == '-' else 1 for c in t[:-1]]
            fout.write('Case #{0}: {1}\n'.format(i, solve(a)))
