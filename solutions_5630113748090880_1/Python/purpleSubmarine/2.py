def find_ans(arr, n):
    c = 0
    ans = []
    for i in range(1, 3000):
        if (arr[i] == 1):
            c += 1
            ans.append(i)
            if (c == n):
                return ans

t = int(raw_input())

for p in xrange(1, t + 1):
    n = int(raw_input())
    count = []
    for i in range(1, 3000):
        count.append(0)
    for y in range(2 * n - 1):
        for s in raw_input().split(" "):
            x = int(s)
            if (count[x] == 0):
                count[x] = 1
            else:
                count[x] = 0
    lst = find_ans(count, n)
    print "Case #" + str(p) + ":",
    for i in range(len(lst)):
        if (i < (len(lst) - 1)):
            print lst[i],
        else:
            print lst[i]
