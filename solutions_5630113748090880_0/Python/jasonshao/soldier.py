t = input()
for poo in range(t):
    n = input()
    freq = {}
    for i in range(2*n - 1):
        a = map(int, raw_input().split())
        for j in a:
            freq[j] = freq.get(j, 0) + 1
    ans = []
    for i in freq:
        if freq[i] % 2 != 0:
            ans.append(i)
    ans.sort()
    ans = map(str, ans)
    print "Case #" + str(poo + 1) + ": " + ' '.join(ans)
