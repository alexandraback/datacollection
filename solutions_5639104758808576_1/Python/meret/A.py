d = int(raw_input())
for i in range(1, d + 1):
    _, s = raw_input().split()
    added = 0
    total = 0
    for j in range(len(s)):
        added = max(added, j - total)
        total += int(s[j])
    print 'Case #' + str(i) + ': ' + str(added)
