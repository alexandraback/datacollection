import sys

VOWELS = set(['a', 'e', 'i', 'o', 'u'])

num_cases = int(sys.stdin.readline())

def get_value(name, n):
    start = 0
    cursor = 0
    value = 0

    while cursor < len(name):
        count = 0
        while cursor < len(name):
            if name[cursor] in VOWELS:
                count = 0
            else:
                count += 1
            if count == n:
                seg_start = (cursor - n + 1)
                permutations = (len(name) - cursor) * (seg_start - start + 1)
                value += permutations
                start = (seg_start + 1)
                cursor = start
                count = 0
            else:
                cursor += 1
    return value


for j in xrange(num_cases):
    name, n_str = sys.stdin.readline().strip().split()
    n = int(n_str)

    print "Case #%s: %s" % (j+1, get_value(name, n))
    j += 1

