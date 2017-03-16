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


def read_input(        ):
    size, _ = int_input()
    motes = int_input()
    return size, motes

def solve(size, motes):
    #do not divide by zero
    if size == 1:
        return len(motes)

    motes.sort(reverse=True)

    mini = len(motes)
    n_added = 0
    while len(motes) != 0:
        if motes[-1] < size:
            size += motes[-1]
            motes.pop()
            mini = min(mini, n_added + len(motes))
        else:
            val = motes[-1]
            n = (val - size + 1 + size - 2) // (size - 1)
            n_added += n
            size += n * (size - 1)

    return mini


#######################################################


for n_test_case in range(1, int(raw_input()) + 1):
    debug("Solving case ", n_test_case)

    printf("Case #", n_test_case, ": ", str(solve(*read_input())))

