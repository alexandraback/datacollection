def solve(single_case):
    output = []
    for c in single_case:
        if len(output) == 0:
            output.append(c)
        elif c >= output[0]:
            output.insert(0,c)
        else:
            output.append(c)
    return ''.join(output)

def main():
    testcases = input()
    for case_num in xrange(1, testcases+1):
        single_case = raw_input()
        print("Case #%i: %s" % (case_num, solve(single_case)))

def test():
    single_case = raw_input()
    print("Case #1: %s" % (solve(single_case)))


if __name__=='__main__':
    main()
    #test()


