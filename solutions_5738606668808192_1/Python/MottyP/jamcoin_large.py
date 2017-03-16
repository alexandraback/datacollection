# If for a number in base B, the sum of digits at the even places, minus the sum
# of digits at the odd places, divides by B+1, then the number divides by B+1.
# We can easily make these two sums equal, by filling the same pattern of 1's twice.

def assertCorrect(numstr):
    assert all(int(numstr, base) % (base+1) == 0 for base in range(2,11))

def solve():
    print 'Case #1:'
    for index in range(1, 501):
        s = bin(index).replace('0b', '') + '1'
        s = s.rjust(16, '0')
        numstr = s[::-1] + s
        assertCorrect(numstr)
        print numstr, ' '.join(str(d) for d in range(3, 12))

if __name__ == '__main__':
    solve()
