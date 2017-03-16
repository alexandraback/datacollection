TESTCASE = int(input())
for test in range(TESTCASE):
    N = int(input())
    posts = [input().split()[0] for i in range(N)]
    print('Case #' + str(test + 1) + ':', len(posts)-len(set(posts)))
