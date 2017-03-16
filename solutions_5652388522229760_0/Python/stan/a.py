import sys

def next_stop_number(n):
    add = n
    seen_digits = set(str(n))
    while len(seen_digits) != 10:
        n += add
        seen_digits |= set(str(n))
    return n

num_tests = int(sys.stdin.readline())
for test_num in xrange(num_tests):
    n = int(sys.stdin.readline())
    print "Case #%d:" % (test_num + 1), next_stop_number(n) if n > 0 else "INSOMNIA"

