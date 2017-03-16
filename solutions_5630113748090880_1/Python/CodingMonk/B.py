t = int(raw_input())

for i in xrange(1, t + 1):
    n = int(raw_input())
    counter = {}
    for j in xrange(2*n - 1):
        line = raw_input()
        nums= line.split(" ")
        for y in nums:
            if y in counter:
                counter[y] += 1
            else:
                counter[y] = 1
    ans = []
    for z in counter:
        if counter[z] % 2 != 0:
            ans.append(z)
    nums = [int(a) for a in ans]
    nums.sort()
    final_ans = [str(b) for b in nums]
    print "Case #{}: {}".format(i, " ".join(final_ans))