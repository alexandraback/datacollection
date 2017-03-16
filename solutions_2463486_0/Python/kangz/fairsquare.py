import sys

def concat_str(args):
    s = ""
    for arg in args:
        s += str(arg)
    return s

def debug(*args):
    sys.stderr.write(concat_str(args) + "\n")

def printf(*args):
    debug(*args)
    print concat_str(args)

def int_input():
    return map(int, raw_input().split(' '))


#######################################################

def is_palindrome(i):
    l = [x for x in str(i)]
    return l == list(reversed(l))

squares = []

for i in xrange(10**7):
    if is_palindrome(i) and is_palindrome(i * i):
        debug(i)
        squares.append(i * i)

debug(squares)

def read_input(        ):
    return int_input()


def solve(start, end):
    return len(filter(lambda x: start <= x <= end, squares))



#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

