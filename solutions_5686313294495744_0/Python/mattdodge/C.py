from collections import defaultdict


def run_case(input):
    t1s = defaultdict(int)
    t2s = defaultdict(int)
    num_topics, = read_ints(input)
    topics = []
    for i in range(num_topics):
        t1, t2 = read_strs(input)
        topics.append((t1, t2))
        t1s[t1] += 1
        t2s[t2] += 1

    num_fakes = 0
    for t1, t2 in topics:
        if t1s[t1] > 1 and t2s[t2] > 1:
            num_fakes += 1
            t1s[t1] -= 1
            t2s[t2] -= 1

    return num_fakes

##############################
#    CODE JAM BOILERPLATE    #
##############################


def read_ints(input, n=1):
    """ Read n integers from input - all on one line, space separated """
    return (int(st) for st in read_strs(input, n))


def read_strs(input, n=1):
    """ Read n strings from input - all on one line, space separated """
    return input.pop(0).rstrip("\n").split(" ")

# GCJ boiler plate...call run_case for each case given
if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    lines = sys.stdin.readlines()
    sys.stdin = open('/dev/tty')
    num_cases = int(lines.pop(0))
    for case_num in range(num_cases):
        print("Case #%d: %s" % (case_num + 1, run_case(lines)))
