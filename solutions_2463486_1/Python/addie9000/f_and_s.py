#!/usr/local/bin/python
import sys, string, math, time

FAIR_CACHE = []


#square
def square(x):
    return x * x


# check if num x is palindrome
def is_palindrome(x):
    candidate = list(str(x))
    while len(candidate) > 1:
        if candidate.pop(0) != candidate.pop():
            return False
    return True


# create palindrome_cache
def create_fair_cache(max):
    del FAIR_CACHE[:]
    root = 1
    sq = square(root)

    while sq <= max:
        if is_palindrome(root) and is_palindrome(sq):
            FAIR_CACHE.append(sq)

        #prepare for next
        root += 1
        sq = square(root)


#solve case function
def solve_case(ab, case_number):
    fs = 0
    for fair in FAIR_CACHE:
        if fair < ab[0]:
            continue
        if fair > ab[1]:
            break
        fs += 1

    print "Case #%d: %d" % (case_number, fs)


#main
def main():
    create_fair_cache(int(pow(10, 14)))

    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        ab = map(int, r.readline().strip().split(' '))
        solve_case(ab, case_number)

# invoke main
if __name__ == "__main__":
    main()