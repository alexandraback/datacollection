import sys


def solve(testcase):
    parts = testcase.split(' ')

    s_max = int(parts[0])
    n = s_max + 1

    audience = [int(x) for x in parts[1]]

    sum_prefix = [0] * n
    sum_prefix[0] = audience[0]

    for i in range(1, n):
        sum_prefix[i] = sum_prefix[i - 1] + audience[i]

    counter = 0
    #print(sum_prefix)
    for i in range(1, n):
        if audience[i] == 0: continue
        s = i - sum_prefix[i - 1] - counter
        if s > 0:
            counter += s
            #print(i, counter)

    return counter


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        testcase = input()
        print("Case #%i: %s" % (caseNr, solve(testcase)))