import numpy as np
def solve(N, lists):
    # assume we lost a column list
    count = {}
    for l in lists:
        for h in l:
            if h not in count: count[h] = 1
            else: count[h] += 1
    missing_list = [key for key, value in count.iteritems() if value%2]
    return ' '.join(map(str, sorted(missing_list)))

def main():
    testcases = input()
    for case_num in xrange(1, testcases+1):
        N = int(raw_input())
        lists = []
        for i in xrange(2*N-1):
            lists.append(raw_input().split(' '))
        lists = np.array(lists).astype(int)
        print("Case #%i: %s" % (case_num, solve(N, lists)))

def test():
    single_case = raw_input()
    print("Case #1: %s" % (solve(single_case)))


if __name__=='__main__':
    main()
    #test()

